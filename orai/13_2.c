#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// http://users.hszk.bme.hu/~ht1520/emberek.csv

char* sorolvas(FILE *f) {
	// kezdeti �res sztring
	char* sor = malloc(1);
	*sor = '\0';

	while (1) {
		// megpr�b�lunk karaktert beolvasni
		char ch;
		int siker = fscanf(f, "%c", &ch);

		// v�ge van a f�jlnak?
		if (siker != 1)
			break;

		// v�ge van a sornak?
		if (ch == '\n')
			break;

		// �j ter�let m�rete
		int uj_meret = strlen(sor) + 2;
		// �j ter�let foglal�sa
		char* uj_sor = malloc(uj_meret);
		// r�gi adatok �tm�sol�sa
		strcpy(uj_sor, sor);
		// r�gi hely felszabad�t�sa
		free(sor);
		// �j adat hozz�f�z�se
		uj_sor[uj_meret - 2] = ch;
		uj_sor[uj_meret - 1] = '\0';
		// v�ltoz�k aktualiz�l�sa
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
	
	// v�ltoz�k statisztik�hoz
	int sum=0, db=0;
	int osszes_db=0;
	int db_500_felett = 0;

	printf("30 evnel fiatalabbak:\n");

	// beolvas�s sorr�l sorra
	while (!feof(f)) {
		// sor beolvas�sa
		char *sor = sorolvas(f);
		
		// csak azokat vizsg�ljuk, amik
		// nem ;-vel kezd�dnek
		if (*sor != ';') {
			// sor darabol�sa
			char* adat1 = sor;
			char* adat2 = darabol(adat1, ",");
			char* adat3 = darabol(adat2, ",");

			// sz�madatok kinyer�se
			int kor, kereset;
			sscanf(adat2, "%d", &kor);
			sscanf(adat3, "%d", &kereset);

			// feladatmegold�s
			if (kor < 30) {
				printf("\t%s\n", adat1);
			}

			// 50 �v feletti �tlagkereset
			if (kor > 50) {
				db++;
				sum += kereset;
			}

			// �sszes ember
			osszes_db++;

			// 500 felett keres
			if (kereset > 500) {
				db_500_felett++;
			}
		}

		free(sor);
	}
	
	fclose(f);

	// eredm�nyek ki�r�sa
	printf("50 ev feletti atlagkereset: %f\n", (double)sum / db);
	printf("a fajlban %d ember adatai talalhatok\n", osszes_db);
	printf("az emberek %f%%-a keres 500 felett\n", (double)db_500_felett / osszes_db * 100);

	_getch();
	return 0;
}