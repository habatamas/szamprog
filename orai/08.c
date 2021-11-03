#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

// üdvözlő függvény
void udvozlet() { // definíció
	printf("Hello MOGI!\n");
}

// egész számot hatványozó függvény a^b, b>=0
int hatvany(int a, int b) {
	int eredmeny = 1;
	for (int i = 0; i < b; i++)
		eredmeny *= a;
	return eredmeny;
}

// maradékos osztó függvény
int osztas(int osztando, int oszto, int maradek) {
	maradek = osztando % oszto; // nem csinál semmit :(
	return osztando / oszto;
}

int osztas_jo(int osztando, int oszto, int *maradek) {
	*maradek = osztando % oszto;
	return osztando / oszto;
}

// összeg
int tomb_osszeg(int tomb[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += tomb[i];
	return sum;
}

int tomb_osszeg2(int *tomb, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += tomb[i];
	return sum;
}

int tomb_osszeg3(int *ptr, int n) {
	int sum = 0;
	while(n>0){
		n--;
		sum += *ptr; // aktuálisan mutatott elem hozzáadása
		ptr++; // pointer léptetése
	}
	return sum;
}

int g = 0; // globális változó

// Fibonacci-sorozat
// fib(1)=fib(2)=1
// fib(n)=fib(n-1)+fib(n-2)
int fib(int n) {
	g++; // globális változó módosítása
	// n egy lokális változó
	if (n <= 2)
		return 1;
	return fib(n - 1) + fib(n - 2); // rekurzió!
}

int main(void) {
	g = 20;
	
	for (int i = 1; i <= 8; i++) {
		printf("fib(%d): %d\n", i, fib(i));
		printf("   g: %d\n", g);
	}

	udvozlet(); // hívás
	udvozlet();
	udvozlet();

	printf("2^10 = %d\n", hatvany(2, 10));

	int m=123;
	int h = osztas(15, 4, m);
	printf("15/4 = %d (maradek: %d)\n", h, m);

	h = osztas_jo(15, 4, &m);
	printf("15/4 = %d (maradek: %d)\n", h, m);

	int szam=123;
	scanf("%d", &szam);

	// pointer demo
	int a;
	a = 6;
	printf("a: %d\n", a);
	int *p;
	p = &a;
	*p = 8;
	printf("a: %d\n", a);

	// tömbkezelés demo
	int szamok[] = { 3,6,1,2 };
	int db = 4;
	printf("osszeg: %d\n", tomb_osszeg2(szamok, db));
	printf("osszeg: %d\n", tomb_osszeg3(szamok, db));

	int* ptr1 = szamok; // tömb kezdőcíme
	                    // &(szamok[0])
	int* ptr2 = &(szamok[2]);
	printf("int merete: %d byte\n", sizeof(int));
	printf("ptr1: %d\n", ptr1);
	printf("ptr2: %d\n", ptr2);
	// pointer aritmetika
	printf("ptr2-ptr1: %d\n", ptr2 - ptr1);
	ptr2++; // következő elemre mutat
	printf("*ptr2 = %d\n", *ptr2);

	_getch();
	return 0;
}