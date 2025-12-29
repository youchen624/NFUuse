#include <stdio.h>
#include <stdlib.h>

int main() {
	// 1 ******** ******** ******** ********
	printf("方式一\n");
	const char dataName[5][31] = {
		"M1A2T", "M88A2",
		"CH-47", "Patriot",
		"M109A6"
	};
	const int dataPrice[5] = { 293679000, 130524000, 978930000, 13052400000, 163155000 };
	int tnM = 0, tnm = 0;
	for (int i = 0, tm = 0, tn = dataPrice[0]; i < 5; i++) {
		if (tm < dataPrice[i]) tm = dataPrice[tnM = i];
		if (tn > dataPrice[i]) tn = dataPrice[tnm = i];
		printf("產品%d: %30s, 價格: %d\n", i, dataName[i], dataPrice[i]);
	}
	printf("最貴的產品: %30s, 價格: %d\n", dataName[tnM], dataPrice[tnM]);
	printf("最便宜的產品: %30s, 價格: %d\n", dataName[tnm], dataPrice[tnm]);

	// 2 ******** ******** ******** ********
	printf("\n\n方式二\n");
	const char* dataName2[5] = {
		"M1A2T", "M88A2",
		"CH-47", "Patriot",
		"M109A6"
	};
	tnM = 0, tnm = 0;
	for (int i = 0, tm = 0, tn = dataPrice[0]; i < 5; i++) {
		if (tm < dataPrice[i]) tm = dataPrice[tnM = i];
		if (tn > dataPrice[i]) tn = dataPrice[tnm = i];
		printf("產品%d: %30s, 價格: %d\n", i, dataName2[i], dataPrice[i]);
	}
	printf("最貴的產品: %30s, 價格: %d\n", dataName2[tnM], dataPrice[tnM]);
	printf("最便宜的產品: %30s, 價格: %d\n", dataName2[tnm], dataPrice[tnm]);

	// 3 ******** ******** ******** ********
	printf("\n\n方式三\n");
	struct product {
		char name[31];
		int price;
	};
	const struct product theProducts[5] = {
		{ "M1A2T", 293679000    },
		{ "M88A2", 130524000    },
		{ "CH - 47", 978930000   },
		{ "Patriot", 13052400000 },
		{ "M109A6", 163155000  }
	};
	tnM = 0, tnm = 0;
	for (int i = 0, tm = 0, tn = theProducts[0].price; i < 5; i++) {
		if (tm < theProducts[i].price) tm = theProducts[tnM = i].price;
		if (tn > theProducts[i].price) tn = theProducts[tnm = i].price;
		printf("產品%d: %30s, 價格: %d\n", i, theProducts[i].name, theProducts[i].price);
	}
	printf("最貴的產品: %30s, 價格: %d\n", theProducts[tnM].name, theProducts[tnM].price);
	printf("最便宜的產品: %30s, 價格: %d\n", theProducts[tnm].name, theProducts[tnm].price);
	// end
	return 0;
}