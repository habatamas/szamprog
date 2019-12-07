#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(void) {
	// sztring == karaktertömb + \0
	char str1[] = {'m','o','g','i','\0'};
	printf("%s\n",str1);
	str1[0] = 'g';
	str1[1] = 't';
	str1[2] = '3';
	str1[3] = '\0';
	printf("%s\n", str1);

	// sztring megadása
	char str2[] = "hello";
	str2[1] = 'a';
	printf("%s\n", str2);

	// sztring megadása
	char* str3 = "hello";
	// str3[1] = 'a'; /// nem mûködik!
	printf("%s\n", str3);

	// sztring beolvasása
	char str4[30];
	printf("irj be valamit: ");
	// gets(str4); // sor beolvasása
	scanf("%s", str4); // szó beolvasása
	printf("beirtad: %s\n", str4);

	// sztring hossza 
	printf("beirt hossz: %d\n", strlen(str4));

	// str összehasonlítás
	printf("%d\n", strcmp("egyik",str4) );

	// str másolás
	char str5[100];
	strcpy(str5, str4);
	printf("masolat: %s\n", str5);

	// hozzáfûzés
	strcat(str5, " mogi");
	printf("masolat: %s\n", str5);

	// keresés (ha nincs találat -> NULL)
	char* str6 = "gepszerkesztes alapjai";
	char* talalat1 = strchr(str6, 'e');
	char* talalat2 = strstr(str6, "sz");
	printf("str6 = %d\n", str6);
	printf("talalat1 = %d\n", talalat1);
	printf("talalat2 = %d\n", talalat2);

	// strncpy!!!
	char str7[] = "*************************";
	strncpy(str7, "szia", 4);
	puts(str7);

	// formázott kiírás sztringbe
	char str8[100];
	sprintf(str8,"valami: %d %s", 123, "hello");
	puts(str8);

	// formázott beolvasás sztringbõl
	char str9[] = "9:28";
	int ora, perc;
	sscanf(str9, "%d:%d", &ora, &perc);
	printf("ora=%d perc=%d\n", ora, perc);

	_getch();
	return 0;
}