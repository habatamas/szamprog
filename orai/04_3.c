#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	int hossz = 10;
	int szamok[] = { 1,7,12,5,1,7,3,61,9,1 };

	// elem keresése
	int keresendo = 2432;
	int talalat_index = -1;
	for (int i = 0; i < hossz; i++) {
		if (szamok[i] == keresendo) {
			printf("%d helye a tombben: %d\n", keresendo, i);
			talalat_index = i;
			break; // első találat
		}
	}
	printf("talalat: %d\n", talalat_index);

	// minimum és maximumkeresés
	int maximum = szamok[0];
	int maximumhely = 0;
	for (int i = 0; i < hossz; i++)
		if (szamok[i] > maximum) {
			maximum = szamok[i];
			maximumhely = i;
		}
	printf("legnagyobb elem: %d @ %d\n", maximum, maximumhely);

	// összegzés, szorzat
	int osszeg = 0;
	int szorzat = 1;
	for (int i = 0; i < hossz; i++) {
		osszeg += szamok[i];
		szorzat *= szamok[i];
	}
	printf("osszeg: %d\n", osszeg);
	printf("szorzat: %d\n", szorzat);

	// buborékrendezés
	for (int j = 0; j < hossz; j++) {
		for (int i = 0; i <= hossz - 2; i++) {
			// hibás a sorrend?
			if (szamok[i] > szamok[i + 1]) {
				// csere
				int tmp = szamok[i];
				szamok[i] = szamok[i + 1];
				szamok[i + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < hossz; i++) {
		printf("%d, ", szamok[i]);
	}

	_getch();
	return 0;
}
