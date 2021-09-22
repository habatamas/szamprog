#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
	// elemszám beolvasása
	int n;
	printf("mennyi elem legyen? ");
	scanf_s("%d", &n);

	// tömb feltöltése
	int* tomb = (int*)malloc(n*sizeof(int));

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		tomb[i] = rand() % 2;
		printf("tomb[%d]=%d\n", i, tomb[i]);
	}

	// leghosszabb 1-es részsorozat
	int count=0;
	int legjobb_index;
	int legjobb_ertek=-1;

	for (int i = 0; i < n; i++) {
		if (tomb[i] == 1) // 1-es sorozat közben vagyunk
			count++;
		if (tomb[i] == 0) { // 1-es sorozat vége
			if (count > legjobb_ertek) { // találtunk hosszabb sorozatot
				legjobb_ertek = count;
				legjobb_index = i - count;
			}
			count = 0;
		}
	}

	printf("kezdoindex: %d\n", legjobb_index);
	printf("hossz: %d\n", legjobb_ertek);

	// tömb felszabadítása
	free(tomb);

	return 0;
}