#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "ruchy.h"

void ruch(PlayBoard**Plansza)
{
        int a,b;
        printf("jaki ruch:");
        scanf("%d %d",&a,&b);
        Plansza[a-1][b-1].output[1]=' ';

}
