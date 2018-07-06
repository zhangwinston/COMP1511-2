#include <stdio.h>
#include <stdlib.h>

float averageMark(float score1, float score2, float score3);
char reportMark(float average);

int main (int argc, char *argv[]){

    float grade1, grade2, grade3;

    printf("Enter your 3 test grades: ");
    scanf(" %f",&grade1);
    scanf(" %f",&grade2);
    scanf(" %f",&grade3);

    float averageMarkTotal = averageMark(grade1,grade2,grade3);
    char finalGrade = reportMark(averageMarkTotal);
    printf("\n");
    printf("Average mark: %.2f\n", averageMarkTotal);
    printf("Final Report Mark: %c\n", finalGrade);
    

    return 0;

}

float averageMark(float score1, float score2, float score3){

    float avg = (score1 + score2 + score3)/3;
    return avg;
}

char reportMark(float average){
    char finalGrade;

    if (average < 50){
        finalGrade = 'D';
    } else if (average > 50 && average < 65){
        finalGrade = 'C';
    } else if (average > 65 && average < 85){
        finalGrade = 'B';
    } else if (average > 85 && average < 100){
        finalGrade = 'A';
    } else if (average == 100){
        finalGrade = 'A';
    } else {
        finalGrade = 'E';
    }

    return finalGrade;


}

