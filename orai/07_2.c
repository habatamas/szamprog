#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void) {
	unsigned char a = 135;
	unsigned char b = ~a;
	unsigned char c = 0b00110100;

	// 
	unsigned char maszk = 0b01101000; // melyik biteken v�gezze a m�veletet?
	unsigned char d = c | maszk; // n�h�ny bit 1-re �ll�t�sa
	unsigned char e = c & (~maszk); // n�h�ny bit 0-ra �ll�t�sa
	unsigned char f = c ^ maszk; // n�h�ny bit invert�l�sa

	while (c != 0) {
		printf("%d", c % 2);
		c /= 2;
	}
	printf("\n");

	while (a != 0) {
		printf("%d", a % 2);
		a /= 2;
	}
	printf("\n");


	while (b != 0) {
		printf("%d", b % 2);
		b /= 2;
	}
	printf("\n");

	printf("hello MOGI\n");

	_getch();
	return 0;
}