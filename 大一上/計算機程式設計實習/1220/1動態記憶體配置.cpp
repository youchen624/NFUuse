#include <stdio.h>
#include <stdlib.h>

int getNumsNums(char*);

int main() {
	int n; scanf("%d", &n);
	char* data = (char*)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i <= n; data[i] = '\0', i++);
	getchar();
	char c = getchar();
	for (int i = 0; c != '\n'; data[i] = c, i++) c = getchar();
	printf("%d", getNumsNums(data));
	return 0;
}

int getNumsNums(char* p) {
	int t = 0;
	for (; *p != '\0'; p++)
		if ('0' <= *p && *p <= '9')
			t += *p - '0';
	return t;
}