#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>


int main(void)
{
	// spec. karakterek ki�r�sa
	printf("hello\nworld"); printf("hello\tworld\n");
	printf("hello world\n");
	printf("hesdg world\n");

	// v�ltoz� deklar�l�s �s ki�r�s
	int valtozo = 123;
	printf("a valtozo erteke: %d\n", valtozo);

	// v�ltoz� �rt�k�nek m�dos�t�sa
	valtozo = 8;
	printf("a valtozo erteke: %d\n", valtozo);

	// egy�b t�pusok
	double x = 3.56273642;
	printf("x erteke: %f\n", x);
	char ch = 'M';
	printf("a karakter: %c\n", ch); // mag�t a karaktert
	printf("a karakter: %d\n", ch); // a karakter k�dja

	// beolvas�s
	int bemenet;
	printf("irj be egy szamot: ");
	scanf("%d", &bemenet);
	printf("a beolvasott ertek: %d\n", bemenet);

	double bemenet2;
	printf("irj be egy valos szamot: ");
	scanf("%lf", &bemenet2);
	printf("a beolvasott ertek: %f\n", bemenet2);

	// m�veletv�gz�s
	double szorzat;
	szorzat = bemenet * bemenet2;
	printf("szorzat: %f\n", szorzat);
	printf("osszeg: %f\n", bemenet+bemenet2);
	printf("kulonbseg: %f\n", bemenet - bemenet2);
	printf("hanyados: %f\n", bemenet / bemenet2);

	// eg�sz sz�mok oszt�sa �s marad�ksz�m�t�s
	printf("hetharmad: %d\n", 7 / 3);
	printf("maradek: %d\n", 7 % 3);

	// �tkasztol�s
	int a = 7, b = 3;
	printf("a/b=%f\n", (double)a / b);

	// ki�r�s opci�i
	printf("%d\n", 123);
	printf("%5d\n", 123);
	printf("%05d\n", 123);
	printf("%.2f\n", 3.141592);

	// t�bb dolog ki�r�sa
	printf("egyik: %d masik: %d hanyados: %d\n", a, b, a / b);

	// egyszer� feladat
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
