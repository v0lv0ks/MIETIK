#include <iostream>
#include <string>
#include <vector>

void separetion(){
    std :: cout << "------------------------" << std::endl;
}


class book{
private:
    std::string title;
    int page_count;
    std::string color;
    std::string author;
    int year_creation;

    std::string title_;
    int page_count_;
    std::string color_;
    std::string author_;
    int year_creation_;

public:

   book(){  //конструктор без параметров
        title = "autovaz2109";
        page_count = 123;
        color = "green";
        author = "Dostoevsky";
        year_creation = 2005;

    }
   book(const std::string&titl , const int page_coun, const std::string&colo, const std::string&autho, const int year_creatio){  //конструктор c параметрами
        title = titl;
        page_count = page_coun;
        color = colo;
        author = autho;
        year_creation = year_creatio;

    }


    void set_title(const std::string& title_){
            title = title_;
    }
    std::string get_title() const{
        return title;
    }

    void set_color(const std::string& color_){
        color = color_;
    }
    std::string get_color() const{
        return color;
    }

    void set_author(const std::string& author_){
        author = author_;
    }
    std::string get_author() const{
        return author;
    }

    void set_year_creation(const int year_creation_){
        if (year_creation_ < 2025){
            std::cout << "Wrong year_creation" << std::endl;
        }
        else{
            year_creation = year_creation_;
        };
    }
    int get_year_creation() const{
        return year_creation;
    }

    void setpage_count(const int page_count_){

        if (page_count_ < 1){
            std::cout << "Too little pages" << std::endl;
        }
        else{
            page_count = page_count_;
        };
    }
    ////////////////////////////////////////////
    void print0() const{
        std::cout << "Title:" << title << std::endl;
    }
    void print1() const{
        std::cout << "Page count:" << page_count << std::endl;
    }
    void print2() const{
        std::cout << "Color:" << color << std::endl;
    }
    void print3() const{
        std::cout << "Author:" << author << std::endl;
    }
    void print4() const{
        std::cout << "Year creation:" << year_creation << std::endl;
    }
};

int main()
{
    book b1;
    std::vector<book> Book_tokens;
    Book_tokens.push_back(b1);
    using std::cout;
    using std::cin;
    using std::endl;


    book b2("Onegin", 99, "blue", "Pushkin", 1823 );//вызов конструктора с параметрами
    //range-based for
    Book_tokens.push_back(b2);

    //b1.set_author("volvoks");
    //cout << b1.get_author() << endl;

    for (const auto& i: Book_tokens){ //универсальный вывод
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
        separetion();
    }
    return 0;
}
