#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 15
int main (int argc, char *argv[]){

	int squares[MAXSIZE];
	int counter = 0;
	while (counter < MAXSIZE){
		squares[counter] = counter * counter;
		printf("%d\n",squares[counter]);
		counter ++;
	}
	return EXIT_SUCCESS;
}
