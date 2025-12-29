#include <stdio.h>
#include <stdlib.h>
int Days(int, int);

int main() {
	int n = 0;
	scanf("%d", &n);
	while (n > 0) {
		int y, m;
		scanf("%d%d", &y, &m);
		printf("%d\n", Days(y, m));
		n--;
	}
	return 0;
}

int Days(int year, int month) {
	int bala[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2) { if (!(year % 400) || (!(year % 4) && (year % 100))) return 29; }
	return bala[month - 1];
	//%400 || %4!%100
}