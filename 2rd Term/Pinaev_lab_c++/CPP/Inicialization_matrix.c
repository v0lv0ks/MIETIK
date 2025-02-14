#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


struct tm * timeinfo;
#include <stdio.h>
#include <time.h>


// Функция для вычисления количества часов между двумя датами
int hoursBetween() {
    struct tm start_tm = {0}, end_tm = {0};
    
    start_tm.tm_year = 2024 - 1900;
    start_tm.tm_mon = 5 -1 ;
    start_tm.tm_mday = 23;

    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    end_tm.tm_year = timeinfo->tm_year;
    end_tm.tm_mon = timeinfo->tm_mon;
    end_tm.tm_mday = timeinfo->tm_mday;
    
    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);
    
    double diff_seconds = difftime(end_time, start_time);
    
    int hours = diff_seconds / 3600;
    printf("%d", hours);
}

int main() {
struct tm * timeinfo;
time_t CT; srand(time(&CT)); 
hoursBetween();
    return 0;
    
}