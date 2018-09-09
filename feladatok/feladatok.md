# Számítógépek programozásának alapjai feladatok

A tantárgy sikeres teljesítéséhez elengedhetetlen a rendszeres gyakorlás. Ez a feladatgyűjtemény a készülést segíti, de mindenkinek magának kell érezni, hogy mennyi gyakorlásra van szüksége.

A feladatok megoldása nem a teljes (lefordítható) forráskódot tartalmazza, csupán a lényeges részt.

Eredményes gyakorlást kívánok!

## 1. hét

### Üdvözlet

Írj egy programot, ami kiírja, hogy "Hello BME!"!
<details>
 <summary>megoldás:</summary>
 
```C
printf("Hello BME!\n");
```
</details>

### Doboz

Írj egy programot, ami kirajzol egy #-ekből álló 4 karakter széles, 3 karakter magas dobozt. Csak egyetlen printf-et használhatsz!
<details>
 <summary>megoldás:</summary>
 
```C
printf("####\n####\n####\n");
```
</details>

### Maradékos osztás

A program kérjen be egy osztandót és egy osztót, majd írja ki a hányadost és a maradékot!
<details>
 <summary>megoldás:</summary>
 
```C
int osztando, oszto;
printf("osztando: ");
scanf("%d", &osztando);
printf("oszto: ");
scanf("%d", &oszto);
printf("hanyados: %d\nmaradek: %d\n", osztando/oszto, osztando%oszto);
```
</details>

### Téglatest

A program kérje be egy téglatest oldalhosszait, majd írja ki felszínét, térfogatát és éleinek összhosszúságát!
<details>
 <summary>megoldás:</summary>
 
```C
double a,b,c;
printf("egyik oldal hossza: "); scanf("%lf", &a);
printf("masik oldal hossza: "); scanf("%lf", &b);
printf("harmadik oldal hossza: "); scanf("%lf", &c);
printf("felszin = %g\n", 2*a*b+2*a*c+2*b*c);
printf("terfogat = %g\n", a*b*c);
printf("elhossz = %g\n", 4*a+4*b+4*c);
```
</details>

### Mozgás

A program kérje be egy egyenes vonalon mozgó pont kezdőpozícióját, kezdősebességét, gyorsulását és mozgásának idejét. Eredményként írja ki a mozgás végén a pozícióját és sebességét. A mozgás során a pont gyorsulása állandó. Az eredményeket 4 tizedes pontossággal írja ki.
<details>
 <summary>megoldás:</summary>
 
```C
// kezdeti paraméterek beolvasása
double x0,v0,a,t;
printf("kezdopozicio: "); scanf("%lf", &x0);
printf("kezdosebesseg: "); scanf("%lf", &v0);
printf("gyorsulas: "); scanf("%lf", &a);
printf("ido: "); scanf("%lf", &t);

// mozgás számítása (négyzetes úttörvény)
double xt = x0 + a/2*t*t + v0 * t;
double vt = v0 + a*t;

// eredmények kiírása
printf("pozicio a mozgas vegen: %.4f\n", xt);
printf("vegsebesseg: %.4f\n", vt);
```
</details>

### Kedvező ár

Egy bolt termékeinek árait úgy akarják emelni, hogy a vásárlóknak ne legyen szembetűnő. Éppen ezért minden termék árát úgy emelik, hogy 99-re végződjön. Az eleve 99-re végződő árak változatlanul maradnak. Írj programot, ami bekéri egy termék árát, és kiírja az áremelés utáni árat!
<details>
 <summary>megoldás:</summary>
 
```C
// régi ár bekérése
int regi;
printf("ar: "); scanf("%d", &regi);

// új ár kiszámítása
int uj = regi + 99 - regi%100;

// új ár kiírása
printf("uj ar: %d\n", uj);
```
</details>

### Törtszámok

A program kérje be két törtszám számlálóját és nevezőjét, majd írja ki az összegüket törtvonalas tört alakban. Egyszerűsítést nem kell végezni.
<details>
 <summary>megoldás:</summary>
 
