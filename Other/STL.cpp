/*Задача 1. Выполнить задание 4 с использованием подходящих контейнерных классов и алгоритмов библиотеки.
Содержимое контейнеров (не менее миллиона элементов) формировать с помощью генераторов случайных чисел.
Задание 4. Разработать программу обработки одномерного массива вещественных величин.
Размерность массива задать именованной константой.
Написать программу, в которой можно выполнить следующие пункты:
•	Найти номер минимального элемента массива.
•	Найти сумму элементов массива, расположенных между первым и вторым отрицательными элементами.
•	Преобразовать массив таким образом, чтобы сначала располагались все элементы, модуль которых не превышает 1, а потом — все остальные.*/
#include	<iostream>
#include	<string>
#include	<vector>
#include	<algorithm>
#include	<chrono>
#include	<iterator>
using  namespace  std;

class FourthTask
{
	static const int size = 100000;
	int j = 0;
	double sum = 0, fl = 0, min = 0;
public:
	FourthTask() {
		auto beginT = chrono::high_resolution_clock::now();
		vector <int> vector(size);
		//foreach
		for (auto &i : vector) {
			i = -50 + rand() % 100;
		}
		//самописный цикл через два итератора
		/*for (auto it = begin(vector); it != end(vector); ++it)
		{
		for (auto qt = it; qt != end(vector); ++qt) {
		if (abs(*qt) <= 1) {
		swap(*it, *qt);
		break;
		}
		}
		}*/
		//самописный цикл через find
		for (auto it = begin(vector); it != end(vector); it++)
		{
			auto result = find(it, end(vector), abs(*it) <= 1);
			if (result != vector.end()) swap(*it, *result);
		}
		//Вывод с помощью итератора вывода
		cout << "Преобразованный  массив\n";
		copy(begin(vector), end(vector), ostream_iterator<int>(cout, " "));
		//Нахождение итератора минимального эллемента с помощью алг STL
		cout << "\nMin element " << *min_element(begin(vector), end(vector));

		for (auto i : vector)
		{
			if (fl)
			{
				if (i < 0)
					break;
				sum += i;
			}
			if (i < 0)
				fl = 1;
		}
		cout << "\nСумма  элементов  массива,  расположенных  между  первым  и  вторым  отрицательными элементами=" << sum << endl;

		auto endT = chrono::high_resolution_clock::now();
		cout << "\nПрограмма выполнялась " << chrono::duration_cast<chrono::milliseconds>(endT - beginT).count() << " mili seconds" << endl;
	}
};


/*Задача 2. Замерить время обработки с помощью средств стандартной библиотеки (заголовочный файл <chrono>). Сравнить
полученный результат с результатом работы аналогичных функций (задание 4), полученных при выполнении задания 10.
Задание 10. Для хранения данных о планшетах описать структуру с именем TABLET, содержащую следующие поля: бренд, операционная система, название, разрешение экрана, диагональ экрана, цена, наличие модуля сотовой связи, наличие клавиатуры, оперативная память, встроенная память.
Написать функцию записи в бинарный файл данных о планшете из приведенной структуры. Структура файла: в первых двух байтах размещается количество сделанных в файл записей; далее без пропусков размещаются записи о сканерах.
Написать функцию, извлекающую данные о планшете из файла в структуру, описанного типа на основании определенных характеристик.
Привести пример программы, создающей файл с данными о планшетах (данные вводятся с клавиатуры) и выводящей на экран запрошенные записи.
*/


/*Задача 3. Выполнить задание 7 с использованием подходящих контейнерных классов и алгоритмов библиотеки. Разработать
и продемонстрировать два функциональных объекта (предиката) реализующих различные критерии формирования результата.
Задание 7	Описать структуру с именем AEROFLOT, содержащую следующие поля:
-название пункта назначения рейса;
-номер рейса
-тип самолета
Написать программу, выполняющую следующие действия:
-ввод с клавиатуры данных в массив, состоящий из семи элементов типа AEROFLOT
-записи должны быть размещены в алфавитном порядке по названиям пунктов назначения
-вывод на экран пунктов назначения и номеров рейсов, обслуживаемых самолетом, тип которого введен с клавиатуры
-если таких рейсов нет, выдать на дисплей соответствующее сообщение*/

class SeventhTask
{
	struct AEROFLOT
	{
		string namereice;
		int №somoleta;
		string tipsomoleta;
	};
public:
	SeventhTask() {
		cout << " AEROFLOT\nСколько элементов типа AEROFLOT будет в базе? ";
		int T;
		cin >> T;
		databaseСreation(T);
		task(T);
	}
	vector <AEROFLOT> DateBase;
	AEROFLOT AirStruct;
	void databaseСreation(int count) {
		for (; count != 0; count--)
		{
			cout << "Введите пункт назначения ";
			cin >> AirStruct.namereice;
			cout << "Введите тип самолета ";
			cin >> AirStruct.tipsomoleta;
			cout << "Введите номер самолета ";
			cin >> AirStruct.№somoleta;
			DateBase.push_back(AirStruct);
			cout << "\n";
		}
	};
	int task(int count) {
		while (true)
		{
			cout << "\n  Available tasks\n1 Список пунктов назначения рейсов отсортирован по алфавиту\n2 Список структур отсортированный по номерам рейсов\n3 Поиск по типу самолёта\n";
			cout << "\nEnter the job number, or -1 to exit ";
			int T;
			cin >> T;
			cout << "\n";
			switch (T)
			{
			case 1: {
				sort(DateBase.begin(), DateBase.end(), [](const AEROFLOT& lhs, const AEROFLOT& rhs) {
					return (lhs.namereice < rhs.namereice);
				});
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					cout << "\nПункт назначения > " << it->namereice << "\nТип самолёта > " << it->tipsomoleta << "\nНомер рейса > " << it->№somoleta;
				}
				break;
			}
			case 2: {
				sort(DateBase.begin(), DateBase.end(), [](const AEROFLOT& lhs, const AEROFLOT& rhs) {
					return (lhs.№somoleta < rhs.№somoleta);
				});
				cout << "\nСписок структур отсортированный по номерам рейсов:\n";
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					cout << "\nПункт назначения > " << it->namereice << "\nТип самолёта > " << it->tipsomoleta << "\nНомер рейса > " << it->№somoleta;
				}
				break;
			}
			case 3: {
				cout << "\n\nВведите тип самолёта ";
				string typeaircraft;
				cin >> typeaircraft;
				bool ret = false;
				for (auto it = DateBase.begin(); it != DateBase.end(); ++it)
				{
					if (it->tipsomoleta == typeaircraft)
					{
						cout << "\nПункт назначения " << it->namereice;
						cout << "\nНомер рейса " << it->№somoleta << "\n";
						ret = true;
					}
				}
				if (!ret) printf("Таких рейсов нет");
				break;
			}
			case -1: return 1;
			default:
				break;
			}
		}
	}
};

int  main()
{
	setlocale(LC_ALL, "rus");
	cout << "\n  Available tasks\n4 Операции с одномерным массивом\n0 Замер времени обработки функций\n7 Структура AEROFLOT\n";
	cout << "\nEnter the job number ";
	int T;
	cin >> T;
	cout << "\n";
	switch (T)
	{
	case 4:
	{
		FourthTask My4;
		cout << endl;
		system("pause");
		break;
	}
	case 0:
	{
		break;
	}
	case 7:
	{
		SeventhTask My7;
		cout << endl;
		system("pause");
		break;
	}
	default:
		break;
	}
}