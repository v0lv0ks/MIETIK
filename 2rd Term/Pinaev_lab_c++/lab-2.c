#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define col 5
int main(){
time_t k;
srand (time(&k));
printf("Calculating the maximum(even) and mininam value\n");


    const int N = 100;
    int mas[N];
    int i,minimum,maximum;
    char s;

do{
    for (i = 0; i < N; i++) {//filling the array
        mas[i] = rand() % 100;}

    minimum = mas[0];
    
    for (i = 0; i < N;i++){//find the minium
        if (mas[i] < minimum) {minimum = mas[i];}}
    printf("Minimum element = %d\n", minimum);

    maximum=minimum;

    for (i = 0; i < N;i++){//find the maximum
        if ( mas[i]%2==0 &&  mas[i] > maximum ) {maximum=mas[i];}}

    if (maximum%2!=0)
         printf("Maximum element not found\n");
    else printf("Maximum element = %d\n", maximum);


    for (i = 0;i < N; i++)//output
    {
        printf("%d", mas[i]);
        if ( (i + 1) % col) printf("\t");
        else printf("\n");
    }
    printf("\n");
    

printf("Stop or repeat? (y/n) : ");
scanf ("%c",&s);

} 
while (s=='n');
return 0;
}


