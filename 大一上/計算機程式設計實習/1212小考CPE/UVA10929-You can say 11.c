//UVA10929-You can say 11
#include <stdio.h>
#include <string.h>

int main() {
    char data[1001] = {0};
    while(scanf("%s", data) != EOF){
        if(*data == '0' && strlen(data) == 1) break;
        int di = 0;
        for(int i = 0; i < strlen(data); i++){
            if(i % 2) di -= data[i] - '0';
            else di += data[i] - '0';
        }
        if(! (di % 11)) printf("%s is a multiple of 11.\n", data);
        else printf("%s is not a multiple of 11.\n", data);
    }
    return 0;
}