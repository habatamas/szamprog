#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

void inkremental(int *szam) {
	(*szam)++;
}

void tomb_kiir(int *t, int db) {
	for (int i = 0; i < db; i++)
		printf("%d ", t[i]);
	printf("\n");
}

void tomb_kiir2(int* t, int db) {
	for (int i = 0; i < db; i++) {
		printf("%d ", *t);
		t++;
	}
	printf("\n");
}

int main(void) {
	int szam = 15;
	scanf("%d", &szam);
	inkremental(&szam);
	printf("szam: %d\n", szam);
	printf("hello MOGI\n");

	int a = 4;

	int* p = &a;

	*p = 9;

	printf("%d\n", a);

	int szamok[] = { 2,6,1,7,2 };
	tomb_kiir(szamok, 5);
	tomb_kiir2(szamok, 5);

	_getch();
	return 0;
}