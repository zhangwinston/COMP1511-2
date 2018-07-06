#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *message);

int main(int argc, const char *argv[]) {
	char *message = "";
	char *reversed = reverse(message);
	printf("\n\n\n\n\n%s\n\n\n\n", reversed);
	free(reversed);
	return EXIT_SUCCESS;
}

char *reverse(char *message) {
	int counter = 0;
	int reversedCounter = 0;

	int lengthOfMessage = strlen(message);
	char *reversed;
	reversed = malloc(sizeof(char)*lengthOfMessage);
	while (reversedCounter <= lengthOfMessage) {
		reversed[reversedCounter] = message[lengthOfMessage - counter - 1];
		counter++;
		reversedCounter++;
	}
	return reversed;
}
