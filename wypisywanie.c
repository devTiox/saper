#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"

void wybor_poziomu(int*l_bomb,int*y,int*x,char move,int*mnoznik)
{
	printf("Wybierz poziom trudnosci ");
        if(scanf("%c",&move)!=0)
        {
                switch (move)
                        {
                        case 'c':
                                *mnoznik=0;
                                printf("Podaj rozmiar planszy");
				int bombs_c;
                                scanf("%d %d %d",y,x,&bombs_c);
				if(bombs_c>0.76*(*y)*(*x))
				{
					printf("Zbyt duzo bomb\n");
					help();
					exit (2);
				}
				*l_bomb=bombs_c;
                                break;
                        case 'e':
                                *mnoznik=1;
                                printf("easy\n");
                                *x=9;
                                *y=9;
				*l_bomb=10;
                                break;
                        case 'm':
                                *mnoznik=2;
                                printf("medium\n");
                                *x=16;
                                *y=16;
				*l_bomb=40;
                                break;
                        case 'h':
                                *mnoznik=3;
                                printf("hard\n");
                                *x=16;
                                *y=30;
				*l_bomb=99;
                                break;
                        default:
                                help();
				exit (1);
                        }

        }else
                printf("nieudany odczyt wyboru\n");
}

void help()
{
	printf("Instrukcja obslugi:\n");
	printf("Wybor poziomu trudnosci:\n");
	printf("c-custom(wlasne ustawienia,koniecznosc podania ilosci bomb(nie wiecej niz 75%% planszy dla zachowania sensu rozgrywki)!!)\n");
	printf("e-easy(latwy 5x5 X bomb)\nm-medium(sredni 10x10 X bomb)\nh-hard(trudny 15x15 X bomb)\n");
}

void poczatkowa(int y,int x,PlayBoard**Plansza)
{
        printf("Punkty: 0\n");
	for(int i=0;i<y;i++)
	{
		printf("%3d",i+1);
		for(int j=0;j<x;j++)
		{
			for(int l=0;l<3;l++)
			printf("%c",Plansza[i][j].output[l]);

		}printf("\n");
	}
}

void zmienianie(int y,int x,PlayBoard**Plansza,int*punkty)
{
	int pkt=punkty[0];
        printf("Punkty: %d\n",pkt);
	for(int k=0;k<=y;k++)
		printf("%3d",k);
	printf("\n");
        for(int i=0;i<y;i++)
        {
                printf("%3d",i+1);
                for(int j=0;j<x;j++)
                {
                        for(int l=0;l<3;l++)
                        printf("%c",Plansza[i][j].output[l]);

                }printf("\n");
        }

}
