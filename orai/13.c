#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// beolvassa f fájl kövekező sorát egy dinamikusan foglalt stringbe
// és visszatér a string kezdőcímével
// vagy ha már nem lehet mit olvasni, akkor NULL-t ad vissza
char* sorolvas(FILE* f) {
	int meret = 10; // foglalt memóriaterület mérete
	int hossz = 0; // beolvasott karakterek száma
	char* sor = (char*)malloc(meret); // a foglalt terület

	// karakterek beolvasása egyesével
	while (1) {
		// egy karakter beolvasása
		char ch;
		int siker = fscanf(f, "%c", &ch);

		// ha nem sikerült semmit beolvasni
		if (siker != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// sor vége van?
		if (ch == '\n' || siker!=1)
			break;

		// szükség szerint memória újrafoglalása
		if (hossz + 2 > meret) {
			int uj_meret = meret + 10; // új terület mérete
			char* uj_sor = (char*)malloc(uj_meret); // új terület
			memcpy(uj_sor, sor, hossz); // régi adatok átmásolása
			free(sor); // régi terület felszabadítása
			meret = uj_meret; // változók aktuálizálása
			sor = uj_sor;
		}

		// új karakter beírása
		sor[hossz] = ch;
		hossz++;
	}

	// lezáró nulla
	sor[hossz] = '\0';

	// visszatérés az eredménnyel
	return sor;
}

char* darabol(char *mit, char *elv) {
	char* talalat = strstr(mit, elv);
	*talalat = '\0';
	return talalat + strlen(elv);
}

int main(void) {
	// fájl megnyitása
	FILE* file = fopen("bolygok.csv", "r");

	// változók a statisztikához
	int bolygok_szama = 0;
	double Endor_lakossaga = 0;
	double ossz_lakossag = 0;
	int kis_bolygo = 0; // hány db Földnél kisebb bolygó van
	double max_lakossag=0;
	char* max_bolygo=NULL;
	printf("Nagyreszt vizzel boritott bolygok:\n");

	// fájl adatainak feldolgozása
	while (1) {
		// sor beolvasása
		char* sor = sorolvas(file);
		if (sor == NULL)
			break;

		// sor feldolgozása
		if (strcmp(sor,"")!=0 && sor[0]!=';') {
			// darabolás
			char* nev = sor;
			char* atmero_str = darabol(nev, ";");
			char* vizek_str = darabol(atmero_str, ";");
			char* lakossag_str = darabol(vizek_str, ";");
			
			// adatok konvertálása
			double atmero = atof(atmero_str);
			double vizek = atof(vizek_str);
			double lakossag = atof(lakossag_str);

			// bolygók számlálása
			bolygok_szama++;

			// nagyon vizes bolygók
			if (vizek > 50)
				printf("    %s\n", nev);

			// Endor lakossága
			if (strcmp(nev, "Endor") == 0)
				Endor_lakossaga = lakossag;

			// Földnél kisebb bolygók átlaglakossága
			if (atmero < 12742) {
				kis_bolygo++;
				ossz_lakossag += lakossag;
			}

			// maximumkeresés
			if (max_bolygo==NULL || lakossag>max_lakossag) {
				free(max_bolygo);
				max_lakossag = lakossag;
				max_bolygo = (char*)malloc(strlen(nev)+1);
				strcpy(max_bolygo, nev);
			}
		}
		// felszabadítás
		free(sor);
	}

	// eredmények kiírása
	printf("A fajlban %d bolygo adatai vannak.\n", bolygok_szama);
	printf("Az Endor lakossaga %.2f ezer fo.\n", Endor_lakossaga);
	printf("A Foldnek kisebb bolygok atlagos lakossaga %.2f ezer fo.\n",
		ossz_lakossag / kis_bolygo);
	printf("A legnagyobb lakossagu bolygo a(z) %s.\n", max_bolygo);

	free(max_bolygo);

	// fájl lezárása
	fclose(file);

	return 0;
}