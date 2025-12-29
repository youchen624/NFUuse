#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char ch[1000][51];
	for (int i = 0; i < 1000; i++) ch[i][0] = '\0';
	printf("輸入單字..\n");
	for (int i = 0; scanf("%s", ch[i]) != EOF; i++);
	printf("輸入找尋字..\n");
	char goal[51]; scanf("%s", goal);
	int 字元數量 = 0, 單字數量 = 0, 目標 = 0;
	for (; 單字數量 < 1000; 單字數量++) {
		if (!strcmp(ch[單字數量],goal)) 目標++;
		if (ch[單字數量][0] == '\0') break;
		for (int i = 0; ch[單字數量][i] != '\0'; i++, 字元數量++);// if (ch[單字數量][i]);
	}
	printf("%d\n%d\n%d\n", 字元數量, 單字數量, 目標);
	return 0;
}//I want to change some coins. Please give me some dimes and some nickels.