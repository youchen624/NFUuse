#include <stdio.h>

int cell(int);
int C(int, int);
int cellU(int);
int CU(int, int);

int main() {
	int m, n, ti;
	scanf("%d", &ti);
	for (; ti > 0; ti--) {
		scanf("%d%d", &m, &n);
		printf("以遞迴函式處理： %d\n以非遞迴函式處理：%d\n", C(m, n), CU(m, n));
	}
	return 0;
}

int cell(int a) {
	if (a < 0) return -1;
	return (a > 1) ? a*cell(a-1) : 1;
}

int C(int m, int n) {
	return cell(m) / (cell(n) * cell(m - n));
}

int cellU(int a) {
	if (a < 0) return -1;
	int t = a;
	while (a > 1) {
		t *= --a;
	}
	return t;
}

int CU(int m, int n) {
	return cellU(m) / (cellU(n) * cellU(m - n));
}