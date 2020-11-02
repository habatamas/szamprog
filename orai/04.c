#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(void){
	// randomgenerátor indítása
	time_t t = time(NULL);
	srand((unsigned int)t);

	// intervallum
	double min = -5;
	double max = 10;


	// 0..1 között (normáljuk)
	double szam = (double)rand() / RAND_MAX * (max - min) + min;
	printf("%f\n", szam);
	szam = (double)rand() / RAND_MAX * (max - min) + min;
	printf("%f\n", szam);
	szam = (double)rand() / RAND_MAX * (max - min) + min;
	printf("%f\n", szam);
	szam = (double)rand() / RAND_MAX * (max - min) + min;
	printf("%f\n", szam);
	szam = (double)rand() / RAND_MAX * (max - min) + min;
	printf("%f\n", szam);

	double osszeg_tort = 1231238.2;
	int osszeg = (int)(osszeg_tort+0.5);

	switch (osszeg % 10) {
		case 0:
		case 1:
		case 2:
			// lefele kerekítés
			osszeg -= osszeg % 10;
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			// 5-re kerekítünk
			osszeg -= osszeg % 10;
			osszeg += 5;
			break;
		default:
			// felfele kerekítünk
			osszeg -= osszeg % 10;
			osszeg += 10;
			break;
	}

	printf("osszeg: %d\n",osszeg);

	_getch();

	// http://github.com/habatamas/szamprog


	unsigned char adat = 21;
	// ezt toljuk el >> ennyivel
	// ezt toljuk el << ennyivel

	if (adat & (1 << 7)) printf("1"); else printf("0");
	if (adat & (1 << 6)) printf("1"); else printf("0");
	if (adat & (1 << 5)) printf("1"); else printf("0");
	if (adat & (1 << 4)) printf("1"); else printf("0");
	if (adat & (1 << 3)) printf("1"); else printf("0");
	if (adat & (1 << 2)) printf("1"); else printf("0");
	if (adat & (1 << 1)) printf("1"); else printf("0");
	if (adat & (1 << 0)) printf("1"); else printf("0");

	// 8 bitet
	char b0, b1, b2, b3, b4, b5, b6, b7;
	printf("irj be egy bin szamot: ");
	scanf("%c", &b7);
	scanf("%c", &b6);
	scanf("%c", &b5);
	scanf("%c", &b4);
	scanf("%c", &b3);
	scanf("%c", &b2);
	scanf("%c", &b1);
	scanf("%c", &b0);
	int eredmeny =
		(b0 == '0' ? 0 : 1) +
		(b1 == '0' ? 0 : 2) +
		(b2 == '0' ? 0 : 4) +
		(b3 == '0' ? 0 : 8) +
		(b4 == '0' ? 0 : 16) +
		(b5 == '0' ? 0 : 32) +
		(b6 == '0' ? 0 : 64) +
		(b7 == '0' ? 0 : 128);
	printf("%d\n", eredmeny);

	return 0;
}