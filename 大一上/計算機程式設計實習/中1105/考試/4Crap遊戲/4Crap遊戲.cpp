#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6
#define MIN 1

void play();
int doDice(int*);
void doGoal(int*, int*, int, int*);
void 玩家輸(int*, int*);
void 玩家贏(int*, int*);

int main() {
	play();
	srand(time(0));
	return 0;
}

void play() {
	int balance = 1000, w = 1, t = 0, round = 0, r = 1;
	printf("餘額: %d 元\n輸入賭金: ", balance);
	while (w != 0){
		scanf("%d", &w);
		if (!w) break;
		r = doDice(&t);
		if (r == 7 || r == 11) 玩家贏(&balance, &w);
		else if (r == 2 || r == 3 || r == 12) 玩家輸(&balance, &w);
		else {
			printf("目標點: %d\n", r);
			doGoal(&balance, &w, r, &t);
		}
		round++;
		printf("餘額: %d 元\n輸入賭金: ", balance);
	}
	printf("T: %d\nR: %d\n", t, round);
	printf("每回合平均投擲骰子次數: %.2lf\n", round>0 ? (t / (double)round) : 0);
}

int doDice(int* total) {
	int a = (rand() % (MAX - MIN + 1) + MIN) + (rand() % (MAX - MIN + 1) + MIN);
	(*total)++;
	printf("擲出骰子和: %d\n", a);
	printf("T: %d\n", *total);
	return a;
}

void doGoal(int* m, int* w, int g, int* total) {
	int r = doDice(total);
	if (r == 7) {
		玩家輸(m, w);
		return;
	}
	else if (r == g) {
		玩家贏(m, w);
		return;
	}
	doGoal(m, w, g, total);
}

void 玩家輸(int* m, int* w) {
	printf("玩家輸\n");
	*m -= *w;
}
void 玩家贏(int* m, int* w) {
	printf("玩家贏\n");
	*m += *w;
}