#ifndef WYPISYWANIE_H
#define WYPISYWANIE_H
#include "struktury.h"

int custom_mnoznik(int*x,int*y,int bombs_c);

void clear_console();

void wybor_poziomu(int*l_bomb,int*y,int*x,char move,int*mnoznik);
void help();
void zmienianie(int y,int x,PlayBoard**Plansza,int*punkty);
void poczatkowa(int y,int x,PlayBoard**Plansza);

#endif
