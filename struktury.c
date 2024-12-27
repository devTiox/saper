#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"

PlayBoard**stworz_plansze(int rozmiar)
{
	PlayBoard**Plansza=(PlayBoard**)malloc(rozmiar*sizeof(PlayBoard*));
	for(int i=0;i<rozmiar;i++)
	{
		Plansza[i]=(PlayBoard*)malloc(rozmiar*sizeof(PlayBoard));
		for(int j=0;j<rozmiar;j++)
		{
			Plansza[i][j].output=(char*)malloc(3*sizeof(char));
			Plansza[i][j].output[0]='[';
			Plansza[i][j].output[1]='-';
			Plansza[i][j].output[2]=']';
		}
	}
	return Plansza;
}
