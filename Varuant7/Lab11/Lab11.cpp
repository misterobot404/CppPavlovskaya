/*
Написать программу, демонстрирующую работу с объектами двух типов, SymbString и DecString, для чего создать систему соответствующих классов.
Каждый объект должен иметь идентификатор (в виде произвольной строки символов) и одно или несколько полей для хранения состояния (текущего значения) объекта.
Клиенту (функции main) должны быть доступны следующие основные операции (методы): создать объект, удалить объект, показать значение объекта, operator +(SymbString, SymbString), operator +(DecString, DecString).
Операции по созданию и удалению объектов инкапсулировать в классе Factory.
Предусмотреть меню, позволяющее продемонстрировать заданные операции.
При необходимости в разрабатываемые классы добавляются дополнительные методы (например, конструктор копирования, операция присваивания и т.п.) для обеспечения надлежащего функционирования этих классов.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Демонстрация возможностей классов SymbString и DecString" << endl;
	char Control;
	while (true)
	{
		cout << endl << "Интерфейс программы:" << endl;
		cout << "1. Объект SymbString (символьная строка)" << endl;
		cout << "2. Объект DecString (десятичная строка)" << endl;
		cout << ">";
		cin >> Control;
		switch (Control)
		{
		case '1':
		{
			FactorySymbString factorySymbString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nSymbString (символьная строка)" << endl;
				cout << "1. Добавить объект" << endl;
				cout << "2. Удалить объект" << endl;
				cout << "3. Показать созданные объекты" << endl;
				cout << "4. Сложить объекты" << endl;
				cout << "5. Вернуться к выбору типа объекта" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					cout << "Введите строку: ";
					cin.ignore();
					string symbString;
					getline(cin, symbString);
					factorySymbString.addObject(symbString);
					break;
				}
				case '2':
					factorySymbString.deleteObject();
					break;
				case '3':
					factorySymbString.printContainer();
					break;
				case '4':
				{
					cout << "Первый объект" << endl;
					cout << "Введите строку: ";
					cin.ignore();
					string str;
					getline(cin, str);
					SymbString symbString1(str);
					cout << "Второй объект" << endl;
					cout << "Введите строку: ";
					getline(cin, str);
					SymbString symbString2(str);
					SymbString symbString = symbString1 + symbString2;
					cout << "Результат" << endl;
					symbString.printObject();
					cout << "Резултат добавлен в базу объектов" << endl;
					factorySymbString.addObject(symbString);
					break;
				}
				case '5':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		case '2':
		{
			FactoryDecString factoryDecString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nDecString (десятичная строка)" << endl;
				cout << "1. Добавить объект" << endl;
				cout << "2. Удалить объект" << endl;
				cout << "3. Показать созданные объекты" << endl;
				cout << "4. Сложить объекты" << endl;
				cout << "5. Вернуться к выбору типа объекта" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					cout << "Введите строку: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos))
					{
						cout << "В строке могут присутствовать символы только от 0 до 9 без пробелов";
						break;
					};
					factoryDecString.addObject(str);
					break;
				}
				case '2':
					factoryDecString.deleteObject();
					break;
				case '3':
					factoryDecString.printContainer();
					break;
				case '4':
				{
					cout << "Первый объект" << endl;
					cout << "Введите строку: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos) && str.find(' ') != string::npos)
					{
						cout << "В строке могут присутствовать символы только от 0 до 9 без пробелов";
						break;
					};
					DecString decString1(str);
					cout << "Второй объект" << endl;
					cout << "Введите строку: ";
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos) && str.find(' ') != string::npos)
					{
						cout << "В строке могут присутствовать символы только от 0 до 9 без пробелов";
						break;
					};
					DecString decString2(str);
					DecString decString = decString1 + decString2;
					cout << "Результат" << endl;
					decString.printObject();
					cout << "Резултат добавлен в базу объектов" << endl;
					factoryDecString.addObject(decString);
					break;
				}
				case '5':
					breakCheck = false;
					break;
				default: continue;
				}
			}
			break;
		}
		default: continue;
		}
	}
	return 0;
}