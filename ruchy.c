#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "ruchy.h"

void koniec(PlayBoard**Plansza, board**bomby, int y, int x)
{
        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                        if(bomby[i][j].IsMine==1)
                                Plansza[i][j].output[1]='*';
                }
        }
}

void odkryj(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b, int*punkty)
{
        if(Plansza[a][b].output[1]=='-'){
                (*punkty)++;
                if(bomby[a][b].bomby_blisko==0){
                        Plansza[a][b].output[1]='0';
                        odkryj_sasiadow(Plansza, bomby, y, x, a, b, punkty);
                }
                else
                {
                        Plansza[a][b].output[1]=bomby[a][b].bomby_blisko + '0';
                }
        }
}


void odkryj_sasiadow(PlayBoard** Plansza, board** bomby, int y, int x, int c, int d, int* punkty)
{
    if (c - 1 >= 0 && d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c - 1, d - 1, punkty);
    if (c - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c - 1, d, punkty);
    if (c - 1 >= 0 && d + 1 < x)
        odkryj(Plansza, bomby, y, x, c - 1, d + 1, punkty);
    if (d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c, d - 1, punkty);
    if (d + 1 < x)
        odkryj(Plansza, bomby, y, x, c, d + 1, punkty);
    if (c + 1 < y && d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c + 1, d - 1, punkty);
    if (c + 1 < y)
        odkryj(Plansza, bomby, y, x, c + 1, d, punkty);
    if (c + 1 < y && d + 1 < x)
        odkryj(Plansza, bomby, y, x, c + 1, d + 1, punkty);
}



int ruch(PlayBoard**Plansza, board**bomby, int y, int x)
{
	int punkty=0;
        int a,b;
        char c;
        printf("jaki ruch:");
       	scanf("%d %d %c",&a,&b,&c);
	a=a-1;
       	b=b-1;
       	switch (c)
       	{
       	case 'm':
       	        if(bomby[a][b].IsMine==1)
				{
       	            koniec(Plansza, bomby, y, x);
					BOOM=0;
               	}
               	else
               	{
                    odkryj(Plansza, bomby, y, x, a, b, &punkty);
               	}
               	break;
       	case 'f':
       	case 'F':
		if(Plansza[a][b].output[1]=='F')
               		Plansza[a][b].output[1]='-';
		else if(Plansza[a][b].output[1]=='-')
			Plansza[a][b].output[1]='F';
		else
			;
               	break;

       	default:
               	help();
               	break;
      	}
	return punkty;
}
