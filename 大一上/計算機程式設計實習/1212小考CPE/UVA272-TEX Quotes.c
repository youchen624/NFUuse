//UVA272-TEX Quotes
#include <stdio.h>

int main(){
	char input = ' ';
	int un = 1;
	while((input = getchar())!= EOF){
		if(input== '\"'){
			if(un>0)printf("``");
			else printf("\'\'");
			un *= -1;
		}
		else printf("%c", input);
	}
	return 0;
}