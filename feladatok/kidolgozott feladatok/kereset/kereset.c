#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// malloc és free ellenõrzéséhez
int malloc_szamlalo = 0;
int free_szamlalo = 0;
void *sajat_malloc(int meret) {
	malloc_szamlalo++;
	return malloc(meret);
}
void sajat_free(void *mem) {
	free_szamlalo++;
	free(mem);
}
#define malloc sajat_malloc
#define free sajat_free

// egy sort beolvas egy fájlból dinamikus sztringbe
// ha sikerül: visszatér a sztringgel (dinamikus)
// ha nem sikerül: visszatér NULL pointerrel
char *sorbeolvas(FILE *file) {
	// kezdeti tömb foglalása
	int meret = 10;
	char *sor = (char*)malloc(meret);
	int hossz = 0;

	// karakterenkénti beolvasás
	while (1) {
		// egy karakter beolvasása
		char ch;
		int siker = fscanf(file, "%c", &ch);

		// vége van a fájlnak?
		if (siker != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// vége van a sornak?
		if (ch == '\n' || siker != 1)
			break;

		// megtelt a sor?
		if (hossz == meret - 1) {
			// új terület foglalása
			int uj_meret = meret + 10;
			char *uj_sor = (char*)malloc(uj_meret); // új terület
			memcpy(uj_sor, sor, meret); // régi adatok átmentése
			free(sor); // régi terület felszabadításas
			sor = uj_sor; // sor frissítése
			meret = uj_meret; // méret frissítése
		}

		// karakter hozzáfûzése
		sor[hossz] = ch;
		hossz++;
	}

	// lezáró \0
	sor[hossz] = '\0';

	return sor;
}

// sztring kettévágó: eredeti sztringet lefejezi
// visszatér a maradékkal
// ha nem vágható ketté, null pointert ad vissza
char *kettevag(char *str, char *elvalaszto) {
	char *talalat = strstr(str, elvalaszto);
	if (talalat == NULL)
		return NULL;
	*talalat = '\0';
	return talalat + strlen(elvalaszto);
}

// http://users.hszk.bme.hu/~ht1520/emberek.csv
int main(void) {
	// fájl megnyitása
	FILE *f = fopen("emberek.csv", "r");

	// változók statisztikához
	int emberek_szama_50_felett = 0;
	int osszkereset_50_felett = 0;
	int emberek_szama = 0;
	int emberek_szama_500_felett = 0;

	// maximumkereséshez
	int elso = 1;
	char *legtobbet_kereso = NULL; // itt azért kellett valami kezdeti érték, mert a fordító kiabált
	int legnagyobb_kereset;

	// soronként beolvassuk
	printf("30 evnel fiatalabb:\n");
	char *sor = sorbeolvas(f);
	while (sor != NULL) {
		// sor beolvasása és értelmezése
		char *nev = sor;
		char *maradek = kettevag(sor, ",");
		int kor, kereset;
		sscanf(maradek, "%d,%d", &kor, &kereset);

		// maximumkeresés
		if (elso) {
			// a legelsõ embert speciálisan kezeljük
			elso = 0;
			legtobbet_kereso = (char*)malloc(strlen(nev) + 1);
			strcpy(legtobbet_kereso, nev);
			legnagyobb_kereset = kereset;
		}
		else if (kereset > legnagyobb_kereset) {
			free(legtobbet_kereso);
			legtobbet_kereso = (char*)malloc(strlen(nev) + 1);
			strcpy(legtobbet_kereso, nev);
			legnagyobb_kereset = kereset;
		}

		// 30 évnél fiatalabb?
		if (kor < 30)
			printf("    %s\n", nev);

		// 50 évnél idõsebb?
		if (kor > 50) {
			emberek_szama_50_felett++;
			osszkereset_50_felett += kereset;
		}

		// számlálás
		emberek_szama++;

		// 500 felett keres?
		if (kereset > 500)
			emberek_szama_500_felett++;

		// következõ sor beolvasása
		free(sor);
		sor = sorbeolvas(f);
	}

	// eredmények kiírása
	printf("atlagkereset 50 ev felett: %g\n", (double)osszkereset_50_felett / emberek_szama_50_felett);
	printf("emberek szama: %d\n", emberek_szama);
	printf("az emberek %g%%-a keres 500 felett\n", 100.0*emberek_szama_500_felett / emberek_szama);
	printf("%s keresi a legtobbet, keresete: %d\n", legtobbet_kereso, legnagyobb_kereset);
	free(legtobbet_kereso);

	// fájl bezárása
	fclose(f);

	// ugyanannyit foglaltunk, mint amennyit felszabadítottunk?
	printf("malloc: %d free: %d\n", malloc_szamlalo, free_szamlalo);

	_getch();
	return 0;
}