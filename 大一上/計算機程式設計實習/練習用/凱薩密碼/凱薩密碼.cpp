#include <stdio.h>
#include <stdlib.h>

int main() {
	char a[60];
	char p = ' ';// , 'A65', 'Z90'; -26 Z90 W87
	scanf("%s", &a);
	for (int i = 0; i < 5; i++) {
		if (a[i] < 65 || a[i]>90) continue;
		if ((a[i] += 3) > 90)a[i] -= 26;
	}
	printf("%s", a);
	return 0;
}