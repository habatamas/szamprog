#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int* minimum_keres(int* tomb, int meret) {
	int *legkisebb = tomb;
	for (int i = 0; i < meret; i++) {
		if (*tomb < *legkisebb)
			legkisebb = tomb;
		tomb++;
	}
	return legkisebb;
}

int* keres(int* tomb, int meret, int keresett) {
	for (int i = 0; i < meret; i++) {
		if (*tomb == keresett) {
			return tomb;
		}
		tomb++;
	}
	return NULL;
}

int main(void) {
	int t[] = { 6,2,1,8,2 };
	int* minimum = minimum_keres(t, 5);
	printf("min: %d\n", *minimum);
	printf("index: %d\n", minimum - t);
	printf("tomb kezdocime: %d\n", (int)t);
	printf("minimum kezdocime: %d\n", (int)minimum);

	int* talalat = keres(t, 5, 2);
	if (talalat != NULL) {
		printf("talalat helye: %d\n", talalat - t);
		int* kovetkezo = keres(talalat + 1, 5 - (talalat - t)-1, 2);

		printf("talalat helye: %d\n", kovetkezo - t);
	} else {
		printf("nincs talalat\n");
	}

	printf("hello MOGI\n");

	_getch();
	return 0;
}