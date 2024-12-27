#include <stdio.h>
#include <stdlib.h>
#include "struktury.h"

int main(int argc,char**argv)
{
	int n=atoi(argv[1]);
	PlayBoard**Plansza=stworz_plansze(n);
	for(int k=0;k<=n;k++)
		printf("%3d",k);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%3d",i+1);
		for(int j=0;j<n;j++)
		{
			for(int l=0;l<3;l++)
			printf("%c",Plansza[i][j].output[l]);
		}
		printf("\n");
	}
}
