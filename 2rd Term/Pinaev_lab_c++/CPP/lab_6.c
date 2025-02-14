#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char* s  = "hecx";
    int a = 10;
    int &ref = a;
    printf("%s\n", s + 1);
}