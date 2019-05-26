/*
Требуется создать шаблон некоторого целевого класса Stack.
В каждом варианте уточняются требования к реализации — указанием на применение некоторого серверного класса std::list.
Это означает, что объект класса std::list используется как элемент класса Stack.
Во всех вариантах показать в клиенте main использование созданного класса, включая ситуации, приводящие к генерации исключений.
Показать инстанцирование шаблона для типов int, double, std::string.
*/
#include "Stack.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Демонстрация целевого шаблонного класса Stack с типом int" << endl;
	try
	{
		// для int(для всего остального делается аналогично)
		Stack<int> stackInt;

		cout << "Добавление в стек значений типа int от 0 до 9" << endl;
		for (int i = 0; i < 10; ++i)
			stackInt.push(i);

		cout << "Вывод стека" << endl;
		while (!stackInt.empty())
		{
			std::cout << stackInt.top() << ' ';
			stackInt.pop();
		}
		cout << "\nОчистка стека...Стек пуст" << endl;

		cout << "Попытка удалить ещё один элемент из стека.." << endl;
		// исключение т.к. стек уже пуст
		stackInt.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Stack<double> stackDouble;

		cout << "Добавление в стек значений типа double от 0.5 до 9.5" << endl;
		for (double i = 0.5; i < 10; ++i)
			stackDouble.push(i);

		cout << "Вывод стека" << endl;
		while (!stackDouble.empty())
		{
			std::cout << stackDouble.top() << ' ';
			stackDouble.pop();
		}
		cout << "\nОчистка стека...Стек пуст" << endl;

		cout << "Попытка удалить ещё один элемент из стека.." << endl;
		// исключение т.к. стек уже пуст
		stackDouble.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Stack<string> stackString;

		cout << "Добавление в стек значений типа string от '0' до '9'" << endl;
		for (int i = 0; i < 10; ++i)
		{
			string s = "'" + to_string(i) + "'";
			stackString.push(s);
		}

		cout << "Вывод стека" << endl;
		while (!stackString.empty())
		{
			std::cout << stackString.top() << ' ';
			stackString.pop();
		}
		cout << "\nОчистка стека...Стек пуст" << endl;

		cout << "Попытка удалить ещё один элемент из стека.." << endl;
		// исключение т.к. стек уже пуст
		stackString.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
