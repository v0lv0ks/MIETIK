#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define col 3
int const N1 = 6;
int const N2 = 4;
int i , j, sum=0;


int function(int array[N1][N2]){
    int mas_k[N2]; 
    //output array
    for ( i = 0; i < N1 ; i++){
        printf("\n");
        for ( j = 0 ; j < N2 ; j++)
            printf("%d\t", array[i][j] );
        }
    printf("\n\n");

    for ( j = 0; j < (N2+1)/2 ; j++)//sum1
        {for ( i = 0 ; i < (N1+1)/2 ; i++){
            sum += array[i][j];
            }
        mas_k[j] = sum;
        sum = 0;
        }

    for ( j = (N2+1)/2 ; j < N2 ; j++)//sum2
        {for ( i = (N1+1)/2 ; i < N1 ; i++){
            sum += array[i][j];
            }
        mas_k[j] = sum;
        sum = 0;
        }

    for (j = 0; j < N2; j++)
        printf("%d\t", mas_k[j]);

    printf("\n\n");
    return 0;

}

int main(){
    int mas[N1][N2];
    time_t k;
    srand (time(&k));

    for ( i = 0; i < N1 ; i++)//create array
        for ( j = 0 ; j < N2 ; j++)
            mas[i][j] = rand()%10;

    function(mas);
system ("pause");
return 0;
}
