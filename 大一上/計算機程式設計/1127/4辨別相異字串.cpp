#include <stdio.h>
#include <string.h>
/*
寫一C程式, 
處理使用者給定的多個字串(字串中無空白, 到空白行結束，不超過100個字串, 每個字串不超過30個字)，
根據字串出現次數排序(由高到低), 若字串出現次數相同, 則按字典順序, 字串小者在前面。
印出排序結果(若有相同字串僅印出1次)
*/
void dosomethingMystery(char[][30], char*[], int*);

int main() {
	char data[100][30] = {};
	char* uoData[100] = { NULL };
	int uoDataTi[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		char t = ' ';
		int fuse = 0;
		for (fuse = 0; (t = getchar()) != '\n' && fuse < 30; fuse++)
			data[i][fuse] = t;
		if (!fuse) break;
	}
	dosomethingMystery(data, uoData, uoDataTi);
	///===========
	for (int i = 0; i < 100; i++) {
		if (!uoData[i]) break;
		printf("%s\n", uoData[i]); //printf("%d:%s, %d\n",i ,uoData[i], uoDataTi[i]);
	}
	return 0;
}

void dosomethingMystery(char ar[][30], char* uoAr[], int* arT) {
	for (int i = 0; i < 100; i++) {
		if (!ar[i][0]) break;
		int ii = 0;
		for (; ii < i; ii++) {//尋找是否有重複或是否存在
			if (!uoAr[ii]) break;
			if (!strcmp(ar[i], uoAr[ii])) break;
		}
		uoAr[ii] = ar[i];//在該位置儲存指標 並增加相對數量
		arT[ii]++;
	}
	// #TODO 比較排序
	//找有效範圍
	int refPos = 0;
	for (; arT[refPos + 1] > 0; refPos++);
	//依照 arT 大小排列
	for (int i = 0; i < refPos; i++) {
		for (int ii = i + 1; ii <= refPos; ii++) {
			if (arT[i] < arT[ii]) {
				int t = arT[i];
				arT[i] = arT[ii];
				arT[ii] = t;
				char* tt = uoAr[i];
				uoAr[i] = uoAr[ii];
				uoAr[ii] = tt;
			}
		}
	}
	//依照 arT 相同大小的字典排列 字串小在前
	//尋找同值有效範圍
	for (int refPfrom = 0, refPto = 0; refPfrom < refPos; refPfrom++) {
		for (int temp = arT[refPto]; temp == arT[refPto + 1]; refPto++);
		if (refPfrom != refPto) {
			for (int i = refPfrom; i < refPto; i++) {
				for (int ii = i + 1; ii <= refPto; ii++) {
					if (strcmp(uoAr[i], uoAr[ii]) > 0) {
						char* tt = uoAr[i];
						uoAr[i] = uoAr[ii];
						uoAr[ii] = tt;
					}
				}
			}
			refPfrom = refPto++;
		}
	}
}