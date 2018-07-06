#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define FIRST_LETTER 'a'
#define LAST_LETTER 'z'
int isLetter(char);
char encode(char);
void testEncode(void);
int main (int argc, char *argv[]){
	
	testEncode();
	char plainText;
	
	printf("Enter a plain text character! \n");
	scanf("%c", &plainText);
	printf("Encrypted is %c\n",encode(plainText));
	
	return EXIT_SUCCESS;
}

char encode(char plainText){
	char cipherText;
	int toBeEncoded = isLetter(plainText);
	
	if (toBeEncoded){
		cipherText = plainText +1;
		if (cipherText > LAST_LETTER){
			cipherText = FIRST_LETTER;
		
		}
	} else {
		cipherText = plainText;
	}
	return cipherText;
}

int isLetter(char plainText){
	int aLetter;
	aLetter = (plainText >= FIRST_LETTER && plainText <= LAST_LETTER);
	return aLetter;
}

void testEncode(void){

	assert(encode('z') == 'a');
	assert(encode('a') == 'b');
	assert(encode('1') == '1');
	assert(encode('A') == 'A');


	printf("All tests passed!");
	printf("You are awesome!\n");

}
