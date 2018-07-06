/*
	WILLIAM GAO
	z5218662
	HS1511 (2018)
	ASSIGNMENT #1
    doomsday.c
    A program to test a function dayOfWeek which determines which
    day of the week a particular date falls on.
    (only for dates after the start of the Gregorian calendar).
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Months
#define JANUARY  1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

// Days per Week
#define DAYS_PER_WEEK 7

// Days
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6


// Boolean Defines
#define TRUE 1
#define FALSE 0


// Declare functions
int dayOfWeek(int doomsday, int leapYear, int month, int day);
int monthAnchor(int leapYear, int month);
void testCases (void);

// Main function
int main(int argc, char * argv[]) {
	testCases();
	return EXIT_SUCCESS;
}


int dayOfWeek(int doomsday, int leapYear, int month, int day) {
	int differenceDays;

	// Gets anchor day of month
    int anchorOfMonth = monthAnchor(leapYear, month);
    
    // Gets difference between day given and anchorOfMonth
    differenceDays = day - anchorOfMonth;
    
	// Gets day of week through formula
    int dayOfWeek = (doomsday + (differenceDays)) % DAYS_PER_WEEK;

	// If its negative, take the ABS of dayOfWeek by * -1
	// e.g (-1)(-1) = 1, as we need the distance
    if (dayOfWeek < 0) {
        dayOfWeek = DAYS_PER_WEEK - (dayOfWeek * -1);
    }

	// Return value
    return dayOfWeek;
}

// Get the anchor of the month
int monthAnchor(int leapYear, int monthOfYear) {
	int anchor = 0;
	
	if (monthOfYear == JANUARY && !leapYear) {
		anchor = 3;	
	} else if (monthOfYear == JANUARY && leapYear) {
		anchor = 11;
	} else if (monthOfYear == FEBRUARY && !leapYear) {
		anchor = 14;
	} else if (monthOfYear == FEBRUARY && leapYear) {
		anchor = 22;
	} else if (monthOfYear == MARCH) {
		anchor = 14;
	} else if (monthOfYear == APRIL) {
		anchor = 4;
	} else if (monthOfYear == MAY) {
		anchor = 9;
	} else if (monthOfYear == JUNE) {
		anchor = 6;
	} else if (monthOfYear == JULY) {
		anchor = 11;
	} else if (monthOfYear == AUGUST) {
		anchor = 8;
	} else if (monthOfYear == SEPTEMBER) {
		anchor = 5;	
	} else if (monthOfYear == OCTOBER) {
		anchor = 10;
	} else if (monthOfYear == NOVEMBER) {
		anchor = 7;
	} else if (monthOfYear == DECEMBER) {
		anchor = 12;
	}
	
	return anchor;
}

// Test cases
void testCases(void){

// Given Unit Tests
	assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
	assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
	assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
	assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
	assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

	assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
	assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
	assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
	assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
	assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
	assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
	assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
	assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

	assert (dayOfWeek (WEDNESDAY, FALSE,  8, 31) == FRIDAY);   // Angela Finlayson
	 
	 
// 2017 HS1511 Cohort Test Units
	assert (dayOfWeek (TUESDAY  ,  TRUE,  8, 18) == FRIDAY);   // Stanley Su
	assert (dayOfWeek (MONDAY   ,  TRUE,  1,  1) == FRIDAY);   // Alex Huang
	assert (dayOfWeek (TUESDAY  ,  TRUE,  2, 28) == MONDAY);   // Felicia Ee
	assert (dayOfWeek (SATURDAY , FALSE,  1,  2) == FRIDAY);   // Maksim Lisau
	assert (dayOfWeek (SATURDAY , FALSE,  3, 15) == SUNDAY);   // Angeni Bai
	assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Alex Tan
	assert (dayOfWeek (MONDAY   ,  TRUE,  1,  9) == SATURDAY); // Luke Fisk-Lennon
	assert (dayOfWeek (THURSDAY ,  TRUE,  2, 29) == THURSDAY); // Jarrod Li
	assert (dayOfWeek (FRIDAY   ,  TRUE,  1,  3) == THURSDAY); // Mirela Tomicic
	assert (dayOfWeek (TUESDAY  , FALSE,  3, 16) == THURSDAY); // Andrew Yu
	assert (dayOfWeek (SUNDAY   , FALSE,  7, 11) == SUNDAY);   // Samuel Hagan
	assert (dayOfWeek (TUESDAY  , FALSE,  4,  6) == THURSDAY); // Tracey Chiu
	assert (dayOfWeek (MONDAY   ,  TRUE, 12, 31) == SATURDAY); // Andrew Timkov
	assert (dayOfWeek (TUESDAY  , FALSE, 12, 25) == MONDAY);   // Matthew Darley
	assert (dayOfWeek (TUESDAY  , FALSE, 12,  5) == TUESDAY);  // Nicholas Austen
	assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Christina Shi
	assert (dayOfWeek (MONDAY   , FALSE,  8, 10) == WEDNESDAY);// Noa Challis 
	assert (dayOfWeek (FRIDAY   ,  TRUE, 11, 24) == MONDAY);   // Evan Lee
	assert (dayOfWeek (WEDNESDAY,  TRUE,  2, 29) == WEDNESDAY);// Callum Predavec
	assert (dayOfWeek (TUESDAY  , FALSE, 11, 11) == SATURDAY); // Joel Perry
	assert (dayOfWeek (SATURDAY , FALSE,  3,  1) == SUNDAY);   // Phoebe Zuo 
	assert (dayOfWeek (MONDAY   , FALSE,  2, 25) == FRIDAY);   // Sebastien Higgs
	assert (dayOfWeek (TUESDAY  , FALSE,  3, 25) == SATURDAY); // Nicholas Patrikeos
	assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) == TUESDAY);  // Rahul Kumar
	assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != MONDAY);   // Roman Ozerski
	assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != THURSDAY); // Dylan Stephens
	assert (dayOfWeek (TUESDAY  , FALSE, 12,  4) == MONDAY);   // Lucas Barbosa :)
	assert (dayOfWeek (WEDNESDAY,  TRUE,  1,  4) == WEDNESDAY);// Eddie Qi
	assert (dayOfWeek (TUESDAY  , FALSE,  7, 12) == WEDNESDAY);// Jason Hidajat
	assert (dayOfWeek (TUESDAY , TRUE, 4, 4) == TUESDAY);      // Charlotte Low
	assert (dayOfWeek (MONDAY   ,  TRUE,  2,  1) == MONDAY);   // Tim Lee
	assert (dayOfWeek (MONDAY   ,  TRUE, 12, 25) == SUNDAY);   // George Flabouris
	assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // 28/02/1972 (Jack Jiang)
	assert (dayOfWeek (TUESDAY  , FALSE,  7,  1) == SATURDAY); // Kevin Yan
	assert (dayOfWeek (THURSDAY, FALSE, 4, 5) == FRIDAY);      // Archie Croston
	assert (dayOfWeek (SUNDAY  , FALSE, 7, 12) != FRIDAY);     // Chris Law 
	assert (dayOfWeek (WEDNESDAY, FALSE, 12, 19) == 
		    dayOfWeek (WEDNESDAY, TRUE, 12, 19) );             // Marcus Handley
	assert (dayOfWeek (THURSDAY, FALSE, 4, 2) == TUESDAY);     // Callum Koh (2017)



// 2018 HS1511 Cohort Test Units
	assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
	assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
	assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
	assert (dayOfWeek (THURSDAY, FALSE, 1, 2) == WEDNESDAY);   // Paul Lapinski
	assert (dayOfWeek (TUESDAY, TRUE, 2, 27) == SUNDAY);       // Paul Lapinski
	assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Paul Lapinski
	assert (dayOfWeek (THURSDAY, TRUE, 2, 2) == 
		    dayOfWeek (WEDNESDAY, FALSE, 2, 2));               // Tom Harrison-Brown
	assert (dayOfWeek (MONDAY, TRUE, 8, 1) == MONDAY);         // Tom Harrison-Brown
	assert (dayOfWeek (SATURDAY, FALSE, 1, 21) == WEDNESDAY);  // Jennivine Chen
	assert (dayOfWeek (SUNDAY   , TRUE, 1, 4) == SUNDAY);      // Kai Mashimo
	assert (dayOfWeek (WEDNESDAY, FALSE, 8, 23) == THURSDAY);  // Lily Yang
	assert (dayOfWeek (MONDAY, TRUE, 2, 27) != MONDAY);        // Joshua Quail :P
	assert (dayOfWeek (WEDNESDAY, FALSE, 10, 8) == MONDAY);    // Luke Cantor
	assert (dayOfWeek (SUNDAY, TRUE, 12, 14) == TUESDAY);      // Dillon de Silva XD
	assert (dayOfWeek (WEDNESDAY, FALSE, 12, 31) == MONDAY);   // Izaac Coffey
	assert (dayOfWeek (MONDAY, TRUE, 1, 1) == FRIDAY);         // James Wilkie
	assert (dayOfWeek (WEDNESDAY, FALSE, 11, 9) == FRIDAY);    // Darby Thompson
	assert (dayOfWeek (WEDNESDAY, FALSE, 1, 29) == MONDAY);    // Reilly Fox
	assert (dayOfWeek (FRIDAY, FALSE, 8, 12) == TUESDAY);      // Lucca Harvey
	assert (dayOfWeek (TUESDAY, TRUE, 4, 20) == THURSDAY);     // Callum Koh (2018) ;)
	assert (dayOfWeek (THURSDAY, FALSE, 1, 1) == TUESDAY);     // Harold Chin
	assert (dayOfWeek (WEDNESDAY, TRUE, 3, 14) == WEDNESDAY);  // Luke Cantor (pi day)
	assert (dayOfWeek (FRIDAY, TRUE, 3, 0) == FRIDAY);         // Josh Harcombe
	assert (dayOfWeek (THURSDAY, TRUE, 6, 6) == THURSDAY);     // Sophie Ogilvy
	assert (dayOfWeek (FRIDAY, FALSE, 12, 12) == FRIDAY);      // James Balajan
	assert (dayOfWeek (WEDNESDAY, FALSE, 8, 26) == SUNDAY);    // Tay your bae
	assert (dayOfWeek (TUESDAY, TRUE, 5, 27) == SATURDAY);     // Allan Goodman
	assert (dayOfWeek (FRIDAY, FALSE, 3, 26) == WEDNESDAY);    // Eric R Chang
	assert (dayOfWeek (MONDAY, FALSE, 6, 27) == MONDAY);       // Patrick Fennell
	assert (dayOfWeek (TUESDAY, TRUE, 8, 23) == WEDNESDAY);    // Harris Borman (You forgot a parenthesis!)
	assert (dayOfWeek (SATURDAY, TRUE, 5, 13) == WEDNESDAY);   // Luka Lafaye de Micheaux
	assert (dayOfWeek (SATURDAY, TRUE, 10, 9) == FRIDAY);      // Luka Lafaye de Micheaux
	assert (dayOfWeek (TUESDAY, FALSE,  3, 4) == SATURDAY);    // Zachary Cheng
	assert (dayOfWeek (THURSDAY, FALSE, 7, 2) == TUESDAY);     // Sam Chapman - trying to get negative answers
	assert (dayOfWeek (WEDNESDAY, FALSE, 10, 2) == TUESDAY);   // Sam Chapman - trying to get negative answers
	assert (dayOfWeek (THURSDAY, FALSE, 11, 0) == THURSDAY);   // Sam Chapman - trying to get negative answers
	assert (dayOfWeek (WEDNESDAY, FALSE, 12, 4) == TUESDAY);   // Sam Chapman - trying to get negative answers
	assert (dayOfWeek (THURSDAY, FALSE, 5, 1) == WEDNESDAY);   // Sam Chapman - trying to get negative answers
	assert (dayOfWeek (MONDAY, FALSE, 3, 10) == THURSDAY);     // Sam McKay
	assert (dayOfWeek (FRIDAY, TRUE, 1, 20) == SUNDAY);        // Sam McKay
	assert (dayOfWeek (FRIDAY, TRUE, 4, 4) == FRIDAY);         // Josh Green: Ensuring LeapYear Doesn't throw off
	assert (dayOfWeek (MONDAY, TRUE, 12, 12) == MONDAY);       // Josh Green: same as above
	assert (dayOfWeek (SUNDAY, FALSE, 4, 5) == MONDAY);        // Josh Green above
	assert (dayOfWeek (WEDNESDAY, FALSE, 12, 11) == TUESDAY);  // Josh Green below
	assert (dayOfWeek (THURSDAY, FALSE, 6, 14) == FRIDAY);     // Jessica Luo 
	assert (dayOfWeek (FRIDAY, TRUE, 7, 28) == MONDAY);      // Mehidi Hussaini
	assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);    // Laeeque Jamdar
	assert (dayOfWeek (SATURDAY, TRUE, 12, 30) == WEDNESDAY);  // Jason Yu
	assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Taylor Wood
	assert (dayOfWeek (FRIDAY, TRUE, 1, 1) == TUESDAY);        // James Leib
	assert (dayOfWeek (THURSDAY, FALSE, 1, 21) == MONDAY);     // Ayden Gebran
	assert (dayOfWeek (THURSDAY, TRUE, 2, 23) == FRIDAY);      // Dominic Lee (ovo)
	assert (dayOfWeek (THURSDAY, FALSE, 6, 21) == FRIDAY);     // Monique Curulli
	assert (dayOfWeek (WEDNESDAY, TRUE, 6, 10) == SUNDAY);     // Matthew Rossouw
	assert (dayOfWeek (SUNDAY, FALSE, 4, 17) == SATURDAY);     // Matthew Rossouw
	assert (dayOfWeek (THURSDAY, FALSE, 1, 4) == FRIDAY);      // Justin Lou
	assert (dayOfWeek (THURSDAY, FALSE, 1, 3) == THURSDAY);    // Justin Lou
	assert (dayOfWeek (THURSDAY, FALSE, 1, 2) == WEDNESDAY);   // Justin Lou
	assert (dayOfWeek (FRIDAY, FALSE, 12, 2) == TUESDAY);      // Zach Leong
	assert (dayOfWeek (WEDNESDAY, FALSE, 1, 1) == MONDAY);     // Ezra Hui
	assert (dayOfWeek (WEDNESDAY, TRUE, 12, 31) == MONDAY);    // Ezra Hui 
	assert (dayOfWeek (SUNDAY, FALSE, 2, 29) == MONDAY);       // Manu Masson :) This one may break some people
	assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);    // Gidon Kessler
	assert (dayOfWeek (MONDAY, FALSE, 1, 364) == FRIDAY);      // Oden Petersen, abnormal value for day of month
	assert (dayOfWeek (THURSDAY, TRUE , 1, 5) == FRIDAY);      // Nan Yan
	assert (dayOfWeek (FRIDAY, TRUE, 2, 28) == THURSDAY);      // Nan Yan
	assert (dayOfWeek (MONDAY, TRUE, 12, 31) == SATURDAY);     // Nan Yan
	assert (dayOfWeek (WEDNESDAY, FALSE, 3, 25) == SUNDAY);    // William Gao (the day the assignments due!)
	printf("All 137 test cases from 2017 and 2018, and given tests succeeded =) \n\n\n");
}
