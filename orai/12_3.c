#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

int lnko(int a, int b) {
	int lnko;
	for (int i = 1; i <= (a + b); i++) {
		if (a % i == 0 && b % i == 0)
			lnko = i;
	}
	/// hiányzik a return, errõl még warningot is kaptál
	return lnko;
}


char* beolvas() {
	// üres sztring
	char* str = malloc(1);
	*str = '\0';

	while (1) {
		char ch;
		scanf("%c", &ch);

		if (ch == '\n')
			break;

		int n = strlen(str); // régi hossz
		// új terület foglalása
		char* uj_str = malloc(n + 2);
		strcpy(uj_str, str); // régi másolása
		uj_str[n] = ch; // karakter hozzáffûz
		uj_str[n + 1] = '\0'; // lezáró nulla
		free(str);
		str = uj_str;
	}

	return str;
}

int main(void)
{

	printf("lnko %d\n", lnko(120 * 7, 120 * 123323));
	char helyes_jelszo[] = "mogi";
	char *beirt_jelszo;

	while (1) {
		printf("ird be a jelszot: ");
		beirt_jelszo = beolvas();

		if (strcmp(beirt_jelszo, helyes_jelszo) == 0) {
			free(beirt_jelszo);
			break;
		}
		free(beirt_jelszo);

		printf("Hibas jelszo! Probald ujra!\n");
	}

	printf("A jelszo helyes.\n");

	_getch();
	return 0;
}