// William Gao z5218662
// Leap Year (functions) Activity
// HS1511 UNSW
// 08/03/2018

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Start of the calender
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
	// If year % 0 == 0, assign isLeap to 1.
    if ((year % 400) == 0){
    	isLeap = 1;
	    	// If year % 0 == 0, assign isLeap to 0.
    }else if((year % 100) == 0){
		isLeap = 0;
	    	// If year % 0 == 0, assign isLeap to 1.
	}else if((year % 4) == 0){
		isLeap = 1;
	}else{
		isLeap = 0;
	}			
	
	// Remember that 1 is TRUE and 0 is FALSE
	// (defined in the constants at the top!)
	if (isLeap == 1){
		// If isLeap == 1, return TRUE
		return 1;
	}else{
		// If isLeap == 0, return FALSE
		return 0;
	}
}



