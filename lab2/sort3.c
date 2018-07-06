#include <stdio.h>
#include <stdlib.h>

int sortNumbers(int num1,int num2,int num3);
int main(int argc, const char * argv[]){
	int num1,num2,num3;
	
	scanf("%d %d %d",&num1,&num2,&num3);
	
	sortNumbers(num1,num2,num3);
	
	return EXIT_SUCCESS;
	
}

int sortNumbers(int num1,int num2,int num3){
	int middle,highest,lowest;
	if (num1 > num2){
		middle = num1;
		lowest = num2;
	} else {
		middle = num2;
		lowest = num1;
	}
	
	if (middle > num3){
		highest = middle;
		if (lowest > num3){
			middle = lowest;
			lowest = num3;
		} else {
			middle = num3;
		}
	} else highest = num3;
	
	printf("%d\n",lowest);
	printf("%d\n",middle);
	printf("%d\n",highest);
	
	return 0;
}

