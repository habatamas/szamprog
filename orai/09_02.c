#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void sulyok_feltolt(double *t, int n) {
	for (int i = 0; i < n; i++)
		t[i] = 1 - i * 0.2;
}

double ma(double* t, double* suly, double ujadat, int meret) {
	// elemek csúsztatása, új elem az elejére
	for (int i = meret - 1; i > 0; i--)
		t[i] = t[i - 1];
	t[0] = ujadat;

	// lineáris kombináció (suly vektor és a t vektor skaláris szorzata)
	double eredmeny=0;
	for (int i = 0; i < meret; i++)
		eredmeny += t[i] * suly[i];
	return eredmeny;
}

int main(void)
{
	// tömbök foglalása
	int n;
	printf("tomb merete: ");
	scanf_s("%d", &n);
	double* jel = (double*)malloc(n * sizeof(double));
	double* sulyok = (double*)malloc(n * sizeof(double));

	// súlyok inicializálása
	sulyok_feltolt(sulyok, n);

	// jel tömb inicializálása
	for (int i = 0; i < n; i++)
		jel[i] = 0;

	// egységugrás hatása
	for (int i = 0; i < 20; i++) {
		printf("%g\n", ma(jel, sulyok, 1, n));
	}

	// felszabadítás
	free(jel);
	free(sulyok);

	return 0;
}