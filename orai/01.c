#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	// ez egy kiírás
	printf("hello MOGI\n");
	printf("hello MM\n");
	
	// github.com/habatamas/szamprog

	// formázás
	printf("%04d\n", 5); // vezető nullák
	printf("%4d\n", 5); // szóközökkel kitöltés
	printf("%.2f\n", 3.141592); // tizedesjegyek száma

	// változók
	int szam; // deklaráció
	szam = 11.5; // értékadás
	printf("a valtozo erteke: %i ....\n", szam);
	printf("a asdtozo erteke: %d ....\n", szam);
	printf("a valtozo erteke: %x ....\n", szam);

	int masik = 21;
	printf("egyik: %d masik: %d\n", szam, masik);

	// valós számok
	float a = 3.14;
	double b = 3.14;

	printf("a: %f b: %f\n", a, b);

	// beolvasás
	int beolvasott;
	printf("irj be egy egesz szamot: ");
	scanf("%d", &beolvasott);
	printf("ezt irtad be: %d\n", beolvasott);

	/*
	float be2;
	printf("irj be egy valos szamot: ");
	scanf("%f", &be2);
	printf("ezt irtad be: %f\n", be2);

	double be3;
	printf("irj be egy valos szamot: ");
	scanf("%lf", &be3);
	printf("ezt irtad be: %f\n", be3);
	*/

	// derékszögű háromszög területe
	double befogo1, befogo2;
	printf("Ird be az egyik befogo hosszat: ");
	scanf("%lf", &befogo1);
	printf("Ird be a masik befogo hosszat: ");
	scanf("%lf", &befogo2);

	double T = (befogo1 * befogo2) / 2;
	printf("A terulet: %f (t.e.)\n", T);
	printf("A terulet: %f (t.e.)\n", (befogo1 * befogo2) / 2);

	// egész szám osztás
	int x = 7, y = 3;
	printf("7/3=%d es a maradek: %d\n", x / y, x%y);


	return 0;
}