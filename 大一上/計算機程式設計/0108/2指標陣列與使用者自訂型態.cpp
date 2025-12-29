#include <stdio.h>

struct product {
	char* name;
	int price;
};

int main() {
	char ch[5][31];
	char* chp[5];
	struct product item[5];
	int price[5];
	int expenst = 0, cheapst = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%s%d", ch[i], &price[i]);
	}
	for (int i = 0; i < 5; i++) chp[i] = ch[i];
	for (int i = 0; i < 5; i++) {
		item[i].name = ch[i];
		item[i].price = price[i];
		if (price[expenst] < price[i]) expenst = i;
		if (price[cheapst] > price[i]) cheapst = i;
	}

	for (int i = 0; i < 5; i++)
		printf("%s: %d\n", ch[i], price[i]);
	printf("程禥 %s: %d\n", ch[expenst], price[expenst]);
	printf("程獽﹜ %s: %d\n\n", ch[cheapst], price[cheapst]);
	for (int i = 0; i < 5; i++)
		printf("%s: %d\n", chp[i], price[i]);
	printf("程禥 %s: %d\n", chp[expenst], price[expenst]);
	printf("程獽﹜ %s: %d\n\n", chp[cheapst], price[cheapst]);
	for (int i = 0; i < 5; i++)
		printf("%s: %d\n", item[i].name, item[i].price);
	printf("程禥 %s: %d\n", item[expenst].name, item[expenst].price);
	printf("程獽﹜ %s: %d\n\n", item[cheapst].name, item[cheapst].price);
	/*
	for (int i = 0; i < 5; i++) {
		printf("%s,%d\n", ch[i], price[i]);
	}
	*/
	return 0;
}