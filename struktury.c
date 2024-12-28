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
			pole[i][j].left=NULL;
			pole[i][j].right=NULL;
			pole[i][j].up=NULL;
			pole[i][j].down=NULL;
			pole[i][j].lup=NULL;
			pole[i][j].pup=NULL;
			pole[i][j].ldown=NULL;
			pole[i][j].pdown=NULL;
		}
	}
	return pole;
}

void ustaw_sasiadow(int y,int x,board**pole)
{
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			pole[i][j].bomby_blisko=0;
			if(j>0)
			{
				pole[i][j].left=&pole[i][j-1];
				if(pole[i][j-1].IsMine)
					pole[i][j].bomby_blisko++;
			}
                        if(j<x-1)
			{
				pole[i][j].right=&pole[i][j+1];
				if(pole[i][j+1].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
			if(i>0)
			{
				pole[i][j].up=&pole[i-1][j];
				if(pole[i-1][j].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
			if(i<y-1)
			{
				pole[i][j].down=&pole[i+1][j];
				if(pole[i+1][j].IsMine)
                                        pole[i][j].bomby_blisko++;
			}	
			if(i>0&&j>0)
			{
				pole[i][j].lup=&pole[i-1][j-1];
				if(pole[i-1][j-1].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
			if(i>0&&j<x-1)
			{
				pole[i][j].pup=&pole[i-1][j+1];
				if(pole[i-1][j+1].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
		      	if(i<y-1&&j>0)
			{
				pole[i][j].ldown=&pole[i+1][j-1];
				if(pole[i+1][j-1].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
			if(i<y-1&&j<x-1)
			{
				pole[i][j].pdown=&pole[i+1][j+1];
				if(pole[i+1][j+1].IsMine)
                                        pole[i][j].bomby_blisko++;
			}
			if(pole[i][j].bomby_blisko!=0)
				printf("sosiad: %d %d %d\n",i+1,j+1,pole[i][j].bomby_blisko);
		}
	}

}

