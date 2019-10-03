#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

int main(void) {
	// for ciklus
	for (int i = 1; i <= 10; i++) {
		printf("i erteke: %d\n", i);
	}

	// számok 1-től 10-ig
	int i = 1;
	while (i <= 10) {
		printf("%d\n", i);
		i++;
	}

	// első 10 négyzetszám
	i = 1;
	while (i <= 10) {
		printf("%d\n", i*i);
		i++;
	}

	// egy szám osztói
	printf("123323 osztoi:\n");
	int szam = 123323;
	i = 1;
	while (i <= szam) {
		if (szam%i == 0) { // osztható a szám i-vel?
			printf("%d\n", i);
		}
		i++;
	}

	// ZH írás
	int jegy;
	int hanyadik_pot = 0;
	do {
		printf("hanyasra irtad a ");
		// ki kell írni sokszor a "pot" szót
		int i = 1;
		while (i<=hanyadik_pot) {
			printf("pot");
			i++;
		}
		printf("ZH - t ? ");
		scanf("%d", &jegy);
		hanyadik_pot++;
	} while(jegy<2);

	// switch-case
	printf("menu:\n");
	printf("1: beallitasok\n");
	printf("2: zh iras\n");
	printf("3: gepszerk begyakorlok megirasa\n");
	printf("4: 032-es kerveny\n");

	int valasztas;
	do {
		printf("valassz: ");
		scanf("%d", &valasztas);
		if (valasztas < 1 || valasztas>4) {
			printf("nincs ilyen menupont!!!\n");
		}
	} while (valasztas<1 || valasztas>4);

	switch (valasztas) {
		case 1:
			printf("404\n");
			break;
		case 2:
			printf("majd csak az 5. heten\n");
			break;
		case 3:
			printf("majd gyak elott az R109 elott\n");
			break;
		case 4:
			printf("majd csak potheten\n");
			break;
		default:
			printf("nincs ilyen menupont\n");
			break;
	}

	// PIN kód bekérése
	int beirt_pin;
	printf("ird be a PIN-kodot: ");
	scanf("%d", &beirt_pin);

	// helyes-e a beírt kód?
	if (beirt_pin == 1234) {
		printf("helyes\n");
	} else {
		printf("hibas\n");
	}

	printf("program vege\n");

	_getch();
	return 0;
}
