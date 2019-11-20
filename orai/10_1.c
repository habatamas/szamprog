#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

/*
feltételes minimumkeresés:
a megadott limitnél nagyobb számot keresünk,
ami az adott fájlban a lehetõ legkisebb

ha nincs találat, akkor visszatérési érték 0
ha van találat, akkor 1
a megtalált minimum pedig pointerrel lesz visszaadva
*/
int felteteles_minimum(FILE* f, int limit, int *legkisebb) {
	int van_talalat = 0;
	while (!feof(f)) {
		int szam;
		fscanf(f, "%d", &szam);
		
		// csak a limitnél nagyobb értékek számítanak
		if (szam > limit) {
			// ha elsõ beolvasás, akkor az mindenképp jó
			if (van_talalat == 0) {
				*legkisebb = szam;
			}

			van_talalat = 1;

			if (szam < *legkisebb)
				*legkisebb = szam;
		}
	}

	return van_talalat;
}

int main(void) {
	// minimumkeresés
	// fájl megnyitás
	// fclose(fopen("bemenet.txt", "w"));
	
	FILE* fbe = fopen("bemenet.txt", "r");
	
	int legkisebb;
	fscanf(fbe, "%d", &legkisebb);

	while (!feof(fbe)) {
		int szam;
		fscanf(fbe, "%d", &szam);
		
		if (szam < legkisebb)
			legkisebb = szam;
	}

	// fájl bezárás
	fclose(fbe);
	printf("min: %d\n", legkisebb);

	// kimenet
	FILE* fki = fopen("kimenet.txt", "w");

	int limit = legkisebb-1;
	while (1) {
		// következõ szám beolvasása
		int felt_minimum;
		fbe = fopen("bemenet.txt", "r");
		int siker = felteteles_minimum(fbe, limit, &felt_minimum);
		fclose(fbe);

		// ha elfogytak a számok, akkor vége
		if (!siker) break;

		// ha nem fogytak még el, akkor írjuk ki
		fprintf(fki, "%d\n", felt_minimum);

		// a következõ limit frissítése
		limit = felt_minimum;
	}

	fclose(fki);

	_getch();
	return 0;
}