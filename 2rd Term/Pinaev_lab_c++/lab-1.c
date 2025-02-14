
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


/*
int main(){
float a, b, s;
printf("Please, input triangle base length:\n");
scanf("%f", &a);
printf("Please,input triangle height length:\n");
scanf("%f",&b);
while (!(a>0 && b>0)){
    printf("Please, input correct values:\n");
    scanf("%f", &a);
    scanf("%f",&b);
}
s = a * b;
printf("Area: %f\n", s);
return s;
}

int findcount(long long int n)
{int k =0;
while (n!=0){
    k++;
    n=n/10;}
    return k;
}
int main(){
long long int n;
if (n!=0){
    scanf("%d",&n);
    printf("%d digits",findcount(n));}0
}

// int => 4 byte = 32 bit => 2^31 - 1 => max : 2,147,000,000
*/
/*
int main(){
    int n;
    int i,s=1;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
    s=s*i;
    printf("%d hh",i);
    }
printf("%d",s);
}
"""
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int M[5]={0,12,13,5}
int main()
{int a;
a=M[3];
printf("%d",a);
}
int M[5]={1,1,1,1,1},sum=0,i;
int main()
{for (i=0,sum=0;i<5;i++){
    sum+=M[i];

}

printf("%d",sum);
}
#define col 2
int main(){
int dig[]={5,3,2,4,6,7,11,17,0,13}; 
int i; 

for (i=0; i<=9; i++)
{printf("%d",dig[i]); 
if ((i+1)%col) printf("\t");
else		  printf("\n");
}
return 0;
}
###############################
#define col 2
int main(){
time_t k;
srand (time(&k));

    const int N = 4;
    int mas[N];
    int i;

    for (i = 0; i < N; i++) {
        mas[i] = rand() % 100;
    }
    for (i = 0;i < N; i++)
    {
        printf("%d", mas[i]);
        if ( (i + 1) % col) printf("\t");
        else printf("\n");
    }
    printf("\n");
    system("pause");
}
#############################

int main()
{
    time_t k;
    srand(time(&k));
    const int N = 10;
    int i,j;
    int mas[N][N];
    for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) mas[i][j] = rand() % 21 - 10;

    for (i=0;i<N;i++)
    { printf("\n");
        for (j=0;j<N;j++) printf("%d\t",mas[i][j]);
    }
    printf("\n");
    system("pause");
}*/
int n,a,i=0;
int main(){
    scanf("%d",&n); 
    while (2^i<n); 
     {a=2^i;
        printf("%d",a);
     i+=1;} 
             
}