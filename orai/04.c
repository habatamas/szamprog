#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

// struktúra: mintha saját típus
struct idopont {
	int ora;
	int perc;
	int masodperc;
};

int main(void){
	// struktúrák
	struct idopont most;
	most.ora = 12;
	most.perc = 50;
	most.masodperc = 8;

	// időpont kiírása
	printf("%d:%d:%d\n", most.ora, most.perc, most.masodperc);

	// értékadás
	struct idopont masik;
	masik = most; // értékadás egyszerre
	printf("%d:%d:%d\n", masik.ora, masik.perc, masik.masodperc);

	// tömbkezelés
	double szamok[5];
	szamok[0] = 3.14;
	szamok[1] = 9.012;
	szamok[2] = -2;
	szamok[3] = 55;
	szamok[4] = 0;
	// ne címezzünk túl: szamok[5] !!!!
	// ne címezzünk alul: szamok[-1] !!!!
	
	// tömb kiírása
	printf("a tomb elemei:\n");
	for (int i = 0; i < 5; i++) {
		printf(" %f\n", szamok[i]);
	}

	// tömb másolása
	double tomb2[5];
	// hibás: tomb2 = szamok;
	for (int i = 0; i < 5; i++)
		tomb2[i] = szamok[i];

	// minimumkeresés
	int n = 5;
	double tomb3[] = {9, 2, 6, -2.2, 8};

	double min = tomb3[0];
	for (int i = 1; i < n; i++) {
		// i-edik elem kisebb-e mint az eddigi minimum?
		if (tomb3[i] < min) {
			min = tomb3[i];
		}
	}
	printf("min: %f\n", min);

	// összeg és átlagszámítás
	double sum=0;
	for (int i = 0; i < n; i++)
		sum += tomb3[i];
	printf("osszeg: %f\n", sum);
	printf("atlag: %f\n", sum / n);

	// buborékrendezés O(n^2)
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n - j - 1; i++) {
			// i-edik és az i+1-edik elem összehasonlítása
			if (tomb3[i] > tomb3[i + 1]) {
				// csere
				double tmp = tomb3[i];
				tomb3[i] = tomb3[i + 1];
				tomb3[i + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%f\t", tomb3[i]);
	return 0;
}