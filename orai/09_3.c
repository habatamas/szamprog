#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

// fájlban megkeresi a legkisebb számot,
// ami egy adott értéket már meghalad
int legkisebb_keres(FILE *f, int limit, int *legkisebb) {
	int van_talalat = 0;

	while (!feof(f)) {
		int szam;
		fscanf(f, "%d", &szam);
		if (szam > limit) {
			if (!van_talalat) {
				*legkisebb = szam;
				van_talalat = 1;
			} else {
				if (*legkisebb > szam) {
					*legkisebb = szam;
				}
			}
		}
	}

	return van_talalat;
}

int main(void){
	FILE* f = fopen("idopontok.txt", "r");

	int leghosszabb = -1; // feltételezzük, hogy csak pozitív

	while (!feof(f)) {

		int ora1, perc1, ora2, perc2;
		fscanf(f, "%d:%d - %d:%d", &ora1, &perc1, &ora2, &perc2);

		int hossz = (ora2 * 60 + perc2) - (ora1 * 60 + perc1);
		printf("muszak hossza: %d:%d\n", hossz / 60, hossz % 60);

		if (hossz > leghosszabb)
			leghosszabb = hossz;
	}

	fclose(f);

	printf("a leghosszabb muszak: %d perc = %d:%d\n",
		leghosszabb, leghosszabb / 60, leghosszabb % 60);

	// legkisebb szám
	FILE* fbe = fopen("szamok.txt", "r");
	int legkisebb;
	fscanf(fbe, "%d", &legkisebb);
	while (!feof(fbe)) {
		int szam;
		fscanf(fbe, "%d", &szam);
		if (szam < legkisebb)
			legkisebb = szam;
	}
	fclose(fbe);
	printf("%d\n", legkisebb);

	FILE* fki = fopen("egyedi.txt", "w");
	fprintf(fki, "%d\n", legkisebb);

	while (1) {
		fbe = fopen("szamok.txt", "r");
		int uj_szam;
		int siker = legkisebb_keres(fbe, legkisebb, &uj_szam);
		fclose(fbe);

		if (siker) {
			fprintf(fki, "%d\n", uj_szam);
			legkisebb = uj_szam;
		} else {
			break;
		}
	}

	fclose(fki);


	_getch();
	return 0;
}