#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int initmas( double A[], int n )
{ for ( int i = 0; i < n; i++ )
    A[ i ] = rand()%100/3.55; }

int printmas( double A[], int n )
{ for ( int i = 0; i < n; i++ ) 
    printf( " %f \t ", A[i]); }

int findmax( double M[], int n )
{ double max;
  int index,i;

    for ( i = 0, max = M[0],index = 0; i < n; i++ ) 
        
        if ( max < M[i]) {max = M[i],index = i;}
        printf(" Value = %f | polozhenie = %d", max, index + 1 );}



#define N1 3
#define N2 3

int main()

{time_t k;
 srand( time(&k) );
 double A[N1], B[N2];

initmas(A, N1);
printf("Array A:\n");
	printmas (A, N1);
    printf("\n");
    findmax(A, N1);
    printf("\n");

initmas(B, N2);
printf("Array B:\n");
	printmas (B, N2);
    printf("\n");
    findmax(B, N2);
    printf("\n");


 }


 