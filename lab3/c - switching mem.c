// William Gao z5218662
// COMP1511 - Program to swap value of two variables
// 20/03/18

#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second){

	int temp;

	int temp = *first;
	*first = *second;
	*second = temp;
	
}


