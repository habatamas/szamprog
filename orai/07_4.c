#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <conio.h>

#define VAROK_D 0 
#define VAROK_Z 1
#define VAROK_S 2


int main(void){
	int allapot = VAROK_D;

	while (1) {
		char ch;
		scanf("%c", &ch);
		printf("%c", ch);

		switch (allapot){
		case VAROK_D:
			if (ch == 'd') {
				allapot = VAROK_Z;
			}
			break;
		case VAROK_Z:
			if (ch == 'z') {
				allapot = VAROK_S;
			} else {
				allapot = VAROK_D;
			}
			break;
		case VAROK_S:
			if (ch == 's') {
				printf("+");
			}
			allapot = VAROK_D;
			break;
		}
	}

	_getch();
	return 0;
}