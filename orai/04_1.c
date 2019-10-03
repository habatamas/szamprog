#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	int i = 1;
	while (i <= 10) {
		i++;
		if (i == 5) {
			break;
		}
		printf("%d\n", i);
	}

	printf("___________\n");
	i = 1;
	while (i <= 10) {
		i++;
		if (i == 5) {
			continue;
		}
		printf("%d\n", i);
	}

	// ikerprím
	int elozo_prim = 2;
	int ikerprimek_szama = 0;
	int szam = 3;
	while (ikerprimek_szama<=20) {
		int osztok_szama = 0;
		for (int i = 1; i <= szam; i++) {
			if (szam % i == 0)
				osztok_szama++;
			if (osztok_szama == 3) // opt.
				break;
		}
		if (osztok_szama == 2) { // prímet találtunk
			if (elozo_prim + 2 == szam) { // ikerprím
				ikerprimek_szama++;
				printf("%d es %d ikerprimek\n", elozo_prim, szam);
			}
			elozo_prim = szam;
		}
		szam++;
	}

	// 2018-as zh példa
	double osszeg = 0;
	double pontossag = 0.000001;
	int elojel = 1;
	i = 1;
	while(4.0 / i > pontossag/10) {
		osszeg += elojel * 4.0 / i;
		elojel *= -1;
		i+=2;
	}
	printf("osszeg: %f", osszeg);
	
	_getch();
	return 0;
}
