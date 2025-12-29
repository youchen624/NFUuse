/*
請寫一C程式，用「%20」來替代使用者所輸入之字串中的每一個空格。
例如，若使用者輸入字串為「We are happy.」，
則程式會將此字串更改為「We%20are%20happy.」再印出。
除了儲存使用者輸入字串所使用的字元陣列外，你可能會用到額外陣列來處理，
請想想你能否進一步在不使用任何額外陣列輔助的情況下完成此程式。
*/
/*
當空格
	空格後全部往後移2
	空格納格依序%20
*/
#include <stdio.h>
#include <string.h>

void fix(char[], int);

int main() {
	char c[100] = { '\0' };
	gets(c);
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == ' ') fix(c, i);
	}
	printf("%s\n", c);
	return 0;
}

void fix(char c[], int n) {
	int end = n;
	for (end; c[end] != '\0'; end++);
	for (int i = end; i > n; i--) {
		c[i + 2] = c[i];
	}
	c[n] = '%';
	c[n + 1] = '2';
	c[n + 2] = '0';
}