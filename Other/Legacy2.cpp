/*Наследование.cpp :
Описать базовый класс СТРОКА. Обязательные поля класса: 
• указатель на char — хранит адрес динамически выделенной памяти для размещения символов строки; 
• значение типа int — хранит длину строки в байтах. 
Обязательные методы: 
• конструктор без параметров; 
• конструктор, принимающий в качестве параметра С-строку (заканчивается нулевым байтом); 
• конструктор, принимающий в качестве параметра символ; 
• конструктор копирования; 
• получение длины строки;
• очистка строки (сделать строку пустой); 
• деструктор. 
Описать производный от СТРОКА класс БИТОВАЯ__СТРОКА. Строки данного класса могут содержать только символы 'О' или '1'. 
Если в составе инициализирующей строки будут встречены любые символы, отличные от допустимых, БИТОВАЯ_СТРОКА принимает нулевое значение. 
Содержимое данпых строк рассматривается как двоичное число.
Обязательные методы: 
• конструктор без параметров; 
• конструктор, принимающий в качестве параметра С-строку (заканчивается нулевым байтом); а конструктор копирования; 
• деструктор; 
Переопределить следующие операции (длина строки результата равна длине большей из строк;
в случае необходимости более короткая битовая строка расширяется влево знаковым разрядом): 
• присваивание (=);
• сложение (+) — арифметическая сумма строк; 
• операция (==) — проверка на равенство. 
Разработчик вправе вводить любое (с обоснованием необходимости) число дополнительных полей и методов. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
public:
	String();
	String( char *str);
	String(char ch);
	String(String &T);
	~String();
	String &operator=(const String &operand2);
	String &operator== (const String &operand2);

	void Size(const char* str) //получение длины строки;
	{
		cout << "Длина строки " << strlen(str) << endl;
	}
	void Clear(const char* str) //очистка строки(сделать строку пустой);
	{
		memset((void*)str, NULL, n);
		cout << endl << "очистка строки obj2  " << str << endl;

	}
	void show_str() { cout << "s = " << s; cin.get(); }

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

String::String( char *str) //конструктор, принимающий в качестве параметра С - строку(заканчивается нулевым байтом)
{

	cout << endl << "Тут срабатывает конструктор, принимающий в качестве параметра С - строку(заканчивается нулевым байтом)" << endl;
	cout << "Строка " << str << endl;
	n = strlen(str);
	s = new char[n + 1];		// +1
	strcpy(s, str);
	cout << "s =" << s << endl;
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
	cout << "s =" << s << endl;
	cin.get();
}

String::String(String &T) //конструктор копирования
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
	delete[] s;
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
String &String:: operator== (const String &operand2)
{
	cout << "\nТут сработало сравнение";
	int k = strcmp(s, operand2.s);
	if (k == 0) { cout << "/nБитовые строки равны\n"; }
	else cout << "/nБитовые строки не равны\n";
	cin.get();
	return *this;
}

class StringID : public String   // производный класс
{
public:
	StringID() : String() {};
	StringID( char *str) : String(str) 
	{
		cout << "Проверка битовой строки\n";
		for (int i(0); str[i] != '\0'; i++)
		{
			if((str[i]=='0')||(str[i] == '1'))
			{
			}
			else 
			{
				cout << "STROKA NE BITAVA\n";
				memset(s, NULL,n);
				cout << s;
				break;
			}
			if (i==(n-1)) { cout << "STROKA BITAVA\n"; }
		}
	};
	StringID(String &T) : String(T) {};
};


int main()
{
	setlocale(LC_ALL, "rus");
	char str[] = "5rqwe";
	char symbol = 'r';
	String obj1;
	String obj2(str);
	String obj3(symbol);
	String copy(obj2);
	obj2.Size(str);
	obj2.Clear(str);
	obj2.Size(str);
	cout << endl;
	////дочерний класс
	cout << "DOCHERNI CLASS\n";
	char str2[] = "1100";
	StringID obj4;
	StringID o1(str2);
	o1.show_str();
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	//перегрузка
	////////////////////////присваивание (=)
	StringID test1("4t");
	StringID test2("double");
	test2 = test1;
	test2.show_str();
	////////////////////////Сравнение (==)
	test2 == test1;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cin.get();
	return 0;
}

