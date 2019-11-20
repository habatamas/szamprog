#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

#define BEKAPCSOLVA 1
#define KIKAPCSOLVA 0

int main(void)
{
	int futes = 0;
	double tbe = 22;
	double tki = 26;

	while (1) {
		printf("T? ");
		double T;
		scanf("%lf", &T);

		if (T < tbe && futes==KIKAPCSOLVA) {
			printf("BE\n");
			futes = 1;
			continue;
		}

		if (T < tbe && futes==BEKAPCSOLVA) {
			continue;
		}

		if (T > tki && futes==BEKAPCSOLVA) {
			printf("KI\n");
			futes = 0;
			continue;
		}

		if (T > tki && futes==KIKAPCSOLVA) {
			continue;
		}
	}

	_getch();
	return 0;
}