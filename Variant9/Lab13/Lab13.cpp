/*
���������� ����� � ������ TRAIN, ���������� ��������� ����:
�������� ������ ����������; 
����� ������; 
����� �����������.

���������� ������ ������� � ���� ����� � ������������� �������� ���������� � ������� ��� �������� ���� TRAIN.

�������� ���������, ����������� ��������� ��������:
���� � ���������� ������ � ������, ��������� �� ������ �������� ���� TRAIN;
������ ������ ���� ����������� �� ������� �������;
����� �� ����� ���������� � ������, ����� �������� ������ � ���������� (���� ����� ������� ���, ������ �� ������� ��������������� ���������).
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
	cout << "�������� ������ ����������: ";
	getline(in,ob._destination);
	cout << "����� �����������: ";
	getline(in, ob._departureTime);
	cout << "����� ������ (����� �����): "; cin >> ob._number;
	return in;
}
ostream& operator<< (ostream& out, Train& ob)
{
	out << "�������� ������ ����������: " << ob._destination << "\n";
	out << "����� �����������: " << ob._departureTime << "\n";
	out << "����� ������: " << ob._number << "\n";
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
			cout << "���� ������ � " << i + 1 << " ������\n";
			cin >> N;
			cout << "\n";
			_trainCollection.push_back(N);
		}
	}
	void show()
	{
		cout << "���� ������ �������:\n\n";
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
		cout << "����� ������� �� ������: "; cin >> number;

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
			cout << "����� ������� ���!" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	size_t numberTrain;
	cout << "������� ���������� �������: ";
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