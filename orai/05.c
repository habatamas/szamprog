#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main(void)
{
	// szám osztói
	int szam;
	int i;
	int primek_szama = 0;

	szam = 2;

	while (primek_szama<100) {
		// prímteszt
		i = 2;
		int prim = 1; // 1: prímszám 0: nem prímszám
		while (i * i <= szam) {
			if (szam % i == 0) {
				prim = 0;
				break;
			}
			i++;
		}
		if (prim) {
			primek_szama++;
			printf("%d\n",szam);
		}

		szam++;
	}

	return 0;
}