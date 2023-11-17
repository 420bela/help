#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excelbeolvas.h"
#include "beolvas.h"

void csvBeolvas(const char *fajlnev, Kerdesek **fej) {
    char buffer[1000];
    FILE *fajl = fopen(fajlnev, "r");
    if (fajl == NULL) {
        printf("Hiba: Nem sikerult megnyitni a fajlt.\n");
        return;
    }

    fgets(buffer, sizeof(buffer), fajl);  // Olvassa be a fejlec sort és dobja el

    while (fgets(buffer, sizeof(buffer), fajl) != NULL) {
                    printf("%s", buffer);
        Kerdesek *uj = (Kerdesek *)malloc(sizeof(Kerdesek));
        char *token = strtok(buffer, ";");
        if (token != NULL) {
            uj->nehezseg = atoi(token);
            strncpy(uj->kerdes, strtok(NULL, ";"), sizeof(uj->kerdes) - 1);
            uj->kerdes[sizeof(uj->kerdes) - 1] = '\0';
            strncpy(uj->A, strtok(NULL, ";"), sizeof(uj->A) - 1);
            uj->A[sizeof(uj->A) - 1] = '\0';
            strncpy(uj->B, strtok(NULL, ";"), sizeof(uj->B) - 1);
            uj->B[sizeof(uj->B) - 1] = '\0';
            strncpy(uj->C, strtok(NULL, ";"), sizeof(uj->C) - 1);
            uj->C[sizeof(uj->C) - 1] = '\0';
            strncpy(uj->D, strtok(NULL, ";"), sizeof(uj->D) - 1);
            uj->D[sizeof(uj->D) - 1] = '\0';
            uj->valasz = strtok(NULL, ";")[0];
            strncpy(uj->kategoria, strtok(NULL, ";"), sizeof(uj->kategoria) - 1);
            uj->kategoria[sizeof(uj->kategoria) - 1] = '\0';
        }

        hozzafuz(fej, uj);
    }

    fclose(fajl);
}
