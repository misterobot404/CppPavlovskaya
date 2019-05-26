/*
Требуется создать шаблон некоторого целевого класса Deque.
В каждом варианте уточняются требования к реализации — указанием на применение некоторого серверного класса Vect.
Это означает, что объект класса Vect используется как элемент класса Deque.
В качестве серверного класса может быть указан либо класс, созданный программистом в рамках того же задания, либо класс стандартной библиотеки.
Deque - Двусторонняя очередь (допускает вставку и удаление из обоих концов);
*/
#include "Deque.h"
#include "string"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Deque - Двусторонняя очередь(допускает вставку и удаление из обоих концов)" << endl;
	cout << "Демонстрация интерфейса целевого шаблонного класса Deque, основанном на \n" 
		<< "применении серверного класса Vect, со значениями разных типов" << endl << endl;
	try
	{
		Deque<int> dequeInt;

		cout << "Добавление значений типа int от 0 до 1 в список" << endl;

		for (int i = 0; i < 2; ++i)
			dequeInt.push_back(i);
		dequeInt.show();

		cout << "Добавление значений типа int от 0 до 1 в начало списка" << endl;
		for (int i = 0; i < 2; ++i)
			dequeInt.push_begin(dequeInt.begin(),i);
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала очереди" << endl;
		dequeInt.pop_begin();
		dequeInt.show();

		cout << endl << endl;
	}
	catch (underflow_error& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		Deque<double> dequeInt;

		cout << "Добавление значений типа double от 0.5 до 1.5 в список" << endl;

		for (double i = 0.5; i < 2.5; ++i)
			dequeInt.push_back(i);
		dequeInt.show();

		cout << "Добавление значений типа double от 0.5 до 1.5 в начало списка" << endl;
		for (int i = 0.5; i < 2.5; ++i)
			dequeInt.push_begin(dequeInt.begin(), i);
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала очереди" << endl;
		dequeInt.pop_begin();
		dequeInt.show();
	}
	catch (underflow_error& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		Deque<string> dequeInt;

		cout << "Добавление значений типа string от '0' до '1' в список" << endl;

		for (int i = 0; i < 2; ++i)
			dequeInt.push_back("'" + to_string(i) + "'");
		dequeInt.show();

		cout << "Добавление значений типа string от '0' до '1' в начало списка" << endl;
		for (int i = 0; i < 2; ++i)
			dequeInt.push_begin(dequeInt.begin(), "'" + to_string(i) + "'");
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала и конца очереди" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "Удаление одного элемента с начала очереди" << endl;
		dequeInt.pop_begin();
		dequeInt.show();

		cout << endl << endl;
	}
	catch (underflow_error& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
