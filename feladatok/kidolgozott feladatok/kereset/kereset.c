#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// malloc �s free ellen�rz�s�hez
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

// egy sort beolvas egy f�jlb�l dinamikus sztringbe
// ha siker�l: visszat�r a sztringgel (dinamikus)
// ha nem siker�l: visszat�r NULL pointerrel
char *sorbeolvas(FILE *file) {
	// kezdeti t�mb foglal�sa
	int meret = 10;
	char *sor = (char*)malloc(meret);
	int hossz = 0;

	// karakterenk�nti beolvas�s
	while (1) {
		// egy karakter beolvas�sa
		char ch;
		int siker = fscanf(file, "%c", &ch);

		// v�ge van a f�jlnak?
		if (siker != 1 && hossz == 0) {
			free(sor);
			return NULL;
		}

		// v�ge van a sornak?
		if (ch == '\n' || siker != 1)
			break;

		// megtelt a sor?
		if (hossz == meret - 1) {
			// �j ter�let foglal�sa
			int uj_meret = meret + 10;
			char *uj_sor = (char*)malloc(uj_meret); // �j ter�let
			memcpy(uj_sor, sor, meret); // r�gi adatok �tment�se
			free(sor); // r�gi ter�let felszabad�t�sas
			sor = uj_sor; // sor friss�t�se
			meret = uj_meret; // m�ret friss�t�se
		}

		// karakter hozz�f�z�se
		sor[hossz] = ch;
		hossz++;
	}

	// lez�r� \0
	sor[hossz] = '\0';

	return sor;
}

// sztring kett�v�g�: eredeti sztringet lefejezi
// visszat�r a marad�kkal
// ha nem v�ghat� kett�, null pointert ad vissza
char *kettevag(char *str, char *elvalaszto) {
	char *talalat = strstr(str, elvalaszto);
	if (talalat == NULL)
		return NULL;
	*talalat = '\0';
	return talalat + strlen(elvalaszto);
}

// http://users.hszk.bme.hu/~ht1520/emberek.csv
int main(void) {
	// f�jl megnyit�sa
	FILE *f = fopen("emberek.csv", "r");

	// v�ltoz�k statisztik�hoz
	int emberek_szama_50_felett = 0;
	int osszkereset_50_felett = 0;
	int emberek_szama = 0;
	int emberek_szama_500_felett = 0;

	// maximumkeres�shez
	int elso = 1;
	char *legtobbet_kereso = NULL; // itt az�rt kellett valami kezdeti �rt�k, mert a ford�t� kiab�lt
	int legnagyobb_kereset;

	// soronk�nt beolvassuk
	printf("30 evnel fiatalabb:\n");
	char *sor = sorbeolvas(f);
	while (sor != NULL) {
		// sor beolvas�sa �s �rtelmez�se
		char *nev = sor;
		char *maradek = kettevag(sor, ",");
		int kor, kereset;
		sscanf(maradek, "%d,%d", &kor, &kereset);

		// maximumkeres�s
		if (elso) {
			// a legels� embert speci�lisan kezelj�k
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

		// 30 �vn�l fiatalabb?
		if (kor < 30)
			printf("    %s\n", nev);

		// 50 �vn�l id�sebb?
		if (kor > 50) {
			emberek_szama_50_felett++;
			osszkereset_50_felett += kereset;
		}

		// sz�ml�l�s
		emberek_szama++;

		// 500 felett keres?
		if (kereset > 500)
			emberek_szama_500_felett++;

		// k�vetkez� sor beolvas�sa
		free(sor);
		sor = sorbeolvas(f);
	}

	// eredm�nyek ki�r�sa
	printf("atlagkereset 50 ev felett: %g\n", (double)osszkereset_50_felett / emberek_szama_50_felett);
	printf("emberek szama: %d\n", emberek_szama);
	printf("az emberek %g%%-a keres 500 felett\n", 100.0*emberek_szama_500_felett / emberek_szama);
	printf("%s keresi a legtobbet, keresete: %d\n", legtobbet_kereso, legnagyobb_kereset);
	free(legtobbet_kereso);

	// f�jl bez�r�sa
	fclose(f);

	// ugyanannyit foglaltunk, mint amennyit felszabad�tottunk?
	printf("malloc: %d free: %d\n", malloc_szamlalo, free_szamlalo);

	_getch();
	return 0;
}