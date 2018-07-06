/*
mandelbrot.c
- Runs a web server that produces a 512x512 bitmap of a certain area of the mandelbrot set
William Gao - Solo Team

Stub created by Tim Lambert on 02/04/12.
Containing code created by Richard Buckland on 28/01/11.
*/

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>
#include "pixelColor.h"
#include "mandelbrot.h"

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 99999999

#define SIZE 512
#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)

#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0

#define GET "GET "
#define FAVICON "/favicon.ico"
#define HOMEPAGE "/"
#define TILE "/tile"
#define MANDEL "/mandelbrot/2/"

#define MAX_STEPS 256
#define MAX_DISTANCE 2
#define SQUARED 2
#define POLYNOMIAL_MULTIPLIER 2

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

struct pixel {
  bits8 red;
  bits8 green;
  bits8 blue;
};

typedef struct pixel pixel;

typedef struct _complex {
  double real;
  double imaginary;
} complex;

typedef struct _triordinate {
  double x;
  double y;
  int z;
} triordinate;

triordinate extract (char *message);
double myAtoD (char *message);
long myAtoL (char *message);
int waitForConnection(int serverSocket);
int makeServerSocket(int portno);
void writeBMP(FILE *stream, char *url);
void writeBMPHeader(FILE *file);
void writePixels(FILE *file, complex centre, double zoom);

int main(int argc, char *argv[]) {
  printf ("************************************\n");
  printf ("Starting mandelbrot server %f\n", SIMPLE_SERVER_VERSION);
  printf ("Serving tiles since 2018\n");

  int serverSocket = makeServerSocket (DEFAULT_PORT);
  printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
  printf ("************************************\n\n");

  char request[REQUEST_BUFFER_SIZE];

  int numberServed = 0;
  while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
    printf ("* So far served %d pages\n", numberServed);

    int connectionSocket = waitForConnection (serverSocket);
    // wait for a request to be sent from a web browser, open a new
    // connection for this conversation

    // read the first line of the request sent by the browser
    int bytesRead;
    bytesRead = read (connectionSocket, request, (sizeof request)-1);
    assert (bytesRead >= 0);
    // were we able to read any data from the connection?

    // print entire request to the console
    printf ("Received http request\n");

    // Investigate using sscanf to extract information from the request!
    FILE *stream = fdopen(connectionSocket, "wb");

    // now get the url path containing the details
    int counter = 0;
    int urlPos = strstr(request, GET) - request;
    char *url = malloc(REQUEST_BUFFER_SIZE);
    char current = GET[0];
    while (counter < strlen(request) && current != ' ') {
      url[counter] = request[counter + urlPos + strlen(GET)];
      current = request[counter + urlPos + strlen(GET)];
      counter++;
    }

    if (strncmp(url, FAVICON, strlen(FAVICON)) == 0) {
      // Send the http response header
      char *message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "\r\n";

      printf("Cancelled request due to favicon.ico URL\n");
      fwrite (message, strlen(message), 1, stream);
    } else {
      printf ("Sending http response\n");
      writeBMP(stream, url);
      numberServed++;
    }

    // close the connection after sending the page- keep aust beautiful
    fclose(stream);
    free(url);
  }

  // close the server connection after we are done- keep aust beautiful
  printf ("Shutting down the server\n");
  close (serverSocket);

  return EXIT_SUCCESS;
}

void writeBMP(FILE *stream, char *url) {
  char *message;

  if (strncmp(url, TILE, strlen(TILE)) == 0 || strncmp(url, MANDEL, strlen(MANDEL)) == 0) {
    // now parse the url path into the coords
    triordinate coordinates = extract(url);
    complex centre;
    centre.real = coordinates.x;
    centre.imaginary = coordinates.y;
    double zoom = pow(2, -coordinates.z);

    // Send the http response header
    message = "HTTP/1.0 200 OK\r\n"
              "Content-Type: image/bmp\r\n"
              "\r\n";

    printf ("About to send >\n%s", message);
    fwrite (message, strlen(message), 1, stream);

    writeBMPHeader(stream);
    writePixels(stream, centre, zoom);
  } else if (strncmp(url, HOMEPAGE, strlen(HOMEPAGE)) == 0) {
    // Send the http response header
    message = "HTTP/1.0 200 OK\r\n"
              "Content-Type: text/html\r\n"
              "\r\n"
              "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>\n";

    fwrite (message, strlen(message), 1, stream);
  }
}

