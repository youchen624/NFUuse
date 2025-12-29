/*
#include <stdio.h>

int main() {
	int s = 0;
	long long d = 0;
	while (scanf("%d%lld", &s, &d) != EOF) {
		for (int t = 1; d > 0; d--, t++) {
			//printf("%lld\n", d);
			if (t > s) {
				t = 1; s++;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
*/
#include <stdio.h>

int main() {
	long long d = 0, s = 0;;
	while (scanf("%lld%lld", &s, &d) != EOF) {
		/*
		for(int t = 1;d>0;d--,t++){
			if(t > s){
				t = 1;s++;
			}
		}*/
		while (1) {
			d -= s++;
			printf("%lld\n", d);
			if (d <= 0) break;
		}
		printf("%lld\n", s);
	}
	return 0;
}