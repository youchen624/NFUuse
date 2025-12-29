/*
在主程式中根據使用者給定的整數資料建立一4列4行的二維陣列，
將此二維陣列傳入一函式void Rowsum(int a[][4])中處理，印出出每列之總和；
再建立另一函式int Diagonal_sum(int a[][4])傳回二維陣列之左上右下對角線元素之總和。
。列列列列C
行？。。。
行。？。。
行。。？。
行。。。？
R
*/

#include <stdio.h>
#include <stdlib.h>

void Rowsum(int[][4]);//pr 每row之總和
int Diagonal_sum(int[][4]);

int main() {
	int arR[4][4] = {
		{9, 0, 0, 0},
		{0, 9, 0, 0},
		{0, 0, 9, 0},
		{0, 0, 0, 9}
	};
	for (int i = 0; i < 4; i++)
		for (int ii = 0; ii < 4; ii++)
			scanf("%d", &arR[i][ii]);
	Rowsum(arR);
	printf("左上右下對角線元素之總和：%d", Diagonal_sum(arR));
	return 0;
}

void Rowsum(int ar[][4]) {
	printf("每列之總和：\n");
	for (int i = 0; i < 4; i++) {
		int s = 0;
		for (int ii = 0; ii < 4; ii++)
			s += ar[i][ii];
		printf("%d\n", s);
	}
}//pr 每row之總和

int Diagonal_sum(int ar[][4]) { //return 1 + 1 + 1 + 1;
	int t = 0;
	for (int i = 0; i < 4; i++)
		t += ar[i][i];
	return t;
}