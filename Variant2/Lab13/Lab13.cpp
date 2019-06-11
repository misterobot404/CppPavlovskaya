#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

class Student
{
public:
	friend istream& operator >> (istream& in, Student& ob);
	friend ostream& operator<< (ostream& out, Student& ob);
	
	double getGPA()
	{
		double sum = 0;
		for (size_t i = 0; i < 5; i++)
			sum += ses[i];
		return sum / 5;
	}
	bool statusGoodStudent()
	{
		int x = 0;

		for (int j = 0; j < 5; j++)
			if (ses[j] == 4 || ses[j] == 5)
				x++;

		if (x == 5)
			return true;
		else return false;
	}
private:
	string name;
	string group;
	int  ses[5];
};

istream& operator >> (istream& in, Student& ob)
{
	cin.get();
	cout << "ФИО: ";
	getline(in,ob.name);
	cout << "Группа: ";
	in >> ob.group;
	cout << "Оценки:\n";
	for (size_t i = 0; i < 5; i++)
		in >> ob.ses[i];
	return in;
}
ostream& operator<< (ostream& out, Student& ob)
{
	out << "ФИО: " << ob.name << "\n";
	out << "Группа: " << ob.group << "\n";
	out << "Оценки: ";
	for (size_t i = 0; i < 5; i++)
		out << ob.ses[i] << " ";
	out << "\n";
	return out;
}

class University
{
private:
	vector <Student> students;
public:
	University()
	{
		students.reserve(0);
	}
	University(size_t numberStudents)
	{
		students.reserve(numberStudents);
	}
	void sort()
	{
		std::sort(students.begin(), students.end(), []( Student & a,  Student & b)
		{
			return a.getGPA() < b.getGPA();
		});
	}
	void initInput() {
		for (int i = 0; i < students.capacity(); i++)
		{
			Student N;
			cout << "Ввод данных о " << i + 1 << " студенте\n";
			cin >> N;
			cout << "\n";
			students.push_back(N);
		}
	}
	void show()
	{
		cout << "База данных студентов:\n\n";
		for (int i = 0; i < students.capacity(); i++)
		{
			cout << students[i];
			cout << "\n";
		}
	}

	void showStars()
	{
		cout << "Поиск студентов, которые хорошо учатся..." << endl;

		bool z = false;
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i].statusGoodStudent())
			{
				cout << students[i];
				z = true;
			}
		}

		if (!z)
			cout << "Среди студентов нет хорошистов" << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("color 0A ");

	size_t numberStudents;
	cout << "Введите количество студентов: ";
	cin >> numberStudents;
	cout << "\n";

	University KnASU(numberStudents);
	KnASU.initInput();
	KnASU.sort();
	KnASU.show();
	KnASU.showStars();

	system("pause");
	return 0;
}