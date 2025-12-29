#include <stdio.h>
#include <stdlib.h>

int main() {
	int arR[5][5] = {
		{0, 1, 0, 1, 1},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 1},
		{1, 1, 1, 0, 1},
		{1, 0, 1, 1, 0},
	};
	for (int i = 0; i < 5; i++) {
		for (int ii = 0; ii < 5; ii++)
			printf("%d", arR[i][ii]);
		printf("\n");
	}
	return 0;
}