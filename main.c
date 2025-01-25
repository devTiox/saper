#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "struktury.h"
#include "wypisywanie.h"
#include "ruchy.h"
#include "generator_min.h"
#include "tabela.h"


void generuj(int l_bomb, int y, int x, board**bomby)
{
	reset_bomb(y,x,bomby);
	rozmiesc_bomby(l_bomb,y,x,bomby);	
	ustaw_sasiadow(y,x,bomby);
	while(sprawdzenie(y,x,bomby)>0)
	{
		int poprawki=sprawdzenie(y,x,bomby);
		rozmiesc_bomby(poprawki,y,x,bomby);
		ustaw_sasiadow(y,x,bomby);
	}
}

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
    
	int l_bomb;
	int y, x;
	char move;
	int mnoznik;
	int pkt=0;
	int max_pkt;
	int count;
	int opt;
	int n_ruchu=1;
 
 	if((opt = getopt(argc ,argv, "f:"))!=-1)
        {
                FILE*plik=fopen(optarg,"r");
		game_from_file(plik,&pkt);
                return 0;
        }

	wybor_poziomu(&l_bomb,&y,&x,move,&mnoznik);
	max_pkt=((x*y)-l_bomb)*mnoznik;
	PlayBoard**Plansza=stworz_plansze(y,x);
	board**bomby=pole_minowe(y,x);
	generuj(l_bomb, y, x, bomby);

	for(int k=0;k<=x;k++)
		printf("%3d",k);
	printf("\n");
	poczatkowa(y,x,Plansza);
	printf("Punkty: %d\n",pkt);

	while(BOOM && pkt != max_pkt)
	{
		pkt=pkt+(ruch(Plansza, bomby, y, x, n_ruchu, l_bomb)*mnoznik);
		zmienianie(y,x,Plansza,&pkt);
		n_ruchu++;
	}
	printf("Koniec gry.Liczba zdobytych punktow:%d\n",pkt);
	Tabela wyniki[5];
	czytaj_wyniki(wyniki, &count);
	zmien_wyniki(wyniki, &count, nick, pkt);
	zapisz_wyniki(wyniki, count);


	return 0;
}
