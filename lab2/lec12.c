#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FIRST_LETTER 'a'
#define CAPS_FIRST_LETTER 'A'
#define LAST_LETTER 'z'
#define CAPS_LAST_LETTER 'Z'
#define ROT13 13
char encode (char letter);
char isAlpha(char isAlpha);
void testcases (void);
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
	char encoded;
	encoded = 0;
	if (isAlpha(letter)){
		if (letter >= 'a' && letter <= 'm'){
			encoded = letter + ROT13;
		} else if (letter >= 'n' && letter <= 'z'){
			encoded = letter - ROT13;
		} else {
			if (letter >= 'A' && letter <= 'M'){
				encoded = letter + ROT13;
			} else if (letter >= 'N' && letter <= 'Z'){
				encoded = letter - ROT13;
			} else { 
				letter = encoded;
			}
		}
	}
	return encoded;
}

char isAlpha (char plainText){
	return (plainText >= FIRST_LETTER && plainText <= LAST_LETTER)
	|| (plainText >= CAPS_FIRST_LETTER && plainText <= CAPS_LAST_LETTER);
}

void testcases(void){
    assert(encode('A') == 'N');
    assert(encode('N') == 'A');
    assert(encode('H') == 'U');
    assert(encode('U') == 'H');
    assert(encode('Z') == 'M');
    assert(encode('M') == 'Z');
    assert(encode('a') == 'n');
    assert(encode('n') == 'a');
    assert(encode('h') == 'u');
    assert(encode('u') == 'h');
    assert(encode('z') == 'm');
    assert(encode('m') == 'z');
}