```C
int a_nev, a_szam, b_nev, b_szam;
printf("egyik szam szamlaloja: "); scanf("%d", &a_szam);
printf("egyik szam nevezoje: "); scanf("%d", &a_nev);
printf("masik szam szamlaloja: "); scanf("%d", &b_szam);
printf("masik szam nevezoje: "); scanf("%d", &b_nev);

printf("az osszeg: %d/%d\n", a_nev*b_szam+a_szam*b_nev, a_nev*b_nev);
```
</details>

## 2. hét

### Időintervallum

A program kérjen be óra:perc:másodperc formátumban egy időintervallum elejét és végét. Írja ki az intervallum hosszát másodpercben és óra:perc:másodperc formátumban is.

<details>
 <summary>működési példa:</summary>
 
```
kezdo idopont: 8:15:9
vegso idopont: 12:21:38
Az intervallum 14789 masodpercig tart.
Az intervallum hossza: 4:6:29
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük az intervallum végeit
int kezd_ora, kezd_perc, kezd_masodperc;
printf("kezdo idopont: ");
scanf("%d:%d:%d", &kezd_ora, &kezd_perc, &kezd_masodperc);
int veg_ora, veg_perc, veg_masodperc;
printf("vegso idopont: ");
scanf("%d:%d:%d", &veg_ora, &veg_perc, &veg_masodperc);

// intervallum hossza másodpercekben
int masodpercek = veg_ora*3600 + veg_perc*60 + veg_masodperc - kezd_ora*3600 - kezd_perc*60 - kezd_masodperc;
printf("Az intervallum %d masodpercig tart.\n", masodpercek);

// kiírás szép formátumban
printf("Az intervallum hossza: %d:%d:%d\n", masodpercek/3600, masodpercek/60%60, masodpercek%60);

```
</details>

### Nagybetűsítő

A program kérjen be egy kisbetűt és írja ki a beírt betűt nagybetűsítve. (Megjegyzés: scanf-fel való karakter beolvasásánál is kell entert ütni a bevitelhez.)
<details>
 <summary>megoldás:</summary>
 
```C
char ch;
printf("irj be egy kisbetut: "); scanf("%c", &ch);
printf("nagybetu: %c", ch-32);
```
</details>

### Négyzetszámok

A program írja ki (sorszámokkal együtt) az első 20 négyzetszámot!
<details>
 <summary>megoldás:</summary>
 
```C
for(int i=0; i<=20; i++){
    printf("%d.\t%d\n", i, i*i);
}
```
</details>

### Szorzótábla

A program írja ki a példa szerinti formában a szorzótáblát
<details>
 <summary>működési példa:</summary>
 
```
    1    2    3    4    5    6    7    8    9   10
    2    4    6    8   10   12   14   16   18   20
    3    6    9   12   15   18   21   24   27   30
    4    8   12   16   20   24   28   32   36   40
    5   10   15   20   25   30   35   40   45   50
    6   12   18   24   30   36   42   48   54   60
    7   14   21   28   35   42   49   56   63   70
    8   16   24   32   40   48   56   64   72   80
    9   18   27   36   45   54   63   72   81   90
   10   20   30   40   50   60   70   80   90  100
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
for(int i=1; i<=10; i++){
    for(int j=1; j<=10; j++){
        printf("%5d", i*j);
    }
    printf("\n");
}
```
</details>

### Doboz II.

A program kérje be egy doboz szélességét és magasságát, majd rajzolja ki karakterekből a minta szerint.
<details>
 <summary>minta:</summary>
 
```
#-------#
|       |
|       |
|       |
#-------#
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a doboz méreteit
int sz, m;
printf("szelesseg: "); scanf("%d", &sz);
printf("magassag: "); scanf("%d", &m);

// doboz teteje
printf("#");
for(int i=1; i<=sz-2; i++)
    printf("-");
printf("#\n");

// doboz oldalai
for(int i=1; i<=m-2; i++){
    printf("|");
    for(int j=1; j<=sz-2; j++)
        printf(" ");
    printf("|\n");
}

// doboz alja
printf("#");
for(int i=1; i<=sz-2; i++)
    printf("-");
```
</details>
<details>
 <summary>elegánsabb megoldás:</summary>
 
