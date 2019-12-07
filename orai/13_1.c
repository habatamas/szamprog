#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// csere a sztringben
void strcsere(char *cel, char *miben, char *mit, char *mire) {
	// c�lsztring �resen indul
	*cel = '\0';

	char* talalat = strstr(miben, mit);
	while (talalat != NULL) { // am�g van tal�lat, addig kell cser�lni
		strncat(cel, miben, talalat - miben); // tal�lat el�tti
		strcat(cel, mire); // csere
		
		miben = talalat + strlen(mit);
		talalat = strstr(miben, mit);
	}

	strcat(cel, miben);
}

char* strcsere2(char *miben, char *mit, char *mire) {
	char* eredeti_miben = miben;

	// tal�latok sz�ma
	int db=0;
	char* talalat = strstr(miben, mit);
	while (talalat != NULL) {
		db++;
		miben = talalat + strlen(mit);
		talalat = strstr(miben, mit);
	}

	// helyfogalal�s
	int meret = strlen(eredeti_miben) + db * (strlen(mire) - strlen(mit)) + 1;
	char* cel = malloc(meret);

	// csere
	strcsere(cel, eredeti_miben, mit, mire);
	return cel;
}

// sztring darabol�s
char* lefejez(char *miben, char *elvalaszto) {
	char* talalat = strstr(miben, elvalaszto);
	if (talalat == NULL)
		return NULL; // ha nincs tal�lat
	*talalat = '\0'; // kett�v�g�s
	return talalat + strlen(elvalaszto); // marad�k
}

int main(void)
{
	printf("hello MOGI\n");
	char* s1 = "123 4567 abc jasdaiuh abcdef 9876";
	char s2[100];
	strcsere(s2, s1, "abc", "MOGI");
	char s3[100];
	strcsere(s3, s2, "abc", "MOGI");

	puts(s2);
	puts(s3);

	char* s4 = strcsere2(s1, "abc", "MOGI");
	puts(s4);
	free(s4);

	char s5[] = "hello MOGI:)12345:)98731";

	char* adat1 = s5;
	char* adat2 = lefejez(adat1, ":)");
	char* adat3 = lefejez(adat2, ":)");

	puts(adat1);
	puts(adat2);
	puts(adat3);

	_getch();
	return 0;
}