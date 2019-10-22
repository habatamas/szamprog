#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	int szamlalo = 75*3;
	int nevezo = 75*19;

	// lnko v1.0
	int lnko = 1;
	for (int i = 1; i <= nevezo; i++) {
		if (szamlalo % i == 0 && nevezo % i == 0) {
			lnko = i;
		}
	}
	printf("lnko: %d\n", lnko);

	// lnko v2.0
	lnko = 1;
	for (int i = nevezo; i >= 1; i--) {
		if (szamlalo % i == 0 && nevezo % i == 0) {
			lnko = i;
			break;
		}
	}
	printf("lnko: %d\n", lnko);

	// Euklideszi algoritmus
	int egyik = szamlalo;
	int masik = nevezo;
	while (egyik!=masik) {
		if (egyik < masik) {
			masik -= egyik;
		} else {
			egyik -= masik;
		}
	}
	lnko = egyik;
	printf("lnko: %d\n", lnko);

	szamlalo /= lnko;
	nevezo /= lnko;
	printf("tort: %d/%d\n", szamlalo, nevezo);

	_getch();
	return 0;
}