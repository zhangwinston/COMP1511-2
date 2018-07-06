#include <stdio.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
#define LOWERCASE_A 97
#define LOWERCASE_Z 122
#define UPPERCASE_A 65
#define UPPERCASE_Z 90
int main (int argc, char *argv[]){
	// Stats
	long long lowercaseLetters=0;
	long long uppercaseLetters=0;
	long long totalLetters=0;
	long long totalBytes=0;
	long long statLineFeedChar=0;
	long long numberOfVowels=0;
	long long numberOfSpaces=0;
	double totalKb=0;
	double totalMb=0;
	double percentageVowels=0;
	int lowerAlphabetArray[ALPHABET_SIZE] = {0};
	int upperAlphabetArray[ALPHABET_SIZE] = {0};
	int alphabetArray[ALPHABET_SIZE] = {0};
	int realAlphaIndex=0;
	char userInput;
	userInput = getchar();
	while (userInput != EOF){
		if (userInput >= LOWERCASE_A && userInput <= LOWERCASE_Z){
			realAlphaIndex = userInput - LOWERCASE_A;
			alphabetArray[realAlphaIndex]++;
			lowerAlphabetArray[realAlphaIndex]++;
			lowercaseLetters++;
			totalLetters++;
		} else if (userInput >= UPPERCASE_A && userInput <= UPPERCASE_Z){
			realAlphaIndex = userInput - UPPERCASE_A;
			alphabetArray[realAlphaIndex]++;
			upperAlphabetArray[realAlphaIndex]++;
			uppercaseLetters++;	
			totalLetters++;
		} else if (userInput == 10){
			statLineFeedChar++;
		} else if (userInput == 32){
			numberOfSpaces++;
		} else{}
		totalBytes += sizeof(userInput);
		userInput = getchar();
	}
	int alphaCounter = 0;
	int alphaToAscii = 0;
	double percentageOfFile;
	printf("\n\n === Letter Statistics === ");
	while (alphaCounter < ALPHABET_SIZE){
		percentageOfFile = ((double)alphabetArray[alphaCounter]/(double)totalLetters) * 100;
		alphaToAscii = alphaCounter + LOWERCASE_A;
		printf("\nNumber of %c in file: %d which consists of %d lowercase letters and %d 		uppercase letters which combined, is %.3f percent of the entire file.\n", alphaToAscii, alphabetArray[alphaCounter],lowerAlphabetArray[alphaCounter],upperAlphabetArray[alphaCounter],percentageOfFile);
		alphaCounter++;
	}
	//Vowels
	numberOfVowels = alphabetArray[0] + alphabetArray[4] + alphabetArray[8]+ alphabetArray[14]+ alphabetArray[20];
	percentageVowels = numberOfVowels / (double)totalLetters * 100;
	totalKb = totalBytes / 1000;
	totalMb = totalBytes / 1000000;
	printf("\n\n=== Other Statistics === ");
	printf("\nTotal number of bytes in the file %lld\n",totalBytes);
	printf("\nTotal number of kilobytes in the file %.3f\n",totalKb);
	printf("\nTotal number of megabytes in the file %.3f\n",totalMb);
	printf("\nNumber of LF in the file %lld\n",statLineFeedChar);
	printf("\nNumber of lowercase letters in the file %lld\n",lowercaseLetters);
	printf("\nNumber of uppercase letters in the file %lld\n",uppercaseLetters);
	printf("\nNumber of letters in the file %lld\n",totalLetters);
	printf("\nNumber of spaces in the file %lld\n",numberOfSpaces);
	printf("\nNumber of vowels in the file %lld which is %.7f percent of the entire file\n",numberOfVowels, percentageVowels);
	return EXIT_SUCCESS;
}
