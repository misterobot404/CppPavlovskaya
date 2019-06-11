/*
Требуется создать шаблон некоторого целевого класса List.
Во всех вариантах показать в клиенте main использование созданного класса, включая ситуации, приводящие к генерации исключений.
Показать инстанцирование шаблона для типов int, double, std::string.
*/
#include "List.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "List представляет собой контейнер, который поддерживает быструю вставку" << endl
		<< "и удаление элементов из любой позиции в контейнере." << endl
		<< "Быстрый произвольный доступ не поддерживается (т.к элементы расположены в памяти в хаотичном порядке)." << endl
		<< "List реализован в виде двусвязного списка." << endl << endl;
	cout << "Демонстрация целевого шаблонного класса List с типом int" << endl;
	try
	{
		// для int(для всего остального делается аналогично)
		List<int> listInt(0);

		cout << "Добавление в список значений типа int от 0 до 9" << endl;
		for (int i = 0; i < 10; ++i)
			listInt.push_back(i);

		cout << "Вывод списка" << endl;
		listInt.output();

		cout << "Введите элемент для удаления ";
		int el; cin >> el;
		listInt.remove(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		cout << "Введите элемент для вставки в начало ";
		cin >> el;
		listInt.push_front(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\nОчистка списка...Список пуст" << endl;

		cout << "Попытка удалить ещё один элемент из списка.." << endl;
		// исключение т.к. стек уже пуст
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	cout << endl;
	cout << "Демонстрация целевого шаблонного класса List с типом double" << endl;
	try
	{
		// для int(для всего остального делается аналогично)
		List<double> listInt(0);

		cout << "Добавление в список значений типа double от 0.5 до 9.5" << endl;
		for (double i = 0.5; i < 10; ++i)
			listInt.push_back(i);

		cout << "Вывод списка" << endl;
		listInt.output();

		cout << "Введите элемент для удаления ";
		double el; cin >> el;
		listInt.remove(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		cout << "Введите элемент для вставки в начало ";
		cin >> el;
		listInt.push_front(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\nОчистка списка...Список пуст" << endl;

		cout << "Попытка удалить ещё один элемент из списка.." << endl;
		// исключение т.к. стек уже пуст
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	cout << endl;

	cout << "Демонстрация целевого шаблонного класса List с типом string" << endl;
	try
	{
		List<string> listInt(0);

		cout << "Добавление в список значений типа string от '0' до '9'" << endl;
		for (int i = 0; i < 10; ++i)
		{
			string s = "'" + to_string(i) + "'";
			listInt.push_back(s);
		}

		cout << "Вывод списка" << endl;
		listInt.output();

		cout << "Введите элемент для удаления ";
		string el; cin >> el;
		listInt.remove(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		cout << "Введите элемент для вставки в начало";
		cin >> el;
		listInt.push_front(el);
		cout << "Получившийся список" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\nОчистка списка...Список пуст" << endl;

		cout << "Попытка удалить ещё один элемент из списка.." << endl;
		// исключение т.к. стек уже пуст
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	system("pause");
	return 0;
}
