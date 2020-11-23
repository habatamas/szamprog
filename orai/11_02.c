#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

// el�fordul�sok sz�ma
int hanyszor(const char *ebben, const char *ezt) {
	int szamlalo = 0;

	while (strstr(ebben, ezt) != NULL) {
		const char* talalat = strstr(ebben, ezt);
		ebben = talalat + strlen(ezt);
		szamlalo++;
	}

	return szamlalo;
}

// els� el�fordul�s keres�se �s cser�je
void elso_csere(char *eredmeny, char* miben, char *mit, char *mire) {
	char* talalat = strstr(miben, mit);
	
	// ha nincs tal�lat
	if (talalat == NULL) {
		strcpy(eredmeny, miben);
		return;
	}

	// ha van tal�lat
	// 1. tal�lat el�tti r�sz �tm�sol�sa (strnpy??)
	*eredmeny = '\0'; // lez�r� nulla (�res sztring l�trehoz�sa)
	strncat(eredmeny, miben, talalat - miben);

	// 2. csresztring hozz�f�z�se
	strcat(eredmeny, mire);

	// 3. tal�lat ut�ni r�sz hozz�f�z�se
	strcat(eredmeny, talalat + strlen(mit));
}


int main(void) {
	printf("%d\n", hanyszor("egy ketto harom egy negy", "egy"));

	char str1[] = "hello MOGI :)";
	char str2[100];
	elso_csere(str2, str1, "MOGI", "GT3");
	printf("%s\n", str2);

	// jelszavas bel�ptet�
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