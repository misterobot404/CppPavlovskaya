/*
Написать программу, демонстрирующую работу с объектами двух типов, SymbString и HexString, для чего создать систему соответствующих классов.
Каждый объект должен иметь идентификатор (в виде произвольной строки символов) и одно или несколько полей для хранения состояния (текущего значения) объекта.
Клиенту (функции main) должны быть доступны следующие основные операции (методы): создать объект, удалить объект, показать значение объекта, operator +(SymbString, SymbString), operator +(HexString, HexString).
Операции по созданию и удалению объектов инкапсулировать в классе Factory.
Предусмотреть меню, позволяющее продемонстрировать заданные операции.
При необходимости в разрабатываемые классы добавляются дополнительные методы (например, конструктор копирования, операция присваивания и т.п.) для обеспечения надлежащего функционирования этих классов.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Демонстрация возможностей классов SymbString и HexString" << endl;
	char Control;
	while (true)
	{
		cout << endl << "Интерфейс программы:" << endl;
		cout << "1. Объект SymbString (символьная строка)" << endl;
		cout << "2. Объект HexString (шестнадцатеричная строка)" << endl;
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
			FactoryHexString factoryHexString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nHexString (шестнадцатеричная строка)" << endl;
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
					cout << "Примечание: в строке могут присутствовать цифры от 0 до 9 и буквы A,B,C,D,E,F без пробелов" << endl;
					cout << "Пример: 5CD8" << endl << endl;

					cout << "Введите строку: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "Ошибка ввода." << endl;
						break;
					};
					factoryHexString.addObject(str);
					break;
				}
				case '2':
					factoryHexString.deleteObject();
					break;
				case '3':
					factoryHexString.printContainer();
					break;
				case '4':
				{
					cout << "Примечание: в строке могут присутствовать цифры от 0 до 9 и буквы A,B,C,D,E,F без пробелов" << endl;
					cout << "Пример: 5CD8" << endl << endl;
					cout << "Первый объект" << endl;
					cout << "Введите строку: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "Ошибка ввода." << endl;
						break;
					};
					HexString decString1(str);
					cout << "Второй объект" << endl;
					cout << "Введите строку: ";
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "Ошибка ввода." << endl;
						break;
					};
					HexString decString2(str);
					HexString decString = decString1 + decString2;
					cout << "Результат" << endl;
					decString.printObject();
					cout << "Резултат добавлен в базу объектов" << endl;
					factoryHexString.addObject(decString);
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