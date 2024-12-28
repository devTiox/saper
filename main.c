#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"
#include "wypisywanie.h"

int main(int argc,char**argv)
{
	int n=atoi(argv[1]);
	PlayBoard**Plansza=stworz_plansze(n);
	for(int k=0;k<=n;k++)
		printf("%3d",k);
	printf("\n");
	poczatkowa(n,Plansza);
	while(1)
	zmienianie(n,Plansza);

}
