#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(void) {
	// sztring == karaktert�mb + \0
	char str1[] = {'m','o','g','i','\0'};
	printf("%s\n",str1);
	str1[0] = 'g';
	str1[1] = 't';
	str1[2] = '3';
	str1[3] = '\0';
	printf("%s\n", str1);

	// sztring megad�sa
	char str2[] = "hello";
	str2[1] = 'a';
	printf("%s\n", str2);

	// sztring megad�sa
	char* str3 = "hello";
	// str3[1] = 'a'; /// nem m�k�dik!
	printf("%s\n", str3);

	// sztring beolvas�sa
	char str4[30];
	printf("irj be valamit: ");
	// gets(str4); // sor beolvas�sa
	scanf("%s", str4); // sz� beolvas�sa
	printf("beirtad: %s\n", str4);

	// sztring hossza 
	printf("beirt hossz: %d\n", strlen(str4));

	// str �sszehasonl�t�s
	printf("%d\n", strcmp("egyik",str4) );

	// str m�sol�s
	char str5[100];
	strcpy(str5, str4);
	printf("masolat: %s\n", str5);

	// hozz�f�z�s
	strcat(str5, " mogi");
	printf("masolat: %s\n", str5);

	// keres�s (ha nincs tal�lat -> NULL)
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

	// form�zott ki�r�s sztringbe
	char str8[100];
	sprintf(str8,"valami: %d %s", 123, "hello");
	puts(str8);

	// form�zott beolvas�s sztringb�l
	char str9[] = "9:28";
	int ora, perc;
	sscanf(str9, "%d:%d", &ora, &perc);
	printf("ora=%d perc=%d\n", ora, perc);

	_getch();
	return 0;
}