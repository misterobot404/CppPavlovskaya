/*
Реализация системы классов для работы с одномерными массивами строк.
Составить описание класса одномерных массивов строк, каждая строка задается длиной и указателем на выделенную для нее память.
Предусмотреть контроль выхода за границы массивов, возможность обращения в отдельных строк массива по индексам,
выполнения операций поэлементного сцепления двух массивов с образованием нового массива,
слияния двух массивов с исключением повторяющихся элементов, а также вывод на экран элемента массива и всего массива.
Написать программу, демонстрирующую работу с этим классом.
 Программа должна содержать меню, позволяющее осуществить проверку всех методов класса.
*/
#include <iostream>
#include <iomanip> 

using namespace std;
class PointerArray
{
private:
	char** _string;
	int* _stringLength;
	int _size;
public:
	void create();
	void initialize();
	void merge(int n1, int n2);
	void mergeNotRepeatingElements(int n3, int n4);
	void show();
	void showByIndex(int number);
	void search(int rec, int field);
};
void PointerArray::create() //Создание массива строк
{
	// выделение памяти под массивы
	cout << "Количество строк: "; cin >> _size;
	_stringLength = new int[_size];
	_string = new char* [_size];

	// заполняем массива длины строк
	for (int i = 0; i < _size; i++)
	{
		cout << "Количество символов в " << i + 1 << " строке: ";
		cin >> *(_stringLength + i);
		// добавляем одну единицу к длине для символа конца строки 
		*(_stringLength + i) += 1;
	}

	// выделяем память под каждую строку
	for (int i = 0; i < _size; i++) {
		*(_string + i) = new char[_stringLength[i]];
	}
	cout << endl;
}
// Инициализация массивов
void PointerArray::initialize()
{
	create();
	cin.ignore();
	for (int i = 0; i < _size; i++)
	{
		cout << "Ввод " << i + 1 << " строки (до " << *(_stringLength + i) - 1 << " символов): ";
		cin.getline(*(_string + i), *(_stringLength + i)); // char*, int
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			throw exception();
		}
	}
}
// Ввывод всех строк
void PointerArray::show()
{
	for (int i = 0; i < _size; i++)
	{
		cout << *(_string + i);
		cout << endl;
	}
}
// Ввывод строк по индексу
void PointerArray::showByIndex(int number)
{
	if (number < _size)
	{
		for (int i = 0; i < _size; i++)
		{
			if (i == number)
			{
				cout << *(_string + i) << endl;
			}
		}
	}
	else
	{
		cout << "Выход за пределы диапазона строк." << endl;
	}
}
void PointerArray::search(int rec, int field)//Ввывод конкретного элемента конкретной строки (rec – номер строки выводимого массива, field – номер элемента в строке)
{
	if (rec < _size && field < *(_stringLength + rec))
	{
			cout << *(_string + rec) + field << endl;
	}
	else
	{
		cout << "Выход за пределы диапазона строк или элементов." << endl;
	}
}
//Сцепление двух массивов. Значениям дополнительных переменных m1 и m2 присваиваются длины строк, которые необходимо сцепить. Их сумма есть длина нового массива.
void PointerArray::merge(int n1, int n2)
{
	if (n1 < _size && n2 < _size)
	{
		cout << *(_string + n1) << *(_string + n2) << endl;
	}
	else
	{
		cout << "Выход за пределы диапазона строк." << endl;
	}
}
//Слияние двух массивов
void PointerArray::mergeNotRepeatingElements(int n1, int n2)
{
	if (n1 < _size && n2 < _size)
	{
		cout << *(_string + n1);

		for (size_t i = 0; i < *(_stringLength + n2); i++)
		{
			bool checkEntry = false;
			for (size_t j = 0; j < *(_stringLength + n1); j++)
			{

				if (*(*(_string + n1) + j)  == *(*(_string + n2) + i))
				{
					checkEntry = true;
					break;
				}
			}
			if (!checkEntry)
			{
				cout << *(*(_string + n2) + i);
			}
		}
	}
	else
	{
		cout << "Выход за пределы диапазона строк." << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	PointerArray _string;
	int number, punkt, rec, field, n1, n2, n3, n4;
	while (true)
	{

		cout << "  Меню" << endl;
		cout << "1 Создание массива строк"; cout << endl;
		cout << "2 Вывод всех строк"; cout << endl;
		cout << "3 Вывод строки по индексу"; cout << endl;
		cout << "4 Сцепление двух массивов (поэлементное, с повторениями)"; cout << endl;
		cout << "5 Слияние двух масивов (исключение повторяющихся элементов в сливаевом массиве)"; cout << endl;
		cout << "6 Вывод конкретного элемента конкретной строки"; cout << endl;
		cout << "7 Выход"; cout << endl;
		cout << "Введите номер пункта меню: "; cin >> punkt;
		switch (punkt)
		{
		case 1:
		{
			try
			{
				_string.initialize();
				cout << endl;
			}
			catch (const exception&)
			{
				cout << "bad alloc. Program error" << endl;
				system("pause");
				exit(-1);
			}
		}
		break;
		case 2:
		{
			_string.show();
			cout << endl;
		}
		break;
		case 3:
		{
			cout << "Введите номер массива (нумерация начинаеться с 0!): "; cin >> number;
			_string.showByIndex(number);
			cout << endl;
		}
		break;
		case 4:
		{
			cout << "Введите номер 1-го массива: "; cin >> n1;
			cout << "Введите номер 2-го массива: "; cin >> n2;
			_string.merge(n1, n2);
			cout << endl;
		}
		break;
		case 5:
		{
			cout << "Введите номер 1-го массива: "; cin >> n3;
			cout << "Введите номер 2-го массива: "; cin >> n4;
			_string.mergeNotRepeatingElements(n3, n4);
			cout << endl;
			cout << endl;
		}
		break;
		case 6:
		{
			cout << "Введите номер строки массива: "; cin >> rec;
			cout << "Введите номер столбца: "; cin >> field;
			_string.search(rec, field);
			cout << endl;
		}
		break;
		case 7:
			exit(0);
			break;
		}
	}
}