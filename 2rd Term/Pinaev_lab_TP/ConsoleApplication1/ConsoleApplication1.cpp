#include <iostream>
#include <string>
#include <vector> 
#include <list> 
#include <set> 
#include <algorithm>
#include <iterator> 
#include <math.h>
#include <unordered_set>
using std:: cout;
using std:: cin;
using std:: string;
using std:: vector;
using std:: list;
using std:: endl;
using std:: set;
using std::min;




class piloamtireals
{

private:
    string type = "";
    float cost = 0;;
    float sale = 0;
    float volume = 0;


public:

    piloamtireals(string type, float cost, float sale, float volume)//конструктор
    {
        this->type = type;
        this->cost = cost;
        this->sale = sale;
        this->volume = volume;
    };

    string getType() { return this->type; }
    float getCost() { return this->cost; }
    float getSale() { return this->sale; }
    float getVolume() { return this->volume; }

    
    //функции-методы

    void pr_cost_sale()

    {   
        cout << "Cost:" << cost << " " << "Sale:" << sale << endl;
    }

    void print_volume()

    {   
        cout << "Volume:" << volume << endl;
    };
    ~piloamtireals() {}; // деструктор
};
   

class lumber_warehouse
{
    float current_volume = 0;
    float current_money = 500;
private:
    int number = 0;
    string surname = "";
    float max_volume = 0;
    set <string> list_materials = {};
    set <float> cost_price = {};
    set <float> sale_price = {};

public:

    lumber_warehouse(int number, string surname, float max_volume,
                     set <float> cost_price, set <float> sale_price, set <string> list_of_materials) //конструктор
    {
        this->number = number;
        this->surname = surname;
        this->max_volume = max_volume;
        this->cost_price = cost_price;
        this->sale_price = sale_price;
        this->list_materials = list_of_materials;
    };
    set<string> getList() { return list_materials;  }

    //функции-методы

    void buy(piloamtireals pm)
    {

        if (pm.getCost() <= current_money and pm.getVolume() <= max_volume) { // проверка что хватает денег И места

            this->list_materials.insert(pm.getType());
            this->cost_price.insert(pm.getCost());
            this->sale_price.insert(pm.getSale());
            current_volume += pm.getVolume();
            current_money -= pm.getCost();
        }
        else
            cout << "Not enough money or space " << endl;
    }
    void sale(piloamtireals pm)
    {
        this->list_materials.erase(pm.getType());
        this->cost_price.erase(pm.getCost());
        this->sale_price.erase(pm.getSale());
        current_volume -= pm.getVolume();
        current_money += pm.getSale();
    }

    void message1(piloamtireals pm)
    {
        
        string Message = "";
        float price = pm.getVolume() / pm.getCost();
        int capacity = min(current_money / price, (max_volume - current_volume) / pm.getVolume());
        Message += "We can buy " + std::to_string(capacity) + " of " + pm.getType() + " materials";
        cout << Message << endl;
        cout << "Total money:  " << current_money << "  Total volume:  " << current_volume << endl;

    }
    void message2()
    {
        cout << "We have   " << sizeof(list_materials) << "  materials" << endl;
        cout << "List of materials:   ";
        for (auto const& i : list_materials)
        {
            cout << i << " , ";
        }
    }
    ~lumber_warehouse() {}; //деструктор
};


int main()
{
    /*float> Cost = {74, 21, 56, 98, 13, 47, 3, 62, 85, 29, 90, 7, 53, 44, 66, 18, 32, 72, 91, 15, 39, 50, 24, 9, 77, 36};
    set<float> Sale = { 26, 63, 90, 6, 42, 51, 93, 38, 15, 71, 10, 73, 47, 23, 4, 82, 68, 28, 9, 84, 61, 33, 75, 12, 57, 40 };
    set<string> Pilo = { "board," "plank," "timber,","lumber," 
                         "beam," "stud," "joist," "rafter," "batten,"
                         "plywood," "veneer," "clapboard," "shiplap," "hardwood,"
                         "softwood," "molding," "decking," "particle board," "OSB," 
                         "MDF," "laminate," "blockboard," "cladding," "slab," "trim," "siding."};  */
    set<float> Cost = {};
    set <float> Sale = {};
    set<string> Pilo = {};
    
    lumber_warehouse opt = lumber_warehouse(1250, "Pinaev", 500, Cost, Sale, Pilo);

    piloamtireals Zakaz1 = piloamtireals("board", 74, 26, 15);
    piloamtireals Zakaz2 = piloamtireals("plank", 21, 63, 17);
    piloamtireals Zakaz3 = piloamtireals("timber", 56, 90, 54);
    piloamtireals Zakaz4 = piloamtireals("lumber", 98, 6, 20);
    piloamtireals Zakaz5 = piloamtireals("beam", 13, 42, 45);
    piloamtireals Zakaz6 = piloamtireals("veneer", 47, 51, 100);
    piloamtireals Zakaz7 = piloamtireals("clapboard", 3, 93, 65);
    piloamtireals Zakaz8 = piloamtireals("shiplap", 62, 38, 34);
    piloamtireals Zakaz9 = piloamtireals("hardwood", 85, 15, 99);
    piloamtireals Zakaz10 = piloamtireals("softwood", 29, 71, 20);

    Zakaz1.print_volume();
    Zakaz1.pr_cost_sale(); 

    opt.buy(Zakaz1);
    opt.buy(Zakaz2);
    opt.buy(Zakaz3);
    opt.buy(Zakaz4);
    opt.buy(Zakaz5);
    opt.buy(Zakaz6);
    opt.buy(Zakaz7);
    opt.buy(Zakaz8);
    opt.buy(Zakaz9);
    opt.buy(Zakaz10);
    
    opt.sale(Zakaz1);
    opt.sale(Zakaz10);
    opt.message1(Zakaz1);
    opt.buy(Zakaz10);
    opt.message2();
    
    //cout << Zakaz1.getVolume() << " " <<  Zakaz1.getCost() << " " <<  Zakaz1.getSale() << endl; //альтернативный способ вывода
    return 0;
}