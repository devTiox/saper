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

void odkryj_sasiadow(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b, int*punkty)
{

}

void odkryj(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b, int*punkty)
{
        if(bomby[a][b].bomby_blisko==0)
                odkryj_sasiadow(Plansza, bomby, y, x, a, b, &punkty);
        else
        {
                Plansza[a][b].output[1]=bomby[a][b].bomby_blisko + '0';
        }
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
        case ' ':
        case 'm':
                if(bomby[a][b].IsMine==1){
                        koniec(Plansza, bomby, y, x);
                }
                else
                {
                        odkryj(Plansza, bomby, y, x, a, b, &punkty);

                }
                break;
        case 'f':
        case 'F':
                Plansza[a][b].output[1]='F';
                break;

        default:
                help();
                break;
        }
        return punkty;
        

}
