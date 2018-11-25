#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// sor beolvas�sa f�jlb�l dinamikusan
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

// keres�s �s csere sztringben -> dinamikusan foglal sztringet
char *csere(char *forras, char *mit, char *mire) {
	// el�fordul�sok sz�ma
	int hanyszor = 0;
	char *munkapeldany = forras; // munkap�ld�ny k�sz�t�se
	while (strstr(munkapeldany, mit) != NULL) {
		munkapeldany = strstr(munkapeldany, mit) + strlen(mit);
		hanyszor++;
	}

	// c�lsztring foglal�sa
	char *cel = (char *)malloc(strlen(forras) + hanyszor * (strlen(mire) - strlen(mit)) + 1); // lez�r� null�nak is kell hely!

	// csere elv�gz�se
	*cel = '\0';
	char *talalat = strstr(forras, mit);
	while (talalat != NULL) {
		strncat(cel, forras, talalat - forras);
		strcat(cel, mire);
		forras = talalat + strlen(mit);
		talalat = strstr(forras, mit);
	}
	strcat(cel, forras);

	// visszat�r�s a foglalt sztringgel
	return cel;
}

int main(void)
{
	// adatok beolvas�sa
	printf("Forrasfajl neve: ");
	char *bemenet_fajlnev = sor_beolvas(stdin);
	printf("Cserelendo kifejezes: ");
	char *keresendo = sor_beolvas(stdin);
	printf("Erre cserelje: ");
	char *cserekifejezes = sor_beolvas(stdin);
	printf("Kimeneti fajl neve: ");
	char *kimenet_fajlnev = sor_beolvas(stdin);

	// f�jlok megnyit�sa
	FILE *bemenet_fajl = fopen(bemenet_fajlnev, "r");
	FILE *kimenet_fajl = fopen(kimenet_fajlnev, "w");

	// soronk�nt beolvas�s
	char *sor = sor_beolvas(bemenet_fajl);
	while (sor != NULL) {
		// csere
		char *uj_sor = csere(sor, keresendo, cserekifejezes);

		// ki�r�s f�jlba
		fprintf(kimenet_fajl, "%s\n", uj_sor);

		// felszabad�t�s
		free(uj_sor);
		free(sor);

		// k�vetkez� sor beolvas�sa
		sor = sor_beolvas(bemenet_fajl);
	}

	// takar�t�s
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