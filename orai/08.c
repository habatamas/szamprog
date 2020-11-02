#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int valami = 1; // globális változó

// dátum struktúra
struct datum {
	int ev;
	int honap;
	int nap;
};

void datum_kiir(struct datum d) {
	printf("%d.%02d.%02d\n", d.ev, d.honap, d.nap);
}

void duplaz(int *ptr) {
	(*ptr) *= 2;
}

double hatvany(double alap, unsigned int kitevo) {
	double eredmeny = 1;
	for (int i = 0; i < kitevo; i++)
		eredmeny *= alap;
	return eredmeny;
}


void tomb_kiir(int *tomb, int elemszam) {
	valami++;
	printf("{");
	for (int i = 0; i < elemszam; i++) {
		printf("%6d,", tomb[i]);
	}
	printf("}\n");
}

int main(void)
{
	valami = 0;
	struct datum ma; // itt jön létre a példány
	ma.ev = 2020;
	ma.honap = 10;
	ma.nap = 26;
	datum_kiir(ma);

	struct datum masolat;
	masolat = ma;
	datum_kiir(masolat);

	int a = 2;
	int b = 5;
	duplaz(&a);
	printf("%d\n",a);

	int db;
	printf("hany db szamot akarsz bevinni? ");
	scanf("%d", &db);
	int *szamok = (int*)malloc(db*sizeof(int));
	
	for (int i = 0; i < db; i++) {
		printf("%d. szam: ", i + 1);
		scanf("%d", szamok+i); // pointer aritmetika
	}

	tomb_kiir(szamok, db);

	printf("negyzetosszeg: %g\n", hatvany(a, 2)+ hatvany(b, 2));
	printf("%d\n", valami);
	free(szamok);
	return 0;
}