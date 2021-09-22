#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef unsigned char byte; // ez egy 8 bites sz�m, 0..255
// char t�pus: 8 bites, -128..127



int main(void)
{
	byte a = 0b00010010; // bin�ris
	byte b = 0b10111000; // hexa
	// �s      0001 0000     10
	// vagy    1011 1010     ba
	// xor     1010 1010     aa
	// ~a      1110 1101     ed
	// a<<2    0100 1000     48
	// a>>2    0000 0100     04

	printf("%d\n%d\n", a, b);
	printf("%x\n%x\n", a, b);

	byte eredmeny;
	eredmeny = a & b;
	eredmeny = a | b;
	eredmeny = a ^ b;
	eredmeny = ~a;
	eredmeny = a << 2;
	eredmeny = a >> 2;

	// maszk: azt mondja meg, hogy melyik biteken
	// v�gezz�k el az al�bbi m�veletek valamelyik�t:
	//		adott bitek be�ll�t�sa 1-re (set)
	//		adott bitek t�rl�se (0-ra �ll��s, reset/clear)
	//		adott bitek megford�t�sa (toggle)

	byte c =     0b11010110;
	byte maszk = 0b00011001; 
	// set       0b1101 1111  0xdf
	// ~maszk    0b1110 0110  0xe6
	// clear     0b1100 0110  0xc6
	// toggle    0b1100 1111  0xcf

	// 0&a = 0
	// 1&a = a

	byte eredmeny_set = c | maszk;
	byte eredmeny_clear = c & (~maszk);
	byte eredmeny_toggle = c ^ maszk;

	// adott sz�m� biten m�veletv�gz�s
	byte eredmeny_5_set = c | (1 << 5); // maszk: 0b00100000
	byte eredmeny_5_clear = c & ~(1 << 5); // ~(1 << 5)  ==  ~0b00100000 == 0b11011111
	byte eredmeny_5_toggle = c ^ (1 << 5);

	
	// 2-es bit: LED
	// 3-�s bit: rak�ta kil�v�se
	byte vezerlo_regiszter = 0b00000000;

	// feladat: LED bekapcsol�sa
	vezerlo_regiszter |= (1 << 2); // maszk: 0b00000100
	// elvi hiba: vezerlo_regiszter = vezerlo_regiszter + (1 << 2);

	// vil�g�t-e LED?
	if (vezerlo_regiszter & (1<<2) ) {
		printf("LED vilagit\n");
	} else {
		printf("LED nem vilagit\n");
	}

	// kil�tt�k-e a rak�t�t?
	if (vezerlo_regiszter & (1 << 3)) {
		printf("raketa kilove\n");
	}
	else {
		printf("raketa nincs kilove\n");
	}

	// vezerlo_regiszter bin�risan
	printf("vezerlo_regiszter = 0b");

	if (vezerlo_regiszter & (1 << 7)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 6)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 5)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 4)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 3)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 2)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 1)) printf("1"); else printf("0");
	if (vezerlo_regiszter & (1 << 0)) printf("1"); else printf("0");

	// ezt senki ne haszn�lja:
	printf("\n0b%d%d%d%d%d%d%d%d\n", 
		vezerlo_regiszter / 128 % 2,
		vezerlo_regiszter / 64 % 2,
		vezerlo_regiszter / 32 % 2,
		vezerlo_regiszter / 16 % 2,
		vezerlo_regiszter / 8 % 2,
		vezerlo_regiszter / 4 % 2,
		vezerlo_regiszter / 2 % 2,
		vezerlo_regiszter%2
		);

	// komplex sz�m trig -> alg
	double r = 3;
	double theta = 3.5;

	// algebrai alak
	double im = r * sin(theta);
	double re = r * cos(theta);
	// arctan(im/re) =  theta

	// alg -> trig
	double r2 = sqrt(re*re + im*im);
	double theta2 = atan2(im,re);

	return 0;
}