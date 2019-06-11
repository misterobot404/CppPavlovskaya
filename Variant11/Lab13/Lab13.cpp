/*
Определить класс с именем MARSH, содержащий следующие поля:
-название начального пункта маршрута;
-название конечного пункта маршрута;
-номер маршрута.
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа MARSH.
Написать программу, выполняющую следующие действия:
-ввод с клавиатуры данных в массив, состоящий из восьми объектов типа MARSH;
-записи должны быть упорядочены по номерам маршрутов;
-вывод на экран информации о маршрутах, которые начинаются или кончаются в пункте, название которого введено с клавиатуры
(если таких маршрутов нет, выдать на дисплей соответствующее сообщение)
*/
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

class Marsh
{
public:
	friend istream& operator >> (istream& in, Marsh& ob);
	friend ostream& operator<< (ostream& out, Marsh& ob);
	friend class MarshCollection;

	double getNumber()
	{
		return number;
	}
private:
	string _startName;
	string _endName;
	int  number;
};

istream& operator >> (istream& in, Marsh& ob)
{
	cin.ignore();
	cout << "Название начального пункта маршрута: ";
	getline(in,ob._startName);
	cout << "Название конечного пункта маршрута: ";
	getline(in, ob._endName);
	cout << "Номер маршрута (целое число): "; cin >> ob.number;
	return in;
}
ostream& operator<< (ostream& out, Marsh& ob)
{
	out << "Название начального пункта маршрута: " << ob._startName << "\n";
	out << "Название конечного пункта маршрута: " << ob._endName << "\n";
	out << "Номер маршрута: " << ob.number << "\n";
	return out;
}

class MarshCollection
{
private:
	vector <Marsh> _marshCollection;
public:
	MarshCollection()
	{
		_marshCollection.reserve(0);
	}
	MarshCollection(size_t numberStudents)
	{
		_marshCollection.reserve(numberStudents);
	}
	void sort()
	{
		std::sort(_marshCollection.begin(), _marshCollection.end(), []( Marsh & a,  Marsh & b)
		{
			return a.getNumber() < b.getNumber();
		});
	}
	void initInput() {
		for (int i = 0; i < _marshCollection.capacity(); i++)
		{
			Marsh N;
			cout << "Ввод данных о " << i + 1 << " маршруте\n";
			cin >> N;
			cout << "\n";
			_marshCollection.push_back(N);
		}
	}
	void show()
	{
		cout << "База данных маршрутов:\n\n";
		for (int i = 0; i < _marshCollection.capacity(); i++)
		{
			cout << _marshCollection[i];
			cout << "\n";
		}
	}

	void searchMarsh()
	{
		cin.ignore();
		string str;
		cout << "Поиск маршрутов по названию пунка (начала или конца): "; 
		getline(cin,str);

		bool z = false;
		for (auto marsh : _marshCollection)
		{
			if (marsh._startName == str || marsh._endName == str)
			{
				cout << marsh;
				z = true;
			}
		}
		if (!z)
			cout << "Такие названия пунктов не найдены" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color 0A ");

	size_t numberMarshs;
	cout << "Введите количество маршрутов: ";
	cin >> numberMarshs;
	cout << "\n";

	MarshCollection marshs(numberMarshs);
	marshs.initInput();
	marshs.sort();
	marshs.show();
	marshs.searchMarsh();

	system("pause");
	return 0;
}