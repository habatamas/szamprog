#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	int a = 1, b = 2, tmp;
	printf("a=%d b=%d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);

	// osztópárok
	int szam = 123323;
	int osztok_szama = 0;
	for (int i = 1; i*i <= szam; i++) {
		if (szam % i == 0) {
			printf("%5d %5d\n", i, szam/i);
			osztok_szama += 2;
		}
	}
	printf("osztok szama: %d\n", osztok_szama);
	if (osztok_szama == 2) {
		printf("ez egy primszam\n");
	}

	// négyzetgyökszámolás
	double valami = 2;
	double int_min = 0;
	double int_mid;
	double int_max = valami;

	for (int i = 1; i <= 5000; i++) {
		// intervallum közepe
		int_mid = (int_min + int_max) / 2;
		
		// kiértékeljük
		if (int_mid * int_mid < valami) {
			// felső részintervallum kell
			int_min = int_mid;
		} else {
			// alsó részint.
			int_max = int_mid;
		}
	}
	printf("gyok 2 = %f\n", int_mid);

	// fibonacci számok
	int aktualis = 1;
	int kovetkezo = 1;
	for (int i = 1; i <= 10; i++) {
		// kiírjuk az aktuális tagot
		printf("%d\n", aktualis);

		// következő utáni kiszámolása
		int kovetkezo_utani = aktualis + kovetkezo;

		// lépegetés
		aktualis = kovetkezo;
		kovetkezo = kovetkezo_utani;
	}

	// prímgenerátor (első 10 prím)
	int primek_szama = 0;
	szam = 2;
	while (primek_szama < 10) {
		// szam prímszám?
		int osztok = 0;
		for (int i = 1; i <= szam; i++) {
			if (szam % i == 0) {
				osztok++;
			}
		}

		// ha prím, kiírjuk
		if (osztok == 2) {
			printf("%d\n", szam);
			primek_szama++;
		}

		szam++;
	}

	_getch();
	return 0;
}
