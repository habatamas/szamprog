#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

int g = 40; // globális változó
			// élettartam: létrejön a program indulásakor
			//			   megszűnik a program lefutása után
			// láthatóság: mindenki "látja"

void fv1() {
	int v = 2; // lokális változó
			   // élettartam: a függvényhíváshoz kötött
	           // láthatóság: csak az adott függvény látja
	printf("v: %d\n", v);
	printf("g: %d\n", g);
	g++;

	static int s = 0; // statikus változó
	                  // élettartama: oylan, mint a globális változóké
	                  // láthatósága: olyan, mint a lokális változóké
	printf("s: %d\n", s);
	s++;
}

void fv2() {
	int v = 3; // lokális változó
	printf("v: %d\n", v);
	printf("g: %d\n", g);
	g++;
}

int main(void){
	fv1();
	fv2();

	fv1();
	fv1();
	fv1();
	fv1();
	fv1();

	_getch();
	return 0;
}