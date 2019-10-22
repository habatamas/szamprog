#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
	printf("%f\n", sin(1.567));
	printf("%f\n", sin(3.141592));
	printf("%f\n", tan(3.141592));
	printf("%f\n", log(100));
	printf("%f\n", log10(100));

	// egy nagy szám hány biten ábrázolható?
	int allapotok_szama = 100;
	printf("%f\n", log2(allapotok_szama));
	printf("%d\n", (int)ceil(log2(allapotok_szama))); // felfele kerekítés
	
	// komplex szám
	double im, re;
	printf("ird be a valos reszt: ");
	scanf("%lf", &re);
	printf("ird be a kepzetes reszt: ");
	scanf("%lf", &im);

	printf("z=%g+%gi\n", re, im);

	// trigonometrikus alak
	double r = sqrt(pow(re,2)+pow(im,2));
	printf("r=%g\n", r);
	double theta = atan2(im,re);
	printf("theta=%g [rad]\n", theta);

	double pi = acos(-1);
	printf("theta=%g [°]\n", theta*180/pi);
	printf("hello MOGI\n");

	_getch();
	return 0;
}