```C
// bekérjük a doboz méreteit
int sz, m;
printf("szelesseg: "); scanf("%d", &sz);
printf("magassag: "); scanf("%d", &m);

// koordináták alapján döntjük el a kiírandó karaktert
for(int y=1; y<=m; y++){
    for(int x=1; x<=sz; x++){
        if( (x==1 || x==sz) && (y==1 || y==m) ){
            printf("#");
        } else if(x==1 || x==sz){
            printf("|");
        } else if(y==1 || y==m){
            printf("-");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
```
</details>

### Doboz III.

A program kérje be egy négyzetes doboz oldalhosszát, majd rajzolja ki karakterekből a minta szerint.
<details>
 <summary>minta:</summary>
 
```
#---#
|\  |
| \ |
|  \|
#---#
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a doboz oldalhosszát
int oldal;
printf("oldalhossz: "); scanf("%d", &oldal);

// koordináták alapján döntjük el a kiírandó karaktert
for(int y=1; y<=oldal; y++){
    for(int x=1; x<=oldal; x++){
        if( (x==1 || x==oldal) && (y==1 || y==oldal) ){
            printf("#");
        } else if(x==1 || x==oldal){
            printf("|");
        } else if(y==1 || y==oldal){
            printf("-");
        } else if(x==y){
            printf("\\");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
```
</details>

### Doboz IV.

A program kérje be egy négyzetes doboz oldalhosszát, majd rajzolja ki karakterekből a minta szerint. A minimális oldalhossz 5 (akkor is ekkorát rajzoljon ki, ha a felhasználó kisebb számot adott meg). Az oldalhossz csak páratlan lehet, ha a megadott szám páros, akkor a nála eggyel nagyobb páratlan szám legyen az oldalhossz.
<details>
 <summary>minta:</summary>
 
```
#-----#
|\   /|
| \ / |
|  X  |
| / \ |
|/   \|
#-----#
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a doboz oldalhosszát
int oldal;
printf("oldalhossz: "); scanf("%d", &oldal);

// oldalhossz javítása, ha szükséges
if(oldal<5)
    oldal = 5;
if(oldal%2==0)
    oldal++;

// koordináták alapján döntjük el a kiírandó karaktert
for(int y=1; y<=oldal; y++){
    for(int x=1; x<=oldal; x++){
        if( (x==1 || x==oldal) && (y==1 || y==oldal) ){
            printf("#");
        } else if(x==(oldal+1)/2 && x==y){
            printf("X");
        } else if(x==1 || x==oldal){
            printf("|");
        } else if(y==1 || y==oldal){
            printf("-");
        } else if(x==y){
            printf("\\");
        } else if(x+y==oldal+1){
            printf("/");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
```
</details>

### Faktoriális

Írja ki a program a beolvasott szám faktoriálisát. (A faktoriális nagyon nagy szám is lehet, ennek megfelelő típust kell választani.)
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a számot és a kitevőt
int n;
printf("irj be egy szamot: "); scanf("%d", &n);

// faktoriális kiszámítása
unsigned long int fakt=1;

for(int i=1; i<=n; i++)
    fakt *= i;


