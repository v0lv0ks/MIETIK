﻿

#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
    double a = 0.0, b = 0.5, l, r , x, y1, y2, eps = 0.0001;
    int n = 0;
    l = a, r = b;
    y1 = 2 * a * a * a + 4 * a - 1;
    y2 = 2 * b * b * b + 4 * b - 1;

    if (y1 * y2 > 0)
    {
        cout << "equation hasn't roots" << endl;
        system("pause");
        exit(1);
    }

    do {
        n++;
        x = (a + b) / 2;
        y1 = 2 * a * a * a + 4 * a - 1;
        y2 = 2 * x * x * x + 4 * x - 1;

        if (y1 * y2 > 0)
            a = x;
        else b = x;

    } while ((b - a) > eps);
        x = (a + b) / 2;
        cout << "root on the section "
             <<"["<< l << ", " << r <<"]" << "  equal  " << x
            << " and get from  " << n << " steps";
        cout << endl;
        system("pause");
        return 0;
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
