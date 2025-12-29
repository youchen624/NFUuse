#include <stdio.h>

int main() {
	struct theDate {
		int y, m, d;
	} A, B;
	while (scanf("%d/%d/%d %d/%d/%d", &A.d, &A.m, &A.y, &B.d, &B.m, &B.y) != EOF) {
		//printf("%d,%d,%d,%d,%d,%d\n", A.d, A.m, A.y, B.d, B.m, B.y);
		int tA = A.y * 10000 + A.m * 100 + A.d;
		int tB = B.y * 10000 + B.m * 100 + B.d;
		if(tA==tB)
			printf("Same\n");
		else if (tA > tB)
			printf("After\n");
		else if (tA < tB)
			printf("Before\n");
	}
	return 0;
}