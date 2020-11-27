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
	// kezdeti foglal�s
	int max_meret = 10;
	char* sor = (char*)malloc(max_meret);
	int sor_hossz = 0;

	// karakterenk�nti beolvas�s
	while (1) {
		// egy karakter beolvas�sa
		char ch;
		int siker = fscanf(f,"%c", &ch);

		// ha f�jl v�ge �s nem volt olvasott adat
		if (siker != 1 && sor_hossz == 0) {
			free(sor);
			return NULL;
		}

		// sor v�ge (soremel�s van, vagy v�ge a f�jlnak)
		if (ch == '\n' || siker != 1)
			break;

		// van el�g hely? ha nincs -> �jrafoglal�s
		if (max_meret < sor_hossz + 2) {
			// �j ter�let foglal�sa
			int uj_max_meret = max_meret + 10;
			char* uj_sor = (char*)malloc(uj_max_meret);

			// r�gi adatok �tm�sol�sa
			memcpy(uj_sor, sor, sor_hossz);

			// r�gi ter�let felszabad�t�sa
			free(sor);

			// v�ltoz�k aktualiz�l�sa
			max_meret = uj_max_meret;
			sor = uj_sor;
		}

		// karakter hozz�f�z�se a sztringhez
		sor[sor_hossz] = ch;
		sor_hossz++;
	}

	// lez�r� nulla
	sor[sor_hossz] = '\0';

	return sor;
}

char* darabol(char *miben, char *elvalaszto) {
	char* talalat = strstr(miben, elvalaszto);
	if (talalat != NULL) {
		*talalat = '\0'; // itt lett kett�v�gva a sztring
		return talalat + strlen(elvalaszto);
	}
	return NULL;
}

int main(void) {
	// f�jl megnyit�sa
	FILE* f = fopen("bolygok.csv", "r");
	if (f == NULL) {
		printf("Nincs ilyen fajl.\n");
		return -1;
	}

	// egy�b v�ltoz�k (statisztik�hoz)
	int bolygok_szama = 0;
	int jupiternel_nagyobb = 0;
	double legkisebb_tomeg=-1;
	char *legkisebb_bolygo=NULL;
	int kettoscsillag_korul = 0;
	double kettoscsillag_ossztomeg = 0;
	printf("Bolygok, ahol egy ev hosszabb, mint a Foldon:\n");

	// soronk�nti beolvas�s (teszt verzi�)
	while (1) {
		// sor beolvas�sa
		char* sor = sorbeolvas(f);
		if (sor==NULL)
			break;

		// kommentek �s �res sorok figyelmen k�v�l hagy�sa
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

		// oszlopok sz�tv�laszt�sa
		char* azonosito, * tipus, * tomeg, * sugar, * keringesi_ido;
		azonosito = sor;
		tipus = darabol(azonosito, ";");
		tomeg = darabol(tipus, ";");
		sugar = darabol(tomeg, ";");
		keringesi_ido = darabol(sugar, ";");

		// adatkonverzi�
		double tomeg_szam, sugar_szam, keringesi_ido_szam;
		tomeg_szam = atof(tomeg);
		sscanf(sugar, "%lf", &sugar_szam);
		keringesi_ido_szam = atof(keringesi_ido);

		// feladatmegold�s: bolyg�k sz�ma
		bolygok_szama++;

		// Jupitern�l nagyobb bolyg�k sz�ma
		if (sugar_szam > 1)
			jupiternel_nagyobb++;

		// legkisebb t�meg� bolyg�
		if (legkisebb_tomeg == -1 || tomeg_szam < legkisebb_tomeg) {
			// �j cs�cstart�
			legkisebb_tomeg = tomeg_szam;

			if(legkisebb_bolygo!=NULL)
				free(legkisebb_bolygo); // fel�lirand� bolyg� neve
			legkisebb_bolygo = (char*)malloc(strlen(azonosito) + 1);
			strcpy(legkisebb_bolygo, azonosito);
		}

		// kering�si id�
		if (keringesi_ido_szam > 365)
			printf("    %s\n", azonosito);

		// kett�scsillag k�r�l
		if (strcmp(tipus, "2") == 0) {
			kettoscsillag_korul++;
			kettoscsillag_ossztomeg += tomeg_szam;
		}

		// sor felszabad�t�sa
		free(sor);
	}

	// eredm�nyek ki�r�sa
	printf("A fajlban %d bolygo adatai talalhatok.\n", bolygok_szama);
	printf("%d bolygo nagyobb a Jupiternel.\n", jupiternel_nagyobb);
	printf("A legkisebb tomegu bolygo: %s, melynek tomege: %f\n",
		legkisebb_bolygo, legkisebb_tomeg);
	printf("Kettoscsillag korul keringo bolygok atlagos tomege: %g\n",
		kettoscsillag_ossztomeg / kettoscsillag_korul);

	// felszabad�t�sok
	free(legkisebb_bolygo);

	// f�jl lez�r�sa
	fclose(f);

	printf("malloc: %d\nfree: %d\n", malloc_szamlalo, free_szamlalo);

	return 0;
}