#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

/*
felt�teles minimumkeres�s:
a megadott limitn�l nagyobb sz�mot keres�nk,
ami az adott f�jlban a lehet� legkisebb

ha nincs tal�lat, akkor visszat�r�si �rt�k 0
ha van tal�lat, akkor 1
a megtal�lt minimum pedig pointerrel lesz visszaadva
*/
int felteteles_minimum(FILE* f, int limit, int *legkisebb) {
	int van_talalat = 0;
	while (!feof(f)) {
		int szam;
		fscanf(f, "%d", &szam);
		
		// csak a limitn�l nagyobb �rt�kek sz�m�tanak
		if (szam > limit) {
			// ha els� beolvas�s, akkor az mindenk�pp j�
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
	// minimumkeres�s
	// f�jl megnyit�s
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

	// f�jl bez�r�s
	fclose(fbe);
	printf("min: %d\n", legkisebb);

	// kimenet
	FILE* fki = fopen("kimenet.txt", "w");

	int limit = legkisebb-1;
	while (1) {
		// k�vetkez� sz�m beolvas�sa
		int felt_minimum;
		fbe = fopen("bemenet.txt", "r");
		int siker = felteteles_minimum(fbe, limit, &felt_minimum);
		fclose(fbe);

		// ha elfogytak a sz�mok, akkor v�ge
		if (!siker) break;

		// ha nem fogytak m�g el, akkor �rjuk ki
		fprintf(fki, "%d\n", felt_minimum);

		// a k�vetkez� limit friss�t�se
		limit = felt_minimum;
	}

	fclose(fki);

	_getch();
	return 0;
}