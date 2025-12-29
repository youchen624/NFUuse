#include <stdio.h>
#include <ctype.h>
#include <string.h>

void nonameFunction(char[][50], char[], int*, int*, int*);

int main() {
	char data[1000][50] = {};
	char searchFor[50];
	int i = 0, totalChar = 0, totalWord = 0, totalMatch = 0;
	while (scanf("%s", &data[i]) != EOF && i < 1000) i++;
	scanf("%s", searchFor);
	nonameFunction(data, searchFor, &totalMatch, &totalChar, &totalWord);
	printf("场じ计秖: %d\n场虫计秖: %d\n穓碝计秖:%d\n", totalChar, totalWord, totalMatch);
	return 0;
}

void nonameFunction(char ar[][50], char goal[], int* match, int* theChars, int* theWords) {
	for (int i = 0; i < 1000; i++) { //words
		*match += (!strcmp(ar[i], goal));
		if (isalpha(ar[i][0])) (*theWords)++;
		else break;
		for (int ii = 0; ii < 50; ii++) {//chars
			if (ar[i][ii] != '\0') (*theChars)++;
			else break;
		}
	}
}