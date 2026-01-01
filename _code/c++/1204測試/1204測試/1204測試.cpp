#include <stdio.h>
#include <stdlib.h>

int theC(char*);

int main() {
	int x;
	scanf("%d", &x);
	char* data = (char*)malloc(sizeof(char)*(x+1));
	for (int i = 0; i <= x; i++) data[i] = '\0';
	getchar();
	char t = getchar();
	if (!data) return 0;
	for (int i = 0; t != '\n' && i < x; data[i] = t, t = getchar(),i++);
	printf("%s\nc: %d", data, theC(data));
	return 0;
}

int theC(char *a) {
	int t = 0;
	for (int i = 0; a[i] != '\0'; i++) if ('0' <= a[i] && a[i] <= '9') t++;
	return t;
}