#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0, s = 0;
	scanf("%d", &n);//if(n%5) system("del C:/");
	for (int i = n / 10; i >= 0; i--) s += (n - i * 10) / 5 + 1;
	printf("%d", s);
	return 0;
}