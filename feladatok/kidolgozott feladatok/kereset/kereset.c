#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// sor beolvasása fájlból dinamikusan foglalt sztringbe
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

// sztring kettévágása: az eredeti sztringet lefejezi, a maradékkal visszatér
char *kettevag(char *mit, char *elvalaszto) {
	char *talalat = strstr(mit, elvalaszto);
	if (talalat == NULL)
		return NULL;
	*talalat = '\0';
	return talalat + strlen(elvalaszto);
}

int main(void)
{
	// fájl megnyitása
	FILE *f = fopen("emberek.csv", "r");

	printf("30 evnel fiatalabbak:\n");

	// változók a statisztikához
	int emberek_szama = 0;
	int emberek_szama_50_felett = 0;
	int osszkereset_50_felett = 0;
	int emberek_szama_500_feletti_keresettel = 0;

	// beolvasás soronként
	char *sor = sor_beolvas(f);
	while (sor != NULL) {
		// adatok kinyerése darabolással
		char *nev = sor;
		char *maradek = kettevag(sor, ",");
		int kor, kereset;
		sscanf(maradek, "%d,%d", &kor, &kereset);

		// ha 30 évnél fiatalabb, kiírjuk
		if (kor < 30)
			printf("    %s\n", nev);

		// számlálás
		emberek_szama++;
		if (kor > 50) {
			emberek_szama_50_felett++;
			osszkereset_50_felett += kereset;
		}
		if (kereset > 500)
			emberek_szama_500_feletti_keresettel++;

		// követkzekõ sor beolvasása
		free(sor);
		sor = sor_beolvas(f);
	}

	// fájl bezárása
	fclose(f);

	// eredmények kiírása
	printf("Emberek szama: %d\n", emberek_szama);
	printf("50 evnel idosebbek atlagkeresete: %f\n", (double)osszkereset_50_felett / emberek_szama_50_felett);
	printf("Az emberek %g%%-a keres 500-nal tobbet\n", 100.0*emberek_szama_500_feletti_keresettel / emberek_szama);

	_getch();
	return 0;
}