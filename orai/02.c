// Visual Studio haszn�latakor ez a sor is kell:
#define _CRT_SECURE_NO_WARNINGS

// a forr�sk�d elej�n a program �ltal haszn�lt include-ok kellenek, pl:
#include <stdio.h>
// tov�bbi inculde-ok
// b�rmi

int main() {
	int egesz_szam=99;
	double tort = 3.14;

	printf("a valtozo erteke: %d a masik erteke:%g\n",egesz_szam,tort);


	int ev=2020, honap=9, nap=3; // 2020.09.14.
	printf("%d.%02d.%02d.\n",ev,honap,nap);

	// id�pont bek�r�se 3:14 form�tumban
	int ora, perc;
	printf("mikor szoljon az ebreszto: ");
	scanf("%d:%d", &ora, &perc);
	printf("ora: %d\n", ora);
	printf("perc: %d\n", perc);

	int beolvasott_egesz;
	float beolvasott_float;
	double beolvasott_double;
	
	printf("irj be egy egesz szamot: ");
	scanf("%d", &beolvasott_egesz); // &

	printf("irj be egy valos szamot: ");
	scanf("%f", &beolvasott_float); // &

	printf("irj be egy valos szamot: ");
	scanf("%lf", &beolvasott_double); // &
	
	printf("int: %d\nfloat: %f\ndouble: %f\n", beolvasott_egesz, beolvasott_float, beolvasott_double);

	return 0; // <- mindig kell, ez jelzi program sikeres fut�s�t
}