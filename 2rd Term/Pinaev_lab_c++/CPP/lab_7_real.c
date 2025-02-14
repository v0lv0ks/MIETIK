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
#define SEPARATOR printf("-----------------------------------------------------------------\n");
#define CLEAR_ system("cls");
#define PAUSE_ system("pause");
#define BASE_SIZE 5

struct date{
    int day;
    char month[4];
    int year;
};

struct product {
    struct date production_date;
    char name[28];
    int quantity;//кол-во
    double cost;
    int expiration;//срок годности в часах
};

char * months[12] = {"Jan", "Feb", "Mar", "Apr", 
                     "May", "Jun", "Jul", "Aug", 
                     "Sep", "Oct", "Nov", "Dec"};

struct product *products;
struct tm * timeinfo;
int current_size = 0;
int maxsize;

// Функция для вычисления количества часов между двумя датами
int hoursBetween(struct date production_date, int expiration_hours) {
    struct tm start_tm = {0}, end_tm = {0};

    // Найти индекс месяца
    int month_id;
    for (int i = 0; i < 12; i++) {
        if (strcmp(production_date.month, months[i]) == 0) {
            month_id = i;
            break;
        }
    }
    
    start_tm.tm_year = production_date.year - 1900;
    start_tm.tm_mon = month_id;
    start_tm.tm_mday = production_date.day;
    
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

    return hours;
}

void main_menu(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    MAIN_MENU_SEPARATOR
    printf("  Выберете опцию (введите номер):\n"); 
    printf("| "); color_output_blue printf("Вывести базу данных продуктов ........... 1 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Поиск ................................... 2 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Сортировать БД по возрастанию кол-ва .... 3 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Сформировать случайную базу данных  ..... 4 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Добавить продукт  ....................... 5 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Записать базу в файл  ................... 6 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Считать базу данных из файла  ........... 7 "); color_output_white printf("|\n");
    printf("| "); color_output_blue printf("Закрыть программу  ...................... 8 "); color_output_white printf("|\n");
    MAIN_MENU_SEPARATOR
}

void form_database(int SIZE_FOR_DATABASE) {
    char Products_names[50][28] = {"Apple", "Banana", "Milk", "Bread", "Cheese", "Carrots", "Onions", "Chicken", "Tomatoes", "Rice", "Potatoes",
                                   "Salmon", "Sausage", "Yogurt", "Cake", "Broccoli", "Cookies", "Pasta", "Cereal", "Lemon", "Oranges", "Beef",
                                   "Juice", "Chips", "Pepper", "Honey", "Lettuce", "Peanuts", "Kiwi", "Shrimp", "Beans", "Sushi", "Waffles", "Tofu",
                                   "Salsa", "Grapes", "Melon", "Spinach", "Garlic", "Pickle", "Soup", "Pizza", "Lobster", "Tuna", "Jam", "Soda",
                                   "Plums", "Ginger", "Candy", "Cider"};

    int id_product, id_month;

    if (SIZE_FOR_DATABASE <= 3) { 
        current_size = BASE_SIZE; 
        printf("Введено значение <= 3 !\nИспользовано базовое количество продуктов = 5\n"); 
        PAUSE_
    } else {
        current_size = SIZE_FOR_DATABASE; 
    } 
    maxsize = current_size * 2; 

    products = (struct product*) malloc(maxsize * sizeof(struct product));

    time_t rawtime;
    time(&rawtime);
    struct tm *current_time = localtime(&rawtime);

    for (int i = 0; i < current_size; i++) {
        id_product = rand() % 50;
        id_month = rand() % 12;

        strcpy(products[i].name, Products_names[id_product]);
        products[i].cost = 5 + rand() % ((300 - 10 + 1) + 10) / 1.01;
        products[i].quantity = rand() % 100;
        products[i].expiration = rand() % 100 + 65;

        do {
            products[i].production_date.year = rand() % 3 + (current_time->tm_year + 1900 - 2); // Генерация года от текущего до двух лет назад
            strcpy(products[i].production_date.month, months[id_month]);

            switch (id_month) {
                case 0:  // Jan
                case 2:  // Mar
                case 4:  // May
                case 6:  // Jul
                case 7:  // Aug
                case 9:  // Oct
                case 11: // Dec
                    products[i].production_date.day = rand() % 31 + 1;
                    break;
                case 3:  // Apr
                case 5:  // Jun
                case 8:  // Sep
                case 10: // Nov
                    products[i].production_date.day = rand() % 30 + 1;
                    break;
                case 1: // Feb
                    products[i].production_date.day = rand() % 28 + 1;
                    break;
            }

            struct tm temp_tm = {0};
            temp_tm.tm_year = products[i].production_date.year - 1900;
            temp_tm.tm_mon = id_month;
            temp_tm.tm_mday = products[i].production_date.day;
            time_t production_time = mktime(&temp_tm);
            time_t current_time_sec = mktime(current_time);

            if (difftime(production_time, current_time_sec) <= 0) {
                break;
            }
        } while (1);
    }
}

