// william gao
// isLeap activity
// hs1511 unsw
// 7 march 2018
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define START_OF_CALENDAR 1582
#define TRUE 1
#define FALSE 0

int main(int argc, const char * argv[]){
	int isLeap;
    int year;

    printf("please enter the year you are interested in\n");

    scanf("%d",&year);
	assert (year >= START_OF_CALENDAR);
    
    // Testing whether year is a leap year
    if ((year % 400) == 0){
    	isLeap = TRUE;
    }else if((year % 100) == 0){
		isLeap = FALSE;
	}else if((year % 4) == 0){
		isLeap = TRUE;
	}else{
		isLeap = FALSE;
	}			
	
	// Printing result
	if (isLeap == TRUE){
		printf("%d is a leap year!\n",year);
	}else{
		printf("%d is not a leap year!\n",year);
	}
	
	
	return EXIT_SUCCESS;
}