// Send BMP pixel array
void writePixels(FILE *stream, complex centre, double zoom) {
  double currentX, currentY, topX, topY, col;
  double row = 0;
  int steps;
  pixel p;

  topX = centre.real + zoom * (SIZE / 2);
  topY = centre.imaginary + zoom * (SIZE / 2);

  while (row < SIZE) {
    col = 0;
    while (col < SIZE) {
      if (SIZE + col < SIZE) {
        currentX = topX + (zoom * (SIZE - col));
      } else {
        currentX = topX - (zoom * (SIZE - col));
      }

      if (SIZE + row < SIZE) {
        currentY = topY + (zoom * (SIZE - row));
      } else {
        currentY = topY - (zoom * (SIZE - row));
      }

      steps = escapeSteps(currentX, currentY);
      p = (pixel){stepsToBlue(steps), stepsToGreen(steps), stepsToRed(steps)};
      fwrite (&p, sizeof p, 1, stream);
      col++;
    }
    row++;
  }
}



// write BMP header to FILE
void writeBMPHeader(FILE *file) {
  assert(sizeof (bits8) == 1);
  assert(sizeof (bits16) == 2);
  assert(sizeof (bits32) == 4);

  bits16 magicNumber = MAGIC_NUMBER;
  fwrite (&magicNumber, sizeof magicNumber, 1, file);

  bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
  fwrite (&fileSize, sizeof fileSize, 1, file);

  bits32 reserved = 0;
  fwrite (&reserved, sizeof reserved, 1, file);

  bits32 offset = OFFSET;
  fwrite (&offset, sizeof offset, 1, file);

  bits32 dibHeaderSize = DIB_HEADER_SIZE;
  fwrite (&dibHeaderSize, sizeof dibHeaderSize, 1, file);

  bits32 width = SIZE;
  fwrite (&width, sizeof width, 1, file);

  bits32 height = SIZE;
  fwrite (&height, sizeof height, 1, file);

  bits16 planes = NUMBER_PLANES;
  fwrite (&planes, sizeof planes, 1, file);

  bits16 bitsPerPixel = BITS_PER_PIXEL;
  fwrite (&bitsPerPixel, sizeof bitsPerPixel, 1, file);

  bits32 compression = NO_COMPRESSION;
  fwrite (&compression, sizeof compression, 1, file);

  bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
  fwrite (&imageSize, sizeof imageSize, 1, file);

  bits32 hResolution = PIX_PER_METRE;
  fwrite (&hResolution, sizeof hResolution, 1, file);

  bits32 vResolution = PIX_PER_METRE;
  fwrite (&vResolution, sizeof vResolution, 1, file);

  bits32 numColors = NUM_COLORS;
  fwrite (&numColors, sizeof numColors, 1, file);

  bits32 importantColors = NUM_COLORS;
  fwrite (&importantColors, sizeof importantColors, 1, file);
}

