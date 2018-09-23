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
	// további utasítások
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

### Legyakrabban használt típusok printf/scanf-ben

| Adattípus |  Kiírás | Beolvasás |
| --- | --- | --- |
| ```signed char``` vagy ```char``` | ```%c``` | ```%c``` |
| ```int``` | ```%d``` | ```%d``` |
| ```float``` | ```%f``` vagy ```%g``` | ```%f``` |
| ```double ``` | ```%f``` vagy ```%g``` | ```%lf``` |

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

## Tömbök

Amennyiben sok ugyanolyan típusú adatot kell tárolni, tömböt használunk. A tömbök az alábbi tualjdonságokkal rendelkeznek:

- ugyanolyan típusú adattagokból állnak
- az adattagok száma a deklaráláskor kerül meghatározásra, ami később nem változhat
- az adattagokat sorszámuk szerint lehet elérni (indexelés)

### Tömb deklarálása

```C
// a tömb típusát és méretét tudni kell a deklaráláskor, ezért ezeket kell megadni
int egesz_szamok[10]; // 10 darab egész számot tartalmazó tömb
int a,b,c, t[10], d, q[5]; // tömbök együtt deklarálhatók sima változókkal és más tömbökkel is, ha a típus megegyezik

// kezdeti értékekkel is deklarálhatunk tömböt
float tomb[4] = {3.14, 1.4142136, 6e23, -4.5678};
int primszamok[] = {2, 3, 5, 7, 11}; // nem kell a méret, mivel az elemek felsorolásából egyértelmű
int tomb2[10] = {1, 2, 3}; // ilyenkor a tömb 10 elemű lesz, és az első három eleme lesz beállítva

// a tömb méretét változóban is megadhatjuk, de ekkor a deklaráláskor megadott méretű marad végig
int meret;
printf("mekkora legyen a tomb? "); scanf("%d", &mere); // felhasználó futáskor akármennyit írhat be
double szamok[meret]; // amennyit beírt, annyi elemű lesz a dömb
meret++; // ekkor a tömb mérete változatlan marad, mert futás közben nem méretezhető újra
```

### Tömb elemeinek elérése

A tömb elemei egyenként indexük megadásával elérhetőek. Az elemek viselkedése teljesen megegyezik a változóékkal: kiolvasható az értékük, kaphatnak új értéket.

```C
// deklarálunk egy új tömböt kezdeti értékekkel
int szamok[] = {8,9,10,11};

// tagonként kezeljük
szamok[0] = 123; // 0-nál kezdődnek az indexek -> a tömb tehát: {123, 9, 10, 11}
szamok[3] += szamok[2]+szamok[1]; // a tömb végül: {123, 9, 10, 30};

// TILOS kicímezni a tömbből!
szamok[4] = 0; // TILOS!
```

#### Példa: tömb másolása

Tömböt csak elemenként lehet elérni, ezért csak elemenként lehet másolni.

```C
// deklarálunk két tömböt
int szamok[] = {8,9,10,11};
int masik[4];

masik = szamok; // HIBÁS!

// helyes megoldás: elemenként másoljuk ciklusban
for(int i=0; i<4; i++){
    masik[i] = szamok[i];
}
```

## Struktúrák

A struktúrák a tömbökkel szemben akkor haszonsak, ha több, de különböző típusú adatot szeretnénk egybefogni.

```C
#include <stdio.>

// a főprogramon kívül definiálom a struktúrát
struct pont3d {
	double x; // az adattagok megadása a változók deklarálásához hasonló
	double y; // DE: kezdeti értékük nem lehet
	double z;
};

// a főprogramban úgy használom, mintha egy adattípus lenne
int main(){
    // deklarálok két 3d-s pontot, A-t és B-t
    struct pont3d A, B;
    
    // adattagok elérése névvel történik
    A.x = 3;
    A.y=-8; 
    A.z=-2.5;
    
    printf("%f\n", A.x);
    
    // struktúrát lehet másolni értékadással
    B = A;
    
    return 0;
}
```

## Beépített matematikai függvények

A forráskód elejére szükséges az alábbi include:
```C
#include <math.h>
```

A leggyakrabban az alábbi matematikai függvényekre van szükség:
```C
// abszolútérték
abs(x); // egész szám abszolútértéke
fabs(x); // valós szám abszolútértéke

// kerekítés
round(x); // kerekítés (3.5 -> 4)
ceil(x); // plafon (3.5 -> 4)
floor(x); // padló (3.5 -> 3)

// hatvány, gyök, logaritmus
pow(alap, kitevo); // hatványozás
sqrt(x); // négyzetgyök
cbrt(x); // négyzetgyök
exp(x); // e az x-ediken
log(x); // természetes logaritmus (ln)
log10(x); // 10-es alapú logaritmus
log2(x); // 2-es alapú logaritmus

// trigonometriai függvények (radián!)
sin(x); // szinusz
cos(x); // koszinusz
tan(x); // tangens
asin(x); // inverz szinusz
acos(x); // inverz koszinusz
atan(x); // inverz tangens
atan2(y,x); // inverz tangens, megfelelő síknegyed figyelembevételével
```

## Véletlenszám-generátor

A forráskód elejére az alábbi include-ok kellenek:
```C
#include <stdlib.h>
#include <time.h>
```

A véletlenszám-generátort egyszer használat előtt inicializálni kell:
```C
srand(time(NULL));
```

Ezután már lehet véletlenszámokat generálni:
```C
int r = rand(); // egész szám 0-tól RAND_MAX-ig
```

#### Példa
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// generátor indítása
	srand(time(NULL));
	
	// véletlenszám 0-tól RAND_MAX-ig
	int random = rand();
	printf("0-tol %d-ig: %d\n", RAND_MAX, random);
	
	// véletlenszám 1-től 10-ig
	int egytol_tizig = rand()%10+1;
	printf("1-től 10-ig: %d\n", egytol_tizig);
	
	// valós véletlenszám 0 és 1 között
	double random_valos = (double)rand()/RAND_MAX;
	printf("0-tol 1-ig: %f\n", random_valos);
	
	_getch();
	return 0;
}
```