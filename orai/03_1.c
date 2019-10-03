#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	// régi ár bekérése
	int regi_ar;
	printf("ird be a termek arat: ");
	scanf("%d", &regi_ar);

	// új ár kiszámítása
	int uj_ar;
	regi_ar++;
	uj_ar = regi_ar/100;
	uj_ar *= 100; // !!!
	uj_ar += 99; // !!!

	// kiírjuk az új árat
	printf("az uj ar: %d\n", uj_ar);

	// óra:perc beolvasása
	int h, m;
	printf("irj be egy idopontot: ");
	scanf("%d:%d", &h, &m);
	printf("a beirt ora: %d perc: %d\n", h, m);

	_getch();
	return 0;
}
