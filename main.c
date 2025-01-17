#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"
#include "ruchy.h"
#include "generator_min.h"

int BOOM=1;

int main(int argc,char**argv)
{
	int l_bomb;
	int y, x;
	char move;
	int mnoznik;
	int punkty=0;
	wybor_poziomu(&l_bomb,&y,&x,move,&mnoznik);
	PlayBoard**Plansza=stworz_plansze(y,x);
	board**bomby=pole_minowe(y,x);
	rozmiesc_bomby(l_bomb,y,x,bomby);	
	ustaw_sasiadow(y,x,bomby);
	while(sprawdzenie(y,x,bomby)>0)
	{
		int poprawki=sprawdzenie(y,x,bomby);
		rozmiesc_bomby(poprawki,y,x,bomby);
		ustaw_sasiadow(y,x,bomby);
	}	
	for(int k=0;k<=x;k++)
		printf("%3d",k);
	printf("\n");
	poczatkowa(y,x,Plansza);
	while(BOOM)
	{
		punkty=punkty+(ruch(Plansza, bomby, y, x)*mnoznik);
		zmienianie(y,x,Plansza,&punkty);

	}
	printf("Koniec gry.Liczba zdobytych punktow:%d\n",punkty);
	
	return 0;
}
