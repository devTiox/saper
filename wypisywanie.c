#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"

void clear_console() {
    system("cls");
}

int custom_mnoznik(int*x,int*y,int bombs_c)
{
	int mnoznik;
                                float wariant=bombs_c/(*y)*(*x);
                                if(wariant<0.15)
                                        mnoznik=1;
                                else if(wariant>=0.15&&wariant<0.2)
                                        mnoznik=2;
                                else if(wariant>=0.2&&wariant<0.5)
                                        mnoznik=3;
                                else
                                        mnoznik=4;
                                if(bombs_c>0.76*(*y)*(*x))
                                {
                                        printf("Zbyt duzo bomb\n");
                                        help();
                                        exit (2);
                                }
				return mnoznik;

}
void wybor_poziomu(int*l_bomb,int*y,int*x,char move,int*mnoznik)
{
	printf("Wybierz poziom trudnosci ");
        if(scanf("%c",&move)!=0)
        {
                switch (move)
                        {
                        case 'c':
                                printf("Podaj rozmiar planszy");
				int bombs_c;
                                scanf("%d %d %d",y,x,&bombs_c);
				*mnoznik=custom_mnoznik(x,y,bombs_c);
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
                                *x=30;
                                *y=16;
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
	printf("\nWybor poziomu trudnosci:\n");
	printf("c-custom(wlasne ustawienia,koniecznosc podania ilosci bomb(nie wiecej niz 75%% planszy dla zachowania sensu rozgrywki)!!)\n");
	printf("e-easy(latwy 5x5 X bomb)\nm-medium(sredni 10x10 X bomb)\nh-hard(trudny 15x15 X bomb)\n");
        printf("\nWybor ruchu:\n");
        printf("Przy wyborze ruchu należy podać parametr ruchu, pozycje y oraz pozycje x\n");
        printf("Pozycje y i x musza znajdowac sie na planszy\n");
        printf("Parametrem funkcji moze byc:\nr/R (jesli chcemy odkryc pole)\nlub f/F (jesli chcemy postawic lub usunac flage)");
}

void poczatkowa(int y,int x,PlayBoard**Plansza)
{
        clear_console();
        for(int k=0;k<=x;k++)
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

void zmienianie(int y,int x,PlayBoard**Plansza,int*punkty)
{
        clear_console();
	int pkt=punkty[0];
	for(int k=0;k<=x;k++)
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

        printf("Punkty: %d\n",pkt);
}
