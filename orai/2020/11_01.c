#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
	char str1[] = "hello"; // RW
	char* str2 = "hello"; // csak olvashat�
	char* str3 = "hello";

	if (strcmp(str1,str2)==0) // egyez�s
		printf("egyenlo\n");

	str1[0] = 'b';
	// str2[0] = 'b'; // hib�t dob

	printf("%s\n", str1);
	printf("%s\n", str2);

	// sztring m�sol�sa
	char str4[100];
	strcpy(str4, str3);
	printf("str4=%s\n", str4);

	// hozz�f�z�s
	strcat(strcat(str4, " szia"), " bello");
	printf("str4=%s\n", str4);

	// els� 3 karakter hozz�f�z�se
	strncat(str4, " MOGI", 3);
	printf("str4=%s\n", str4);

	// sztring hossza
	printf("hossz: %d\n", strlen(str4));

	// n karakter m�sol�sa !!!!!!!!!!!!!!!!
	char str5[100];
	strncpy(str5, str4, 13);
	str5[13] = '\0';
	printf("str5=%s\n", str5);

	// karakter keres�se
	char *talalat = strchr("hello MOGI", 'X');
	printf("talalat=%s\n", talalat);

	talalat = strstr("hello MOGI", "lo");
	printf("talalat=%s\n", talalat);

	// sztringb�l olvas�s
	int szam;
	char* str6 = "123";
	sscanf(str6, "%d", &szam);
	//szam = atoi(str6);
	printf("szam=%d\n", szam);

	// sztringbe �r�s
	char str7[100];
	sprintf(str7, "%d", 456);
	printf("str7=%s\n", str7);

	// string beolvas�sa soronk�nt
	char str_be[100];
	printf("irj be valamit: ");
	gets(str_be);
	printf("ezt irtad be: %s\n", str_be);


	// string beolvas�sa szavank�nt
	printf("irj be valamit: ");
	scanf("%s", str_be); // nem kell &!!!!
	printf("ezt irtad be: %s\n", str_be);


	return 0;
}