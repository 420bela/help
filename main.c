#include <stdio.h>
#include <stdlib.h>
#include "beolvas.h"
#include "excelbeolvas.h"
#include "bemenet.h"
#include "dicslist.h"
#include "idoszam.h"

#ifdef _WIN32
    #include <windows.h>
    #endif


void kiirKerdesek(Kerdesek *eleje) {
    Kerdesek *jelenlegi = eleje;

    while (jelenlegi != NULL) {
        printf("Nehezseg: %d\n", jelenlegi->nehezseg);
        printf("Kerdes: %s\n", jelenlegi->kerdes);
        printf("A: %s\n", jelenlegi->A);
        printf("B: %s\n", jelenlegi->B);
        printf("C: %s\n", jelenlegi->C);
        printf("D: %s\n", jelenlegi->D);
        printf("Valasz: %c\n", jelenlegi->valasz);
        printf("Kategoria: %s\n", jelenlegi->kategoria);

        jelenlegi = jelenlegi->kovetkezo;

        printf("\n");
    }
}

int main() {
    #ifdef _WIN32
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    #endif
    Kerdesek *eleje = NULL;
    const char *csvFajlnev = "kerdes.csv";
    csvBeolvas(csvFajlnev, &eleje);
    if(csvBeolvas(csvFajlnev,&eleje)==1){
        printf("Hiba");
        return 1;
    }
    kiirKerdesek(eleje);
    struct Jatekos jatekos;
    fbemenet(&jatekos);
    //printf("Jatekos adatai: %s - Pontszam: %d, Jatekido: %d perc\n", jatekos.nev, jatekos.pontszam, jatekos.jatek_ido);
    idoMeresInditas();
    //JÁTÉK IDE JÖN MAJD
    int jatekido=lejartIdoMeres();
    idoMeresLeallitas();
    // Dicsõséglistát frissítjük a játékos adataival és a játék idõvel
    frissitDicsosleglistat(&jatekos, jatekido);
    kiirDicsosleglistat();
        felszabadit(eleje);
    return 0;
}


