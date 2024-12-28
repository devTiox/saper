#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator_min.h"
#include "struktury.h"

void rozmiesc_bomby(int l_bomb,int y,int x,board**pole)
{

        int rozlozone=0;
        srand(time(NULL));
        for(int n=0;n<l_bomb;n++)
        {
                while(rozlozone<l_bomb)
                {
                        int bomb_x=rand()%x;
                        int bomb_y=rand()%y;
                        if(pole[bomb_y][bomb_x].IsMine==0)
                        {
                                pole[bomb_y][bomb_x].IsMine=1;
                                rozlozone++;
                                printf("MINA: %d %d %d\n",bomb_y+1,bomb_x+1,pole[bomb_y][bomb_x].IsMine);
                        }
                }
        }
}
int sprawdzenie(int y,int x,board**pole)
{
        int bledy=0;
        for(int i=0;i<y;i++)
        {
                for(int j=0;j<x;j++)
                {
                        if(pole[i][j].IsMine==1&&pole[i][j].bomby_blisko==8)
                        {
                                pole[i][j].IsMine=0;
                                bledy++;
                        }
                }
        }
        return bledy;
}

