// william gao
// lecture 5 comp1511
// 6 march 2018
// simple c syntax
// if,else,printf,scanf,variables
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]){

    printf("Hello World\n");

    int magicNumber;

    magicNumber = 4;
    magicNumber = 1000001 ;

    printf("Please enter a number less than 9000\n");

    scanf("%d",&magicNumber);

    if ((magicNumber % 4) == 0){
        printf("I like danes!\n");
        if (magicNumber < 9999){
            printf("I reallly love danes!\n");
        } else {
            printf("Else!");
        }

    }

}



