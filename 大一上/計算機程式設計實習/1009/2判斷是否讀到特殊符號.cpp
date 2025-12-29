#include <stdio.h>
#include <stdlib.h>

int main() {
	char x = ' ';
	int y = 0;
	while (x != '@') {
		if (48 <= x && x <= 57) y++;//48 57
		scanf("%c", &x);
	}
	printf("共有 %d 個阿拉伯數字", y);
	system("pause");
	return 0;
}