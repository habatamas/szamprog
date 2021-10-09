#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// véletlenszámgenerátor inicializálása
	srand(time(NULL));

	// adatok bekérése
	int erkezes_ora, erkezes_perc, bedobott_penz;
	printf("Mikor erkeztel?\n");
	printf("   ora: ");
	scanf("%d", &erkezes_ora);
	printf("   perc: ");
	scanf("%d", &erkezes_perc);
	printf("Mennyi penzt dobtal be? ");
	scanf("%d", &bedobott_penz);

	// hány percet parkolhatunk?
	printf("%d percet parkolhatsz.\n", bedobott_penz / 5);

	// hány óra hány perckor jár le a parkolás
	int lejar_ora = erkezes_ora;
	int lejar_perc = erkezes_perc;
	lejar_perc += bedobott_penz / 5;

	// percek túlcsordulása
	lejar_ora += lejar_perc / 60;
	lejar_perc = lejar_perc % 60;

	printf("A parkolas lejar ekkor: %d:%d\n", lejar_ora,
		lejar_perc);

	// parkolóőr jön 8:00 és 17:59 között
	int parkoloor_ora = rand()%10 + 8;
	int parkoloor_perc = rand()%60;
	printf("A parkoloor jon ekkor: %d:%d\n",
		parkoloor_ora, parkoloor_perc);

	// kapunk-e büntetést?
	if (parkoloor_ora * 60 + parkoloor_perc >
		lejar_ora * 60 + lejar_perc) {
		printf("Megbuntet.\n");
	} else {
		printf("Nem buntet meg.\n");
	}

	if (parkoloor_ora > lejar_ora ||
		(parkoloor_ora == lejar_ora &&
			parkoloor_perc > lejar_perc)) {
		// megbüntet
	}

	_getch();
	return 0;
}