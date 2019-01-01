/*
Написать программу учета книг в библиотеке.
Сведения о книгах содержат : фамилию и инициалы автора, название, год издания,
количество экземпляров данной книги в библиотеке.
Программа должна обеспечить выбор с помощью меню и выполнение одной из следующих функций :
- добавление данных о книгах, вновь поступающих в библиотеку;
- удаление данных о списываемых книгах;
- выдача сведений о всех книгах, упорядоченных по фамилиям авторов;
- выдача сведений о всех книгах, упорядоченны по годам издания.
Хранение данных организовать с применением контейнерного класса myltimap, в качестве ключа использовать "Фамилию и инициалы автора".
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Library
{
	struct Book
	{
		string fio;
		string name;
		int year;
		int antall;
	};
public:
	Library()
	{
		cout << "\tБИБЛИОТЕКА\nСколько книг будет в библиотеке? ";
		int size = 0;
		inputValidation(size);
		addBook(size);
		interface();
	};
	multimap <string, Book> multimap;
	Book book;
	void interface() {
		bool next = true;
		while (next)
		{
			cout << "1. Добавление данных о книгах, вновь поступающих в библиотеку\n";
			cout << "2. Удаление данных о списываемых книгах\n";
			cout << "3. Выдача сведений о всех книгах, упорядоченных по фамилиям авторов\n";
			cout << "4. Выдача сведений о всех книгах, упорядоченны по годам издания\n";
			cout << "5. Выдача сведений о книгах по авторам\n";
			cout << "6. Выход\n";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
			{
				cout << "Сколько книг добавить в библиотеку? " << endl;
				int size;
				cin >> size;
				if (size == 0) {
					return;
				}
				addBook(size);
				break;
			}
			case 2:
			{

				deleteBook();
				break;
			}
			case 3:
			{
				showFio();
				break;
			}
			case 4:
			{
				showYear();
				break;
			}
			case 5:
			{
				author();
				break;
			}
			case 6:
			{
				next = false;
				break;
			}
			default: cout << "Не верный ввод! Попробуйте еще раз.\n";
			}
		}
	}
	void showYear() {
		vector <Book> vect;
		for (auto it = multimap.begin(); it != multimap.end(); ++it) {
			vect.push_back(it->second);
		}
		sort(vect.begin(), vect.end(), [](const Book& lhs, const Book& rhs) {
			return (lhs.year > rhs.year);
		});
		for (auto it = vect.begin(); it != vect.end(); ++it)
		{
			cout << "\nАвтор -> " << it->fio << "\nНазвание -> " << it->name << "\nГод -> " << it->year << "\nКоличество -> " << it->antall << endl;
		}
	}
	void showFio() {
		for (auto ptr = multimap.begin(); ptr != multimap.end(); ++ptr)
		{
			cout << "\nАвтор -> " << ptr->first << "\nНазвание -> " << ptr->second.name << "\nГод издания -> " << ptr->second.year << "\nКоличество -> " << ptr->second.antall << "\n";
		}
	}
	void addBook(int sizeAdd) {
		for (; sizeAdd != 0; sizeAdd--)
		{
			cin.ignore();
			cout << "\nАвтор -> ";
			string fio_1;
			getline(cin, fio_1);
			book.fio = fio_1;
			cout << "Название -> ";
			getline(cin, book.name);
			cout << "Год издания -> ";
			inputValidation(book.year);
			cout << "Количество -> ";
			inputValidation(book.antall);
			bool T = true;
			if (!multimap.empty())
			{
				for (auto ptr = multimap.begin(); ptr != multimap.end(); ++ptr)
				{
					if ((ptr->first == book.fio) && (ptr->second.name == book.name))
					{
						T = false;
						ptr->second.antall = ptr->second.antall + book.antall;
					}
				}
			}
			if (T) multimap.insert(make_pair(fio_1, book));
		}
		cout << endl;
	};
	void deleteBook() {
		cout << "Заполните информацию об удаляемой(ых) книге(ах):\nАвтор -> ";
		cin.ignore();
		string fioFake;
		getline(cin, fioFake);
		cout << "Название -> ";
		string nameFake;
		getline(cin, nameFake);
		bool T = true;
		for (auto ptr = multimap.begin(); ptr != multimap.end();)
		{
			if ((ptr->first == fioFake) && (ptr->second.name == nameFake))
			{
				T = false;
				cout << "Количество -> ";
				int antallFake = 0;
				inputValidation(antallFake);
				if (ptr->second.antall >= antallFake) {
					ptr->second.antall = ptr->second.antall - antallFake;
					if (ptr->second.antall == 0)
					{
						ptr = multimap.erase(ptr);
					}
					else ++ptr;
				}
				else cout << "Вы ввели на " << antallFake - ptr->second.antall << " книг больше, чем есть в библиотеке (попробуйте ещё раз)\n";
			}
			else ++ptr;
		}
		if (T) cout << "Таких книг нет\n";
	}
	void author() {
		string author;
		cout << "Автор -> ";
		cin >> author;
		for (auto ptr = multimap.begin(); ptr != multimap.end(); ++ptr)
		{
			if (ptr->first == author)
			{
				cout << "\nНазвание -> " << ptr->second.name << "\nГод издания -> " << ptr->second.year << "\nКоличество -> " << ptr->second.antall << "\n";
			}
		}
	}
	template <typename T>
	void inputValidation(T &name) {
		while (!(cin >> name)) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Неправильный ввод. Повторите.\n";
			cout << "Введите число ";
		}
	}
};
int main()
{
	setlocale(0, "Rus");
	Library PavlyukLiza;
	return 0;
}
