#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int main(void){
	// elemsz�m beolvas�sa
	int n;
	printf("mennyi elem legyen? ");
	scanf_s("%d", &n);

	// t�mb felt�lt�se
	int* tomb = (int*)malloc(n*sizeof(int));

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		tomb[i] = rand() % 2;
		printf("tomb[%d]=%d\n", i, tomb[i]);
	}

	// leghosszabb 1-es r�szsorozat
	int count=0;
	int legjobb_index;
	int legjobb_ertek=-1;

	for (int i = 0; i < n; i++) {
		if (tomb[i] == 1) // 1-es sorozat k�zben vagyunk
			count++;
		if (tomb[i] == 0) { // 1-es sorozat v�ge
			if (count > legjobb_ertek) { // tal�ltunk hosszabb sorozatot
				legjobb_ertek = count;
				legjobb_index = i - count;
			}
			count = 0;
		}
	}

	printf("kezdoindex: %d\n", legjobb_index);
	printf("hossz: %d\n", legjobb_ertek);

	// t�mb felszabad�t�sa
	free(tomb);

	return 0;
}