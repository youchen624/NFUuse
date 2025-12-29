#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);

int main() {
	int p[2] = { 0, 0 }, v[2] = {0, 10};
	int c = 0, t = 0, pt = t;
	while (c != 3) {
		scanf("%d", &t);
		scanf("%d", &c);
		p[0] += (t - pt) * v[0];
		p[1] += (t - pt) * v[1];
		pt = t;
		if ((c == 1)&& v[1]) v[1] *= -1;
		if ((c == 2)&& v[0]) v[0] *= -1;
		swap(&v[0], &v[1]);
		//printf("x=%d, y=%d\nt=%d, v=%d,%d\n\n", p[0], p[1], t, v[0], v[1]);
	}
	printf("%d\n%d", p[0], p[1]);
	return 0;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}