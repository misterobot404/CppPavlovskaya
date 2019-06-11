/*
Требуется создать шаблон некоторого целевого класса Queue.
В каждом варианте уточняются требования к реализации — указанием на применение некоторого серверного класса std::list.
Это означает, что объект класса std::list используется как элемент класса Queue.
Во всех вариантах показать в клиенте main использование созданного класса, включая ситуации, приводящие к генерации исключений.
Показать инстанцирование шаблона для типов int, double, std::string.
*/
#include "Queue.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Queue абстрактный тип данных с дисциплиной доступа к элементам «первый пришёл — первый вышел»." << endl;
	cout << "Добавление элемента возможно лишь в конец очереди, выборка — только из начала очереди." << endl << endl;
	cout << "Демонстрация целевого шаблонного класса Queue с разными типами данных" << endl << endl;

	try
	{
		// для int(для всего остального делается аналогично)
		Queue<int> queueInt;

		cout << "Добавление в очередь значений типа int от 1 до 5" << endl;
		for (int i = 1; i < 6; ++i)
			queueInt.push_back(i);

		cout << "Вывод очереди: ";
		queueInt.show();

		cout << "Добавление в очередь значения 1" << endl;
		queueInt.push_back(1);

		cout << "Первый элемент очереди: " << queueInt.front() << endl;
		cout << "Последний элемент очереди: " << queueInt.back() << endl;

		cout << "Освобождение очереди" << endl;
		while (!queueInt.empty())
		{		
			cout << "Освобождаемый элемент: " << queueInt.front() << endl;
			queueInt.pop_front();
		}

		cout << "Попытка удалить ещё один элемент из очереди.." << endl;
		// исключение т.к. стек уже пуст
		queueInt.pop_front();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Queue<double> queueDouble;

		cout << "Добавление в очередь значений типа double от 1.5 до 5.5" << endl;
		for (double i = 1.5; i < 6; ++i)
			queueDouble.push_back(i);

		cout << "Вывод очереди: ";
		queueDouble.show();

		cout << "Добавление в очередь значения 1.5" << endl;
		queueDouble.push_back(1.5);

		cout << "Первый элемент очереди: " << queueDouble.front() << endl;
		cout << "Последний элемент очереди: " << queueDouble.back() << endl;

		cout << "Освобождение очереди" << endl;
		while (!queueDouble.empty())
		{
			cout << "Освобождаемый элемент: " << queueDouble.front() << endl;
			queueDouble.pop_front();
		}

		cout << "Попытка удалить ещё один элемент из очереди.." << endl;
		queueDouble.pop_front();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Queue<string> queueString;

		cout << "Добавление в очередь значений типа string от Hello1 до Hello5" << endl;
		for (int i = 1; i < 6; ++i)
		{
			string str = "Hello" + to_string(i);
			queueString.push_back(str);
		}

		cout << "Вывод очереди: ";
		queueString.show();

		cout << "Добавление в очередь значение Hello1" << endl;
		queueString.push_back("Hello1");

		cout << "Первый элемент очереди: " << queueString.front() << endl;
		cout << "Последний элемент очереди: " << queueString.back() << endl;

		cout << "Освобождение очереди" << endl;
		while (!queueString.empty())
		{
			cout << "Освобождаемый элемент: " << queueString.front() << endl;
			queueString.pop_front();
		}

		cout << "Попытка удалить ещё один элемент из очереди.." << endl;
		queueString.pop_front();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
