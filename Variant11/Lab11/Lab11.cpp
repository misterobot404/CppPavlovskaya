/*
Написать программу, демонстрирующую работу с объектами двух типов, Quadrate и Triangle, для чего создать систему соответствующих классов.
Каждый объект должен иметь идентификатор (в виде произвольной строки символов) и одно или несколько полей для хранения состояния (текущего значения) объекта.
Клиенту (функции main) должны быть доступны следующие основные операции (методы): создать объект, удалить объект, показать значение объекта, Move(), Compare(T&, T&).
Операции по созданию и удалению объектов инкапсулировать в классе Factory.
Предусмотреть меню, позволяющее продемонстрировать заданные операции.
При необходимости в разрабатываемые классы добавляются дополнительные методы (например, конструктор копирования, операция присваивания и т.п.) для обеспечения надлежащего функционирования этих классов.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Демонстрация возможностей классов Quadrate(квадрат) и Triangle(треугольник)" << endl;

	char Control;
	while (true)
	{
		cout << endl << "Интерфейс программы:" << endl;
		cout << "1. Объект Quadrate (квадрат)" << endl;
		cout << "2. Объект Triangle (треугольник)" << endl;
		cout << ">";
		cin >> Control;
		switch (Control)
		{
		case '1':
		{
			FactoryQuadrate factoryQuadrate;
			cout << "Создание квадрата с координатами по умолчанию.." << endl;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nQuadrate (квадрат)" << endl;
				cout << "1. Создать квадрат с новыми координатами" << endl;
				cout << "2. Удалить квадрат" << endl;
				cout << "3. Показать координаты квадрата" << endl;
				cout << "4. Переместить квадрат" << endl;
				cout << "5. Сравнение площадей квадратов" << endl;
				cout << "6. Вернуться к выбору фигуры" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					factoryQuadrate.addObject();
				}
				break;
				case '2':
				{
					factoryQuadrate.deleteObject();
				}
				break;
				case '3':
				{
					factoryQuadrate.quadrate_.Result();
				}
				break;
				case '4':
				{
					factoryQuadrate.quadrate_.Move();
				}
				break;
				case '5':
				{
					factoryQuadrate.quadrate_.Compare();
				}
				break;
				case '6':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		case '2':
		{
			FactoryTriangle factoryPentagon;

			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\Triangle (треугольник)" << endl;
				cout << "1. Создать треугольник с новыми координатами" << endl;
				cout << "2. Удалить треугольник" << endl;
				cout << "3. Показать координаты треугольника" << endl;
				cout << "4. Переместить треугольник" << endl;
				cout << "5. Сравнение площадей треугольноков" << endl;
				cout << "6. Вернуться к выбору фигуры" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					factoryPentagon.addObject();
				}
				break;
				case '2':
				{
					factoryPentagon.deleteObject();
				}
				break;
				case '3':
				{
					factoryPentagon.pentagon_.Result();
				}
				break;
				case '4':
				{
					factoryPentagon.pentagon_.Move();
				}
				break;
				case '5':
				{
					factoryPentagon.pentagon_.Compare();
				}
				break;
				case '6':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		}
	}
	return 0;
}