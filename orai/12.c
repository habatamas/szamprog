#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

// saj�t sor beolvas� f�ggv�ny
char* sorolvas(FILE *f) {
	// kezdeti mem�riater�let foglal�sa
	int foglalt_terulet = 10;
	char* sor = (char*)malloc(foglalt_terulet);
	int hossz = 0;

	// beolvas�s karakterenk�nt
	while (1) {
		// egy karakter beolvas�sa
		char ch;
		int eredmeny = fscanf(f,"%c", &ch);

		// f�jl v�ge
		if (eredmeny != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// sorv�ge (vagy sort�r�s, vagy v�ge a f�jlnak)
		if (ch == '\n' || eredmeny!=1)
			break;

		// elfogyott a mem�ria?
		if (hossz+2 > foglalt_terulet) {
			// �j ter�let foglal�sa
			int uj_foglalt_terulet = foglalt_terulet + 10;
			char* uj_sor = (char*)malloc(uj_foglalt_terulet);

			// r�gi adatok �tm�sol�sa
			memcpy(uj_sor, sor, hossz);

			// r�gi ter�let felszabad�t�sa
			free(sor);

			// v�ltoz�k friss�t�se
			foglalt_terulet = uj_foglalt_terulet;
			sor = uj_sor;
		}

		// karakter hossz�f�z�se a sztringhez
		sor[hossz] = ch;
		hossz++;
	}

	// lez�r� nulla
	sor[hossz] = '\0';

	// visszat�r�s az eredm�nnyel
	return sor;
}

void jelszavas() {
	// jelszavas bel�ptet�
	char jelszo[] = "pass123";
	char* beirt;

	while (1) {
		printf("ird be a jelszot: ");
		// gets(beirt); // !!!!
		beirt = sorolvas(stdin);
		printf("beirt: %s\n", beirt);

		if (strcmp(beirt, jelszo) == 0)
			break;
		printf("hibas jelszo!\n");
		free(beirt);
	}

	printf("udvozollek!\n");
}

void file_teszt() {
	// f�jl megnyit�sa
	FILE* f = fopen("teszt.txt", "a"); // w=fel�l�r�s a=hozz��r�s

	// f�jlba �r�s
	// fprintf(f, "hello MOGI!");

	// f�jl lez�r�sa
	fclose(f);

	// f�jlb�l olvas�s
	f = fopen("teszt.txt", "r"); // r=olvas�s
	if (f == NULL) {
		printf("Hiba: nem sikerult a fajl megnyitasa!\n");
		return -1;
	}

	int db = 0;
	double sum = 0;

	while (1) {
		// pr�b�ljunk meg beolvasni egy sz�mot
		double szam;
		int eredmeny = fscanf(f, "%lf", &szam);

		// ha nem siker�lt beolvasni, akkor szak�tsuk meg a ciklust
		if (eredmeny != 1)
			break;

		// siker: adat feldolgoz�sa
		printf("szam: %g\n", szam);
		db++;
		sum += szam;
	}

	printf("atlag: %g\n", sum / db);

	// f�jl lez�r�sa
	fclose(f);
}


// Shanta Slick,55,321
//             ^talalat
// Shanta Slick055,321
//"Shanta Slick"
//             "55,321"
//              ^vissza
char* kettevag(char* str, char* elvalaszto) {
	char* talalat = strstr(str, elvalaszto);
	if (talalat != NULL) {
		*talalat = '\0';
		return talalat + strlen(elvalaszto);
	}
	return NULL;
}

int main(void) {
	// jelszavas();
	// file_teszt();
	
	// soronk�nt beolvas�s f�jlb�l
	
	// megnyit�s
	FILE* f = fopen("teszt.txt", "r");
	if (f == NULL) {
		printf("hiba!\n");
		return -1;
	}

	// beolvas�s szavank�nt
	/*
	while (1) {
		char szo[100];
		int eredmeny = fscanf(f, "%s", szo);
		if (eredmeny != 1)
			break;
		printf("szo: %s\n", szo);
	}
	*/
	// lez�r�s

	/*
	while (!feof(f)) {
		char sor[100];
		fgets(sor, 100, f);
		printf("sor: %s\n", sor);
	}
	*/

	while(1) {
		char* sor = sorolvas(f);

		// f�jl v�ge?
		if (sor == NULL)
			break;

		// sztring darabol�s
		char* nev, * eletkor, * kereslet;
		nev = sor;
		eletkor = kettevag(nev, ",");
		kereslet = kettevag(eletkor, ",");

		printf("nev: %s\t eletkor: %s\t kereslet: %s\n", nev, eletkor, kereslet);
		free(sor);
	}

	fclose(f);

	return 0;
}