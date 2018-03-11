// William Gao z5218662
// Leap Year (functions) Activity
// HS1511 UNSW
// 08/03/2018

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define START_OF_CALENDAR 1582
// Define TRUE as 1 and FALSE as 0.
#define TRUE 1
#define FALSE 0

// Declare the function - important.
int isLeapYear(int year);

int main(int argc, const char * argv[]){
	int year;
	int isLeap;
	
	// Asks for the user input.
	scanf("%d",&year);
	
	// Assigns isLeap to the return value of calling the function
	isLeap = isLeapYear(year);
	
	// Prints value
	printf("%d\n",isLeap);
	
	
	return EXIT_SUCCESS;
}

int isLeapYear(int year){
	
	// Defines isLeap as an integer
	int isLeap;
    
    // Testing whether year is a leap year
    if ((year % 400) == 0){
    	isLeap = 1;
    }else if((year % 100) == 0){
		isLeap = 0;
	}else if((year % 4) == 0){
		isLeap = 1;
	}else{
		isLeap = 0;
	}			
	
	// Returning 0 or 1, where 0 is FALSE and 1 is TRUE (constants)
	if (isLeap == 1){
		return 1;
	}else if (isLeap == 0){
		return 0;
	}
}



