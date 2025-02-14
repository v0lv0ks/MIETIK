#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main(){
    time_t k;
    srand(time(&k));
    const int N1 = 6;
    const int N2 = 9;
    int i,j,sum=0,m=0;
    int mas_k[N2];
    printf("Creat a new array with number of zero volums from painted part with even columns \n");

        int mas[N1][N2];
        for (i = 0; i < N1; i++)
        for (j = 0; j < N2; j++) mas[i][j] = rand() % 101-100;

        for (i=0;i<N1;i++)
        { printf("\n");
            for (j=0;j<N2;j++) printf("%d\t",mas[i][j]);
        }
        printf("\n");
        printf("\n");
        
        for (j = 0;j < N2; j++){//Task1
            if (j%2 != 0){//because caunt from zero
            {for (i=N1/2;i < N1;i++)
                if (mas[i][j]==0){m+=1;}}}
        mas_k[j] = m;
        m=0;}
        
        for (i = 0;i < N2; i++)//output mas_k array
            printf("%d\t",mas_k[i]);
        printf("\n");printf("\n");
        
        for (j = 0;j < N2; j++)//find sum painted part(Task2)
            for (i = N1/2; i < N1; i++)
                sum += mas[i][j];
        printf("summa = %d\n",sum);
        return 0;

    return 0;
}