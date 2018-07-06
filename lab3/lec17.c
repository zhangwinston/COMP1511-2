// William Gao z5218662
// 20 march 18
// Sings a Song!


#include <stdio.h>
#include <stdlib.h>
#define LINE "##########\n"

void singVerse(int batCount);

int main (int argc, char *argv[]){
	int batCount;
	batCount = 0;
	
	int maxNumberOfBats = 11;
	
	while(batCount < maxNumberOfBats){
		singVerse(batCount);
		printf("\n\n\n");
		batCount += 1;
	}
	return EXIT_SUCCESS;
}

void singVerse(int batCount){

	printf("%d bats sitting in my belfrey\n",batCount);
	printf("1 bat flies in thru my door\n");
	batCount++;
	printf("that makes %d bats sitting in my belfrey\n",batCount);
	printf("but wait, there's more...");
	
}

