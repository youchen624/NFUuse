/*
一個HTML文件的絕對網址如下形式:
http://www.nfu.edu.tw/index.html
其中包含了兩個主要部分
server至主機的domain name：nfu.edu.tw
網頁名稱：index.html
請寫一C程式包含函式
void fun(char a[] ,char b[], char c[])的絕對網址轉換程式，
主程式接受使用者指定的domain name與網頁名稱由參數b及c傳入
該HTML文件的兩個主要部分(即b陣列及c陣列分別儲存相對之domain name及網頁名稱)，
將其轉成絕對網址後置於a字元陣列內，並在主程式中印出存在a陣列中的絕對網址。
輸入有多筆測資至使用者輸入Ctrl+z結束輸入，每一行代表一筆測資，有domain name 與網頁名稱；
輸出為每一筆測資相對的絕對網址
<Sample input>
nfu.edu.tw			index.html
chwa.com.tw		service.html
<Ctrl+z><Ctrl+z><Ctrl+z>
<Sample output>
http://www.nfu.edu.tw/index.html
http://www.chwa.com.tw/service.html
*/

#include <stdio.h>
#include <string.h>

void fun(char[], char[], char[]);

int main() {
	char a[240], b[100], c[100];
	while (scanf("%s%s", &b, &c) != EOF) {
		fun(a, b, c);
	}
	return 0;
}

void fun(char a[], char b[], char c[]) {
	strcpy(a, "http://www.");
	strcat(a, b);
	strcat(a, "/");
	strcat(a, c);
	printf("%s\n", a);
}