// lab_3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class pilomatireals {

public:
    
    pilomatireals(string t, int cop, int cos, int volume)
    {
        this->type = t;
        this->cost_of_purchase = cop;
        this->cost_of_sale = cos;
        this->volume = volume;
    };

    ~pilomatireals() {};

    string getType() { return this->type;  }
    int getVolume()  { return this->volume; }
    int getCop() { return this->cost_of_purchase; }
    int getCos() { return this->cost_of_sale; }

    bool operator==(const pilomatireals& other) const {
        if (this->type == other.type)
        {
            return true;
        }
        return false;
    }

private:
    string type{""};
    float cost_of_purchase = 0;
    float cost_of_sale = 0;
    float volume = 0;
};

class warehouse {

public:

    warehouse(int id
        , string d_sur
        , float max
        , vector<pilomatireals> PML
        , vector<float> purch
        , vector<float> sel
        , float money)
    {
        this->id = id;
        this->d_sur = d_sur;
        this->max_volume = max;
        this->PML = PML;
        this->purchasingCosts = purch;
        this->sellingCosts = sel;
        this->money = money;

    };

    int getid()             { return this->id; };
    string getd_Sur()       { return this->d_sur; };
    float getMax()          { return this->max_volume; };
    vector< pilomatireals>getPML() { return this->PML; };
    vector<float>getPurch() { return this->purchasingCosts; };
    vector< float>getSell() { return this->sellingCosts; };
    int getMoney()          { return this->money; };

    ~warehouse() {};
    
    void add(pilomatireals pm)
    {
        if (this->money >= pm.getCop()) 
        {

            this->PML.push_back(pm);
            this->purchasingCosts.push_back(pm.getCop() / pm.getVolume());
            this->sellingCosts.push_back(pm.getCos() / pm.getVolume());
            this->money -= pm.getCop();
        }
        else
            cout << "No_money";
    }           
    void sell(pilomatireals pm) 
    {
        int id = -1;
        for (const auto& other : this->PML) 
        {
            id += 1;
            if (pm == other)
            {
                //PML.erase(other);
                PML.erase(PML.begin() + id);
            }
        }
    }
    string message_canBuy(pilomatireals pm)
    {
        string Message = ""; 
        int amount = this->money / pm.getCop();
        int capacity = pm.getVolume() *  amount;
       //auto minCost = std::min_element(this->PML.begin(), this->PML.end());

        // [](auto a, auto b){return not compare_model(a,b); }

        while (capacity > this->max_volume)
        {
            capacity -= pm.getVolume();
            amount -= 1;
        }
        Message += "We can buy " + std::to_string(amount) + " of " + pm.getType() + " materials";
        return Message;
    }
    string message_available() 
    {

    }


private:
    int id;
    string d_sur;
    float max_volume;
    vector<pilomatireals> PML;
    vector<float> purchasingCosts;
    vector<float> sellingCosts;
    float money;
    
};

int main()
{
   
    pilomatireals Pilo = pilomatireals("woood",20,40,23);

    cout << Pilo.getVolume();


   /* wood.setType(-2);
    try {
        this.type = t
    }
    catch ArgumentError
    cathc 

    cout << nwood.getType() << nwood.getVolume() << endl;
    */
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
