/*
1. Определить класс с именем TRAIN, содержащий следующие поля:
 - название пункта назначения;
 - номер поезда;
 - время отправления.
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа TRAIN.
2. Написать программу, выполняющую следующие действия:
 - ввод с клавиатуры данных в массив, состоящий из восьми объектов типа TRAIN; записи должны быть размещены в алфавитном порядке по названиям пунктов назначения;
 - вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени, если таких поездов нет, выдать на дисплей соответствующее сообщение.
*/
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

class Train {
public:
	Train() {}
	Train(string pn, int num, string time) {
		pn_ = pn;
		num_ = num;
		time_ = time;
	}
	string getPn() { return pn_; };
	string getTime() { return time_; };
	friend ostream& operator<<(ostream& out, const Train& rv);
	friend istream& operator>>(istream& in, Train& rv);
private:
	string pn_;
	int num_;
	string time_;
};

ostream& operator<<(ostream& out, const Train& rv) {
	cout << "Пункт назначения: " << rv.pn_ << endl;
	cout << "Номер поезда: " << rv.num_ << endl;
	cout << "Время отправления: " << rv.time_ << endl;
	return out;
}
istream& operator>>(istream& in, Train& rv) {
	cout << "Введите пункт назначения: ";
	getline(cin, rv.pn_);
	while (true)
	{
		cout << "Введите номер поезда: ";
		int num;
		cin >> num;
		cin.ignore(256, '\n');
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вводите только целые числа!" << endl;
		}
		else
		{
			rv.num_ = num;
			break;
		}
	}
	cout << "Введите время отправления: ";
	getline(cin, rv.time_);
	return in;
}

class TrainCollection {
public:
	TrainCollection(int count) {
		for (size_t i = 0; i < count; i++)
			addTrain();
	}
	void addTrain() {
		Train train;
		cin >> train;
		cout << endl;
		trainCollections_.push_back(train);
	}
	void printTrainCollections() {
		for (auto train : trainCollections_)
		{
			cout << train;
			cout << endl;
		}
	}
	void sortTrainCollections() {
		sort(
			trainCollections_.begin(),        
			trainCollections_.end(),
			[](Train& a, Train& b) {
				return a.getPn() < b.getPn();
			}
		);
	}
	void searchAndPrintTrainByTime(string time) {
		bool inp = false;
		for (auto train : trainCollections_)
		{
			if (train.getTime() == time)
			{
				cout << train;
				inp = true;
			}
		}
		if (inp != true) cout << "Поезда не найдены" << endl;
	}
private:
	vector <Train> trainCollections_;
};

int main(void)
{
	setlocale(LC_ALL, "rus");
	cout << "Введите начальное количество поездов: ";
	size_t count;
	cin >> count;
	cin.ignore(256, '\n');
	TrainCollection trainCollection(count);
	cout << "База поездов" << endl;
	trainCollection.printTrainCollections();
	cout << "База поездов после сортировки" << endl;
	trainCollection.sortTrainCollections();
	trainCollection.printTrainCollections();
	cout << "Введите время отправления для поиска поездов: ";
	string time;
	getline(cin, time);
	trainCollection.searchAndPrintTrainByTime(time);
	system("pause");
	return 0;
}