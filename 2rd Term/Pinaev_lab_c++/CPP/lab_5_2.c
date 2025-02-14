#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_STRLEN 20
#define MAX_WORDS_AMOUNT 20

char ** Find_p(char*text)
{   
    int i,j,k;
    int cnt = 0, ptrs_cnt = 1;
    char ** ptrs = (char **) malloc(sizeof(char *) * ptrs_cnt);
    
    char words[20][20] = {NULL};

    for (i = j = k = 0; ; j++){
        // printf("j = %d | *(text + j - 1) = '%c' | *(text + j) = '%c' | *(text + j + 1) = '%1c' | i = %d | P_C = %d\n", j, *(text + j - 1), *(text + j), *(text + j + 1), i, ptrs_cnt);

        if (*(text + j) == '\0') break;

        if (*(text + j) != ' '){
            if (*(text + j - 1) == ' ') i++;

            words[i][k] = *(text + j);
            k++;
        }
        else k = 0;

        if (j > 0 && ((*(text + j) == ' '       && *(text + j - 1) != ' ') || 
                      (*(text + j + 1) == '\0'  && *(text + j) != ' ')))
        {
            if (i >= ptrs_cnt){
                ptrs = realloc( ptrs, sizeof(char *) * ++ptrs_cnt);
            }
            ptrs[ptrs_cnt - 1] = text + j - strlen(words[i]);
            if (*(text + j + 1) == '\0') ptrs[ptrs_cnt - 1] += 1;
            //printf("PTRS[%d] =  ''%s'' | words[%d] = ''%s''\n\n", ptrs_cnt - 1, ptrs[ptrs_cnt - 1], i, words[i]);
        }
    }

    
    k = i + 1;
    int count = 0;
    char ** dup = (char **) malloc(sizeof(char *) * 100);
    for (i = 0; i < k - 1; i++){
        for (j = i + 1; j < k; j++){
            if ( !(strcmp(words[i], words[j])) ){
                count += 2;
                if (sizeof(char *) * count > sizeof(dup))   dup = realloc( dup, sizeof(char *) * count);
                dup[count - 2] = ptrs[i];
                dup[count - 1] = ptrs[j];                
            }
        }
    }
    dup = realloc(dup, sizeof(char *) * (count + 1));
    dup[count] = NULL;
    return dup;
}

int main(){
    system("cls");
    char stopword[3] = "no";
    char**strmas = (char**)malloc(sizeof(*strmas) * 20);//выделение памяти под массив указателей на строки
    char buff[80] = {'q'};
    int flag = 1;
    int count_of_strings = 0;
    printf("Enter a few lines (the end of the input word <no>)\n");
    int max_len = 0;
    for (int k = 0; flag; k++)
    {   
        gets(buff);

        strmas[k] = (char*) malloc (strlen(buff)+1);//выделение паямти под строки
        strcpy (strmas[k], buff);//копируем строки из буфера в память
        count_of_strings++;//добавляем счетчик слов 

        if (strlen(strmas[k]) > max_len) max_len = strlen(strmas[k]);//находим макс длину введенной строки
        
        if (strcmp(strmas[k], stopword) == 0){//проверка на стоп-слово
        flag = 0; count_of_strings--;//убираем это стоп слова из счетчика
    }
    strmas[count_of_strings] = NULL;
    }
    
    printf("\nText:\n"); // ВЫВОД ЁЛОЧКИ
    for (int j = 0; j < count_of_strings; j++)
    {   
        printf("%*s\n", (max_len - strlen(strmas[j]) + 1) / 2 + strlen(strmas[j]), strmas[j]);//выравнивание по центру
    }
    int k = 0;
    for (int j = 0; j < count_of_strings; j++) // ПОИСК ОДИНАКОВЫХ СЛОВ
    {   

        char ** PTRS = Find_p(strmas[j]);
        int cnt = 0;
        for (int i = 0; PTRS[i] != NULL; i++){
            cnt++;
        }

        printf("\nDuplication words:\n");
        int max_len = strlen(PTRS[0]);
        for (int i = 0; i < cnt; i+=2){
            int word_len;
            const char space[2] = " ";
            for (word_len = 0; ; word_len++){
                if (PTRS[i][word_len] == ' ') break;
            }
            printf("%s\n", strtok(PTRS[i], space));
            // printf("| %*s | %s |\n", max_len, PTRS[i], PTRS[i + 1]);
        }
        free(strmas[j]); 
    }
    free(strmas);
    system("pause");
}