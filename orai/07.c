#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// makrók
#define ZARVA 0
#define NYITVA 1

void bin_kiir(unsigned char b) {
	printf("0b");
	for (int i = 0; i < 8; i++) {
		unsigned char tmp = b / pow(2, 7 - i);
		printf("%d", tmp % 2);
	}
	printf("\n");
}

int main(void)
{
	printf("hello MOGI\n");

	// adott szám kiírása kettes számrendszerben
	unsigned char b=92; // 1 byte adat, azaz 8 bit
						// 0..255
	for (int i = 0; i < 8; i++) {
		// kettes maradék kiírása
		printf("%d", b % 2);
		// felezzük a számot
		b /= 2;
	}
	printf("\n");

	// kiírás (MSB first)
	//for(int i=0; i<=255; i++)
	//	bin_kiir(i);

	// bitműveletek

	// negálás
	b = 92;
	unsigned char negalt = ~b;
	printf("NOT:\n");
	bin_kiir(b);
	bin_kiir(negalt);

	// bitenkénti és
	printf("AND:\n");
	unsigned char egyik = 23;
	unsigned char masik = 118;
	bin_kiir(egyik);
	bin_kiir(masik);
	bin_kiir(egyik & masik);

	// bitenkénti vagy
	printf("OR:\n");
	bin_kiir(egyik);
	bin_kiir(masik);
	bin_kiir(egyik | masik); // altgr+w

	// bitenkénti kizáró vagy
	printf("XOR:\n");
	egyik = 0b10100011; // bináris megadás
	masik = 0b00111100;
	bin_kiir(egyik);
	bin_kiir(masik);
	bin_kiir(egyik^masik);

	// shiftelés
	printf("shift:\n");
	bin_kiir(egyik);
	bin_kiir(egyik << 2);
	bin_kiir(egyik >> 3);

	// adott bit set
	int bit = 5; // ötös bitet akarjuk set-elni
	unsigned char reg = 0b10011101;
	reg |= (1 << bit); // reg = reg | (1<<bit)
	                   // reg = reg | 0b00100000
	                   //                ^maszk^
	bin_kiir(reg);

	// állapotgép: forgóvilla
	int allapot=ZARVA;
	while (1) {
		// aktuális állapot kiírása
		switch (allapot){
		case ZARVA:
			printf("allapot: zarva\n");
			break;
		case NYITVA:
			printf("allapot: nyitva\n");
			break;
		}

		// esemény beolvasása
		printf("0: atmegyek\n");
		printf("1: lehuzom a kartyam\n");
		printf("mit teszel? ");
		int esemeny;
		scanf("%d", &esemeny);

		// állapotátmenet
		switch (allapot){
		case ZARVA:
			// nyitás
			if (esemeny == 1)
				allapot = NYITVA;
			break;
		case NYITVA:
			// áthaladás
			if (esemeny == 0)
				allapot = ZARVA;
			break;
		}
	}

	_getch();
	return 0;
}