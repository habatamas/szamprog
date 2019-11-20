#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void letrehoz(int n, int r) {
	FILE* f = fopen("szamok.txt", "w");
	
	for (int i = 0; i < n; i++) {
		// véletlenszám -r-tõl r-ig
		// 2r+1 különbözõ érték születhet
		int randomszam = rand() % (2 * r + 1) - r;
		fprintf(f, "%d\n", randomszam);
	}

	fclose(f);
}

int darab() {
	FILE* f = fopen("szamok.txt", "r");
	int db = 0;
	while (1) {
		int szam;
		int siker = fscanf(f, "%d", &szam);
		if (siker!=1) break;
		db++;
	}
	fclose(f);
	return db;
}

int index(int i) {
	FILE* f = fopen("szamok.txt", "r");
	int db = 0;
	while (1) {
		int szam;
		int siker = fscanf(f, "%d", &szam);
		if (siker != 1) break;

		// ezt akartuk megkapni?
		if (db==i) {
			fclose(f);
			return szam;
		}

		db++;
	}
	fclose(f);
	return db;
}

int minimum() {
	int legkisebb = index(0);
	for (int i = 0; i < darab(); i++)
		if (index(i) < legkisebb)
			legkisebb = index(i);
	return legkisebb;
}

int maximum() {
	int legnagyobb = index(0);
	for (int i = 0; i < darab(); i++)
		if (index(i) > legnagyobb)
			legnagyobb = index(i);
	return legnagyobb;
}

int main(void){
	// randomgenerátor indítása
	srand(time(NULL));

	printf("hello MOGI\n");
	letrehoz(100, 10);

	printf("db=%d\n", darab());
	printf("szamok[45]=%d\n", index(45));

	printf("min=%d\n", minimum());
	printf("max=%d\n", maximum());

	_getch();
	return 0;
}