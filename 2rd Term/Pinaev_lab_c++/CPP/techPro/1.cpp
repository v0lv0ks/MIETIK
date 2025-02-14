#include <iostream>
#include <cmath>

int main() {
    double epsilon;
    std::cout << "Введите значение эпсилон (ε): ";
    std::cin >> epsilon;

    int i = 1;
    double a_prev = 0.0; // a_0 = 0
    double a_curr = exp(-a_prev); // a_1 = exp(-a_0)
    std::cout << "a_0 = " << a_prev << std::endl;

    // Продолжаем вычисление, пока условие не выполнено
    while (fabs(a_curr - a_prev) >= epsilon) {
        std::cout << "a_" << i << " = " << a_curr << std::endl;

        // Переходим к следующему элементу
        a_prev = a_curr;
        a_curr = exp(-a_prev);
        i++;
    }

    // Выводим последний элемент, когда условие выполнено
    std::cout << "a_" << i << " = " << a_curr << std::endl;
    std::cout << "Минимальный номер i = " << i-1 << std::endl;

    return 0;
}
