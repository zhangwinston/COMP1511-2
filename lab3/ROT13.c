// William Gao
// 24.03.18
// COMP1511
// Converts plaintext to rot13, works the other way around as
// conversions are +-13.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FIRST_LETTER 'a'
#define CAPS_FIRST_LETTER 'A'
#define LAST_LETTER 'z'
#define CAPS_LAST_LETTER 'Z'
#define ROT13_CYCLE 13
#define LOWER_A 'a'
#define LOWER_M 'm'
#define LOWER_N 'n'
#define LOWER_Z 'z'


#define UPPER_A 'A'
#define UPPER_M 'M'
#define UPPER_N 'N'
#define UPPER_Z 'Z'

char encode (char letter); // encodes plainText to rot13
char testAlpha(char plainText); // checks if plainText is a letter
void testcases (void); // testcases to ensure code works

int main (int argc, char *argv[]){
	testcases();

	char plainText;
	char encoded;

	printf("Enter a letter to translate into ROT13\n");
	scanf("%c",&plainText);

	encoded = encode(plainText);
	printf("%c\n",encoded);

	return EXIT_SUCCESS;

}

char encode (char letter){
	if (testAlpha(letter)){
        // Tests for lowercase letters
		if (letter >= LOWER_A && letter <= LOWER_M){
			letter = letter + ROT13_CYCLE;
		} else if (letter >= LOWER_N && letter <= LOWER_Z){
            letter = letter - ROT13_CYCLE;
		} else {
		    // Tests for capital letters
			if (letter >= UPPER_A && letter <= UPPER_M){
				letter = letter + ROT13_CYCLE;
			} else if (letter >= UPPER_N && letter <= UPPER_Z){
				letter = letter - ROT13_CYCLE;
			} else {
				letter = letter;
			}
		}
	}
	return letter;
}

char testAlpha (char plainText){
    // Checks if the plainText being passed through encode is a letter
	return (plainText >= FIRST_LETTER && plainText <= LAST_LETTER)
	||
	(plainText >= CAPS_FIRST_LETTER && plainText <= CAPS_LAST_LETTER);
}

void testcases(void){

    // Testcases (upper)
    assert(encode('A') == 'N');
    assert(encode('N') == 'A');
    assert(encode('H') == 'U');
    assert(encode('U') == 'H');
    assert(encode('Z') == 'M');
    assert(encode('M') == 'Z');
    printf("Uppercase testcases succeeded\n\n");

    // Testcases (lower)
    assert(encode('a') == 'n');
    assert(encode('n') == 'a');
    assert(encode('h') == 'u');
    assert(encode('u') == 'h');
    assert(encode('z') == 'm');
    assert(encode('m') == 'z');
    printf("Lowercase testcases succeeded\n\n");

}


