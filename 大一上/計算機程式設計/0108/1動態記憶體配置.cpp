#include <stdio.h>
#include <stdlib.h>

int nums(char*);

int main() {
	int n = 0; scanf("%d ", &n);// getchar();
	char* ch = (char*)malloc(sizeof(char) * (n + 1));
	for (int i = 0; i < n; i++) ch[i] = '\0';
	for (int i = 0; i < n; i++) {
		ch[i] = getchar();
		if (ch[i] == '\n') break;
	}
	printf("%d", nums(ch));
	return 0;
}

int nums(char *ch) {
	int a = 0;
	for (int i = 0; *(ch+i) != '\0'; i++)
		if ('0' <= *(ch + i) && *(ch + i) <= '9')
			a += *(ch + i) - '0';
	return a;
}