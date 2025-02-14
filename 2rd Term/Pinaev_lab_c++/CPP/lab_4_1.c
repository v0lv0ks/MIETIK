#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define  N1 8
#define  N2 5
#define  COL 1


int initmas (int *p, int n)
{int *tp;
  for (tp=p; tp < (p+n); tp++)
*tp=rand()%80-50;}

int printmas (int *p, int n, int k)
{	int i;
	for (i=0; i<n; i++,p++)
	{	printf("%d\t",*p);}
	printf("\n");
}

int* maxpol(int *p, int n)
{   int *tmax;
    int *tp;
    for (tmax = tp = p; tp < (p + n); tp++)
        if ( *tp > 0) tmax = tp;
    return tmax;  
}

int minmas (int *p, int n)
{	int* tmin;
	int* tp;	
	for (tmin=tp=p; tp < (p+n); tp++)
		if (*tmin>*tp) tmin=tp; 
	return *tmin;
} 

int main()
{   int mas1[N1], mas2[N2], min1, min2;
    srand (time(0));
    initmas(mas1,N1);
    initmas(mas2,N2);

    printf("Array number 1:\n");
    printmas(mas1,N1,COL);
    int *q = maxpol(mas1,N1);
    printf("Poloszenie: %ld\n", q-mas1);
    min1 = minmas(mas1, q-mas1 );
    printf("minimal element:%d\n", min1);
    
    printf("\n");

    printf("Array number 2:\n");
    printmas(mas2,N2,COL);
    int *c = maxpol(mas2,N2);
    printf("Poloszenie: %ld\n", c-mas2);
    min2 = minmas(mas2, c-mas2 );
    printf("minimal element: %d\n", min2);
}


