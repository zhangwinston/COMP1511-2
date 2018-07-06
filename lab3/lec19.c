// William Gao z5218662	

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define WIDTH 15
#define HEIGHT 5
#define IRISH_WIDTH 5
void testLibya(void);
void showLibya(void);
void showPixel (int col);

int main (int argc, char *argv[]){

	showLibya();
	
	return EXIT_SUCCESS;
}

void testLibya(void){
	printf("Outpit should look like this \n");
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	showLibya();
}

void showLibya(void){

	int col = 0;
	int row = 0;
	while (row < HEIGHT){
		while (col < WIDTH){
			showPixel(col);
			col ++;
		}
	}
	printf("\n");
	row ++;

}

void showPixel (int col){
	char pixel;
	if (col < IRISH_WIDTH){
		pixel = 'g';
	} else if (col < (2 * IRISH_WIDTH)){
		pixel = 'w';
	} else {
		pixel = 'o';
	}
	printf("%c",pixel);

}
