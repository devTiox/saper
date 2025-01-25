#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nick[100];
    int punktyt;
} Tabela;

void czytaj_wyniki(Tabela wyniki[], int *count);
void zapisz_wyniki(Tabela wyniki[], int count);
void zmien_wyniki(Tabela wyniki[], int *count, const char *nick, int punkty);
