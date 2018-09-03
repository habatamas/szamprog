# C jegyzet

A Számítógépek programozásának alapjai c. tárgyhoz készült jegyzet.
Összeállította: Haba Tamás.

## Egy C-ben írt program felépítése

Egyszerűbb esetben csak egyetlen forrásfájlból áll a program, melynek szerkezete az alábbi: 

```C
// Visual Studio használatakor ez a sor is kell:
#define _CRT_SECURE_NO_WARNINGS

// a forráskód elején a program által használt include-ok kellenek, pl:
#include <stdio.h>
#include <conio.h>
// további inculde-ok
// ...

int main(){

	/* itt kezdődik a végrehajtás,
	    ide kerül a program "lényegi" része, pl: */
	printf("Hello World!\n");
	// további tasítások
	// ...
	
	_getch(); // ne lépjen ki egyből a program
	
	return 0; // <- mindig kell, ez jelzi program sikeres futását 
}
```

## Kommentek

A kommentek a program működésében nem vesznek részt, viszont a forráskódot egyértelművé és olvashatóbbá teszik.

```C
// komment állhat külön sorban
printf("Hello World!\n"); // komment állhat utasítás után is
/* de akár több
sorból is állhat */

```

## Változók deklarálása és értékadása

```C
// minden változót használat előtt deklarálni kell
// a típus és a név megadásával
char ch;
int b=55; // változó kaphat kezdeti értéket
float x, pi = 3.141592, y; // ugyanolyan típusból egyszerre több változó is deklarálható

// értékadás
ch = 'R';
x = 1.22;
y = 1e26;

// egy változó értéke akárhányszor felülírható
x = 44.1;

// az értékadás jobb oldalán akár összetett kifejezés is állhat
x = 3*1.1/y + pi;
```

## Adattípusok

Az adattípusok a változók értékkészletét határozzák meg. Különböző platformokon eltérő lehet az értékkészlet, ezért a szabány egy minimális szélességű intervallumot határozott meg.

| Adattípus |  Előírt legszűkebb értékkészlet |
| --- | --- |
| ```signed char``` vagy ```char``` | egész szám -127-től +127-ig |
| ```unsigned char``` | egész szám 0-tól 255-ig |
| ```short int``` vagy ```short``` | egész szám -32767-től +32767-ig |
| ```unsigned short int``` vagy ```unsigned short``` | egész szám 0-tól 65535-ig |
| ```int``` | egész szám -32767-től +32767-ig |
| ```unsigned int``` | egész szám 0-tól 65535-ig |
| ```long int``` vagy ```long``` | egész szám -2147483647-től +2147483647-ig |
| ```unsigned long int``` vagy ```unsigned long``` | egész szám 0-tól 4294967295-ig |
| ```float``` | lebegőpontos szám ~6 tizedesjeggyel |
| ```double ``` | lebegőpontos szám ~10 tizedesjeggyel |

## Számábrázolás

```C
char ch;
int n;
double x;

// az alábbi értékadások egyenértékűek
n = 162; // tízes számrendszer
n = 0xA2; // 16-os számrendszer
n = 0242; // 8-as számrendszer
n = 0b10100010; // 2-es számrendszer

// a karakter is csak egy szám
ch = 'C'; // A C karakter ASCII kódja
ch = 67; // ugyanezt jelenti

x = 0.000023461; // tizedespont
x = 2.3461e-5; // normál alak
```

##  Kiírás és beolvasás

```C
// kiírás printf-fel
printf("sima szöveg");

// speciális karakterek
printf("egyik sor\nmásik sor"); // sortörés
printf("egyik oszlop\tmásik oszlop"); // tabulátor
printf("\n"); // sortörés
printf("\\"); // a \ karakter
printf("\""); // a " karakter

// értékek behelyettesítése a szövegbe
int osszeg = 1325;
printf("végösszeg: %d Ft\n", osszeg); // ezt írja ki: végösszeg: 1325 Ft
printf("%d tyúk %d nap alatt %d tojást tojt\n", 9, 2, 18);
// ezt írja ki: 9 tyúk 2 nap alatt 18 tojást tojt

// beolvasás scanf-fel
int a; float b; double c;
printf("írj be egy egész számot: ");
scanf("%d", &a);
printf("írj be egy tetszőleges számot: ");
scanf("%f", &b);
printf("írj be egy tetszőleges számot: ");
scanf("%lf", &c);
```

## Operátorok

### Aritmetikai műveletek

| Operátor | Jelentés |
| --- | --- |
| ```+``` | összeadás |
| ```-``` | kivonás |
| ```*``` | szorzás |
| ```/``` | osztás |
| ```%``` | osztási maradék |

### Bináris műveletek

| Operátor | Jelentés |
| --- | --- |
| ```~``` | bitenkénti negálás |
| ```&``` | bitenkénti és |
| ```\|``` | bitenkénti vagy |
| ```^``` | bitenkénti kizáró vagy |
| ```>>``` | jobbraléptetés |
| ```<<``` | balraléptetés |

### Összehasonlító operátorok

Feltételekben és ciklusokban kellenek.

| Operátor | Jelentés |
| --- | --- |
| ```==``` | egyenlő |
| ```!=``` | nem egyenlő |
| ```<``` | kisebb |
| ```<=``` | kisebbegyenlő |
| ```>``` | nagyobb |
| ```>=``` | nagyobbegyenlő |

### Logikai operátorok

Összetett feltételeknél hasznosak.

| Operátor | Jelentés |
| --- | --- |
| ```!``` | tagadás |
| ```&&``` | logikai és |
| ```\|\|``` | logikai vagy |

## Elágazások

### If

```C
if( feltétel ){
	igaz ág
	...
}
```

![feltétel](if.svg)

### If + else

```C
if( feltétel ){
	igaz ág
	...
} else {
	hamis ág
	...
}
```

![feltétel hamis ággal](if_else.svg)


### Switch + case

```C
switch( vizsgált_érték ){
	case érték1:
		igaz ág érték1 esetén
		...
		break;
	case érték2:
		igaz ág érték2 esetén
		...
		break;
	...
	default:
		minden más esetben
		...
		break;
}
```

## Ciklusok

### While

```C
while( feltétel ){
	ciklusmag
	...
}
```

![elöltesztelő ciklus](while.svg)

### Do + while (hátultesztelő ciklus)

```C
do{
	ciklusmag
	...
} while( feltétel );
```

![hátultesztelő ciklus](do_while.svg)

### For

```C
for( előkészítés; feltétel; léptetés ){
	ciklusmag
	...
}
```

![hátultesztelő ciklus](for.svg)