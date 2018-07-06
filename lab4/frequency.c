#include <stdio.h>
#include <stdlib.h>
#define ALPHABETSIZE 26
#define LOWERCASE_a 97
#define LOWERCASE_z 122
#define UPPERCASE_A 65
#define UPPERCASE_Z 90
int main (int argc, const char *argv[]){

	char letter;
	long alphaIndex = 0;
	
	// stats
	long long lowerCaseAmtLetter = 0;
	long long upperCaseAmtLetter = 0;
	long long amtLetters = 0;
	long long LF = 0;
	long long bytes = 0;
	long long spaces = 0;
	
	long long alphabet[ALPHABETSIZE+1] = {0};

	letter = getchar();
	
	while (letter != EOF){
		if (letter >= LOWERCASE_a && letter <= LOWERCASE_z){
			long index = letter - LOWERCASE_a;
			alphabet[index]++;
			amtLetters++;
			lowerCaseAmtLetter++;
		} else if (letter >= UPPERCASE_A && letter <= UPPERCASE_Z){
			long index = letter - UPPERCASE_A;
			alphabet[index]++;
			amtLetters++;
			upperCaseAmtLetter++;
		} else if (letter == 10){
			LF++;
		} else if (letter == 32){
			spaces++;
		} else {}
		bytes += sizeof(letter);
		letter = getchar();
	}	

	while (alphaIndex < ALPHABETSIZE){
		long long numLetters = alphabet[alphaIndex];
		char ascii = alphaIndex + LOWERCASE_a;
		double percentInTotal = alphabet[alphaIndex] / (double)amtLetters*100;
		printf("\nNumber of %c in file: %lld\t Percentage of %c in file: %f\n", ascii, numLetters, ascii, percentInTotal);
		alphaIndex++;
	}
	int numVowels = alphabet[0] + alphabet[4] + alphabet[8] + alphabet[14] + alphabet[20];
	double percentVowels = (double) numVowels / (double) amtLetters;
	
	double percentNumKk = (double)alphabet[10] / (double)amtLetters;
	printf("\n\nbytes is %lld\n\n",bytes);
	printf("\n\nNumber of Line Feed letters: %lld\n", LF);
	printf("\n\nNumber of letters: %lld\n", amtLetters);
	printf("\n\nNumber of spaces: %lld\n", spaces);
	printf("\n\nNumber of lowercase letters: %lld\n", lowerCaseAmtLetter);
	printf("\n\nNumber of uppercase letters: %lld\n", upperCaseAmtLetter);
	printf("\n\nPercent of total letters that are vowels: %f\n",percentVowels*100);
	printf("\n\nPercent of total letters that are K or k: %f\n",percentNumKk*100);


	return EXIT_SUCCESS;

}
