#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main(void)
{
	// sz�m oszt�i
	int szam;
	int i;
	int primek_szama = 0;

	szam = 2;

	while (primek_szama<100) {
		// pr�mteszt
		i = 2;
		int prim = 1; // 1: pr�msz�m 0: nem pr�msz�m
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