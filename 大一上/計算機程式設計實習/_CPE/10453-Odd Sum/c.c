#include <stdio.h>

int main() {
	int t, a, b;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d%d", &a, &b);
		int temp = 0;
		for(; a <= b; a++){
			if(a%2) temp += a;
		}
		printf("Case %d: %d\n", i+1, temp);
	}
	return 0;
}