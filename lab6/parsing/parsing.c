// Functions and types used to extract x,y,z values from a string
// containing a URL of the form:
// http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define EPSILON 1e-10

typedef struct _triordinate {
	double x;
	double y;
	int z;
} triordinate;


triordinate extract(char *message);

double myAtoD(char *message);

long myAtoL(char *message);

int main(int argc, char *argv[]) {
	char *message = "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp";

	triordinate dat = extract(message);
	printf("z value is %d\n\n", dat.z);
	printf("x value is %f\n\n", dat.x);
	printf("y value is %f\n\n", dat.y);


	printf("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);


	//Add extra tests for extract, myAtoD and myAtoL

	return EXIT_SUCCESS;
}
//http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp
// Index of Z is at 48
// Index of X is at 50
// Index of Y is at 55
// Extract the z,x,y coordinates of the url. 5 is z, 3.14 is x, -0.141 is y


triordinate extract(char *message) {

	triordinate extractResult = { 0,0,0 };

	// Extract Z value
	int ZmessageIndex = 48;
	int zIndex = 0;
	char zValue[sizeof(long)] = { 0 };
	while (message[ZmessageIndex] != '/') {
		zValue[zIndex] = message[ZmessageIndex];

		ZmessageIndex++;
		zIndex++;
	}

	extractResult.z = myAtoL(zValue);


	// Extract X value
	int XmessageIndex = 50;
	int xIndex = 0;
	char xValue[sizeof(double)] = { 0 };
	while (message[XmessageIndex] != '/') {
		xValue[xIndex] = message[XmessageIndex];
		XmessageIndex++;
		xIndex++;
	}

	extractResult.x = myAtoD(xValue);

	// Extract Y value
	int YmessageIndex = 55;
	int yIndex = 0;
	char yValue[sizeof(double)] = { 0 };
	while (message[YmessageIndex] != '/') {
		yValue[yIndex] = message[YmessageIndex];
		YmessageIndex++;
		yIndex++;
	}
	extractResult.y = myAtoD(yValue);

	return extractResult;
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

double myAtoD(char*message){
	char *ptr = 0;
	return strtod(message,&ptr);
}


