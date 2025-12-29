//UVA10170-The Hotel with Infinite Rooms
#include <stdio.h>
#include <math.h>

int main() {
	double d = 0,s = 0;;
	while(scanf("%lf%lf", &s, &d) != EOF){
		while(d!=0){
			d-=s;
			if(d<=0){
				printf("%.0lf\n", s);
				break;
			}else s++;
		}
	}
	return 0;
}