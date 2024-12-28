#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"
#include "ruchy.h"
#include "generator_min.h"
int main(int argc,char**argv)
{
	int l_bomb;
	int y, x;
	char move;
	wybor_poziomu(&l_bomb,&y,&x,move);
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
	while(1)
	{
		ruch(Plansza);
		zmienianie(y,x,Plansza);

	}
}
