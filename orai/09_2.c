#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main(void) {
	// f�jl nyit�sa �r�sra
	FILE* f = fopen("teszt.txt", "r");
	int minimum;
	fscanf(f, "%d", &minimum);

	while(1) {
		// sz�m beolvas�sa
		int szam;
		int siker = fscanf(f, "%d", &szam);

		// ha nem siker�lt a beolvas�s, akkor v�ge
		if (siker != 1) break;

		if (szam < minimum) {
			minimum = szam;
		}
	}

	printf("min: %d\n", minimum);

	fclose(f);

	FILE *fki = fopen("fuggvenytabla.txt", "w");
	for (double x = 0; x <= 2 * acos(-1); x += 0.1) {
		fprintf(fki, "%10.1f    %10.4f\n", x, sin(x));
	}
	fclose(fki);

	FILE* fbe = fopen("fuggvenytabla.txt", "r");
	double x = 2.05;

	double sinx, elozo_sinx;
	double tabla_x, elozo_tabla_x;
	
	while (1) {
		// sor beolvas�sa
		fscanf(fbe, "%lf %lf", &tabla_x, &sinx);

		// meghaladtuk a keresett helyet?
		if (tabla_x > x) break;

		// l�ptet�s
		elozo_tabla_x = tabla_x;
		elozo_sinx = sinx;
	}

	// s�lyok
	double beta = (x-elozo_tabla_x) / (tabla_x-elozo_tabla_x);
	double alfa = 1 - beta;
	double eredmeny = alfa * sinx + beta * elozo_sinx;



	fclose(fbe);

	printf("elozo_sinx=%f\n", elozo_sinx);
	printf("eredmeny=%f\n", eredmeny);
	printf("sinx=%f\n", sinx);
	printf("sin(%f)=%f\n", x, sin(x));

	_getch();
	return 0;
}