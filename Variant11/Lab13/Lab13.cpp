/*
���������� ����� � ������ MARSH, ���������� ��������� ����:
-�������� ���������� ������ ��������;
-�������� ��������� ������ ��������;
-����� ��������.
���������� ������ ������� � ���� ����� � ������������� �������� ���������� � ������� ��� �������� ���� MARSH.
�������� ���������, ����������� ��������� ��������:
-���� � ���������� ������ � ������, ��������� �� ������ �������� ���� MARSH;
-������ ������ ���� ����������� �� ������� ���������;
-����� �� ����� ���������� � ���������, ������� ���������� ��� ��������� � ������, �������� �������� ������� � ����������
(���� ����� ��������� ���, ������ �� ������� ��������������� ���������)
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
	cout << "�������� ���������� ������ ��������: ";
	getline(in,ob._startName);
	cout << "�������� ��������� ������ ��������: ";
	getline(in, ob._endName);
	cout << "����� �������� (����� �����): "; cin >> ob.number;
	return in;
}
ostream& operator<< (ostream& out, Marsh& ob)
{
	out << "�������� ���������� ������ ��������: " << ob._startName << "\n";
	out << "�������� ��������� ������ ��������: " << ob._endName << "\n";
	out << "����� ��������: " << ob.number << "\n";
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
			cout << "���� ������ � " << i + 1 << " ��������\n";
			cin >> N;
			cout << "\n";
			_marshCollection.push_back(N);
		}
	}
	void show()
	{
		cout << "���� ������ ���������:\n\n";
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
		cout << "����� ��������� �� �������� ����� (������ ��� �����): "; 
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
			cout << "����� �������� ������� �� �������" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color 0A ");

	size_t numberMarshs;
	cout << "������� ���������� ���������: ";
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