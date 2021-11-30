#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
	// beolvasandó számok darabszáma
	int db;
	printf("Hany szamot akarsz beirni? ");
	scanf("%d", &db);

	// memória foglalása a beolvasandó számoknak
	int *szamok = (int*)malloc( db*sizeof(int) );

	// számok beolvasása
	for (int i = 0; i < db; i++) {
		printf("%d. szam: ", i+1);
		scanf("%d", &(szamok[i]));
		// scanf("%d", szamok+i); // pointer aritmetika FTW
	}

	// feldolgozás (most csak kiírjuk)
	for (int i = 0; i < db; i++) {
		printf("%d\t", szamok[i]);
	}

	// terület felszabadítása
	free(szamok);

	_getch();
	return 0;
}