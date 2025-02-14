#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define  N1 4
#define  N2 4
#define  COL 5


int* initmas (int n, int m)
{   int*mas1;
	mas1 = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i< n; i++)  
		{	for (int j = 0; j < m; j++)
				mas1[i * m + j] = rand()%100 - 40;}
	return mas1;
}

int printmas (int *p, int n, int m, int k)
{	int h = 0;
	for (int i = 0; i < n; i++)  
		{ for (int j = 0; j < m; j++)
				printf("%d\t",p[i * m + j]);
				h+=m;
					if (h % k) printf(" ");
					else printf("\n");}
}


void find (int *p, int n,int m, int *min, int *max)
{	
    int* tmin;
    int* tmax;
	int* tp;
    int* np;
    	
	for (tmin = tp = p + n/2 * m; tp < (p+n*m); tp++)
		if (*tmin>*tp) tmin=tp; 
    *min = *tmin;

	for (tmax = np = p + n/2 * m; np < (p+n*m); np++)
		if (*tmax<*np) tmax=np; 
	*max =  *tmax; 
} 

int main()
{   int *pi;
    pi = initmas(N1 , N2);
    int min, max;
    srand (time(0));
    printmas(pi, N1, N2, COL);
    find(pi,N1,N2,&min, &max);
    printf("\n");
    printf("min = %d |  max = %d\t", min, max);
	free(pi);
}
