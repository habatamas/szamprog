#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

// elõfordulások száma
int hanyszor(const char *ebben, const char *ezt) {
	int szamlalo = 0;

	while (strstr(ebben, ezt) != NULL) {
		const char* talalat = strstr(ebben, ezt);
		ebben = talalat + strlen(ezt);
		szamlalo++;
	}

	return szamlalo;
}

// elsõ elõfordulás keresése és cseréje
void elso_csere(char *eredmeny, char* miben, char *mit, char *mire) {
	char* talalat = strstr(miben, mit);
	
	// ha nincs találat
	if (talalat == NULL) {
		strcpy(eredmeny, miben);
		return;
	}

	// ha van találat
	// 1. találat elõtti rész átmásolása (strnpy??)
	*eredmeny = '\0'; // lezáró nulla (üres sztring létrehozása)
	strncat(eredmeny, miben, talalat - miben);

	// 2. csresztring hozzáfûzése
	strcat(eredmeny, mire);

	// 3. találat utáni rész hozzáfûzése
	strcat(eredmeny, talalat + strlen(mit));
}


int main(void) {
	printf("%d\n", hanyszor("egy ketto harom egy negy", "egy"));

	char str1[] = "hello MOGI :)";
	char str2[100];
	elso_csere(str2, str1, "MOGI", "GT3");
	printf("%s\n", str2);

	// jelszavas beléptetõ
	char jelszo[] = "pass123";
	char beirt[10];
	printf("%d", beirt - jelszo);
	do {
		printf("ird be a jelszot: ");
		gets(beirt);

		if (strcmp(beirt, jelszo) != 0)
			printf("hibas jelszo!\n");
	} while (strcmp(beirt,jelszo)!=0);
	printf("udvozollek!\n");

	return 0;
}