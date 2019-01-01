#include <iostream>
#include "stdafx.h"

using namespace std;

class Komplecs {
private:
	double r, i;
public:

	Komplecs() : r(0.0), i(0.0) { }
	Komplecs(double ar, double ai) : r(ar), i(ai) { }

	void Vvod();
	void Print();

	friend Komplecs operator+(Komplecs a, Komplecs b);
	friend Komplecs operator-(Komplecs a, Komplecs b);
	friend Komplecs operator*(Komplecs a, Komplecs b);
};

void Komplecs::Print()
{
	cout << r << "+i*";
	if (i < 0) {
		cout << "(" << i << ")";
	}
	else {
		cout << i;
	}
	cout << endl;
}

void Komplecs::Vvod()
{
	cout << "  действительная часть числа: ";
	cin >> r;
	cout << "  мнимая часть числа: ";
	cin >> i;
	cout << "  введено число: ";
	Print();
}

Komplecs operator+(Komplecs a, Komplecs b)
{
	return Komplecs(a.r + b.r, a.i + b.i);
}

Komplecs operator-(Komplecs a, Komplecs b)
{
	return Komplecs(a.r - b.r, a.i - b.i);
}

Komplecs operator*(Komplecs a, Komplecs b)
{
	return Komplecs(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);
}


int main()
{

	cout << "*** Типа комплексная арифметика ***\n";

	Komplecs a, b;

	int v = 1;

	while (true)
	{
		cout <<
			"\n"
			"1-Сложение чисел\n"
			"2-Умножение чисел\n"
			"3-Вычитание чисел\n"
			"0-Выход" << endl;
		cin >> v;
		if (v == 0) {
			break;
		}

		if (v < 1 || v > 3) {
			cout << "Не угадал. Попробуй ещё раз!" << endl;
			continue;
		}

		cout << "\nВведите первое число:\n";
		a.Vvod();
		cout << "\nВведите второе число:\n";
		b.Vvod();
		cout << endl;

		switch (v) {
		case 1:
			cout << "Результат сложения: ";
			(a + b).Print();
			break;
		case 2:
			cout << "Результат умножения: " << endl;
			(a * b).Print();
			break;
		case 3:
			cout << "Результат вычитания: " << endl;
			(a - b).Print();
			break;
		}

	}
	return 0;
}