#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int factorial(int n){
    if (n<2)
        return 1;
    return n*factorial(n-1);
}




int main(){
    int i,n;
    double sum;
    for (i=1,sum=0;1<1000;i++)
    {
        sum+=(i^2*2^i)/factorial(n+2);

    }

printf("sum=%f",sum);

}