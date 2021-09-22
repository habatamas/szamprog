#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

// saját sor beolvasó függvény
char* sorolvas(FILE *f) {
	// kezdeti memóriaterület foglalása
	int foglalt_terulet = 10;
	char* sor = (char*)malloc(foglalt_terulet);
	int hossz = 0;

	// beolvasás karakterenként
	while (1) {
		// egy karakter beolvasása
		char ch;
		int eredmeny = fscanf(f,"%c", &ch);

		// fájl vége
		if (eredmeny != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// sorvége (vagy sortörés, vagy vége a fájlnak)
		if (ch == '\n' || eredmeny!=1)
			break;

		// elfogyott a memória?
		if (hossz+2 > foglalt_terulet) {
			// új terület foglalása
			int uj_foglalt_terulet = foglalt_terulet + 10;
			char* uj_sor = (char*)malloc(uj_foglalt_terulet);

			// régi adatok átmásolása
			memcpy(uj_sor, sor, hossz);

			// régi terület felszabadítása
			free(sor);

			// változók frissítése
			foglalt_terulet = uj_foglalt_terulet;
			sor = uj_sor;
		}

		// karakter hosszáfûzése a sztringhez
		sor[hossz] = ch;
		hossz++;
	}

	// lezáró nulla
	sor[hossz] = '\0';

	// visszatérés az eredménnyel
	return sor;
}

void jelszavas() {
	// jelszavas beléptetõ
	char jelszo[] = "pass123";
	char* beirt;

	while (1) {
		printf("ird be a jelszot: ");
		// gets(beirt); // !!!!
		beirt = sorolvas(stdin);
		printf("beirt: %s\n", beirt);

		if (strcmp(beirt, jelszo) == 0)
			break;
		printf("hibas jelszo!\n");
		free(beirt);
	}

	printf("udvozollek!\n");
}

void file_teszt() {
	// fájl megnyitása
	FILE* f = fopen("teszt.txt", "a"); // w=felülírás a=hozzáírás

	// fájlba írás
	// fprintf(f, "hello MOGI!");

	// fájl lezárása
	fclose(f);

	// fájlból olvasás
	f = fopen("teszt.txt", "r"); // r=olvasás
	if (f == NULL) {
		printf("Hiba: nem sikerult a fajl megnyitasa!\n");
		return -1;
	}

	int db = 0;
	double sum = 0;

	while (1) {
		// próbáljunk meg beolvasni egy számot
		double szam;
		int eredmeny = fscanf(f, "%lf", &szam);

		// ha nem sikerült beolvasni, akkor szakítsuk meg a ciklust
		if (eredmeny != 1)
			break;

		// siker: adat feldolgozása
		printf("szam: %g\n", szam);
		db++;
		sum += szam;
	}

	printf("atlag: %g\n", sum / db);

	// fájl lezárása
	fclose(f);
}


// Shanta Slick,55,321
//             ^talalat
// Shanta Slick055,321
//"Shanta Slick"
//             "55,321"
//              ^vissza
char* kettevag(char* str, char* elvalaszto) {
	char* talalat = strstr(str, elvalaszto);
	if (talalat != NULL) {
		*talalat = '\0';
		return talalat + strlen(elvalaszto);
	}
	return NULL;
}

int main(void) {
	// jelszavas();
	// file_teszt();
	
	// soronként beolvasás fájlból
	
	// megnyitás
	FILE* f = fopen("teszt.txt", "r");
	if (f == NULL) {
		printf("hiba!\n");
		return -1;
	}

	// beolvasás szavanként
	/*
	while (1) {
		char szo[100];
		int eredmeny = fscanf(f, "%s", szo);
		if (eredmeny != 1)
			break;
		printf("szo: %s\n", szo);
	}
	*/
	// lezárás

	/*
	while (!feof(f)) {
		char sor[100];
		fgets(sor, 100, f);
		printf("sor: %s\n", sor);
	}
	*/

	while(1) {
		char* sor = sorolvas(f);

		// fájl vége?
		if (sor == NULL)
			break;

		// sztring darabolás
		char* nev, * eletkor, * kereslet;
		nev = sor;
		eletkor = kettevag(nev, ",");
		kereslet = kettevag(eletkor, ",");

		printf("nev: %s\t eletkor: %s\t kereslet: %s\n", nev, eletkor, kereslet);
		free(sor);
	}

	fclose(f);

	return 0;
}