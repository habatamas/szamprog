#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int malloc_szamlalo=0, free_szamlalo=0;
void* sajat_malloc(size_t meret) {
	malloc_szamlalo++;
	return malloc(meret);
}
void sajat_free(void *ptr){
	free_szamlalo++;
	free(ptr);
}
#define malloc sajat_malloc
#define free sajat_free

char* sorbeolvas(FILE *f) {
	// kezdeti foglalás
	int max_meret = 10;
	char* sor = (char*)malloc(max_meret);
	int sor_hossz = 0;

	// karakterenkénti beolvasás
	while (1) {
		// egy karakter beolvasása
		char ch;
		int siker = fscanf(f,"%c", &ch);

		// ha fájl vége és nem volt olvasott adat
		if (siker != 1 && sor_hossz == 0) {
			free(sor);
			return NULL;
		}

		// sor vége (soremelés van, vagy vége a fájlnak)
		if (ch == '\n' || siker != 1)
			break;

		// van elég hely? ha nincs -> újrafoglalás
		if (max_meret < sor_hossz + 2) {
			// új terület foglalása
			int uj_max_meret = max_meret + 10;
			char* uj_sor = (char*)malloc(uj_max_meret);

			// régi adatok átmásolása
			memcpy(uj_sor, sor, sor_hossz);

			// régi terület felszabadítása
			free(sor);

			// változók aktualizálása
			max_meret = uj_max_meret;
			sor = uj_sor;
		}

		// karakter hozzáfûzése a sztringhez
		sor[sor_hossz] = ch;
		sor_hossz++;
	}

	// lezáró nulla
	sor[sor_hossz] = '\0';

	return sor;
}

char* darabol(char *miben, char *elvalaszto) {
	char* talalat = strstr(miben, elvalaszto);
	if (talalat != NULL) {
		*talalat = '\0'; // itt lett kettévágva a sztring
		return talalat + strlen(elvalaszto);
	}
	return NULL;
}

int main(void) {
	// fájl megnyitása
	FILE* f = fopen("bolygok.csv", "r");
	if (f == NULL) {
		printf("Nincs ilyen fajl.\n");
		return -1;
	}

	// egyéb változók (statisztikához)
	int bolygok_szama = 0;
	int jupiternel_nagyobb = 0;
	double legkisebb_tomeg=-1;
	char *legkisebb_bolygo=NULL;
	int kettoscsillag_korul = 0;
	double kettoscsillag_ossztomeg = 0;
	printf("Bolygok, ahol egy ev hosszabb, mint a Foldon:\n");

	// soronkénti beolvasás (teszt verzió)
	while (1) {
		// sor beolvasása
		char* sor = sorbeolvas(f);
		if (sor==NULL)
			break;

		// kommentek és üres sorok figyelmen kívül hagyása
		if (sor[0] == ';' || sor[0] == '\n') {
			free(sor);
			continue;
		}

		
		// sor: "HAT-P-34 b"0"3.328"1.197"5.4527"
		//       ^sor
		//       ^azonosito ^tipus
		//                    ^tomeg
		//                          ^sugar
		//                                ^keringesi_ido

		// oszlopok szétválasztása
		char* azonosito, * tipus, * tomeg, * sugar, * keringesi_ido;
		azonosito = sor;
		tipus = darabol(azonosito, ";");
		tomeg = darabol(tipus, ";");
		sugar = darabol(tomeg, ";");
		keringesi_ido = darabol(sugar, ";");

		// adatkonverzió
		double tomeg_szam, sugar_szam, keringesi_ido_szam;
		tomeg_szam = atof(tomeg);
		sscanf(sugar, "%lf", &sugar_szam);
		keringesi_ido_szam = atof(keringesi_ido);

		// feladatmegoldás: bolygók száma
		bolygok_szama++;

		// Jupiternél nagyobb bolygók száma
		if (sugar_szam > 1)
			jupiternel_nagyobb++;

		// legkisebb tömegû bolygó
		if (legkisebb_tomeg == -1 || tomeg_szam < legkisebb_tomeg) {
			// új csúcstartó
			legkisebb_tomeg = tomeg_szam;

			if(legkisebb_bolygo!=NULL)
				free(legkisebb_bolygo); // felülirandó bolygó neve
			legkisebb_bolygo = (char*)malloc(strlen(azonosito) + 1);
			strcpy(legkisebb_bolygo, azonosito);
		}

		// keringési idõ
		if (keringesi_ido_szam > 365)
			printf("    %s\n", azonosito);

		// kettõscsillag körül
		if (strcmp(tipus, "2") == 0) {
			kettoscsillag_korul++;
			kettoscsillag_ossztomeg += tomeg_szam;
		}

		// sor felszabadítása
		free(sor);
	}

	// eredmények kiírása
	printf("A fajlban %d bolygo adatai talalhatok.\n", bolygok_szama);
	printf("%d bolygo nagyobb a Jupiternel.\n", jupiternel_nagyobb);
	printf("A legkisebb tomegu bolygo: %s, melynek tomege: %f\n",
		legkisebb_bolygo, legkisebb_tomeg);
	printf("Kettoscsillag korul keringo bolygok atlagos tomege: %g\n",
		kettoscsillag_ossztomeg / kettoscsillag_korul);

	// felszabadítások
	free(legkisebb_bolygo);

	// fájl lezárása
	fclose(f);

	printf("malloc: %d\nfree: %d\n", malloc_szamlalo, free_szamlalo);

	return 0;
}