#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void sulyok_feltolt(double *t, int n) {
	for (int i = 0; i < n; i++)
		t[i] = 1 - i * 0.2;
}

double ma(double* t, double* suly, double ujadat, int meret) {
	// elemek cs�sztat�sa, �j elem az elej�re
	for (int i = meret - 1; i > 0; i--)
		t[i] = t[i - 1];
	t[0] = ujadat;

	// line�ris kombin�ci� (suly vektor �s a t vektor skal�ris szorzata)
	double eredmeny=0;
	for (int i = 0; i < meret; i++)
		eredmeny += t[i] * suly[i];
	return eredmeny;
}

int main(void)
{
	// t�mb�k foglal�sa
	int n;
	printf("tomb merete: ");
	scanf_s("%d", &n);
	double* jel = (double*)malloc(n * sizeof(double));
	double* sulyok = (double*)malloc(n * sizeof(double));

	// s�lyok inicializ�l�sa
	sulyok_feltolt(sulyok, n);

	// jel t�mb inicializ�l�sa
	for (int i = 0; i < n; i++)
		jel[i] = 0;

	// egys�gugr�s hat�sa
	for (int i = 0; i < 20; i++) {
		printf("%g\n", ma(jel, sulyok, 1, n));
	}

	// felszabad�t�s
	free(jel);
	free(sulyok);

	return 0;
}