void print_info_product(int id){
    printf("| %10s | %8d | %6.2lf p |  %2d %3s %4d | %11d |\n", 
                products[id].name,  products[id].quantity, products[id].cost,
                products[id].production_date.day, 
                products[id].production_date.month,
                products[id].production_date.year,
                products[id].expiration);
}

void print_database(){
    CLEAR_
    printf("БАЗА ДАННЫХ - Продукты\n"); SEPARATOR 
    printf("|%14s|%10s|%19s|%25s|%13s|\n", "Наименование", "Количество", "Стоимость","Произведено", "Срок годности"); SEPARATOR 
    for (int id = 0; id < current_size; id++){
        print_info_product(id);
    }
    if (current_size == 0) { printf("База данных ещё не заполнена !\n"); }
    SEPARATOR PAUSE_ CLEAR_
}

void clear_memory(){
    free(products);
}

void sort_data_base(){
    struct product temp;
    for (int i = 0; i < current_size - 1; i++){
        for (int j = 0; j < current_size - i - 1; j++){
            if (products[j].quantity > products[j + 1].quantity){
                temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void find_expiration_product(int* found_cnt){
    CLEAR_
    SEPARATOR
    for (int id = 0; id < current_size; id++){
        int hours = hoursBetween(products[id].production_date, products[id].expiration);
        if (hours > products[id].expiration) {
            (*found_cnt)++;
            print_info_product(id);
        }
    }
    if (*found_cnt != 0) {SEPARATOR PAUSE_ CLEAR_}
}

void find_from_name(int* found_cnt){
    CLEAR_
    SEPARATOR
    getchar();
    char name_buffer[20];
    printf("Введите название: "); gets(name_buffer); CLEAR_
    for (int id = 0; id < current_size; id++){
        if (strstr(products[id].name, name_buffer)){
            (*found_cnt)++;
            print_info_product(id);
        }
    }
    if (*found_cnt != 0) {SEPARATOR PAUSE_ CLEAR_}
}

void find_from_cost(int* found_cnt){
    int cost_buf;
    printf("Введите стоимость, выше которой будет производится поиск продуктов: \n"); scanf("%d", &cost_buf);
    SEPARATOR 
    for (int id = 0; id < current_size; id++){
        if (products[id].cost > cost_buf){
            (*found_cnt)++;
            print_info_product(id);
        }
    }
    if (*found_cnt != 0) {SEPARATOR PAUSE_ CLEAR_}
}

void write_database(char * File_Name) {
    if (_access(File_Name, 0) == 0) {
        FILE * File_Pointer = fopen(File_Name, "w");
    
        for (int id = 0; id < current_size; id++) {
            printf("ЗАПИСЫВАЕМ ДАННЫЕ ... %d / %d\n", id + 1, current_size);
            fprintf(File_Pointer, "|%s|%d|%.2lf|%d|%s|%d|%d|\n", 
                products[id].name,  products[id].quantity, products[id].cost,
                products[id].production_date.day, 
                products[id].production_date.month,
                products[id].production_date.year,
                products[id].expiration);
        }
        fclose(File_Pointer);
    }
    printf("ДАННЫЕ УСПЕШНО ЗАПИСАНЫ !\n");
    
}

void read_database(char * File_Name) {
    if (_access(File_Name, 0) == 0) {        
        current_size = 0; maxsize = 1;
        products = (struct product*) malloc(sizeof(struct product) * maxsize);

        FILE * File_Pointer = fopen(File_Name, "r");
    
        char buffer_line[200];
        char * token;
        int id = 0;
        while (fgets(buffer_line, 200, File_Pointer)) {
            if (current_size == maxsize) {
                maxsize *= 2;
                products = realloc(products, sizeof(struct product) * maxsize);
            }
            // Записываем название
            token = strtok(buffer_line, "|");
            strcpy(products[id].name, token);

            // Записываем количество
            token = strtok(NULL, "|");
            products[id].quantity = atoi(token);
            
            // Записываем стоимость
            token = strtok(NULL, "|");
            products[id].cost = strtod(token, NULL);
    
            // Записываем дату изготовления
            token = strtok(NULL, "|");
            products[id].production_date.day = atoi(token);
            token = strtok(NULL, "|");
            strcpy(products[id].production_date.month, token);
            token = strtok(NULL, "|");
            products[id].production_date.year = atoi(token);

            // Записываем срок годности
            token = strtok(NULL, "|");
            products[id].expiration = atoi(token);

            id++;
            current_size++;
        }
        printf("ДАННЫЕ УСПЕШНО ПРОЧИТАНЫ !\n");
        fclose(File_Pointer);
        PAUSE_
    }
}

void add_product(){
    struct product new_product;
    char new_month[4];
    getchar(); // Очистка буфера ввода после предыдущего ввода

    printf("Введите:\nНазвание:\n ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // Удаление символа новой строки

    printf("Количество:\n ");
    scanf("%d", &new_product.quantity);

    printf("Стоимость:\n");
    scanf("%lf", &new_product.cost);

    printf("День изготовления > \n");
    scanf("%d", &new_product.production_date.day);

    getchar(); // Очистка буфера ввода после ввода числа
    printf("Месяц изготовления> \n");
    fgets(new_month, sizeof(new_month), stdin);
    new_month[strcspn(new_month, "\n")] = 0; // Удаление символа новой строки
    strcpy(new_product.production_date.month, new_month);

    printf("Год изготовления:\n");
    scanf("%d", &new_product.production_date.year);

    printf("Срок годности(в часах):\n > ");
    scanf("%d", &new_product.expiration);

    if (current_size == maxsize){
        maxsize *= 2;
        products = realloc(products, maxsize * sizeof(struct product));
    }
    products[current_size] = new_product;
    current_size++;
}

void search(){
    int inMenu1 = 1;
    int found_cnt = 0, was_finding = 0;
    char Menu_Option_1 = '0';

    while(inMenu1){
        CLEAR_ SEPARATOR
        printf("Введите тип поиска:\n");
        printf("1. По Названию \n2. Выше заданной стоимости\n3. C истекшим сроком годности\n4. Вернуться в главное меню\n");
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
            case '3':   // ПОИСК С ИСТЕКШИМ СРОКОМ
                find_expiration_product(&found_cnt);
                inMenu1 = 0;
                break;
            case '4':   // ВЫХОД В ГЛАВНОЕ МЕНЮ
                inMenu1 = 0;
                break;
            default:
                break;
        }
    // СМОТРИМ, БЫЛ ЛИ ПРОИЗВЕДЕН ПОИСК
        switch(Menu_Option_1){
            case '1':
            case '2':
            case '3':
                was_finding = 1;
                break;
            default:
                break;
        }
        // Проверка, был ли произведен поиск
        if (was_finding == 1 && found_cnt == 0) {
            printf("Не было найдено продуктов по такому запросу...\n\n");
            PAUSE_
        }
    }
}

int main(void)
{   
    time_t CT; srand(time(&CT)); 
    time_t rawtime;
    char *file_name = "Read_ME_Lab_7.txt";
    time(&rawtime);
    timeinfo = localtime(&rawtime); 
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
            case 4:     // Сгенерировать базу данных
                int input;
                CLEAR_ color_output_blue printf("Введите сколько сгенерировать продуктов в базу данных:\n! Минимально - 3\n"); 
                color_output_green scanf("%d", &input); color_output_white
                form_database(input);
                break; 
            case 5:
                add_product();
                break;
            case 6:     // Записать базу данных  в файл
                write_database(file_name);
                PAUSE_
                break;
            case 7:     // Считать базу данных  файла
                clear_memory();
                read_database(file_name);
                break;
            case 8:
                MENU = 0;
                write_database(file_name);
                clear_memory();
                CLEAR_ 
                color_output_red printf("ЗАКРЫВАЕМ ПРОГРАММУ...");
                break;
            default:
                break;
        }
    }
    return 0;
}
