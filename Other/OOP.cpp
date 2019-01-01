/*Задача 1. Выполнить задания 1, 2, 3 реализовав для каждого из заданий отдельный класс.
Для ввода и вывода данных в каждом из классов перегрузить операторы ввода из потока и вывода в поток*/
#include	<iostream>
#include	<fstream> 
#include	<string>
#include	<vector>
#include	"iomanip"
using  namespace  std;

//Написать программу расчета по двум формулам, результат должен совпадать
class FirstTask
{
private:
	double a;
public:
	FirstTask() {
		a = 5;
	}
	virtual void set(int ac) {
		a = ac;
	}
	virtual void set() {
		cin >> a;
	}
	double ONE() {
		return (sin(2 * a) + sin(5 * a) - sin(3 * a)) / (cos(a) + 1 - 2 * (pow(sin(2 * a), 2)));
	}
	double TWO() {
		return 2 * sin(a);
	}
	friend ostream & operator <<(ostream & out, FirstTask & ac);
};
ostream & operator <<(ostream & out, FirstTask & ac)
{
	out << "a = " << ac.a << "\n";
	out << ac.ONE();
	out << endl;
	out << ac.TWO();
	return out;
}

/*Написать программу, определяющую попадание точки с определенными координатами в заданную плоскую область.
Значения координат вводить с клавиатуры. Результат работы программы вывести в виде текстового сообщения*/
class SecondTask
{
private:
	float x, y;
public:
	SecondTask() {
		x = 4;
		y = 3;
	}
	virtual void Set() {
		cin >> x;
		cin >> y;
	}
	virtual void Set(double first, double second) {
		x = first;
		y = second;
	}
	friend ostream & operator <<(ostream & out, SecondTask & ac);
};
ostream & operator <<(ostream & out, SecondTask & ac) {
	if (((ac.x <= 0 && ac.x >= -6 && ac.y >= 4) || (ac.x <= 6 && ac.y >= 0)) || ((ac.x*ac.x + ac.y * ac.y) <= 16 && ac.x >= 0 && ac.x <= 4 && ac.y >= 0 && ac.y <= 4))
		cout << "\npoint in the field\n";
	else cout << "\npoint outside the field\n";
	return out;
}

/*Вычислить и вывести на экран в виде таблицы значения функции, заданной с помощью ряда Тейлора,
на интервале от xнач до xкон с шагом dx с точностью ε Таблицу снабдить заголовком и шапкой.
Каждая строка должна содержать значение аргумента, значение функции и количество просуммированных членов ряда*/
class ThirdTask
{
private:
	const int Iter = 1000;
	double ch, yn, y, x1, x2, dx, eps;
public:
	ThirdTask() {
		cout << "Введите Xнач ";
		cin >> x1;
		cout << "Введите Xкон ";
		cin >> x2;
		cout << "Введите шаг изменения dx ";
		cin >> dx;
		cout << "Введите точность e ";
		cin >> eps;
	}
	void Main(){
		cout << "Значение аргумента |" << setw(20) << left << "Значение функции |" <<
			setw(40) << "Кол-во" << endl;
		int b;
		for (double x = x1; x <= x2; x += dx)
		{
			b = 0;
			yn = ch = 0;
			y = 1 - (x * x * x) / 3;
			for (int n = 1; n <= Iter; n++)
			{
				ch = -(x * x) / ((n << 1 + 2) * (n << 1 + 1));
				yn = ch + y;
				if (fabs(ch) < eps)
					break;
				y = yn;
				b++;
			}
			printf(x, yn, b);
		}
		cout << "\n";
	}
	inline void printf(double x, double yn, int b) {
		cout << setw(21) << left << x << setw(20) << left << yn << b << endl;
	}

};

/*Задача 2	Выполнить задание 10 с использованием файловых потоков и методов обработки ошибок.
Задание 10	Для хранения данных о планшетах описать структуру с именем TABLET, содержащую следующие поля: бренд, операционная система,
название, разрешение экрана, диагональ экрана, цена, наличие модуля сотовой связи, наличие клавиатуры, оперативная память, встроенная память.
Написать функцию записи в бинарный файл данных о планшете из приведенной структуры. Структура файла: в первых двух байтах размещается количество
сделанных в файл записей; далее без пропусков размещаются записи о сканерах.
Написать функцию, извлекающую данные о планшете из файла в структуру, описанного типа на основании определенных характеристик.
Привести пример программы, создающей файл с данными о планшетах (данные вводятся с клавиатуры) и выводящей на экран запрошенные записи.
Вариант 1
•	вывести записи о планшетах определенного бренда;
•	вывести записи о планшетах не превышающих заданной цены.*/
class TenthTask
{
private:
	struct TABLET
	{
		char brand[10];
		char OS[10];
		char name[10];
		int ekran_x;
		int ekran_y;
		int diagonal;
		int price;
		char svyaz[5];
		char klava[5];
		int oppam;
		int pam;
	};
	vector <TABLET> vector;
	short size;
	string way;
public:
	TenthTask()
	{
		cout << "Enter path to the file, or -1 for create her ";
		cin >> way;
		if (way == "-1") {
			cout << "Введите количество планшетов: ";
			cin >> size;
			vector.resize(size);
			StructInput();
			RecordingToFile();
			ExtractingDataFromFile(way);
			Interface();
		}
		else
		{
			ExtractingDataFromFile(way);
			Interface();
		}
	}

