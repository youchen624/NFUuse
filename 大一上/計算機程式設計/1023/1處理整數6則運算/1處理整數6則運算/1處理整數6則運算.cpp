#include <stdio.h>
#include <stdlib.h>

int pow(int, int);

int main() {
	int a, b;
	char c = ' ';
	scanf("%d%c%d", &a, &c, &b);
	switch (c)
	{
	case '+': printf("a+b= %d", a + b); break;
	case '-': printf("a-b= %d", a - b); break;
	case '*': printf("a*b= %d", a * b); break;
	case '/': printf("a/b= %.2lf", a /(double) b); break;
	case '%': printf("a%cb= %d", c ,a % b); break;
	case '#': printf("a#b= %d", pow(a, b)); break;
	default: break;
	}
	system("pause");
	return 0;
}

int pow(int a, int b) {
	int t = a;
	for (int i = 1; i < b; i++) t *= a;
	return t;
}