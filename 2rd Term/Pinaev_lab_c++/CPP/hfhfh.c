#include <stdio.h>
#include <time.h>
int v(int* gh){
    *gh+=1;
    printf("%d", gh);
}
int main(){
    time_t CT;
    srand(&CT);

    printf("%f\n", rand() % ((300 - 10 + 1) + 10 )/1.01);
    printf("%.2lf\n", rand() % 30 );
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);
    printf("%.2lf\n", rand() % 30 / 100.0);


    int gh = 0;
    v(&gh);

}