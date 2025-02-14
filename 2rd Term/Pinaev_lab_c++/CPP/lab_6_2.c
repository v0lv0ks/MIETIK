#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <Windows.h>
#include "RU_CL_console.h"


#define color_output_blue  SetConsoleTextAttribute(hConsole, 3);
#define color_output_green SetConsoleTextAttribute(hConsole, 2);
#define color_output_red   SetConsoleTextAttribute(hConsole, 4);
#define color_output_white SetConsoleTextAttribute(hConsole, 7);
#define MAIN_MENU_SEPARATOR printf("-----------------------------------------------\n");
#define SEPARATOR printf("-----------------------------------\n");
#define CLEAR_ system("cls");
#define PAUSE_ system("pause");
#define BASE_SIZE 5

struct product *products;
int current_size = 0;
int maxsize;

struct product {
    char* name;
    int quantity;//кол-во
    double cost;
};

void main_menu(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    MAIN_MENU_SEPARATOR
    //printf("| "); color_output_blue printf("Добавить ещё одного студента ............ 1 "); color_output_white printf("|\n");
    printf("  Выберете опцию (введите номер):\n"); 
    printf("| "); color_output_blue printf("Вывести базу данных продуктов ........... 1 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Поиск ................................... 2 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Сортировать БД по возрастанию кол-ва .... 3 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Сформировать случайную базу данных  ..... 4 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Закрыть программу  ...................... 5 "); color_output_white printf("|\n");
    
    MAIN_MENU_SEPARATOR
    // printf("| "); color_output_blue printf("Сформировать случайную базу данных  ..... 5 "); color_output_white printf("|\n");
    // printf("| "); color_output_blue printf("Записать базу данных в файл ............. 6 "); color_output_white printf("|\n");
    // printf("| "); color_output_blue printf("Считать базу данных с файла ............. 7 "); color_output_white printf("|\n");
    // printf("| "); color_output_blue printf("Закрыть программу  ...................... 8 "); color_output_white printf("|\n");
    // MAIN_MENU_SEPARATOR color_output_blue printf("  Выберете опцию (введите номер)\n"); color_output_green
}

void form_database(int SIZE_FOR_DATABASE){

    char Products_names[50][28] = {"Apple", "Banana", "Milk", "Bread", "Cheese", "Carrots", "Onions", "Chicken", "Tomatoes", "Rice", "Potatoes", 
    "Salmon", "Sausage", "Yogurt", "Cake", "Broccoli", "Cookies", "Pasta", "Cereal", "Lemon", "Oranges", "Beef", "Juice", "Chips", "Pepper", "Honey",
    "Lettuce", "Peanuts", "Kiwi", "Shrimp", "Beans", "Sushi", "Waffles", "Tofu", "Salsa", "Grapes", "Melon", "Spinach", "Garlic", "Pickle", "Soup",
    "Pizza", "Lobster", "Tuna", "Jam", "Soda", "Plums", "Ginger", "Candy", "Cider"};

    int id_product, id_month;

    if (SIZE_FOR_DATABASE <= 3) { current_size = BASE_SIZE; printf("Введено значение <= 3 !\nИспользовано базовое количество продуктов = 8\n"); PAUSE_} 
    else {current_size = SIZE_FOR_DATABASE; } 
    maxsize = current_size * 2; 

    products = (struct product*) malloc(maxsize * sizeof(struct product));

    for (int i = 0; i < current_size; i++){
        id_product = rand()%50;
        id_month = rand()%12;
        products[i].name = (char*) malloc(sizeof(Products_names[id_product]) + 1);
        strcpy( products[i].name,Products_names[id_product]);

        products[i].cost = 5 + rand() % ((300 - 10 + 1) + 10 ) / 1.01;
        products[i].quantity = rand()%100;
        
}
}

void print_info_product(int id){

     printf("| %10s | %8d | %6.2lf p|\n", 
                products[id].name,  products[id].quantity, products[id].cost);

}

