/*
Определить класс с именем TRAIN, содержащий следующие поля:
название пункта назначения; 
номер поезда; 
время отправления.

Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа TRAIN.

Написать программу, выполняющую следующие действия:
ввод с клавиатуры данных в массив, состоящий из восьми объектов типа TRAIN;
записи должны быть упорядочены по номерам поездов;
вывод на экран информации о поезде, номер которого введен с клавиатуры (если таких поездов нет, выдать на дисплей соответствующее сообщение).
*/
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

class Train
{
public:
	friend istream& operator >> (istream& in, Train& ob);
	friend ostream& operator<< (ostream& out, Train& ob);
	friend class TrainCollection;

	double getNumber()
	{
		return _number;
	}
private:
	string _destination;
	string _departureTime;
	int  _number;
};

istream& operator >> (istream& in, Train& ob)
{
	cin.ignore();
	cout << "Название пункта назначения: ";
	getline(in,ob._destination);
	cout << "Время отправления: ";
	getline(in, ob._departureTime);
	cout << "Номер поезда (целое число): "; cin >> ob._number;
	return in;
}
ostream& operator<< (ostream& out, Train& ob)
{
	out << "Название пункта назначения: " << ob._destination << "\n";
	out << "Время отправления: " << ob._departureTime << "\n";
	out << "Номер поезда: " << ob._number << "\n";
	return out;
}

class TrainCollection
{
private:
	vector <Train> _trainCollection;
public:
	TrainCollection()
	{
		_trainCollection.reserve(0);
	}
	TrainCollection(size_t numberTrain)
	{
		_trainCollection.reserve(numberTrain);
	}
	void sort()
	{
		std::sort(_trainCollection.begin(), _trainCollection.end(), []( Train & a,  Train & b)
		{
			return a.getNumber() < b.getNumber();
		});
	}
	void initInput() {
		for (int i = 0; i < _trainCollection.capacity(); i++)
		{
			Train N;
			cout << "Ввод данных о " << i + 1 << " поезде\n";
			cin >> N;
			cout << "\n";
			_trainCollection.push_back(N);
		}
	}
	void show()
	{
		cout << "База данных поездов:\n\n";
		for (int i = 0; i < _trainCollection.capacity(); i++)
		{
			cout << _trainCollection[i];
			cout << "\n";
		}
	}

	void searchTrain()
	{
		cin.ignore();
		int number;
		cout << "Поиск поездов по номеру: "; cin >> number;

		bool z = false;
		for (auto train : _trainCollection)
		{
			if (train._number == number)
			{
				cout << train;
				z = true;
			}
		}
		if (!z)
			cout << "Такие поездов нет!" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	size_t numberTrain;
	cout << "Введите количество поездов: ";
	cin >> numberTrain;
	cout << "\n";

	TrainCollection trainCollection(numberTrain);
	trainCollection.initInput();
	trainCollection.sort();
	trainCollection.show();
	trainCollection.searchTrain();

	system("pause");
	return 0;
}