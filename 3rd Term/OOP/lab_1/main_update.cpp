﻿// Lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <Windows.h>


std::vector<std::string> split_line(const std::string& str, char delim) {

    std::vector<std::string> tokens;

    if (!str.empty()) {
        size_t start = 0, end;
        do {
            tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
            end = str.find(delim, start);
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}
class lesson {
    int number;
    std::string title;
    std::string type;
    int lecture;
    void Setnumber(int )

};
int main() {
    //setlocale(LC_ALL, "Russian");
    setlocale(0, "");

    std::ifstream file("lab_1.csv");

    if (file.is_open()) {
        std::string line;

        while (!file.eof()) {
            std::getline(file, line);
            std::vector<std::string> tokens_ = split_line(line, ';');//чтение и запись
            std::cout << line << std::endl;
        }
        file.close();
    }

    else {
        std::cout << "Failed to open file" << std::endl;
    }
    std::sort(tokens_.begin(), tokens.end(), [](int a, int b) { return a < b; });
    //сортировка

    return 0;

}
*/
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <print>

void separator() {
    std::cout << "------------------------" << std::endl;
}
enum Color
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};


void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, Color background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


class book {
private:
    std::string title;
    int page_count;
    std::string color;
    std::string author;
    int year_creation;


public:

    book()//конструктор  со списком инициализации
        : title{ "autovaz2109" }
        , page_count{ 123 }
        , color{ "green" }
        , author{ "Dostoevsky" }
        , year_creation{ 2005 }
    {
        ////////
    }
 
    book(const std::string& title_, const int page_count_, const std::string& color_, const std::string& author_, const int year_creation_) //конструктор с параметрами и со списком инициализации

        :title { title_ }
        , page_count{ page_count_ }
        , color{ color_ }
        , author{ author_ }
        , year_creation{ year_creation_ }
    {

    }

    ~book() {
        //std::cout << "Here destructor" << std::endl;
    }


    void set_title(const std::string& title) {
        this->title = title;
    }
    std::string get_title() const {
        return title;
    }

    void set_color(const std::string& color) {
        this->color = color;
    }
    std::string get_color() const {
        return color;
    }

    void set_author(const std::string& author) {
        this->author = author;
    }
    std::string get_author() const {
        return author;
    }

    void set_year_creation(const int year_creation) {
        if (year_creation > 2025) {
            //std :: print("Wrong year_creation");
            std::cout << "Wrong year_creation" << std::endl;
            separator();
        }
        else {
            this->year_creation = year_creation;
        };
    }
    int get_year_creation() const {
        return year_creation;
    }

    void setpage_count(const int page_count_) {

        if (page_count < 1) {
            std::cout << "Too little pages" << std::endl;
        }
        else {
            this->page_count = page_count;
        };
    }
    ////////////////////////////////////////////
    void print0() const {
        std::cout << "Title:" << title << std::endl;
    }
    void print1() const {
        std::cout << "Page count:" << page_count << std::endl;
    }
    void print2() const {
        std::cout << "Color:" << color << std::endl;
    }
    void print3() const {
        std::cout << "Author:" << author << std::endl;
    }
    void print4() const {
        std::cout << "Year creation:" << year_creation << std::endl;
        
    }
};

int main()
{   
    using std::cout;
    using std::cin;
    using std::endl;

    {
        book b1;
        b1.set_year_creation(2026);
        //cout << b1.get_author() << endl;
        book b2;
        book b3("Onegin", 99, "blue", "Pushkin", 1823);
        std::vector<book> Book_tokens;
        Book_tokens.push_back(b1);
        Book_tokens.push_back(b2);
        Book_tokens.push_back(b3);

        for (const auto& i : Book_tokens) {     //range-based for

            i.print0();
            cout << endl;
            i.print1();
            cout << endl;
            i.print2();
            cout << endl;
            i.print3();
            cout << endl;
            i.print4();
            cout << endl;
            separator();
        }
        
    }
    return 0;
}
