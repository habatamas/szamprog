#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void) {
	// statikus tömb
	int tomb1[10];

	// dinamikus tömb
	int* tomb2;
	tomb2 = malloc(10 * sizeof(int)); // foglalás
	
	tomb2[0] = 2;
	tomb2[1] = 12534;
	for (int i = 0; i < 10; i++)
		printf("%d\n", tomb2[i]);

	free(tomb2);

	// akármennyi szám beolvasása
	int db;
	printf("hany szamot fogsz beirni? ");
	scanf("%d", &db);

	int* tomb3 = malloc(db * sizeof(int));
	
	for (int i = 0; i < db; i++) {
		printf("irj be egy szamot: ");
		scanf("%d", tomb3+i);
	}

	printf("beirt szamok:\n");
	for (int i = 0; i < db; i++) {
		printf("   %d\n", tomb3[i]);
	}

	free(tomb3);


	printf("hello MOGI\n");

	// folyamatosan jönnek az adatok
	int beirt_db=0;
	int kapacitas = 10;
	int* dintomb = malloc(kapacitas * sizeof(int));

	while (1) {
		printf("irj be egy szamot: ");
		int szam;
		int siker = scanf("%d",&szam);

		if (siker != 1)
			break;
	
		// sikeres beolvasás esetén

		// elfogyott-e a hely?
		if (beirt_db == kapacitas) {
			// új terület foglalása
			int uj_kapacitas = kapacitas + 10;
			int* uj_dintomb = malloc(uj_kapacitas * sizeof(int));

			// régi adatok átmásolása
			memcpy(uj_dintomb, dintomb, kapacitas * sizeof(int));

			// régi hely felszabadítása
			free(dintomb);

			// változók aktualizálása
			kapacitas = uj_kapacitas;
			dintomb = uj_dintomb;
		}
	
		// új elem hozzáfûzése
		dintomb[beirt_db] = szam;
		beirt_db++;
	}

	for (int i = 0; i < beirt_db; i++) {
		printf("%d\n", dintomb[i]);
	}

	free(dintomb);

	_getch();
	return 0;
}