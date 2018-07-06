/*
 *
 *  reads in a permutation of the alphabet then encodes
 *  lower case letters using that permutation
 *  module 4 template code you asked for - might need some cleaning up...
 *
 *  Licensed under Creative Commons BY 3.0.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STOP -1
#define ALPHABET_SIZE 26
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

int indexInString(char letter, char *searchString);
char encode(int plainChar, char *permuation);
void testcases(void);

int main(int argc, char *argv[]) {
    testcases();

    char permutation[ALPHABET_SIZE];
    scanf("%s", permutation);

    // getchar() reads and returns one character from the keyboard
    // returns -1 when the input is finished / end-of-file is reached
    // signal this from the keyboard by pressing ^D in linux/^Z windows
    char plainCharacter = getchar();
    while (plainCharacter != STOP) {
        char encodedCharacter = encode(plainCharacter, permutation);
        printf ("%c", encodedCharacter);
        plainCharacter = getchar();

    }
    return EXIT_SUCCESS;
}


char encode(int plainText, char *perm) {
    int letterNum = indexInString(plainText, ALPHABET);
    char encoded;
    if (letterNum != -1) {
        encoded = perm[letterNum];
    } else {
        encoded = plainText;
    }
    return encoded;
}

int indexInString(char letter, char *searchString) {

    int i = 0;
    int index = -1;
    while (searchString[i] != 0) {
        if (letter == searchString[i]) {
            index = i;
        }

        i+=1;
    }
    return index;
}

void testcases(void){
   assert (encode ('A',"abcdefghijklmnopqrstuvwxyz") == 'A');
   assert (encode ('?',"abcdefghijklmnopqrstuvwxyz") == '?');
   assert (encode (' ',"abcdefghijklmnopqrstuvwxyz") == ' ');
   assert (encode ('\n',"abcdefghijklmnopqrstuvwxyz") == '\n');

   assert (encode ('a',"abcdefghijklmnopqrstuvwxyz") == 'a');
   assert (encode ('m',"abcdefghijklmnopqrstuvwxyz") == 'm');
   assert (encode ('z',"abcdefghijklmnopqrstuvwxyz") == 'z');

   assert (encode ('a',"bcdefghijklmnopqrstuvwxyza") == 'b');
   assert (encode ('m',"bcdefghijklmnopqrstuvwxyza") == 'n');
   assert (encode ('z',"bcdefghijklmnopqrstuvwxyza") == 'a');

   assert (encode ('a',"qwertyuiopasdfghjklzxcvbnm") == 'q');
   assert (encode ('b',"qwertyuiopasdfghjklzxcvbnm") == 'w');
   assert (encode ('z',"qwertyuiopasdfghjklzxcvbnm") == 'm');
}