	void StructInput() {
		cout << "ВВОД ДАННЫХ О ПЛАНШЕТАХ\n";
		for (auto &it : vector) cin >> it;
	}

	void RecordingToFile(){
		cout << "Enter name file ";
		cin >> way;
		cout << "ЗАПИСЫВАЕМ ДАННЫЕ В ФАЙЛ...\n";
		ofstream input(way, ios::binary);
		input.write((char*)&size, sizeof(size));
		for (int i = 0; i < size; i++)	input.write((char*)&vector[i], sizeof(vector[i]));
		input.close();
	}

	void ExtractingDataFromFile(string way) {
		ifstream output(way, ios::binary);
		output.read((char*)&size, sizeof(size));
		vector.resize(size);
		for (int i = 0; i < size; i++)	output.read((char*)&vector[i], sizeof(vector[i]));
		output.close();
	}

	void Interface(){
		while (true)
		{
			cout << "\nВ базе данные из файла " << way << endl;
			cout << "Кол-во планшетов " << size << endl;
			cout << "\tMENU\n1 Вывод всех планшетов из файла\n2 Вывести записи о планшетах определенного бренда\n3 Вывести записи о планшетах не превышающих заданной цены\n4 Извлеч базу планшетов из другого файа\n5 Создать новую базу\nEnter number(-1 for exit) ";
			int T;
			cin >> T;
			switch (T)
			{
			case 1: {
				for (auto it : vector)	cout << it;
				break;
			}
			case 2: {
				cout << "Введите бренд ";
				char a[10];
				cin >> a;
				for (auto it : vector)	if (strcmp(it.brand, a) == 0) cout << it;
				break;
			}
			case 3: {
				cout << "Введите цену ";
				int a;
				cin >> a;
				for (auto it : vector)	if (it.price >= a) cout << it;
				break;
			}
			case 4: {
				cout << "Enter path to the file ";
				cin >> way;
				ExtractingDataFromFile(way); 
				break;
			}
			case 5: {
				cout << "Введите количество планшетов: ";
				cin >> size;
				vector.resize(size);
				StructInput();
				RecordingToFile();
				break;
			}
			case -1: exit(-1);
			default:
				break;
			}
		}
	}

	friend istream & operator >>(istream & in, TenthTask::TABLET & vector);
	friend ostream & operator <<(ostream & in, TenthTask::TABLET & vector);
};
istream & operator >>(istream & in, TenthTask::TABLET & vector) {

	cout << "Введите название бренда: ";
	cin >> vector.brand;
	cout << "Введите имя операционной системы: ";
	cin >> vector.OS;
	cout << "Введите название планшета: ";
	cin >> vector.name;
GOTO:
	cout << "Введите разрешение экрана: ";
	try
	{
		if (!(cin >> vector.ekran_x) || (cin.peek() != '\n'))
		{
			throw 1;
		}
	}
	catch (int error)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Input error! Retry input" << endl;
		goto GOTO;
	}
	cin >> vector.ekran_y;
	cout << "Введите диагональ устройства: ";
	cin >> vector.diagonal;
	cout << "Введите цену устройства: ";
	cin >> vector.price;
	cout << "Наличие модуля связи (Есть/Нету): ";
	cin >> vector.svyaz;
	cout << "Наличие клавиатуры (Есть/Нету): ";
	cin >> vector.klava;
	cout << "Введите количество оперативной памяти: ";
	cin >> vector.oppam;
	cout << "Введите количество встроенной памяти: ";
	cin >> vector.pam;
	cout << "\n";
	return in;
}
ostream & operator <<(ostream & out, TenthTask::TABLET & vector) {
	cout << "\nНазвание бренда: " << vector.brand << "\n";
	cout << "Имя операционной системы: " << vector.OS << "\n";
	cout << "Название планшета: " << vector.name << "\n";
	cout << "Разрешение экрана: " << vector.ekran_x << "x" << vector.ekran_y << "\n";
	cout << "Диагональ устройства: " << vector.diagonal << "\n";
	cout << "Цена устройства: " << vector.price << "\n";
	cout << "Наличие модуля связи (Есть/Нету): " << vector.svyaz << "\n";
	cout << "Наличие клавиатуры (Есть/Нету): " << vector.klava << "\n";
	cout << "Количество оперативной памяти: " << vector.oppam << "\n";
	cout << "Количество встроенной памяти: " << vector.pam << "\n\n";
	return out;
}

int  main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		cout << "\n  Available tasks\n1 Расчет по двум формулам\n2 Попадание точки в область\n3 Вычисление значения функции, заданной с помощью ряда Тейлора\n10 Запись в бинарный файл и считывание с него";
		cout << "\nEnter the job number, or -1 to exit ";
		int T;
		cin >> T;
		switch (T)
		{
		case 1:
		{
			FirstTask My1;
			My1.set(20);
			cout << My1;
			break;
		}
		case 2:
		{
			SecondTask My2;
			cout << "Enter x and y\n";
			My2.Set();
			cout << My2;
			break;
		}
		case 3:
		{
			ThirdTask My3;
			My3.Main();
			break;
		}
		case 10:
		{
			cout << endl;
			TenthTask My10;
			break;
		}
		case -1:
			return 0;
		default:
			break;
		}
	}
}