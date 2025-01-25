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

void game_from_file(FILE* plik, int* pkt) {
    char line[256];
    int ruch=0;
    int mode = 0; // 0: Odczytywanie planszy, 1: Tryb ruchów
    int x, y, bombs_c, a, b, mnoznik;
    int linia = -1;
    board** pola = NULL;
    PlayBoard** Plansza = NULL;
    while (fgets(line, sizeof(line), plik)) {
        // Odczytanie rozmiaru planszy
        if (linia == -1) {
            if (sscanf(line, "rozmiar: %d %d %d", &y, &x, &bombs_c) != 3) {
                printf("Błąd: Nie udało się odczytać rozmiaru planszy.\n");
                exit(2);
            } else {
                // Inicjalizacja planszy i pola minowego
                mnoznik = custom_mnoznik(&x, &y, bombs_c);
                Plansza = stworz_plansze(y, x);
                pola = pole_minowe(y, x);
                poczatkowa(y, x, Plansza);
                linia++;
                continue;
            }
        }

        // Tryb odczytywania zawartości planszy
        if (mode == 0) {
            if (linia < y) {
                for (int j = 0; j < x; j++) {
                    if (line[2 * j] == '*')
                        pola[linia][j].IsMine = 1;
                    else
                        pola[linia][j].bomby_blisko = line[2 * j] - '0'; // Zamiana znaku na liczbę
                }
                linia++;
            } else {
                mode = 1; // Przechodzimy do trybu ruchów
            }
        }
        // Tryb ruchów
        else if (mode == 1) {
            if (sscanf(line, "%d %d", &a, &b) != 2) {
                printf("Błąd: Nieprawidłowe dane wejściowe w trybie ruchów.\n");
                exit(1);
            }

            // Sprawdzenie poprawności indeksów
            if (a < 1 || a > y || b < 1 || b > x) {
                printf("Błąd: Indeksy a=%d, b=%d są poza zakresem!\n", a, b);
                exit(1);
            }


            // Wykonanie ruchu
            *pkt += ruch_f(Plansza, pola, y, x, a, b) * mnoznik;
            zmienianie(y, x, Plansza, pkt);
	    ruch++;
	    if(BOOM==0)
	    {
		    koniec(Plansza, pola, y, x);
		    break;
	    }
        }
    }
    printf("Wykonane ruchy:%d\nZdobyte punkty:%d\nStatus koncowy:%d\n", ruch, *pkt, BOOM);
}

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
