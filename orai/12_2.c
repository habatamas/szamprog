#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

char* sorbeolvas(FILE *f) {
	int meret = 10; // lefoglalt memóriaterület mérete
	char* sor = (char*)malloc(meret); // hely a lezáró \0-nak
	int n = 0; // hány karaktert olvastunk be eddig

	while (1) {
		// 1 db karakter beolvasása
		char ch;
		int siker = fscanf(f, "%c", &ch);

		// vége a fájlnak
		if (siker != 1 && n == 0) {
			free(sor);
			return NULL;
		}

		// kilépési feltétel: sor vége van
		if (ch == '\n' || siker!=1)
			break;

		// foglalt terület "megnövelése"
		if (n + 2 > meret) {
			int uj_meret = meret + 10;
			char* uj = malloc(uj_meret); // új terület foglalása
			memcpy(uj, sor, n); // régi adatok átmásolása
			free(sor); // régi terület felszabadítása
			sor = uj; // pointer frissítése
			meret = uj_meret; // méret frissítése
		}

		// új adat beírása
		sor[n] = ch;
		n++;
	}

	// lezáró nulla
	sor[n] = '\0';

	// visszatérés
	return sor;
}

int main(void){
	// jelszavas beléptetés
	char jelszo[] = "mogi2021";
	char *beirt=NULL;

	do {
		printf("Jelszo: ");
		free(beirt);
		beirt = sorbeolvas(stdin);
	} while (strcmp(beirt, jelszo)!=0);

	free(beirt);

	printf("Helyes jelszo.\n");

	// fájl beolvasása
	FILE* f = fopen("adatok.txt", "r");
	
	char* sor;
	while(1) {
		// megpróbál beolvasni egy sort
		sor = sorbeolvas(f);

		// ha vége a fájlnak, akkor kész
		if (sor == NULL)
			break;

		printf("sor: %s\n", sor);
		free(sor);
	}

	// fájl lezárása
	fclose(f);

	return 0;
}