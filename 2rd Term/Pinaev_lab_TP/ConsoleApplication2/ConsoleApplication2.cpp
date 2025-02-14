// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

class complex {
protected:
	float real = 0;
	float imag = 0;
public:
	complex() = default;
	complex(const float& r_, const float& i_) : real{ r_ }, imag{ i_ } {}

	float gr() { return this->real;  }

	bool operator== (const complex& other) const
	{
		return (this->real == other.real) && (this->imag == other.imag);
	}

	// Перегрузка оператора вывода данных
	friend std::ostream& operator<<(std::ostream& os, const complex& cn)
	{
		os << "(" << cn.real << " ; " << cn.imag << "i)";
		return os;
	}
};

int main()
{
	std::vector<complex> v = {complex(), complex(4,5) , complex(3,5) , complex(4,6) , complex(40,5) , complex(4,70) };
	int id = -1;
	for (auto& i : v)
	{
		id++;
		if (i.gr() == 4) {
			std::cout << i << "will be deleted" << std::endl;
			v.erase(v.begin() + id);
		}
		std::cout << i << std::endl;
	}

	std::cout << std::endl;

	for (const auto& i : v) std::cout << i << "\n";

	
}
