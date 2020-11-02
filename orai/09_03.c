#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// tankolás struktúra
struct tankolas {
	int km;
	double liter;
};

int main(void)
{
	struct tankolas t;
	t.km = 12;
	t.liter = 12313;

	// tömb létrehozása
	int n;
	printf("hanyszor tankolsz? ");
	scanf_s("%d", &n);
	struct tankolas* tankolasok =
		(struct tankolas*)malloc(n*sizeof(struct tankolas));
	for (int i = 0; i < n; i++) {
		int km;
		do {
			printf("kilometerora allasa: ");
			scanf_s("%d", &km);
		} while (i>0 && tankolasok[i-1].km > km);
		double liter;
		printf("tankolt mennyiseg: ");
		scanf_s("%lf", &liter);

		tankolasok[i].km = km;
		tankolasok[i].liter = liter;
	}

	// fogyasztások
	for (int i = 1; i < n; i++) {
		int megtett_km = tankolasok[i].km - tankolasok[i - 1].km;
		double fogyasztas = tankolasok[i].liter;

		printf("fogyasztas: %g\n", fogyasztas / megtett_km * 100);
	}


	free(tankolasok);

	return 0;
}