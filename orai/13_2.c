#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// http://users.hszk.bme.hu/~ht1520/emberek.csv

char* sorolvas(FILE *f) {
	// kezdeti üres sztring
	char* sor = malloc(1);
	*sor = '\0';

	while (1) {
		// megpróbálunk karaktert beolvasni
		char ch;
		int siker = fscanf(f, "%c", &ch);

		// vége van a fájlnak?
		if (siker != 1)
			break;

		// vége van a sornak?
		if (ch == '\n')
			break;

		// új terület mérete
		int uj_meret = strlen(sor) + 2;
		// új terület foglalása
		char* uj_sor = malloc(uj_meret);
		// régi adatok átmásolása
		strcpy(uj_sor, sor);
		// régi hely felszabadítása
		free(sor);
		// új adat hozzáfûzése
		uj_sor[uj_meret - 2] = ch;
		uj_sor[uj_meret - 1] = '\0';
		// változók aktualizálása
		sor = uj_sor;
	}

	return sor;
}

// http://users.hszk.bme.hu/~ht1520/ora.txt

char* darabol(char* str, char* elv) {
	char* talalat = strstr(str, elv);
	if (talalat == NULL) return NULL;
	*talalat = '\0';
	return talalat + strlen(elv);
}

int main(void) {
	
	FILE* f = fopen("emberek.csv", "r");
	
	// változók statisztikához
	int sum=0, db=0;
	int osszes_db=0;
	int db_500_felett = 0;

	printf("30 evnel fiatalabbak:\n");

	// beolvasás sorról sorra
	while (!feof(f)) {
		// sor beolvasása
		char *sor = sorolvas(f);
		
		// csak azokat vizsgáljuk, amik
		// nem ;-vel kezdõdnek
		if (*sor != ';') {
			// sor darabolása
			char* adat1 = sor;
			char* adat2 = darabol(adat1, ",");
			char* adat3 = darabol(adat2, ",");

			// számadatok kinyerése
			int kor, kereset;
			sscanf(adat2, "%d", &kor);
			sscanf(adat3, "%d", &kereset);

			// feladatmegoldás
			if (kor < 30) {
				printf("\t%s\n", adat1);
			}

			// 50 év feletti átlagkereset
			if (kor > 50) {
				db++;
				sum += kereset;
			}

			// összes ember
			osszes_db++;

			// 500 felett keres
			if (kereset > 500) {
				db_500_felett++;
			}
		}

		free(sor);
	}
	
	fclose(f);

	// eredmények kiírása
	printf("50 ev feletti atlagkereset: %f\n", (double)sum / db);
	printf("a fajlban %d ember adatai talalhatok\n", osszes_db);
	printf("az emberek %f%%-a keres 500 felett\n", (double)db_500_felett / osszes_db * 100);

	_getch();
	return 0;
}