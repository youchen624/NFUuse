#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum dataV {
	C = 0,
	Ak = 1,
	Am,
	Bk,
	Bm,
	Yk,
	Ym = 6
};
void doFunc(int);
void swap(int*, int*);//void swap(int&, int&);
void randomTwoDif(int*, int* , int, int);
void 約分(int*, int*);
int randomPro(int, int);
int gcd(int, int);
int lcm(int, int);

const char sym[4] = { '-', '+', '/', '*' };

int main() {
	srand(time(0));
	for (int i = 1; i <= 10; i++) {
		doFunc(i);
		printf("%c", i % 2 ? '\t' : '\n');
	}
	return 0;
}

void doFunc(int i) {
	int data[7] = { 0 };
	data[C] = randomPro(0, 3);
	randomTwoDif(&data[Ak], &data[Am], 1, 9);
	randomTwoDif(&data[Bk], &data[Bm], 1, 9);
	if (!data[C] && (data[Ak] / (double)data[Am]) < (data[Bk] / (double)data[Bm])) {//!=0
		swap(&data[Ak], &data[Bk]);
		swap(&data[Am], &data[Bm]);
	}
	int m = lcm(data[Am], data[Bm]);
	//int nb[2] = { data[Bk], data[Bm] };
	switch (data[C]) {
		case 0: data[Bk] *= -1;
		case 1:
			data[Yk] = data[Ak]*(m / data[Am]) + data[Bk]*(m / data[Bm]);
			data[Ym] = m;
			break;
		case 2:
			swap(&data[Bk], &data[Bm]);
		case 3:
			data[Yk] = data[Ak] * data[Bk];
			data[Ym] = data[Am] * data[Bm];
			break;
	}
	if (!data[C])data[Bk] *= -1;
	if (data[C] == 2) swap(&data[Bk], &data[Bm]);
	約分(&data[Yk], &data[Ym]);
	printf("(%d)%d/%d %c %d/%d = %d/%d", i, data[Ak], data[Am], sym[data[C]], data[Bk], data[Bm], data[Yk], data[Ym]);
}

void 約分(int* a, int* b) {
	int c = gcd(*a, *b);
	*a /= c;
	*b /= c;
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int randomPro(int min, int max) {
	if (min > max) swap(&min, &max);
	return rand() % (max - min + 1) + min;
}

void randomTwoDif(int* a, int* b, int min, int max) {
	do {
		*a = randomPro(min, max);
		*b = randomPro(min, max);
	} while (*a == *b);
}

int gcd(int p, int q) {
	for (int i = (p > q ? p : q); i > 0; i--) {
		if ((p % i == 0) && (q % i == 0)) { return i; }
	}
	return 1;
}
int lcm(int p, int q) { return (p * q / gcd(p, q)); }