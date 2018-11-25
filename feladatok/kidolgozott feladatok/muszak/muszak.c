#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Sorbeolvasó függvény. Megpróbál adott fájlból egy sort beolvasni. Ha sikerül,
 * akkor dinamikusan foglalt sztringgel tér vissza. Ha vége a fájlnak, akkor
 * NULL pointert ad vissza.
 */
char *sor_beolvas(FILE *file) {
	// helyfoglalás a sztringnek
	int meret = 10;
	char *sor = (char*)malloc(meret);
	int hossz = 0;

	// karakterek olvasása sorvégig vagy fájlvégig
	while (1) {
		// egy karakter beolvasása
		char ch;
		int siker = fscanf(file, "%c", &ch);

		// ha vége van a fájlnak és nem sikerült semmit beolvasni
		if (siker != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// ha vége van a sornak
		if (ch == '\n' || siker != 1)
			break;

		// ha megtelt a sztring
		if (hossz + 1 == meret) { // +1 a lezáró nulla bájt miatt
			// méret megnövelése
			int uj_meret = meret + 10;
			char *uj_sor = (char*)malloc(uj_meret); // új memóriaterület foglalása
			memcpy(uj_sor, sor, meret); // régi adatok átmásolása
			free(sor); // régi memóriaterület felszabadítása
			meret = uj_meret; // méret aktualizálása
			sor = uj_sor; // pointer aktualizálása
		}

		// beolvasott karakter hozzáfűzése
		sor[hossz] = ch;
		hossz++;
	}

	// lezáró nulla
	sor[hossz] = '\0';

	return sor;
}

/**
 * Sztring kettévágó: az adott sztriget kettévágja az elválasztó sztring
 * első előfordulásnál. Az eredeti sztring így megrövidül, a maradék sztringgel
 * pedig visszatér.
 */
char *kettevag(char *str, const char *elvalaszto) {
	char *found = strstr(str, elvalaszto);
	if (found == NULL)
		return NULL;

	str[found - str] = '\0';
	return found + strlen(elvalaszto);
}

/**
 * Eldönti, hogy idopont1 előbb volt-e mint idopont2.
 * Idő formátum: ÉÉÉÉ.HH.NN.ÓÓ:PP
 */
int idopont_kisebb(const char *idopont1, const char *idopont2) {
	// komponensekre bontás
	int ev1, honap1, nap1, ora1, perc1;
	sscanf(idopont1, "%d.%d.%d.%d:%d", &ev1, &honap1, &nap1, &ora1, &perc1);
	int ev2, honap2, nap2, ora2, perc2;
	sscanf(idopont2, "%d.%d.%d.%d:%d", &ev2, &honap2, &nap2, &ora2, &perc2);

	// összehasonlítás szisztematikusan
	if (ev1 != ev2)
		return ev1 < ev2;
	if (honap1 != honap2)
		return honap1 < honap2;
	if (nap1 != nap2)
		return nap1 < nap2;
	if (ora1 != ora2)
		return ora1 < ora2;
	if (perc1 != perc2)
		return perc1 < perc2;
	return 0;
}

/**
 * Eldönti, hogy egy adott időpont benne van-e egy adott időintervallumban,
 * aminek ismerjük az elejét és végét.
 */
int bennevan(const char *idopont, const char *kezdet, const char *veg) {
	return idopont_kisebb(kezdet, idopont) && idopont_kisebb(idopont, veg);
}

/**
 * A program belépési pontja
 */
int main(int argc, char** argv) {
	// időpont bekérése
	printf("Kerek egy idopontot (EEEE.HH.NN.OO:PP): ");
	char *idopont = sor_beolvas(stdin);

	// fájl megnyitása
	FILE *file = fopen("muszak.txt", "r");

	// sorok beolvasása
	int volt_talalat = 0;
	char *sor = sor_beolvas(file);
	while (sor != NULL) {
		// sor szétdarabolása
		char *muszak_kezdet = sor;
		char *muszak_veg = kettevag(muszak_kezdet, " - ");
		char *nev = kettevag(muszak_veg, "\t");

		// ha megfelelő, akkor kiírjuk
		if (bennevan(idopont, muszak_kezdet, muszak_veg)) {
			if (!volt_talalat) {
				volt_talalat = 1;
				printf("A megadott idopontban muszakban volt:\n");
			}
			printf("%s\n", nev);
		}

		// sor felszabadítása, következő beolvasása
		free(sor);
		sor = sor_beolvas(file);
	}

	// ha nem volt találat, akkor külön szöveg kiírása
	if (!volt_talalat) {
		printf("A megadott idopontban senki nem volt muszakban.\n");
	}

	// takarítás
	fclose(file);
	free(idopont);

	_getch();

	return 0;
}


