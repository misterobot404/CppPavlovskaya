/*
Написать программу «Моя записная книжка».
Предусмотреть возможность работы с произвольным числом записей,
поиска записи по какому-либо признаку (например, по фамилии, дате рождения или номеру телефона),
добавления и удаления записей,
сортировки по разным полям.
Хранение данных организовать с помощью класса map или multimap.
*/
#include "Notebook.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Моя записная книжка" << endl;
	int num;
	while (true)
	{
		cout << "Введите cтартовое количество записей: ";
		cin >> num;
		cin.ignore(256, '\n');
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вводите только целые числа!" << endl;
		}
		else break;
	}
	Notebook notebook(num);
	system("cls");

	while (true)
	{	
		size_t selectedMenuItem;
		while (true)
		{
			cout << "\nМоя записная книжка (текущее количество записей " << notebook.getSize() << ")" << endl;
			cout << "1.Вывод всех записей" << endl;
			cout << "2.Добавление записи" << endl;
			cout << "3.Удаление записи" << endl;
			cout << "4.Поиск записей" << endl;
			cout << "5.Сортировка записей " << endl;
			cout << "6.Очистить консоль" << endl;
			cout << "> ";
			cin >> selectedMenuItem;
			cin.ignore(256, '\n');
			if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
			{
				cin.clear(); // то возвращаем cin в 'обычный' режим работы
				cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
				cout << "Вводите только целые числа!" << endl;
			}
			else break;
		}
		switch (selectedMenuItem)
		{
		case 1:
		{
			notebook.printNotebook();
		}
		break;
		case 2:
		{
			notebook.addNote();
		}
		break;
		case 3:
		{
			cout << "Номер удаляемой записи: ";
			size_t number;
			cin >> number;
			notebook.eraseNote(number);
		}
		break;
		case 4:
		{
			bool exit = false;
			while (!exit)
			{
				cout << "Критерии поиска записи:" << endl;
				cout << "1.Поиск по номеру" << endl;
				cout << "2.Поиск по фамилии" << endl;
				cout << "3.Поиск по дате рождения" << endl;
				cout << "4.Поиск по номеру телефона" << endl;
				cout << "5.Назад в гл. меню" << endl;
				cout << ">";
				size_t t;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					cout << "Введите номер: ";
					size_t recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByNumber(recNumber);
				}
					break;
				case 2:
				{
					cout << "Введите фамилию: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByLastName(recNumber);
				}
					break;
				case 3:
				{
					cout << "Введите дату рождения: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByDateOfBirth(recNumber);
				}
					break;
				case 4:
				{
					cout << "Введите номер телефона: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByPhoneNumber(recNumber);
				}
					break;
				case 5:
					exit = true;
					break;
				}
			}
		}
		break;
		case 5:
		{
			bool exit = false;
			while (!exit)
			{
				cout << "Критерии сортировки записей:" << endl;
				cout << "1.По фамилиям" << endl;
				cout << "2.По дате рождения" << endl;
				cout << "3.Назад в гл. меню" << endl;
				cout << ">";
				size_t t;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					notebook.sortAndPrintNotebookByLastName();
				}
				break;
				case 2:
				{
					notebook.sortAndPrintNotebookByDateOfBirth();
				}
				break;
				case 3:
					exit = true;
					break;
				}
			}
		}
		break;
		case 6:
		{
			system("cls");
		}
		break;
		default: system("cls");
		}
	}
	return 0;
}