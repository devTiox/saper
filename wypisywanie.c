#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"

void poczatkowa(int rozmiar,PlayBoard**Plansza)
{
	for(int y=0;y<rozmiar;y++)
	{
		printf("%3d",y+1);
		for(int x=0;x<rozmiar;x++)
		{
			for(int i=0;i<3;i++)
			printf("%c",Plansza[y][x].output[i]);

		}printf("\n");
	}
}

void zmienianie(int rozmiar,PlayBoard**Plansza)
{
	int a,b;
	printf("jaki ruch:");
	scanf("%d %d",&a,&b);
	Plansza[a-1][b-1].output[1]=' ';
	printf("\033[H\033[J");
        for(int y=0;y<rozmiar;y++)
        {
                printf("%3d",y+1);
                for(int x=0;x<rozmiar;x++)
                {
                        for(int i=0;i<3;i++)
                        printf("%c",Plansza[y][x].output[i]);

                }printf("\n");
        }

}
