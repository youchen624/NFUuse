#include <stdio.h>
#include <string.h>

int length(char[]);
void copy(char a[], char[]);
void change(char a[]);
void concatenate(char a[], char[]);
void reverse(char[]);
int main()
{
    char a[80], b[80], c[80];
    printf("請輸入陣列a的內容:\n");
    gets(a); //scanf("%s", a);
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
    strcpy(b, a);
}
void change(char a[]) // 將陣列內容中大寫英文字轉為小寫,小寫英文字轉為大寫
{
    // { 'a', 'z', 'A', 'Z'}  ==== 97 122 || 65 90
    for (int i = 0; i < length(a); i++) {
        if (65 <= a[i] && a[i] <= 90)
            a[i] += 32;
        else if (97 <= a[i] && a[i] <= 122)
            a[i] -= 32;
    }
}
void concatenate(char a[], char b[]) // 複製陣列b的內容到陣列a的後面
{
    int lenA = length(a), lenB = length(b);
    for (int i = 0; i <= lenB; i++) {
        a[i + lenA] = b[i];
    }
}
void reverse(char a[]) // 字串反轉
{
    int t = length(a);
    for (int i = 0; i < t / 2; i++) {
        int temp = a[i];
        a[i] = a[t - i - 1];
        a[t - i - 1] = temp;
    }
}
