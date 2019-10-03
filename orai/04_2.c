#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

struct datum {
	int ev;
	char ho;
	int nap;
};

int main(void)
{
	// struktúrák
	struct datum ma;
	ma.ev = 2019;
	ma.ho = 10;
	ma.nap = 3;

	printf("%d.%02d.%02d.\n", ma.ev, ma.ho, ma.nap);

	printf("irj be egy evet: ");
	scanf("%d", &(ma.ev));
	printf("%d.%02d.%02d.\n", ma.ev, ma.ho, ma.nap);

	// másolható
	struct datum masnap;
	masnap = ma;
	masnap.nap++;
	printf("%d.%02d.%02d.\n", masnap.ev, masnap.ho, masnap.nap);

	// összehas.
	if (ma.ev==masnap.ev && ma.ho==masnap.ho && ma.nap==masnap.nap) {

	}

	// tömbök
	int szamok[] = {1,2,3,4,5,6,7,8,9,10}; // 10 elemű tömb
	szamok[4] = 123;

	for (int i = 0; i < 10; i++)
		printf("%d, ", szamok[i]); printf("\n");

	// tömb másolása elemenként
	int szamok2[10];
	for (int i = 0; i < 10; i++)
		szamok2[i] = szamok[i];
	

	printf("hello MOGI\n");

	_getch();
	return 0;
}
