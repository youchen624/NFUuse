#include <stdio.h>
#include <stdlib.h>

void testMultiIfElse(int, int, int);
void testNestedIf(int, int, int);
void testSwitch(int, int, int);

int main() {
	int a = 0, b = 0;
	char c = ' ';
	//bool x = false;
	scanf("%d %c%d", &a, &c, &b);
	//printf("%d%c%d", a, c, b);
	printf("多重if %d%c%d= ", a, c, b);
	testMultiIfElse(a, b, c);
	printf("\n巢狀if %d%c%d= ", a, c, b);
	testNestedIf(a, b, c);
	printf("\nswitch %d%c%d= ", a, c, b);
	testSwitch(a, b, c);
	printf("\n");
	system("pause");
	return 0;
}

void testMultiIfElse(int a, int b, int c) {
	double y = 0;
	if (c == '+') {
		y = a + b;
	}
	else if (c == '-')
	{
		y = a - b;
	}
	else if (c == '*')
	{
		y = a * b;
	}
	else if (c == '/')
	{
		if (!b) return;
		y = (double)a / b;
	}
	else if (c == '#')
	{
		int t = a;
		for (int i = b - 1; i > 0; i--) {
			a *= t;
		}
		y = a;
	}
	else if (c == '%')
	{
		y = a % b;
	}
	if (c == '/') {
		printf("%.2lf", y);
	}
	else {
		printf("%d", (int)y);
	}
}

void testNestedIf(int a, int b, int c) {
	double y = 0;
	if (c == '/')
	{
		if (!b) return;
		y = (double)a / b;
		printf("%.2lf", y);
	}
	else {
		if (c == '+') y = a + b;
		else if (c == '-') y = a - b;
		else if (c == '*') y = a * b;
		else if (c == '%') y = a % b;
		else if (c == '#')
		{
			int t = a;
			for (int i = b - 1; i > 0; i--) {
				a *= t;
			}
			y = a;
		}
		printf("%d", (int)y);
	}
}

void testSwitch(int a, int b, int c) {
	double y = 0;
	switch (c)
	{
	case '/':
	{
		if (!b) return;
		y = (double)a / b;
		break;
	}
	case '#':
	{
		int t = a;
		for (int i = b - 1; i > 0; i--) {
			a *= t;
		}
		y = a;
		break;
	}
	case '+': { y = a + b; break; }
	case '-': { y = a - b; break; }
	case '*': { y = a * b; break; }
	case '%': { y = a % b; break; }
	default: break;
	}
	if (c == '/') printf("%.2lf", y);
	else printf("%d", (int)y);
}