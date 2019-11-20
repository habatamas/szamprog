#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

int glob = 0; // ez egy globális változó

void statikus_teszt() {
	static int s = 0;
	printf("%d\n", s);
	s++;
}

double szoroz(double a, double b) {
	glob++;
	double eredmeny = a*b;
	return eredmeny;
}

void udvozlet() {
	glob++;
	printf("hello MOGI\n");
}

// érték szerinti paraméterátadás
void inkremental(int szam) {
	szam++;
}

// osztás: hányados és maradék
struct eredmeny {
	int hanyados, maradek;
};

struct eredmeny osztas(int osztando, int oszto) {
	struct eredmeny ret;
	ret.hanyados = osztando / oszto;
	ret.maradek = osztando % oszto;
	return ret;
}

int osztok_szama(int szam) {
	int szamlalo = 0;
	for (int i = 1; i <= szam; i++) {
		if (szam % i == 0) {
			szamlalo++;
		}
	}
	return szamlalo;
}

int primteszt(int szam) {
	if (osztok_szama(szam) == 2) {
		return 1;
	}
	return 0;
}

void ikerprim_generalas(int eddig) {
	for (int i = 2; i <= eddig-2; i++) {
		if (primteszt(i) && primteszt(i + 2)) {
			printf("%d - %d\n", i, i + 2);
		}
	}
}

// rekurzió
int fib(int index) {
	if (index < 2)
		return 1;
	return fib(index - 1) + fib(index - 2);
}

// faktoriális
int fakt(int n) {
	if (n == 0)
		return 1;
	return n * fakt(n - 1);
}

int main() {
	for (int i = 0; i < 10; i++)
		printf("fib: %d\n", fib(i));

	statikus_teszt();
	statikus_teszt();
	statikus_teszt();

	ikerprim_generalas(100);
	printf("%d\n", osztok_szama(120));

	printf("glob: %d\n", glob);
	udvozlet();
	printf("glob: %d\n", glob);
	
	struct eredmeny e = osztas(9, 4);
	printf("hanyados: %d\n", e.hanyados);
	printf("maradek: %d\n", e.maradek);
	
	double x = 6.5, y = -4;
	printf("%f\n", szoroz(x, y));
	printf("glob: %d\n", glob);

	int valami = 7;
	inkremental(valami);
	printf("%d\n", valami);

	_getch();
	return 0;
}