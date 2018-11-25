#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// sor beolvas�sa f�jlb�l dinamikusan foglalt sztringbe
char *sor_beolvas(FILE *file) {
	// helyfoglal�s a sornak
	int meret = 10;
	char *sor = (char*)malloc(meret);
	int hossz = 0;

	// beolvas�s, am�g lehet
	while (1) {
		// beolvas�s
		char ch;
		int siker = fscanf(file, "%c", &ch);

		// speci�lis eset: nem tudunk semmit beolvasni
		if (siker != 1 && hossz == 0) {
			// mem�ria felszabad�t�sa
			free(sor);
			// ilyenkor NULL-al t�r�nk vissza
			return NULL;
		}

		// ha v�ge a f�jlnak vagy a sornak, akkor nem folytatjuk
		if (ch == '\n' || siker != 1)
			break;

		// ha a sor betelt (lez�r� null�val egy�tt), nagyobb hely foglal�sa
		if (hossz + 1 == meret) {
			int uj_meret = meret + 10;
			char *uj_sor = (char*)malloc(uj_meret); // �j t�mb foglal�sa
			memcpy(uj_sor, sor, meret); // r�gi adatok �tm�sol�sa
			free(sor); // r�gi t�mb felszabad�t�sa
			sor = uj_sor; // sor friss�t�se
			meret = uj_meret; // m�ret friss�t�se
		}

		// karakter hozz��r�sa a t�mbh�z
		sor[hossz] = ch;
		hossz++;
	}

	// sztring lez�r�sa �s visszat�r�s
	sor[hossz] = '\0';
	return sor;
}

// sztring kett�v�g�sa: az eredeti sztringet lefejezi, a marad�kkal visszat�r
char *kettevag(char *mit, char *elvalaszto) {
	char *talalat = strstr(mit, elvalaszto);
	if (talalat == NULL)
		return NULL;
	*talalat = '\0';
	return talalat + strlen(elvalaszto);
}

int main(void)
{
	// f�jl megnyit�sa
	FILE *f = fopen("emberek.csv", "r");

	printf("30 evnel fiatalabbak:\n");

	// v�ltoz�k a statisztik�hoz
	int emberek_szama = 0;
	int emberek_szama_50_felett = 0;
	int osszkereset_50_felett = 0;
	int emberek_szama_500_feletti_keresettel = 0;

	// beolvas�s soronk�nt
	char *sor = sor_beolvas(f);
	while (sor != NULL) {
		// adatok kinyer�se darabol�ssal
		char *nev = sor;
		char *maradek = kettevag(sor, ",");
		int kor, kereset;
		sscanf(maradek, "%d,%d", &kor, &kereset);

		// ha 30 �vn�l fiatalabb, ki�rjuk
		if (kor < 30)
			printf("    %s\n", nev);

		// sz�ml�l�s
		emberek_szama++;
		if (kor > 50) {
			emberek_szama_50_felett++;
			osszkereset_50_felett += kereset;
		}
		if (kereset > 500)
			emberek_szama_500_feletti_keresettel++;

		// k�vetkzek� sor beolvas�sa
		free(sor);
		sor = sor_beolvas(f);
	}

	// f�jl bez�r�sa
	fclose(f);

	// eredm�nyek ki�r�sa
	printf("Emberek szama: %d\n", emberek_szama);
	printf("50 evnel idosebbek atlagkeresete: %f\n", (double)osszkereset_50_felett / emberek_szama_50_felett);
	printf("Az emberek %g%%-a keres 500-nal tobbet\n", 100.0*emberek_szama_500_feletti_keresettel / emberek_szama);

	_getch();
	return 0;
}