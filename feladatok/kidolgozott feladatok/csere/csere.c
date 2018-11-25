#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// sor beolvasása fájlból dinamikusan
char *sor_beolvas(FILE *file) {
	// helyfoglalás a sornak
	int meret = 10;
	char *sor = (char*)malloc(meret);
	int hossz = 0;

	// beolvasás, amíg lehet
	while (1) {
		// beolvasás
		char ch;
		int siker = fscanf(file, "%c", &ch);

		// speciális eset: nem tudunk semmit beolvasni
		if (siker != 1 && hossz == 0) {
			// memória felszabadítása
			free(sor);
			// ilyenkor NULL-al térünk vissza
			return NULL;
		}

		// ha vége a fájlnak vagy a sornak, akkor nem folytatjuk
		if (ch == '\n' || siker != 1)
			break;

		// ha a sor betelt (lezáró nullával együtt), nagyobb hely foglalása
		if (hossz + 1 == meret) {
			int uj_meret = meret + 10;
			char *uj_sor = (char*)malloc(uj_meret); // új tömb foglalása
			memcpy(uj_sor, sor, meret); // régi adatok átmásolása
			free(sor); // régi tömb felszabadítása
			sor = uj_sor; // sor frissítése
			meret = uj_meret; // méret frissítése
		}

		// karakter hozzáírása a tömbhöz
		sor[hossz] = ch;
		hossz++;
	}

	// sztring lezárása és visszatérés
	sor[hossz] = '\0';
	return sor;
}

// keresés és csere sztringben -> dinamikusan foglal sztringet
char *csere(char *forras, char *mit, char *mire) {
	// elõfordulások száma
	int hanyszor = 0;
	char *munkapeldany = forras; // munkapéldány készítése
	while (strstr(munkapeldany, mit) != NULL) {
		munkapeldany = strstr(munkapeldany, mit) + strlen(mit);
		hanyszor++;
	}

	// célsztring foglalása
	char *cel = (char *)malloc(strlen(forras) + hanyszor * (strlen(mire) - strlen(mit)) + 1); // lezáró nullának is kell hely!

	// csere elvégzése
	*cel = '\0';
	char *talalat = strstr(forras, mit);
	while (talalat != NULL) {
		strncat(cel, forras, talalat - forras);
		strcat(cel, mire);
		forras = talalat + strlen(mit);
		talalat = strstr(forras, mit);
	}
	strcat(cel, forras);

	// visszatérés a foglalt sztringgel
	return cel;
}

int main(void)
{
	// adatok beolvasása
	printf("Forrasfajl neve: ");
	char *bemenet_fajlnev = sor_beolvas(stdin);
	printf("Cserelendo kifejezes: ");
	char *keresendo = sor_beolvas(stdin);
	printf("Erre cserelje: ");
	char *cserekifejezes = sor_beolvas(stdin);
	printf("Kimeneti fajl neve: ");
	char *kimenet_fajlnev = sor_beolvas(stdin);

	// fájlok megnyitása
	FILE *bemenet_fajl = fopen(bemenet_fajlnev, "r");
	FILE *kimenet_fajl = fopen(kimenet_fajlnev, "w");

	// soronként beolvasás
	char *sor = sor_beolvas(bemenet_fajl);
	while (sor != NULL) {
		// csere
		char *uj_sor = csere(sor, keresendo, cserekifejezes);

		// kiírás fájlba
		fprintf(kimenet_fajl, "%s\n", uj_sor);

		// felszabadítás
		free(uj_sor);
		free(sor);

		// következõ sor beolvasása
		sor = sor_beolvas(bemenet_fajl);
	}

	// takarítás
	fclose(bemenet_fajl);
	fclose(kimenet_fajl);
	free(bemenet_fajlnev);
	free(keresendo);
	free(cserekifejezes);
	free(kimenet_fajlnev);

	printf("Kesz.");
	_getch();
	return 0;
}