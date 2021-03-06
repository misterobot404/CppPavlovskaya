/*Наследование.cpp :
Описать базовый класс СТРОКА
Обязательные поля класса :
• указатель на char — хранит адрес динамически выделенной памяти для размещения
символов строки;
• значение типа int — хранит длину строки в байтах.
Обязательные методы :
• конструктор без параметров;
• конструктор, принимающий в качестве параметра С - строку(заканчивается пулевым байтом);
• конструктор, принимающий в качестве параметра символ;
• конструктор копирования;
• получение длины строки;
• очистка строки(сделать строку пустой);
• деструктор.
Описать производный от СТРОКА класс СТРОКА__ИДЕНТИФИКАТОР.
Строки данного класса строятся по правилам записи идентификаторов в языке С
и могут включать в себя только те символы, которые могут входить в состав
С - идентификаторов.Если исходные данные противоречат правилам записи идентификатора, то создается пустая СТРОКА_ИДЕНТИФИКАТОР.
Обязательные методы :
• конструктор без параметров;
• конструктор, принимающий в качестве параметра С - строку(заканчивается
нулевым байтом);
• конструктор, принимающий в качестве параметра символ;
• конструктор копирования;
• перевод всех символов строки в верхний регистр;
• перевод всех символов строки в нижний регистр;
• поиск первого вхождения символа в строку;
• деструктор.
Переопределить следующие операции:
• присваивание (=);
• сложение (+) — операция конкатенации строк;
• вычитание (-) — из строки (первый операнд) удаляются все символы, входя­
щие в строку — второй операнд, при этом может получиться пустая строка;
• операция (<) — проверка на больше. Строка считается больше другой, если
код символа первой строки в г-й позиции (г изменяется от О до гг-1, где п —
длина более короткой строки) больше кода символа в той же позиции во вто­
рой строке, длины строк могут не совпадать.
• операция (<) — проверка на меньше. Строка считается меньше другой, если
код символа первой строки в г-й позиции (z изменяется от О до w-1, где п —
длина более короткой строки) меньше кода символа в той же позиции во вто­
рой строке, длины строк могут не совпадать. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>

using namespace std;

class String
{
public:
	String();
	String(const char *str);
	String(char ch);
	String( String &T);
	~String();
	String &operator=(const String &operand2);
	String &operator+(const String &operand2);
	String &operator-(const String &operand2);
	String &operator<(const String &operand2);
	String &operator>(const String &operand2);
	void Size(const char* str) //получение длины строки;
	{
		cout << "Длина строки " << strlen(str) << endl;
	}
	void Clear(const char* str) //очистка строки(сделать строку пустой);
	{
		memset((void*)str, NULL, n);
		cout << endl << "очистка строки obj2  " << str << endl;
	}
	void show_str() {cout << "s = " << s; cin.get();}

	protected:
	char *s; //указатель на char — хранит адрес динамически выделенной памяти для размещения символов строки;
	int n; //значение типа int — хранит длину строки в байтах.
};

String::String() //конструктор без параметров
{
	s = 0;
	n = 0;
	cout << endl << "Тут срабатывает конструктор без параметров" << endl;
	cin.get();
}

String::String(const char *str) //конструктор, принимающий в качестве параметра С - строку(заканчивается нулевым байтом)
{

	cout << endl << "Тут срабатывает конструктор, принимающий в качестве параметра С - строку(заканчивается нулевым байтом)"<< endl;
	cout << "Строка " << str << endl;
	n = strlen(str);
	s = new char[n + 1];		// +1
	strcpy(s, str);
	cin.get();
}

String::String(char ch)	//конструктор, принимающий в качестве параметра символ
{
	cout << endl << endl << "Тут срабатывает конструктор, принимающий в качестве параметра символ" << endl;
	cout << "Symbol " << ch << endl;
	s = new char[2];
	s[0] = ch;
	s[1] = '\0';
	n = 1;
	cin.get();
}

String::String( String &T) //конструктор копирования
{
	cout << "Тут срабатывает конструктор копирования" << endl;
	n = T.n;
	s = new char[n + 1];
	strcpy(s, T.s);
	cout << "s =" << s << endl;
	cin.get();
}

String::~String() //деструктор
{
	cout << "Destructor";
	//delete[] s;
	cin.get();
}
 
String &String:: operator= (const String &operand2)
{
	cout << "\nТут сработало присваивание";
	n = operand2.n;
	s = new char[n + 1];
	strcpy(s, operand2.s);
	cin.get();
	return *this;
}

String &String:: operator+ (const String &operand2)
{
	cout << "\nТут сработало сложение строк\n";
	n = n + operand2.n;
	String ju(s);
	s = new char(n+1);  //////////////////??????????????????????????????????????????????
	//cout << "Длина строки" << testsum.n << endl;
	int uiu(0);
	for (int i(0); ju.s[i] != '\0'; uiu++,i++)
	{
		s[uiu] = ju.s[i];
	}
	for (int i(0);  operand2.s[i] != '\0'; uiu++,i++)
	{
		s[uiu] = operand2.s[i];
	}
	s[uiu] = '\0';
	cout << "Строка " << s << endl;
	//strcat(testsum.s, s);
	//strcat(testsum.s, operand2.s);
	return *this;
}

String &String:: operator- (const String &operand2)
{
	cout << "\nТут сработало вычитание строк\n";
	int k, i, j;
	cout << "Из строки " << s << " удалились символы строки " << operand2.s;
	cout << endl;
	for (k = 0; operand2.s[k] != '\0'; k++) 
	{
		for (i = j = 0; s[i] != '\0'; i++)
			if (s[i] != operand2.s[k])
				s[j++] = s[i];
		s[j] = '\0';
	}
	n = strlen(s);
	cin.get();
	return *this;
}

String &String:: operator> (const String &operand2)
{
	cout << "\nТут сработало сравнение строк строк\n";
	int k = strcmp(s, operand2.s);
	if (k > 0) { cout << "Истина\n";}
	else cout << "Ложь\n";
	return *this;
}

String &String:: operator< (const String &operand2)
{
	cout << "\nТут сработало сравнение строк строк\n";
	int k = strcmp(s, operand2.s);
	if (k < 0) { cout << "Истина\n"; }
	else cout << "Ложь\n";
	cin.get();
	return *this;
}

class StringID : public String   // производный класс
{
public:
	StringID() :String() {};
	StringID(const char *str) : String(str) {};
	StringID(char ch) : String(ch) {};
	StringID( String &T) : String(T) {};
	void Detectedsymbol(const char *str)
	{
		char i;
		cout << "Введите символ, который нужно найти ";
		cin >> i;
		for (int g = 0; g != n; g++)
		{
			if (str[g] == i)
			{
				cout << " Моя прелесть находится в " << g;
				break;
			}
			cout << g;
		}
	}
	void UpReg(const char *str)
	{
		{
			cout << endl;
			for (int i = 0; i != n; i++)
			{
				cout << (char)toupper(str[i]);
			}
			cout << endl;
		}
	}
	void DownReg(const char *str)
	{
		cout << endl;
		for (int i = 0; i != n; i++)
		{
			cout << (char)tolower(str[i]);
		}
		cout << endl;
	}
	~StringID() {};
};

int main()
{
	setlocale(LC_ALL, "rus");
	const char str[] = "5rqwe";
	char symbol = 'r';
	String obj1;
	String obj2(str);
	String obj3(symbol);
	String copy(obj2);
	obj2.Size(str);
	obj2.Clear(str);
	obj2.Size(str);
	cout << endl;
	const char s1[] = "QQti";
	StringID obj4(s1);
	obj4.DownReg(s1);
	obj4.UpReg(s1);
	obj4.Detectedsymbol(s1);
	obj4.Clear(s1);
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	//перегрузка
	//////////////////////////////• присваивание (=);
	String test1("4t");
	String test2("double");
	test2 = test1;
	test2.show_str();
	////////////////////////////// сложение(+) — операция конкатенации строк;
	String str6 = test1 + test2;
	str6.show_str();
	//////////////////////////////вычитание (-) — из строки (первый операнд) удаляются все символы, входя­щие в строку — второй операнд, при этом может получиться пустая строка;
	String test3("1115544");
	String test4("224488567345");
	String str7 = test3 - test4;
	str7.show_str();
	/////////////////////////Сравнение
	test3 > test4;
	test3 < test4;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cin.get();
	return 0;
}
