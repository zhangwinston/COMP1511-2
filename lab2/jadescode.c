/* Jade Nguyen
z5218672
HS1511
11/03/2018
"leapYearFunction" Program
*/

#include <stdio.h>
#include <stdlib.h>

#define START_OF_GREG_CALENDER 1582
#define TRUE 1
#define FALSE 0

/// Declare the function
int isLeapYear(int year);

int main (int argc, const char * argv[]){
    int year;
    int isLeap;
    
    printf("please enter the year you are interested in?");
    scanf("%d", &year);
    
    isLeap = isLeapYear(year);
    
    // Prints value
    printf("%d\n",isLeap);


    return EXIT_SUCCESS;
}

int isLeapYear (int year){
    int isLeap;
    
    if ((year % 400) == 0){
        isLeap = 1;
        
    } else if ((year % 100) == 0){
        isLeap = 0;
        
    } else if ((year % 4) == 0){
        isLeap = 1;
    } else {
        isLeap = 0;
    }
    
    if (isLeap == 1) {
        return 1;
        
    }else{
        return 0;
    }
}
