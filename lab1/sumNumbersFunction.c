# include <stdio.h>
# include <stdlib.h>

int sumNums();
int main(int argc, char const *argv[]){

	int num1,num2;
	scanf("%d %d",&num1,&num2);
	
	int returnVal = sumNums(num1,num2);
	printf("%d\n",returnVal);
	
	return 0;


}

int sumNums(int num1,int num2){
	int sum;
	sum = num1 + num2;

	return sum;

}
