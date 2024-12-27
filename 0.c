#include <stdio.h>
#include <stdlib.h>

int main(int argc,char**argv)
{	
	int ruchX;
	int n=atoi(argv[1]);
	for(int i=0;i<n;i++)
	{
		printf("-");
	}
	printf("\nNastepny ruch:");
	scanf("%d",&ruchX);
	for(int i=0;i<n;i++)
	{printf("/r");
		if(i==ruchX-1)
		{
			printf(" ");
		}
	}
}
