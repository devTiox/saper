#ifndef RUCHY_H
#define RUCHY_H
#include "struktury.h"
#include "wypisywanie.h"

extern int BOOM;

void koniec(PlayBoard**Plansza, board**bomby, int y, int x);

int ruch_f(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b);

int ruch(PlayBoard**Plansza, board**bomby, int y, int x);

void odkryj_sasiadow(PlayBoard**Plansza, board**bomby, int y, int x,int c ,int d,int* punkty);

void odkryj(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b,int *punkty);
#endif
