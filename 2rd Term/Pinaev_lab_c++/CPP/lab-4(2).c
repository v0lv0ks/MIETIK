#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define  N1 4
#define  N2 4
#define  COL 4


void initmas (int *p, int n)
{int *tp;
  for (tp=p; tp < (p+n); tp++)
*tp=rand()%80-50;}

void printmas (int *p, int n, int k)
{	int i;
	for (i=0; i<n; i++,p++)
	{	printf("%4d",*p); // f"{i:2.4f}
    	if ((i+1)%k) printf("\t");
	else		  printf("\n");
	}
printf("\n");
}

int* maxpol(int *p, int n)
{   int *tmax;
    int *tp;
    for (tmax = tp = p; tp < (p + n); tp++)
        if ( *tp > 0) tmax = tp;
    return tmax;  
}

void find (int *p, int n, int *min, int *max)
{	
    int* tmin;
    int* tmax;
	int* tp;
    int* np;
    	
	for (tmin=tp=p+(n/2); tp < (p+n); tp++)
		if (*tmin>*tp) tmin=tp; 
    *min = *tmin;

	for (tmax=np=p+(n/2); np < (p+n); np++)
		if (*tmax<*np) tmax=np; 
	*max =  *tmax; 
} 

int main()
{   int mas1[N1*N2], min, max;
    time_t k;
    srand (time(&k));
    initmas(mas1,N1*N2);
    printf("Array number:\n");
    printmas(mas1, N1*N2, COL);
    find(mas1,N1*N2,&min, &max);
    printf("\n");
    printf("min = %d |  max = %d\t", min, max);
}
