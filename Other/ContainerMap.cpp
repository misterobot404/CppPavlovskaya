/*
4 Вариант.
Написать программу моделирования работы автобусного парка.
Сведения о каждом автобусе содержат: номер автобуса, фамилию и инициалы водителя, номер маршрута.
Следует обеспечить выбор с помощью меню и выполнение следующих функций:
-начальное формирование данных о всех автобусах в парке в виде списка (ввод с клавиатуры или из файла);
-имитация выезда автобуса из парка:
1) вводится номер автобуса;
2) программа удаляет   данные об этом автобусе из списка автобусов, находящихся в парке, и записывает эти данные в список автобусов, находящихся на маршруте;
-имитация въезда автобуса в парк:
1) вводится номер автобуса;
2) программа удаляет   данные об этом автобусе из списка автобусов, находящихся на маршруте, и записывает эти данные в список автобусов, находящихся в парке;
-вывод сведений об автобусах, находящихся в парке, и об автобусах, находящихся   на маршруте.
Хранение данных организовать с помощью класса map.
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Access
{
	struct Bus
	{
		string name;
		size_t num;
	};
public:
	typedef map<size_t, Bus> Array;
	typedef map<size_t, Bus>::iterator Iter;
	Array array;         // массив автобусов map<Bus>
	string name;        // слово - маршрут, или парк
	Access(string str) : name(str) {};
	void ReadConsole(size_t size = 1);              // процедура чтения с консоли данных об автобусах
	friend ostream & operator <<(ostream & out, Access & ac); // вывод всех авто. в поток ( консоль )
	bool Remove(Access & ac, size_t key);         // перемещение автобусов из массива в другой массив
};

void Access::ReadConsole(size_t size)// процедура чтения с консоли данных об автобусах
{

	if (size == 0) return;
	Bus bus;
	cout << "Введите данные об автобусах которые будут находиться " << name << "\n";
	for (; size != 0; size--)
	{
		cout << "\nНомер маршрута  ";
		cin >> bus.num;
		cout << "Фамилию и инициалы водителя  ";
		cin.ignore();
		getline(cin, bus.name);
		cout << "Номер автобуса  ";
		size_t num;
		cin >> num;
		array.insert(make_pair(num, bus)); // дабавление автобуса в массив
	}
}
ostream & operator <<(ostream & out, Access & ac)// вывод всех авто. в поток ( консоль )
{
	if (ac.array.empty())
		cout << "\nАвтобусов в " << ac.name << " нет ни одного\n\n";
	else
	{
		cout << "\nАвтобусы в " << ac.name << ":\n\n";
		for (Access::Iter ptr = ac.array.begin(); ptr != ac.array.end(); ++ptr)
		{
			cout << "Номер маршрута > ";
			cout << ptr->second.num << "\n";
			cout << "Фамилию и инициалы водителя > ";
			cout << ptr->second.name << "\n";
			cout << "Номер автобуса > ";
			cout << ptr->first << "\n\n";
		}
	}
	return out;
}
bool Access::Remove(Access & ac, size_t key)//перемещение автобусов из массива в другой массив
{
	Iter ptr = array.find(key); // поиск номера автобуса 
	if (ptr == array.end()) return false; // если не нашли такого номера возвращаем 0
	ac.array.insert(make_pair(ptr->first, ptr->second));
	array.erase(ptr);
	return true;
}

int main()
{
	setlocale(0, "Rus");
	size_t nomer;
	Access BusPark("в автобусном парке: ");
	Access Route("на маршруте: ");
	bool f=0;
	while (f != 1)
	{
		cout << "1. начальное формирование данных\n";
		cout << "2. выезд автобуса из парка\n";
		cout << "3. въезд автобуса в парк\n";
		cout << "4. вывод сведений об автобусах, находящихся в парке и об автобусах, находящихся на маршруте\n";
		cout << "5. выход\n";
		int c;
		cin >> c;
		switch (c)
		{
		case 1:
		{
			BusPark.ReadConsole(2);
			cout << "\n\n_____________________________________________\n";
			break;
		}
		case 2:
		{
			cout << "Введите номер автобуса ";
			cin >> nomer;
			if (BusPark.Remove(Route, nomer))
				cout << "\n\n\nВыводим автобус "<< nomer <<" в маршрут\n\n";
			else  cout << "\n\n\nАвтобуса с номером " << nomer << " нет в авто-парке\n\n";
			break;
		}
		case 3:
		{
			cout << "Введите номер автобуса ";
			cin >> nomer;
			cout << "\n\n\nВозвращаем " << nomer << "  в парк, если такой был...\n\n";
			Route.Remove(BusPark, nomer);
			cout << BusPark;
			cout << Route;
			break;
		}
		case 4:
		{
			cout << BusPark; // какие автобусы в автобусном парке 
			cout << Route; // какие на маршруте 
			cout << "\n\n_____________________________________________\n";
			break;
		}
		case 5:
		{
			f = 1; break;
		}
		default:cout << "Не верный ввод! Попробуйте еще раз.\n";
		}
	}
	return 0;
}