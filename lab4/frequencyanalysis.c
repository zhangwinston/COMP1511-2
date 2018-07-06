// frequency_analysis.c - a program to analyse frequency of character
// by William Gao

#include <stdlib.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

int indexOf(char c);

int upperCase = 0; 
int lowerCase = 0;
int spaces = 0;

int main(int argc, char *argv[]) {
    int frequency[ALPHABET_SIZE];
    int i = 0;
    while (i < (ALPHABET_SIZE)) {
        frequency[i] = 0;
        i += 1;
    }
    
    int characters = 0;
    int letters = 0;

    char c = '\0';
    while (c != EOF) {
        c = getchar();
        characters += 1;

        int i = indexOf(c);
        if (i != -1) {
            letters += 1;
            frequency[i] += 1;
        }
    }
    
    printf("Total number of lowercase letters: %d\n", lowerCase);
    printf("Total number of UPPERCASE LETTERS: %d\n", upperCase);
    printf("Total number of chars inputted: %d\n", characters);
    printf("Total number of letters inputted %d\n", letters);


    i = 0;
    while (i < (ALPHABET_SIZE)) {
        char c = (char)(i + (int)'A');
        printf("%c has a frequency of %d\n", c, frequency[i]);
        i++;
    }

    return EXIT_SUCCESS;
}

int indexOf(char c) {
    if (c >= 'A' && c <= 'Z') {
        upperCase += 1; 
        // typecasting
        return (int)c - (int)'A';
    }

    if (c >= 'a' && c <= 'z') {
        lowerCase += 1;
        return (int)c - (int)'a'; 
    }

    return -1;
}

