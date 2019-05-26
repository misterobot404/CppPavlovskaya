/*
Определить класс с именем NOTE, содержащий следующие поля:
 - фамилия, имя;
 - номер телефона; 
 - день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа NOTE.
Написать программу, выполняющую следующие действия:
 - ввод с клавиатуры данных в массив, состоящий из восьми объектов типа NOTE;  записи должны быть упорядочены по датам дней рождения;
 - вывод на экран информации о человеке, номер телефона которого введен с клавиатуры, если такого нет, выдать на дисплей соответствующее сообщение.
*/
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

class Note {
public:
	Note() {}
	Note(string fio, string phoneNumber, string birthday0, string birthday1, string birthday2) {
		fio_ = fio;
		phoneNumber_ = phoneNumber;
		birthday_[0] = birthday0;
		birthday_[1] = birthday1;
		birthday_[2] = birthday2;
	}
	friend ostream& operator<<(ostream& out, const Note& rv);
	friend istream& operator>>(istream& in, Note& rv);
	friend class Notebook;
private:
	string fio_;
	string phoneNumber_;
	string birthday_[3];
};

ostream& operator<<(ostream& out, const Note& rv) {
	cout << "Фамилия и имя: " << rv.fio_ << endl;
	cout << "Номер телефона: " << rv.phoneNumber_ << endl;
	cout << "День рождения (массив из трех чисел ГГ.ММ.ДД): " << rv.birthday_[0] << "." << rv.birthday_[1] << "." << rv.birthday_[2] << endl;
	return out;
}
istream& operator>>(istream& in, Note& rv) {
	cout << "Введите фамилию и имя: ";
	getline(cin, rv.fio_);
	cout << "Введите номер телефона: ";
	getline(cin, rv.phoneNumber_);
	cout << "Введите день рождения (массив из трех чисел ГГ.ММ.ДД)" << endl;
	cout << "Введите год: ";
	getline(cin, rv.birthday_[0]);
	cout << "Введите месяц: ";
	getline(cin, rv.birthday_[1]);
	cout << "Введите день: ";
	getline(cin, rv.birthday_[2]);
	return in;
}

class Notebook {
public:
	Notebook(int count) {
		for (size_t i = 0; i < count; i++)
			addNote();
	}
	void addNote() {
		Note note;
		cin >> note;
		cout << endl;
		notebook_.push_back(note);
	}
	void printNotebook() {
		for (auto note : notebook_)
		{
			cout << note;
			cout << endl;
		}
	}
	void sortNotebook() {
		sort(
			notebook_.begin(),        
			notebook_.end(),
			[](Note& a, Note& b) {
			if (a.birthday_[0] == b.birthday_[0])
			{
				if (a.birthday_[1] == b.birthday_[1])
				{
					return a.birthday_[2] < b.birthday_[2];
				}
				else return a.birthday_[1] < b.birthday_[1];
			}
			else return a.birthday_[0] < b.birthday_[0];
			}
		);
	}
	void searchAndPrintNoteByPhoneNumber(string phoneNumber) {
		bool inp = false;
		for (auto note : notebook_)
		{
			if (note.phoneNumber_ == phoneNumber)
			{
				cout << note;
				inp = true;
			}
		}
		if (inp != true) cout << "Номер телефона не найден" << endl;
	}
private:
	vector <Note> notebook_;
};

int main(void)
{
	setlocale(LC_ALL, "rus");
	cout << "Введите начальное количество записей: ";
	size_t count;
	cin >> count;
	cout << endl;
	cin.ignore(256, '\n');
	Notebook notebook(count);
	cout << "База записей" << endl;
	notebook.printNotebook();
	cout << "База записей после сортировки" << endl;
	notebook.sortNotebook();
	notebook.printNotebook();
	cout << "Введите номер телефона для поиска записи: ";
	string phoneNumber;
	getline(cin, phoneNumber);
	notebook.searchAndPrintNoteByPhoneNumber(phoneNumber);
	system("pause");
	return 0;
}