// start the server listening on the specified port number
int makeServerSocket (int portNumber) {
  // create socket
  int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
  assert (serverSocket >= 0);
  // error opening socket

  // bind socket to listening port
  struct sockaddr_in serverAddress;
  memset ((char *) &serverAddress, 0,sizeof (serverAddress));

  serverAddress.sin_family      = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port        = htons (portNumber);

  // let the server start immediately after a previous shutdown
  int optionValue = 1;
  setsockopt (
    serverSocket,
    SOL_SOCKET,
    SO_REUSEADDR,
    &optionValue,
    sizeof(int)
  );

  int bindSuccess = bind(
    serverSocket,
    (struct sockaddr *) &serverAddress,
    sizeof (serverAddress)
  );

  assert (bindSuccess >= 0);
  // if this assert fails wait a short while to let the operating
  // system clear the port before trying again

  return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
  // listen for a connection
  const int serverMaxBacklog = 10;
  listen (serverSocket, serverMaxBacklog);

  // accept the connection
  struct sockaddr_in clientAddress;
  socklen_t clientLen = sizeof (clientAddress);
  int connectionSocket =
    accept (
      serverSocket,
      (struct sockaddr *) &clientAddress,
      &clientLen
    );

  assert (connectionSocket >= 0);
  // error on accept

  return (connectionSocket);
}

int escapeSteps (double x, double y) {
  complex c;
  complex z;
  complex newZ;

  int steps = 0;
  double distance = 0;

  z.real = 0;
  z.imaginary = 0;
  c.real = x;
  c.imaginary = y;

  while (distance <= MAX_DISTANCE && steps < MAX_STEPS) {
    newZ.real = pow(z.real, SQUARED) - pow(z.imaginary, SQUARED) + c.real;
    newZ.imaginary = (z.real * z.imaginary * POLYNOMIAL_MULTIPLIER) + c.imaginary;

    z.real = newZ.real;
    z.imaginary = newZ.imaginary;

    distance = sqrt(pow(z.real, SQUARED) + pow(z.imaginary, SQUARED));
    steps++;
  }

  return steps;
}

triordinate extract (char *message) {
  triordinate result;
  char *urlPrefix = TILE;
  char *urlPrefix2 = MANDEL;
  char *urlSuffix = ".bmp";
  char *urlSuffix2 = "/tile.bmp";
  char *coords;
  int counter = 0;
  int coordCounter = 0;

  if (strncmp(urlPrefix, message, strlen(urlPrefix)) == 0) {
    char *data = malloc(strlen(message) - strlen(urlPrefix) - strlen(urlSuffix));

    while (counter < strlen(message)) {
      if (counter < strlen(message) - strlen(urlSuffix)) {
        if (counter >= strlen(urlPrefix)) {
          data[counter - strlen(urlPrefix)] = message[counter];
        }
      }
      counter++;
    }

    coords = strtok(data, "_xyzXYZ");
    result.x = myAtoD(coords);

    while (coords != NULL) {
      coords = strtok(NULL, "_xyzXYZ");
      if (coordCounter == 0) {
        result.y = myAtoD(coords);
      } else if (coordCounter == 1) {
        result.z = myAtoL(coords);
      }
      coordCounter++;
    }

    free(data);
  } else {
    char *data = malloc(strlen(message) - strlen(urlPrefix2) - strlen(urlSuffix2));

    while (counter < strlen(message)) {
      if (counter < strlen(message) - strlen(urlSuffix2)) {
        if (counter >= strlen(urlPrefix2)) {
          data[counter - strlen(urlPrefix2)] = message[counter];
        }
      }
      counter++;
    }

    coords = strtok(data, "/");
    result.z = myAtoL(coords);

    while (coords != NULL) {
      coords = strtok(NULL, "/");
      if (coordCounter == 0) {
        result.x = myAtoD(coords);
      } else if (coordCounter == 1) {
        result.y = myAtoD(coords);
      }
      coordCounter++;
    }

    free(data);
  }


  return result;
}

double myAtoD(char*message) {
	char *ptr = 0;
	return strtod(message, &ptr);
}


long myAtoL(char *message) {

	long sign = 0, offset = 0, n = 0;

	if (message[0] == '-') {
		sign = -1;
	}

	if (sign == -1) {
		offset = 1;
	}
	else {
		offset = 0;
	}

	while (message[offset] != '\0') {

		n = n * 10 + message[offset] - '0';
		offset++;
	}

	if (sign == -1) {
		n *= -1;
	}
	return n;
}
