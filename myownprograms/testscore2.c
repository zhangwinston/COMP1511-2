#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]){
    
    float numberOfTests = 0, scoreEntered = 0, average = 0, grade = 0;
    char gradeLetter;
    
    printf("Enter 0 when finished\n");
    do{
        
        
        printf("Grade: %c \t Average Mark: %.2f \t Total Number of Tests = %.0f\t",
                gradeLetter, average, numberOfTests);
        printf("\nEnter test result: ");
       

        scanf("%f", &scoreEntered);
        
        if (scoreEntered == 0){
            break;
        }
        

        grade = grade + scoreEntered;
        numberOfTests ++;
        average = grade / numberOfTests;
        
        if (average < 65){
            gradeLetter = 'C';
        } else if (average >= 65 && average <= 85){
            gradeLetter = 'B';
        } else if (average > 85 && average < 100){
            gradeLetter = 'A';
        } else if (average == 100){
            gradeLetter = '+';
        } else {
            gradeLetter = '?';
        }

        
    } while (scoreEntered != 0);
    
    printf("\nFinal Results: \n\n Grade: %c\n Average Mark: %.2f\n "
            "Total Number of Tests: %.0f\n\n", gradeLetter, average, numberOfTests);
    
    return 0;
}

