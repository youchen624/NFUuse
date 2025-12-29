#include <stdio.h>
#include <stdlib.h>

int main() {
	char a = ' ';
	printf("請輸入字母...\n");
	scanf("%c", &a);
	if (65 <= a && a <= 90)
		a += 32;
	else if (97 <= a && a <= 122)
		a -= 32;
	printf("%c", a);
	system("pause");
	return 0;
}