#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// tarsasag_general függvény
// kap egy tömböt (pointer+elemszám)
// megkapja, hogy hány napból áll egy év
// feltölti a tömböt random "születésnapokkal"
void tarsasag_general(int* tarsasag, int letszam,
	int ev_hossza) {
	for (int i = 0; i < letszam; i++) {
		tarsasag[i] = rand() % ev_hossza; // 0..ev_hossza-1
	}
}

// egyezik függvény
// megmondja, hogy egy tömbben van-e ismétlődő elem
int egyezik(int* tomb, int db) {
	for (int i = 0; i < db; i++) {
		for (int j = i+1; j < db; j++) {
			// különböző elemek összehasonlítása
			if (tomb[i] == tomb[j]) {
				// van ismétlődő elem
				return 1;
			}
		}
	}
	return 0; // nem volt egyezés
}

int main(void) {
	// randomgenerátor inicializálása
	srand(time(NULL));

	// adatok beolvasása
	int ev_hossza;
	printf("Hany napbol all egy ev? ");
	scanf("%d", &ev_hossza);
	int letszam;
	printf("Hany tagu egy tarsasag? ");
	scanf("%d", &letszam);
	int tarsasagok_szama;
	printf("Hany tarsasagot vizsgalunk? ");
	scanf("%d", &tarsasagok_szama);

	// generáljunk társaságokat
	// és számláljuk a kedvező eseteket
	int tarsasag[1000];
	int kedvezo = 0;

	for (int i = 0; i < tarsasagok_szama; i++) {
		// adott társaság generálása
		tarsasag_general(tarsasag, letszam, ev_hossza);

		// kedvező esetek számlálása
		if (egyezik(tarsasag, letszam))
			kedvezo++;
	}

	printf("Az esetek %f szazalekaban volt egyezes.\n",
		100.0 * kedvezo / tarsasagok_szama);

	// teszt
/*	int emberek[23];
	tarsasag_general(emberek, 23, 365);
	for (int i = 0; i < 23; i++)
		printf("%d\n", emberek[i]);
	if (egyezik(emberek, 23)) {
		printf("van talalat!\n");
	}*/

	_getch();
	return 0;
}