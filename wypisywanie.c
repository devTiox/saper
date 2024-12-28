#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"

void wybor_poziomu(int*l_bomb,int*y,int*x,char move)
{
	printf("Wybierz poziom trudnosci ");
        if(scanf("%c",&move)!=0)
        {
                switch (move)
                        {
                        case 'c':
                                printf("Podaj rozmiar planszy");
				int proc;
                                scanf("%d %d %d",y,x,&proc);
				*l_bomb=0.01*proc*(*x)*(*y);
                                break;
                        case 'e':
                                printf("easy\n");
                                *x=5;
                                *y=5;
				*l_bomb=0.3*(*x)*(*y);
                                break;
                        case 'm':
                                printf("medium\n");
                                *x=10;
                                *y=10;
				*l_bomb=0.45*(*x)*(*y);
                                break;
                        case 'h':
                                printf("hard\n");
                                *x=15;
                                *y=15;
				*l_bomb=0.60*(*x)*(*y);
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
	printf("c-custom(wlasne ustawienia,koniecznosc podania procentowej ilosci bomb!!)\n");
	printf("e-easy(latwy 5x5 X bomb)\nm-medium(sredni 10x10 X bomb)\nh-hard(trudny 15x15 X bomb)\n");
}

void poczatkowa(int y,int x,PlayBoard**Plansza)
{
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

void zmienianie(int y,int x,PlayBoard**Plansza)
{
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
