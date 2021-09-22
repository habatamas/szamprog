#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	// ZH írás
	int jegy;
	do {
		printf("hanyas ZH-t irtal? ");
		scanf("%d", &jegy);
	} while (jegy<2);

	// kiindulunk egy számból
	// ha páros, akkor felezzük
	// ha páratlan, akkor triplázzuk +1
	printf("irj be egy szamot: ");
	int a;
	scanf("%d", &a);
	while (a != 1) {
		printf("%d\n", a);
		if (a % 2 == 0)
			a /= 2; // ua. mint a = a/2;
		else
			a = 3 * a + 1;
	}

	// első 100 prímszám
	int primek_szama = 0;
	int szam2 = 1;
	while(primek_szama<100) {
		// feltételezzük, hogy az aktuális szám prím
		int primszam = 1;
		for (int i = 2; i * i <= szam2; i++) {
			if (szam2 % i == 0) {
				// de ha találunk osztót, akkor nem prím
				primszam = 0;
				break; // kiugrunk a ciklusból
			}
		}
		if (primszam && szam2 >= 2) {
			printf("   %d\n", szam2);
			primek_szama++;
		}
		szam2++;
	}

	// adott számnak az osztói, hány osztója van?
	printf("irj be szamot: ");
	int szam;
	int osztok_szama=0;
	scanf("%d", &szam);
	for (int i = 1; i <= szam; i++) {
		if (szam % i == 0) {
			printf("    osztoja: %d\n", i);
			osztok_szama++;
		}
	}
	printf("osztok szama: %d\n", osztok_szama);
	if (osztok_szama == 2)
		printf("ez egy primszam\n");
	else
		printf("ez nem primszam\n");

	// 1-100-ig egész számok összege
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i; // ua: sum = sum + i;
	}
	printf("szamok osszege 1..100-ig: %d\n", sum);

	// választási lehetőség (pl. menürendszernél)
	printf("1. menupont: Szamprog\n");
	printf("2. menupont: Gepszerk\n");
	printf("3. menupont: Matematika G1\n");
	printf("Milyen orad lesz? ");

	int valasztas;
	scanf("%d", &valasztas);

	switch(valasztas){
	case 1:
		printf("szintaxishiba\n");
		break;
	case 2:
		printf("konturhiba\n");
		break;
	case 3:
		printf("ora eleji idezet\n");
		break;
	default:
		printf("nincs ilyen opcio\n");
		break;
	}

	// számok 1-10
	int cnt = 1;
	while (cnt <= 10) {
		printf("%d\n", cnt);
		cnt++;
	}
	

	printf("ugyanez for ciklussal:\n");
	for (int i = 1; i <= 10; i++)
		printf("%d\n", i);

	// PIN kód beolvasás
	int beirt_pin;
	printf("PIN: ");
	scanf("%d", &beirt_pin);

	// feltételes elágazás
	if (beirt_pin == 1871) {
		printf("Helyes PIN kod.\n");
	} else {
		printf("Hibas PIN kod.\n");
	}


	_getch();
	return 0;
}