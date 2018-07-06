// WILLIAM GAO Z5218662
// WONDROUS FUNCTION
// 21/03/18

#include <stdio.h>
#include <stdlib.h>


int printWondrous(int number);

int main(int argc, char* argv[]){
	printWondrous(3);
	return EXIT_SUCCESS;
}

int printWondrous(int number){
	 printf("%d\n",number);
	 while (number != 1){
	 	if (number % 2 == 0){
	 		number = number / 2;
	 		printf("%d\n",number);
	 	} else {
	 		number = (3 * number) + 1;
	 		printf("%d\n",number);
	 	}
	 }
	return number;
}
