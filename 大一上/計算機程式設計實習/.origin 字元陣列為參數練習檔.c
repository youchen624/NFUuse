#include <stdio.h>

int length(char[]);
void copy(char a[], char[]);
void change(char a[]);
void concatenate(char a[], char[]);
void reverse(char[]);
int main()
{
    char a[80], b[80], c[80];
    printf("請輸入陣列a的內容:\n");
    scanf("%s", a);
    // gets(a);
    printf("陣列a的長度為:%d\n", length(a));
    printf("copy陣列a的內容到陣列b...\n");
    copy(b, a);
    printf("陣列b的內容為:%s\n", b);
    printf("請輸入陣列c的內容\n");
    scanf("%s", c);
    printf("串接陣列c的內容到陣列a的內容之後...\n");
    concatenate(a, c);
    printf("陣列a的內容為:%s\n", a);

    printf("將陣列b的內容中大寫英文字轉為小寫,小寫英文字轉為大寫...\n");
    change(b);
    printf("陣列b的內容為:%s\n", b);
    printf("陣列a的內容原來為:%s\n", a);
    reverse(a);
    printf("陣列a的內容經反轉後成為: %s\n", a);
    system("pause");
    return 0;
}
int length(char a[]) // 計算字串長度
{
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}
void copy(char b[], char a[]) // 複製陣列a的內容到陣列b
{
}
void change(char a[]) // 將陣列內容中大寫英文字轉為小寫,小寫英文字轉為大寫
{
}
void concatenate(char a[], char b[]) // 複製陣列b的內容到陣列a的後面
{
}
void reverse(char a[]) // 字串反轉
{
}
