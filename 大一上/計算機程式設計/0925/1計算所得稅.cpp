#include <stdio.h>
#include <stdlib.h>

int main() {
	int income = 0;
	double rate = 0;
	int difference = 0;
	scanf("%d", &income);
	if (income > 4090000) {
		rate = 0.4;
		difference = 721100;
	}
	else if (income > 2180000) {
		rate = 0.3;
		difference = 312100;
	}
	else if (income > 1090000) {
		rate = 0.21;
		difference = 115900;
	}
	else if (income >410000)
	{
		rate = 0.13;
		difference = 28700;
	}
	else
	{
		rate = 0.06;
	}
	int tax = income * rate - difference;
	printf("%d", tax);
	system("pause");
	return 0;
}