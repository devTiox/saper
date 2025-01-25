#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

#define MAX_ENTRIES 5



void czytaj_wyniki(Tabela wyniki[], int *count) {
    FILE *file = fopen("tabela.txt", "r");
    
    *count = 0;
    while (*count < MAX_ENTRIES && fscanf(file, "%d %s %d", &wyniki[*count].punktyt, wyniki[*count].nick, &wyniki[*count].punktyt) == 3) {
        (*count)++;
    }

    fclose(file);
}

void zapisz_wyniki(Tabela wyniki[], int count) {
    FILE *file = fopen("tabela.txt", "w");
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d\n", i + 1, wyniki[i].nick, wyniki[i].punktyt);
        printf("%d %s %d\n", i + 1, wyniki[i].nick, wyniki[i].punktyt);
    }

    fclose(file);
}

void zmien_wyniki(Tabela wyniki[], int *count, const char *nick, int punkty) {
    Tabela new_entry;
    strcpy(new_entry.nick, nick);
    new_entry.punktyt = punkty;

    int i;
    for (i = *count; i > 0 && wyniki[i - 1].punktyt < punkty; i--) {
        if (i < MAX_ENTRIES) {
            wyniki[i] = wyniki[i - 1];
        }
    }

    if (i < MAX_ENTRIES) {
        wyniki[i] = new_entry;
        if (*count < MAX_ENTRIES) {
            (*count)++;
        }
    }
}