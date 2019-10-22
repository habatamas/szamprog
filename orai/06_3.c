#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

#include <time.h>
#include <stdlib.h>

#include <stdbool.h>

int main(void) {

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		printf("%d\n", rand());
	}

	// dobókocka
	printf("dobokocka\n");
	int dobasok[10];
	for (int i = 0; i < 10; i++) {
		int dobas = rand() % 6 + 1;
		printf("%d\n", dobas);
		dobasok[i] = dobas;
	}

	// -10-tõl 10-ig bármi 
	// rand() -> 0...RAND_MAX
	for(int i=0; i<10; i++)
		printf("%f\n", 20*(double)rand()/RAND_MAX-10);

	// lottó
	int lottoszamok[5];
	int eddig_kihuzva = 0;
	while(eddig_kihuzva<5) {
		int huzas = rand() % 10 + 1;
		
		// szerepelt-e már?
		int szerepelt = 0;
		for (int i = 0; i < eddig_kihuzva; i++) {
			if (lottoszamok[i] == huzas) {
				szerepelt = 1;
			}
		}

		// ha nem, akkor jók vagyunk
		if (!szerepelt) {
			lottoszamok[eddig_kihuzva] = huzas;
			eddig_kihuzva++;
		}
	}

	printf("lottoszamok:\n");
	for (int i = 0; i < 5; i++)
		printf("%d\n", lottoszamok[i]);

	_getch();
	return 0;
}