#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	// pointerek
	int a = 6;
	int* p;
	p = &a;
	*p = 8;
	printf("%d\n", a);


	// tömb
	int szamok[4] = {9,6,1,2};
	int masolat[4];
	
	for (int* p = szamok; p - szamok < 4; p++) {
		printf("%d\n", *p);
	}

	int* ptr = szamok;
	int* ptr2 = &(szamok[3]);
	printf("%d\n",ptr2 - ptr);
	
	ptr++; // 4-gyel növeli a címet, mert sizeof(int)=4
	printf("%d\n", *ptr);
	

	printf("szamok: %d\n", szamok);
	printf("0. elem cime: %d\n", &(szamok[0]));
	printf("1. elem cime: %d\n", &(szamok[1]));
	printf("2. elem cime: %d\n", &(szamok[2]));
	printf("3. elem cime: %d\n", &(szamok[3]));

	// buborékrendezés
	int meret = 4;
	// végigmegyünk páronként
	for (int j = 0; j < meret; j++) {
		for (int i = 0; i < meret - 1; i++) {
			// csere, ha szükséges
			if (szamok[i] > szamok[i + 1]) {
				// csere
				int tmp = szamok[i];
				szamok[i] = szamok[i + 1];
				szamok[i + 1] = tmp;
			}
		}
	}

	int eddigi_legnagyobb = szamok[0];
	for (int i = 1; i < 4; i++) {
		if (szamok[i] > eddigi_legnagyobb)
			eddigi_legnagyobb = szamok[i];
	}
	printf("max: %d\n", eddigi_legnagyobb);


	// adott elem keresése
	int keresett = 1234;
	int van_talalat = 0;
	int i;
	for (i = 0; i < 4; i++) {
		if (szamok[i] == keresett) {
			printf("talalat: %d\n", i);
			van_talalat = 1;
		}
	}
	if (van_talalat==0)
		printf("nincs talalat\n");


	return 0;
}