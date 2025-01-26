#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "ruchy.h"
#include "generator_min.h"
#include "wypisywanie.h"
#include "unistd.h"

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
	    sleep(1);
            if(BOOM==0)
            {
                    koniec(Plansza, pola, y, x);
                    break;
            }
        }
    }
    int pola_odkryte=0;
    for(int i=0;i<y;i++)
    {
	    for(int j=0;j<x;j++)
	    {
		    if(Plansza[i][j].output[1]!='-')
			    pola_odkryte++;
	    }
    }
    if(pola_odkryte<x*y-bombs_c)
	    BOOM=0;
    printf("Wykonane ruchy:%d\nZdobyte punkty:%d\nStatus koncowy:%d\n", ruch, *pkt, BOOM);
}


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

void odkryj(PlayBoard**Plansza, board**bomby, int y, int x, int a, int b, int*punkty)
{
        if(Plansza[a][b].output[1]=='-'){
                (*punkty)++;
                if(bomby[a][b].bomby_blisko==0){
                        Plansza[a][b].output[1]='0';
                        odkryj_sasiadow(Plansza, bomby, y, x, a, b, punkty);
                }
                else
                {
                        Plansza[a][b].output[1]=bomby[a][b].bomby_blisko + '0';
                }
        }
}


void odkryj_sasiadow(PlayBoard** Plansza, board** bomby, int y, int x, int c, int d, int* punkty)
{
    if (c - 1 >= 0 && d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c - 1, d - 1, punkty);
    if (c - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c - 1, d, punkty);
    if (c - 1 >= 0 && d + 1 < x)
        odkryj(Plansza, bomby, y, x, c - 1, d + 1, punkty);
    if (d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c, d - 1, punkty);
    if (d + 1 < x)
        odkryj(Plansza, bomby, y, x, c, d + 1, punkty);
    if (c + 1 < y && d - 1 >= 0)
        odkryj(Plansza, bomby, y, x, c + 1, d - 1, punkty);
    if (c + 1 < y)
        odkryj(Plansza, bomby, y, x, c + 1, d, punkty);
    if (c + 1 < y && d + 1 < x)
        odkryj(Plansza, bomby, y, x, c + 1, d + 1, punkty);
}

int ruch_f(PlayBoard** Plansza, board** bomby, int y, int x, int a, int b)
{
    int punkty = 0;

    // Przekształcenie indeksów na 0-based
    a = a - 1;
    b = b - 1;

    // Sprawdzanie zakresów indeksów
    if (a < 0 || a >= y || b < 0 || b >= x) {
        printf("Błąd: Indeksy poza zakresem: a=%d, b=%d\n", a + 1, b + 1);
        exit(1);
    }

    // Sprawdzanie pola
    if (bomby[a][b].IsMine == 1) {
        koniec(Plansza, bomby, y, x);
        BOOM = 0; // Globalna zmienna, upewnij się, że jest poprawnie zdefiniowana
    } else {
        odkryj(Plansza, bomby, y, x, a, b, &punkty);
    }

    return punkty;
}


int ruch(PlayBoard**Plansza, board**bomby, int y, int x, int n, int l_bomb)
{
	int punkty=0;
        int a,b;
        char c;
        printf("Podaj ruch: ");
       	scanf("%c %d %d",&c,&a,&b);
		a=a-1;
       	b=b-1;
		if(a<=y && a>=0 && b<=x && b>=0){
			switch (c)
			{
			case 'r':
			case 'R':
					if(bomby[a][b].IsMine==1)
					{
						if(n!=1){
							koniec(Plansza, bomby, y, x);
							BOOM=0;
						}
						else{
							while(bomby[a][b].IsMine==1){
								generuj(l_bomb, y, x, bomby);
							}
							odkryj(Plansza, bomby, y, x, a, b, &punkty);
						}
					}
					else
					{
						odkryj(Plansza, bomby, y, x, a, b, &punkty);
					}
					break;
			case 'f':
			case 'F':
			if(Plansza[a][b].output[1]=='F')
						Plansza[a][b].output[1]='-';
			else if(Plansza[a][b].output[1]=='-')
				Plansza[a][b].output[1]='F';
			else
				;
					break;

			default:
					printf("Zle wybrany parametr ruchu\n");
					help();
					return 0;
					break;
			}
		return punkty;
	}
	else{
		printf("Zle wybrana pozycja ruchu\n");
		help();
		return 0;
	}
}
