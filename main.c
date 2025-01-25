#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struktury.h"
#include "wypisywanie.h"
#include "ruchy.h"
#include "generator_min.h"
#include "tabela.h"

int BOOM=1;

int main(int argc,char**argv)
{
	char nick[100];
    printf("Podaj nick: ");
    if (fgets(nick, sizeof(nick), stdin) != NULL) {
        size_t len = strlen(nick);
        if (len > 0 && nick[len-1] == '\n') {
            nick[len-1] = '\0';
        }
    }
    printf("Twoj nick: %s\n", nick);
	int l_bomb;
	int y, x;
	char move;
	int mnoznik;
	int pkt=0;
	int max_pkt;
	int count;
	int opt;
 
 	if((opt = getopt(argc ,argv, "f:"))!=-1)
        {
                FILE*plik=fopen(optarg,"r");
                fscanf(plik,"%d %d",&pkt,&max_pkt);
                printf("%d %d\n",pkt , max_pkt);
                return 0;
        }

	wybor_poziomu(&l_bomb,&y,&x,move,&mnoznik);
	max_pkt=((x*y)-l_bomb)*mnoznik;
	PlayBoard**Plansza=stworz_plansze(y,x);
	board**bomby=pole_minowe(y,x);
	rozmiesc_bomby(l_bomb,y,x,bomby);	
	ustaw_sasiadow(y,x,bomby);
	while(sprawdzenie(y,x,bomby)>0)
	{
		int poprawki=sprawdzenie(y,x,bomby);
		rozmiesc_bomby(poprawki,y,x,bomby);
		ustaw_sasiadow(y,x,bomby);
	}

	for(int k=0;k<=x;k++)
		printf("%3d",k);
	printf("\n");
	poczatkowa(y,x,Plansza);
	        printf("Punkty: %d\n",pkt);

	while(BOOM && pkt != max_pkt)
	{
		pkt=pkt+(ruch(Plansza, bomby, y, x)*mnoznik);
		zmienianie(y,x,Plansza,&pkt);

	}
	printf("Koniec gry.Liczba zdobytych punktow:%d\n",pkt);
	Tabela wyniki[10];
	czytaj_wyniki(wyniki, &count);
	zmien_wyniki(wyniki, &count, nick, pkt);
	zapisz_wyniki(wyniki, count);


	return 0;
}
