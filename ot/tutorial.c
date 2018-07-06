#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char *argv[]){

	printf("\n");
	
	// Missed less than 10 days work and has
	// over 30,000 sales OR signed up ore than 30 new customers
	
	int bobMissedDays = 8, bobTotalSales = 24000,
		bobNewCust = 32;
		
	if ((bobMissedDays < 10) && (bobTotalSales > 30000 || bobNewCust > 30)){
		printf("Bob gets a raise\n\n");
	} else {
		printf("Bob doesn't get a raise\n\n");
	}
	
	return EXIT_SUCCESS;
	
	
	
}