// eredmény kiírása
printf("%d! = %lu", n, fakt);
```
</details>

### Fibonacci

Írja ki a program a Fibonacci-sorozat első 20 elemét! Az első két elem értéke 1, a többi elem pedig az előző kettő összegével egyenlő. 
<details>
 <summary>megoldás:</summary>
 
```C
int mostani=1, kovetkezo=1, kovetkezo_utani;
for(int i=1; i<=20; i++){
    // jelenlegi tag kiírása
    printf("%d\n", mostani);
    
    // következő utáni tag kiszámítása
    kovetkezo_utani = mostani+kovetkezo;
    
    // léptetés
    mostani = kovetkezo;
    kovetkezo = kovetkezo_utani;
}
```
</details>

### Hatvány

A program kérjen be egy valós alapot és egy egész kitevőt, majd írja ki a hatvány értékét.
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük az alapot és a kitevőt
double alap;
printf("alap: "); scanf("%lf", &alap);
int kitevo;
printf("kitevo: "); scanf("%d", &kitevo);

// hatvány számolása
double hatvany = 1;
for(int i=1; i<=kitevo; i++){
    hatvany*=alap;
}

// eredmény kiírása
printf("hatvany: %g\n", hatvany);
```
</details>

### Négyzetgyök

A program kérjen be egy valós számot, és írja ki négyzetgyökét tízezred pontossággal. A számoláshoz [intervallumfelezést](http://www.mathpath.org/Algor/squareroot/algor.square.root.binary.htm) célszerű használni.
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a számot
double szam;
printf("irj be egy szamot: "); scanf("%lf", &szam);

// a kezdeti intervallum: 0-tól szam-ig
double also=0, felso=szam;

// intervallumfelezés, amíg tízezred pontosságú nem lesz az eredmény
while(felso-also > 0.0001){
    // intervallum közepe
    double kozep = (also+felso)/2;
    
    // felezés - melyik felében van a megoldás?
    if(kozep*kozep < szam){
        also = kozep;
    } else {
        felso = kozep;
    }
}

// eredmény kiírása
printf("negyzetgyok: %f\n", (also+felso)/2);
```
</details>

### n-edik gyök

Módosítsd az előző programot úgy, hogy egész gyökkitevőt is kérjen be.
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a számot és a kitevőt
double szam;
printf("irj be egy szamot: "); scanf("%lf", &szam);
int n;
printf("ird be a gyokkitevot: "); scanf("%d", &n);

// a kezdeti intervallum: 0-tól szam-ig
double also=0, felso=szam;

// intervallumfelezés, amíg tízezred pontosságú nem lesz az eredmény
while(felso-also > 0.0001){
    // intervallum közepe
    double kozep = (also+felso)/2;
    
    // hatvány kiszámítása
    double hatvany=1;
    for(int i=1; i<=n; i++){
        hatvany *= kozep;
    }
    
    // felezés - melyik felében van a megoldás?
    if(hatvany < szam){
        also = kozep;
    } else {
        felso = kozep;
    }
}

// eredmény kiírása
printf("gyok: %f\n", (also+felso)/2);
```
</details>

### Sakktábla I.

A program # és szóköz karakterekből rajzoljon ki egy sakktáblát (8x8 mezőt).
<details>
<summary>működési példa:</summary>
 
```
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// soronként és azon belül oszloponként minden karaktert kirajzolunk
for(int sakk_y=1; sakk_y<=8; sakk_y++){
    for(int sakk_x=1; sakk_x<=8; sakk_x++){
        // mező színének meghatározása
        if((sakk_x+sakk_y)%2==0)
            printf("#");
        else
            printf(" ");
    }
    printf("\n");
}
```
</details>

### Sakktábla II.

A program úgy rajzolja ki a sakktáblát, hogy egy a mezők számát (széltében és magasságban) meg lehet adni.
<details>
<summary>működési példa:</summary>
 
```
sakktabla szelessege (db mezo): 7
sakktabla magassage (db mezo): 6
# # # #
 # # # 
# # # #
 # # # 
# # # #
 # # # 

```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a sakktábla méreteit
int sakk_sz, sakk_m;
printf("sakktabla szelessege (db mezo): "); scanf("%d", &sakk_sz);
printf("sakktabla magassage (db mezo): "); scanf("%d", &sakk_m);

// soronként és azon belül oszloponként minden karaktert kirajzolunk
for(int sakk_y=1; sakk_y<=sakk_m; sakk_y++){
    for(int sakk_x=1; sakk_x<=sakk_sz; sakk_x++){
        // mező színének meghatározása
        if((sakk_x+sakk_y)%2==0)
            printf("#");
        else
            printf(" ");
    }
    printf("\n");
}
```
</details>

### Sakktábla III.

A program úgy rajzolja ki a sakktáblát, hogy egy mező szélességét és magasságát is meg lehet adni.
<details>
<summary>működési példa:</summary>
 
```
mezo szelessege (db karakter): 4
mezo magassage (db karakter): 3
####    ####    ####    ####    
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
    ####    ####    ####    ####
####    ####    ####    ####    
####    ####    ####    ####    
####    ####    ####    ####    
    ####    ####    ####    ####
    ####    ####    ####    ####
    ####    ####    ####    ####
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a sakktábla méreteit
int mezo_sz, mezo_m;
printf("mezo szelessege (db karakter): "); scanf("%d", &mezo_sz);
printf("mezo magassage (db karakter): "); scanf("%d", &mezo_m);

// két koordinátarendszer: mezők koordinátái és mezőn belüli koordináták
for(int sakk_y=1; sakk_y<=8; sakk_y++){
    for(int mezo_y=1; mezo_y<=mezo_m; mezo_y++){
        for(int sakk_x=1; sakk_x<=8; sakk_x++){
            for(int mezo_x=1; mezo_x<=mezo_sz; mezo_x++){
                // mező színének meghatározása
                if((sakk_x+sakk_y)%2==0)
                    printf("#");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}
```
</details>

### Sakktábla IV.

A program úgy rajzolja ki a sakktáblát, hogy a mezők számát és méretét is meg lehessen adni.
<details>
<summary>működési példa:</summary>
 
```
sakktabla szelessege (db mezo): 7
sakktabla magassage (db mezo): 6
mezo szelessege (db karakter): 5
mezo magassage (db karakter): 4
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####     
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####     
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
#####     #####     #####     #####
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####     
     #####     #####     #####   
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// bekérjük a sakktábla méreteit
int sakk_sz, sakk_m, mezo_sz, mezo_m;
printf("sakktabla szelessege (db mezo): "); scanf("%d", &sakk_sz);
printf("sakktabla magassage (db mezo): "); scanf("%d", &sakk_m);
printf("mezo szelessege (db karakter): "); scanf("%d", &mezo_sz);
printf("mezo magassage (db karakter): "); scanf("%d", &mezo_m);

// két koordinátarendszer: mezők koordinátái és mezőn belüli koordináták
for(int sakk_y=1; sakk_y<=sakk_m; sakk_y++){
    for(int mezo_y=1; mezo_y<=mezo_m; mezo_y++){
        for(int sakk_x=1; sakk_x<=sakk_sz; sakk_x++){
            for(int mezo_x=1; mezo_x<=mezo_sz; mezo_x++){
                // mező színének meghatározása
                if((sakk_x+sakk_y)%2==0)
                    printf("#");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}
```
</details>

### Osztók

Kérjen be a program egy számot, majd írja ki az összes osztóját és osztóinak számát.
<details>
 <summary>megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// egyesével oszthatóság vizsgálata
int osztok_szama = 0;
for(int i=1; i<=szam; i++){
    if(szam%i == 0){
        printf("%d\n", i);
        osztok_szama++;
    }
}

printf("osztok szama: %d\n", osztok_szama);
```
</details>

### Osztópárok

A program ezúttal az osztópárokat írja ki.
<details>
 <summary>megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// egyesével oszthatóság vizsgálata
for(int i=1; i*i<=szam; i++){
    if(szam%i == 0){
        printf("%d\t%d\n", i, szam/i);
    }
}
```
</details>

### Prímteszt

A program döntse el egy bekért számról, hogy prímszám-e.
<details>
 <summary>megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// osztók számlálása
int osztok_szama = 0;
for(int i=1; i<=szam; i++){
    if(szam%i == 0){
        osztok_szama++;
    }
}

// prímszám definíció szerint: két osztója van
if(osztok_szama==2)
    printf("primszam");
else
    printf("nem primszam");
```
</details>
<details>
 <summary>hatékonyabb megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// osztók számlálása (páronként!)
// így sajnos az 1-et is prímszámnak veszi
int osztok_szama = 0;
for(int i=1; i*i<=szam; i++){
    if(szam%i == 0){
        osztok_szama+=2;
    }
}

// prímszám definíció szerint: két osztója van
// 1-et külön kezeljük
if(osztok_szama==2 && szam!=1)
    printf("primszam");
else
    printf("nem primszam");
```
</details>

### Első 100 prímszám

A program írja ki a 100 első prímszámot.
<details>
 <summary>megoldás:</summary>
 
```C
// érdemes 2-től indítani a számlálást
int szam=2;
int primek_szama=0;
while(primek_szama<100){
    // osztók számlálása (páronként!)
    int osztok_szama = 0;
    for(int i=1; i*i<=szam; i++){
        if(szam%i == 0){
            osztok_szama+=2;
        }
    }

    // prímteszt def. szerint
    if(osztok_szama==2){
        printf("%d\n", szam);
        primek_szama++;
    }
    
    // következő számra lépés
    szam++;
}
```
</details>

### Prím, félprím, nemprím

A bekért számról döntse el a program, hogy prím, félpím (két prím szorzata) vagy nem prím.
<details>
 <summary>megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// osztók számlálása
int osztok_szama = 0;
for(int i=1; i<=szam; i++){
    if(szam%i == 0){
        osztok_szama++;
    }
}

// eldöntés switch-csel
switch(osztok_szama){
    case 2:
        printf("prim\n");
        break;
    case 4:
        printf("felprim\n");
        break;
    default:
        printf("nem prim\n");
        break;
}
```
</details>

### Prímtényezős felbontás

Határozzuk meg egy szám prímtényezőit az alábbi mintának megfelelően.
<details>
<summary>működési példa:</summary>
 
```
irj be egy szamot: 840
       840|2
       420|2
       210|2
       105|3
        35|5
         7|7
         1|
```
</details>
<details>
 <summary>megoldás:</summary>
 
```C
// szám bekérése
int szam;
printf("irj be egy szamot: "); scanf("%d", &szam);

// addig osztogatjuk, amíg 1 nem lesz belőle
while(szam != 1){
    // megkeressük a legkisebb osztóját
    int oszto=2;
    while(szam%oszto!=0)
        oszto++;
        
    // kiírjuk
    printf("%10d|%d\n", szam, oszto);
    
    // elosztjuk vele
    szam /= oszto;
}

// utolsó sor kiírása
printf("         1|\n");
```
</details>

### Törtszámok II.

A program kérjen be két törtszámot (számlálóval és nevezővel), majd írja ki összegüket tört alakban, egyszerűsítve!
<details>
 <summary>megoldás:</summary>
 
```C
// számok bekérése
int szamlalo_1, nevezo_1, szamlalo_2, nevezo_2;
printf("egyik szam szamlaloja: "); scanf("%d", &szamlalo_1);
printf("egyik szam nevezoje: "); scanf("%d", &nevezo_1);
printf("masik szam szamlaloja: "); scanf("%d", &szamlalo_2);
printf("masik szam nevezoje: "); scanf("%d", &nevezo_2);

// összeg számítása
int szamlalo_osszeg = szamlalo_1*nevezo_2 + szamlalo_2*nevezo_1;
int nevezo_osszeg = nevezo_1*nevezo_2;

// legnagyobb közös osztó számítása
int lnko=1;
for(int i=2; i<=nevezo_osszeg; i++)
    if(nevezo_osszeg%i == 0 && szamlalo_osszeg%i == 0)
        lnko = i;

// tört egyszerűsítése
szamlalo_osszeg /= lnko;
nevezo_osszeg /= lnko;

// eredmény kiírása
printf("%d/%d + %d/%d = %d/%d\n", szamlalo_1, nevezo_1, szamlalo_2, nevezo_2, szamlalo_osszeg, nevezo_osszeg);
```
</details>
