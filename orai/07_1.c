#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

struct kartyalap {
	int szin; // 0:treff 1:káró 2:pikk 3:kõr
	int szam; // 2..10:2..10 11:J 12:Q 13:K 14:A
};

int main(void) {
	// randomszámgenerátor indítása
	srand(time(NULL));

	// kártyahúzás
	struct kartyalap lapok[5];
	int kihuzott = 0;
	while (kihuzott < 5) {
		// kártya sorsolása
		struct kartyalap uj_lap;
		uj_lap.szin = rand() % 4;
		uj_lap.szam = rand() % 13 + 2;

		// szerepelt-e már az új lap?
		int szerepelt = 0; // 0=hamis
		for (int i = 0; i < kihuzott; i++) {
			if (lapok[i].szin == uj_lap.szin && lapok[i].szam == uj_lap.szam) {
				szerepelt = 1;
			}
		}

		// ha nem szerepelt még, akkor betesszük a tömbbe
		if (!szerepelt) {
			// új szám a tömbbe
			lapok[kihuzott] = uj_lap;
			kihuzott++;
		}
	}

	for (int i = 0; i < 5; i++) {
		switch (lapok[i].szin){
		case 0: printf("treff "); break;
		case 1: printf("karo "); break;
		case 2: printf("pikk "); break;
		case 3: printf("kor "); break;
		}

		if (lapok[i].szam <= 10) {
			printf("%d\n", lapok[i].szam);
		} else {
			char figurak[] = { 'J','Q','K','A' };
			printf("%c\n", figurak[lapok[i].szam - 11] );
		}
	}

	printf("hello MOGI\n");

	_getch();
	return 0;
}