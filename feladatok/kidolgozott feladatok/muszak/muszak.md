# Műszak

Egy szöveges állomány azt tartalmazza, hogy egy cégnél mettől meddig volt egy személy műszakban. Minden sor egy műszakot tartalmaz, a név és a műszak időintervalluma közt tabulátor van az alábbi minta szerint:

```
2017.03.11.07:55 - 2017.03.11.19:33	Gipsz Jakab
2017.03.11.16:11 - 2017.03.12.04:02	Tipszmiksz II. Csaba
...
```

A program kérjen be egy adott időpontot és írja ki, hogy kik voltak akkor műszakban. Ha senki nem volt műszakban, azt is írja ki az alábbi mintának megfelelően:

```
Adjon meg egy időpontot: 2017.03.11.17:52
A megadott időpontban műszakban volt:
Gipsz Jakab
Tipszmiksz II. Csaba
```

```
Adjon meg egy időpontot: 2017.03.12.11:00
A megadott időpontban senki nem volt műszakban.
```

## Fontos információk a megoldáshoz
- a fájl akármennyi soros lehet, akármilyen hosszú sorokkal
- használj dinamikus memóriakezelést a beolvasásoknál
- a beolvasás és a feldolgozás soronként történjen
- a bemeneti fájlban nincsenek sorbarendezve a műszakok (kiíráskor sem kell semmilyen sorrendet tartani)
- az időintervallumok széleivel nem kell törődni, határesetekkel nem lesz tesztelve a program
