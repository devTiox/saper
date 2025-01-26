#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struktury.h"

PlayBoard**stworz_plansze(int y,int x)
{
	PlayBoard**Plansza=(PlayBoard**)malloc(y*sizeof(PlayBoard*));
	for(int i=0;i<y;i++)
	{
		Plansza[i]=(PlayBoard*)malloc(x*sizeof(PlayBoard));
		for(int j=0;j<x;j++)
		{
			Plansza[i][j].output=(char*)malloc(3*sizeof(char));
			Plansza[i][j].output[0]='[';
			Plansza[i][j].output[1]='-';
			Plansza[i][j].output[2]=']';
		}
	}
	return Plansza;
}
board**pole_minowe(int y,int x)
{
	board**pole=(board**)malloc(y*sizeof(board*));
	for(int i=0;i<y;i++)
	{
		pole[i]=(board*)malloc(x*sizeof(board));
		for(int j=0;j<x;j++)
		{
			pole[i][j].IsMine=0;
			pole[i][j].bomby_blisko=0;
		}
	}
	return pole;
}

void ustaw_sasiadow(int y,int x,board**pole)
{
	 int offsets[8][2] = 
	{
        {-1, -1}, {-1, 0}, {-1, 1},  // Góra-lewo, góra, góra-prawo
        { 0, -1},          { 0, 1},  // Lewo,         Prawo
        { 1, -1}, { 1, 0}, { 1, 1}   // Dół-lewo, dół, dół-prawo
    	};
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			int n=0;
			            // Iteracja po sąsiadach
            		for (int k = 0; k < 8; k++) 
					{
                		int ni = i + offsets[k][0];
                		int nj = j + offsets[k][1];

               			 // Sprawdzenie granic
                		if (ni >= 0 && ni < y && nj >= 0 && nj < x) 
						{
								n += pole[ni][nj].IsMine;
                    			 
               	 		}
            		}
			pole[i][j].bomby_blisko=n;
			//if(pole[i][j].bomby_blisko!=0)
				//printf("sosiad: %d %d %d\n",i+1,j+1,pole[i][j].bomby_blisko);
		}
	}

}

