#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h> // random generáláshoz kell
#include <time.h> // ez is


int main(void)
{
	// véletlenszámgenerálás
	srand(time(NULL)); // randomgenerátor "indítása"

	int random1 = rand(); // 0..RAND_MAX
	printf("%d\n", random1);
	printf("%d\n", rand());
	printf("%d\n", rand());

	// dobókocka
	int dobokocka = rand() % 6 + 1; // 1..6
	printf("dobokocka: %d\n", dobokocka);

	// adott intervallumon double
	double random_norm = (double)rand() / RAND_MAX;
	printf("normalt random: %f\n", random_norm);
	double min = 3, max = 9;
	double veletlen =
		(double)rand() / RAND_MAX * (max - min) + min;
	printf("veletlen: %f\n", veletlen);


	// matematikai függvények, math.h
	double gyokketto = sqrt(2); // négyzetgyök
	double a = pow(1.5, 9); // 1.5 a 9-iken
	int b = abs(-12); // egész szám abszolútértéke
	double c = fabs(-0.5); // valós szám abszlútértéke

	printf("sin(0.5)=%f\n", sin(0.5));
	printf("hello MOGI\n");
	
	float egyik=0.1, masik=1.0/10;
	if (egyik == masik) {
		// nem biztos, hogy teljesül
		printf("egyenlo\n");
	}
	if (fabs(egyik - masik) <= 0.00001) {
		// hibahatár figyelmbe van véve
		printf("majdnem egyenlo\n");
	}

	// komplex számok
	// algebrai -> trig
	// adatok bekérése
	double re, im;
	printf("Ird be a komplex szam valos reszet: ");
	scanf("%lf", &re);
	printf("Ird be a komplex szam kepzetes reszet: ");
	scanf("%lf", &im);

	// átalakítás trigonometrikus alakra
	double rho = sqrt(pow(re,2) + pow(im,2));
	double theta = atan2(im, re);

	// eredmény kiírása
	printf("rho=%f\n", rho);
	printf("theta = %f [rad] = %f [deg]\n",
		theta, theta * 180 / M_PI);
	
	_getch();
	return 0;
}