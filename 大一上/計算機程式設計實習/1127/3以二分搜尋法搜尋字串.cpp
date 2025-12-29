#include <stdio.h>
#include <string.h>

void sortSC(char[][40], int);
int binSearchSCS(char[][40], char[], int, int, int*);

int main() {
	char zodiac[12][40] = {
		"rat", "ox", "tiger", "hare", "dragon", "snake",
		"horse", "sheep", "monkey", "rooster", "dog", "pig"
	};
	char key[40] = {};
	int pos = 0;
	sortSC(zodiac, 12);
	for (int i = 0; i < 12; i++)
		printf("%s\n", zodiac[i]);
	scanf("%s", key);
	if (binSearchSCS(zodiac, key, 0, 11, &pos)) {
		printf("在第 %d 項\n", pos + 1);
	}
	else {
		printf("不在資料庫中\n");
	}
	return 0;
}

void sortSC(char ar[][40], int size) {
	char t[40];
	for (int n = 0; n < size - 1; n++) {
		for (int m = n + 1; m < size; m++) {
			if (strcmp(ar[n], ar[m]) == 1) { //a > b
				strcpy(t, ar[n]);
				strcpy(ar[n], ar[m]);
				strcpy(ar[m], t);
			}
		}
	}
}

int binSearchSCS(char ar[][40], char key[], int from, int to, int* pos) {
	int mid = (from + to) / 2;
	if (!strcmp(ar[mid], key)) {
		*pos = mid;
		return 1;
	}
	if (from == to) return 0;
	if (strcmp(ar[mid], key) > 0) return binSearchSCS(ar, key, from, mid - 1, pos);
	else if (strcmp(ar[mid], key) < 0) return binSearchSCS(ar, key, mid + 1, to, pos); 
	return 0;
}