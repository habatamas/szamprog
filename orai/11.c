#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

/* Karakter keresése adott sztringben.
s: a sztring amiben keresünk
c: a karakter amit keresünk
n-edik előfordulást keressük
(n=0 esetén az első előfordulás)
*/
char* strchr_n(char* s, char c, int n) {
	char* talalat = strchr(s, c);
	for (int i = 0; i < n && talalat!=NULL; i++) {
		talalat++;
		talalat = strchr(talalat, c);
	}
	return talalat;
}

// keresés és csere
void csere(char* cel, char* forras, char* mit, char* mire) {
	char* talalat = strstr(forras, mit);

	// spec. eset: nincs találat
	if (talalat == NULL) {
		strcpy(cel, forras);
		return;
	}

	// ált. eset: van egy találat
	// találat előtti részek átmásolása
	strncpy(cel, forras, talalat - forras);
	cel[talalat-forras] = '\0';

	// cseresztring hozzáfűzés
	strcat(cel, mire);

	// maradék átmásolása
	strcat(cel, talalat + strlen(mit));
}

int main(void) {
	char cserelt[100];
	csere(cserelt, "hello GT3 Tanszek\n", "GT3", "MOGI");
	printf("%s\n", cserelt);


	// (nem is igazi) sztring létrehozása
	char str1[] = { 'h', 'e', 'l' , 'l' , 'o' };
	for (int i = 0; i < 5; i++)
		printf("%c", str1[i]);
	printf("\n");

	// igazi C-s sztring
	// null terminated string
	char str2[] = { 'h', 'e', 'l' , 'l' , 'o', '\0' };
	printf("%s\n", str2);

	// kompakt forma
	char str3[] = "hello";
	printf("%s\n", str3);
	str3[0] = 'b';
	printf("%s\n", str3);

	// pointerrel
	char *str4 = "ujabb sztring"; // read only
	// str4[3] = 'X'; // ez nem megengedett

	// teszt
	char* str5 = str3;
	str5[0] = 'h';

	printf("hello MOGI\n");

	// sztring beolvasása
	// egy szó beolvasása scanf-fel
	/*char str_be[50];
	printf("irj be egy szot: ");
	scanf("%s", str_be);
	printf("ezt irtad be: %s\n", str_be);*/

	// sor beolvasása
	char sor_be[100];
	printf("ird be a jelszot: ");
	gets(sor_be); // get string = sor beolvasása

	// sztringek összehasonlítása
	char *jelszo = "abc123";

	if (strcmp(jelszo, sor_be) == 0) {
		printf("helyes\n");
	} else {
		printf("hibas\n");
	}

	// sztring másolása
	char jelszo_masolat[100];
	strcpy(jelszo_masolat, jelszo);
	printf("jelszo: %s\n", jelszo_masolat);

	// sztring hossza
	int l = strlen("sziasztok");
	printf("sziasztok hossza: %d\n", l);

	// összefűzés
	char *strA = "hello ";
	char *strB = "MOGI";
	char ossze[100];
	strcpy(ossze, strA);
	strcat(ossze, strB); // conCATenate
	printf("%s\n", ossze);

	// keresés
	char* szoveg = "ez itt egy hosszu sztring";

	// karakter keresése
	char *talalat = strchr(szoveg, 'h'); // találatra mutató ptr
	printf("%s\n", talalat);

	int talalat_index = talalat - szoveg;
	printf("hely: %d\n", talalat_index);

	talalat = strchr(szoveg, 'x');
	printf("%s\n", strchr_n(szoveg, 'e', 0));
	printf("%s\n", strchr_n(szoveg, 'e', 1));
	printf("%d\n", strchr_n(szoveg, 'e', 2));

	// sztring keresése sztringben
	talalat = strstr(szoveg, "egy"); // ugyanaz, mint az strchr
	                                 // csak itt str-t keresünk
	printf("%s\n", talalat);

	// n db karakter másolása
	char masolat[100];
	strncpy(masolat, "nagyon hosszu szoveg", 10); // !!!!!
	masolat[10] = '\0'; // manuálisan le kell zárni
	printf("%s\n", masolat);

	// n db karakter hozzáfűzése
	strncat(masolat, ":)###", 2);
	printf("%s\n", masolat);

	return 0;
}