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

void ruch(PlayBoard**Plansza, board**bomby, int y, int x)
{
        int a,b;
        char c;
        printf("jaki ruch:");
        scanf("%d %d %c",&a,&b,&c);
        switch (c)
        {
        case ' ':
        case 'm':
                if(bomby[a-1][b-1].IsMine==1){
                        koniec(Plansza, bomby, y, x);
                }
                else
                        Plansza[a-1][b-1].output[1]=bomby[a-1][b-1].bomby_blisko + '0';
                break;
        case 'f':
        case 'F':
                Plansza[a-1][b-1].output[1]='F';
                break;

        default:
                help();
                break;
        }
        

}
