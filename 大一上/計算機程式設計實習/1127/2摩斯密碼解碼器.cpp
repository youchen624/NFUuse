#include <stdio.h>
#include <string.h>

char mosToChar(char[]);

int main() {
    char data;
    while (scanf("%c", &data) != EOF) {
        if (data == '\n' || data == '|' || data == ' ') continue;
        char ref[9] = {};
        for (int i = 0; data != '|' && data != '\n' && data != ' ' && i < 9; i++) {
            ref[i] = data;
            data = getchar();
        }
        printf("%c", mosToChar(ref));
    }
	return 0;
}

char mosToChar(char morse[]) {
    char morseTable[26][9] = {
        "¡E¡X", "¡X¡E¡E¡E", "¡X¡E¡X¡E", "¡X¡E¡E",            //ABCD
        "¡E", "¡E¡E¡X¡E", "¡X¡X¡E", "¡E¡E¡E¡E",                  //EFGH
        "¡E¡E", "¡E¡X¡X¡X", "¡X¡E¡X", "¡E¡X¡E¡E",         //IJKL
        "¡X¡X", "¡X¡E", "¡X¡X¡X", "¡E¡X¡X¡E",     //MNOP
        "¡X¡X¡E¡X", "¡E¡X¡E", "¡E¡E¡E", "¡X",             //QRST
        "¡E¡E¡X", "¡E¡E¡E¡X", "¡E¡X¡X", "¡X¡E¡E¡X",       //UVWX
        "¡X¡E¡X¡X", "¡X¡X¡E¡E"                         //YZ
    };  //"AZ" 65 90 \0
    int t = 0;
    for (int i = 0; i < 26; i++) {
        if (!strcmp(morse, morseTable[i])) {
            t = i;
            break;
        }
    }
    return (char)(65 + t);
}