#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	// spec. karakterek kiírása
	printf("hello\nworld"); printf("hello\tworld\n");
	printf("hello world\n");
	printf("hesdg world\n");

	// változó deklarálás és kiírás
	int valtozo = 123;
	printf("a valtozo erteke: %d\n", valtozo);

	// változó értékének módosítása
	valtozo = 8;
	printf("a valtozo erteke: %d\n", valtozo);

	// egyéb típusok
	double x = 3.56273642;
	printf("x erteke: %f\n", x);
	char ch = 'M';
	printf("a karakter: %c\n", ch); // magát a karaktert
	printf("a karakter: %d\n", ch); // a karakter kódja

	// beolvasás
	int bemenet;
	printf("irj be egy szamot: ");
	scanf("%d", &bemenet);
	printf("a beolvasott ertek: %d\n", bemenet);

	double bemenet2;
	printf("irj be egy valos szamot: ");
	scanf("%lf", &bemenet2);
	printf("a beolvasott ertek: %f\n", bemenet2);

	// mûveletvégzés
	double szorzat;
	szorzat = bemenet * bemenet2;
	printf("szorzat: %f\n", szorzat);
	printf("osszeg: %f\n", bemenet+bemenet2);
	printf("kulonbseg: %f\n", bemenet - bemenet2);
	printf("hanyados: %f\n", bemenet / bemenet2);

	// egész számok osztása és maradékszámítás
	printf("hetharmad: %d\n", 7 / 3);
	printf("maradek: %d\n", 7 % 3);

	// átkasztolás
	int a = 7, b = 3;
	printf("a/b=%f\n", (double)a / b);

	// kiírás opciói
	printf("%d\n", 123);
	printf("%5d\n", 123);
	printf("%05d\n", 123);
	printf("%.2f\n", 3.141592);

	// több dolog kiírása
	printf("egyik: %d masik: %d hanyados: %d\n", a, b, a / b);

	// egyszerû feladat
	int osztando, oszto;
	printf("irj be egy egesz szamot: ");
	scanf("%d", &osztando);
	printf("irj be egy masik egesz szamot: ");
	scanf("%d", &oszto);

	printf("hanyados: %d\n", osztando / oszto);
	printf("maradek: %d\n", osztando % oszto);


	_getch();
	return 0;
}