void print_database(){
    CLEAR_
    printf("БАЗА ДАННЫХ - Продукты\n"); SEPARATOR
    printf("|%12s|%10s|%19s|\n", "Наименование", "Количество", "Стоимость"); SEPARATOR
    for (int id = 0; id < current_size; id++){
        print_info_product(id);
    }
    if (current_size == 0) { printf("База данных ещё не заполнена !\n"); }
    SEPARATOR PAUSE_ CLEAR_
}

void clear_memory(){
    for ( int id = 0; id < current_size; id++){
        free(products[id].name);
    }
    free(products);
}

void sort_data_base(){
    struct product count;
    for (int i = 0; i < current_size; i++){
        for ( int j = 0; j < current_size; j++){
            if ( products[i].quantity > products[j].quantity ){
            count = products[i];
            products[i] = products[j];
            products[j] = count;}
        }
    }
}

void find_from_name(int* found_cnt){
    CLEAR_
    SEPARATOR
    getchar();
    char name_buffer[20];
    printf("Введите название: ");   gets(name_buffer); CLEAR_ SEPARATOR
    for (int id = 0; id < current_size; id++){
        if ( strstr(name_buffer, products[id].name )){
            if ( strlen(name_buffer) == strlen(products[id].name) ){
                *found_cnt +=1;
                print_info_product(id);

            }
        }
    }
    if (*found_cnt != 0) {SEPARATOR PAUSE_ CLEAR_}
}

void find_from_cost(int* found_cnt){
    int cost_buf;
    printf("Введите стоимость, выше которой будет производится поиск продуктов: \n "); scanf("%d", &cost_buf);
    SEPARATOR 
    for (int id = 0; id < current_size; id++){
        if ( products[id].cost > cost_buf){
                *found_cnt +=1;
                print_info_product(id);}
    }
    if (*found_cnt != 0) {SEPARATOR PAUSE_ CLEAR_}
}

void search(){
    int inMenu1 = 1;
    int found_cnt = 0, was_finding = 0;
    char Menu_Option_1 = '0';

    while(inMenu1){

        CLEAR_  SEPARATOR
        printf("Введите тип поиска:\n");
        printf("1. По Названию \n2. Выше заданной стоимости\n3. Вернуться в главное меню\n");
        SEPARATOR
        Menu_Option_1 = getchar();
        CLEAR_  

        switch(Menu_Option_1){

            case '1':   // ПОИСК ПО НАЗВАНИЮ
                find_from_name(&found_cnt);
                inMenu1 = 0;
                break;
            case '2':   // ПОИСК ПО СТОИМОСТИ
                find_from_cost(&found_cnt);
                inMenu1 = 0;
                break;
            case '3':   // ВЫХОД В ГЛАВНОЕ МЕНЮ
                inMenu1 = 0;
                break;
            default:
                break;
        }
           // СМОТРИМ, БЫЛ ЛИ ПРОИЗВЕДЕН ПОИСК
        switch(Menu_Option_1){
            case '1':
            case '2':
                was_finding = 1;
                break;
            default:
                break;
        }
        if (was_finding == 1 && found_cnt == 0){ // ЕСЛИ ИСКАЛИ И НЕ НАШЛИ
            printf("Не было найдено продуктов по такому запросу... \n\n");
            PAUSE_
        }
    }
}

int main(void)
{   time_t CT; srand(time(&CT));  
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    enable_colors(); set_utf_8();

    int option = -1, MENU = 1;

    while (MENU){
        CLEAR_
        main_menu();
        scanf("%d", &option); color_output_white
        
        switch (option){

            case 1:     // Вывести базу данных
                print_database();
                break;
            case 2:     // Поиск
                search();
                break;
            case 3:     // Сортировать базу данных
                sort_data_base();
                break;
    
            case 4:     // Сгенерировать базу данных из студентов
                int input;
                CLEAR_ color_output_blue printf("Введите сколько сгенерировать продуктов в базу данных:\n! Минимально - 3\n"); 
                color_output_green scanf("%d", &input); color_output_white
                form_database(input);
                break; 
            
            case 5:
                MENU = 0;
                clear_memory(products);
                CLEAR_ 
                color_output_red printf("ЗАКРЫВАЕМ ПРОГРАММУ...");
                break;
            default:
                break;
            
    }
    }
    return 0;
}