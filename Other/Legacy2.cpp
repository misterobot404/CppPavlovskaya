/*������������.cpp :
������� ������� ����� ������. ������������ ���� ������: 
� ��������� �� char � ������ ����� ����������� ���������� ������ ��� ���������� �������� ������; 
� �������� ���� int � ������ ����� ������ � ������. 
������������ ������: 
� ����������� ��� ����������; 
� �����������, ����������� � �������� ��������� �-������ (������������� ������� ������); 
� �����������, ����������� � �������� ��������� ������; 
� ����������� �����������; 
� ��������� ����� ������;
� ������� ������ (������� ������ ������); 
� ����������. 
������� ����������� �� ������ ����� �������__������. ������ ������� ������ ����� ��������� ������ ������� '�' ��� '1'. 
���� � ������� ���������������� ������ ����� ��������� ����� �������, �������� �� ����������, �������_������ ��������� ������� ��������. 
���������� ������ ����� ��������������� ��� �������� �����.
������������ ������: 
� ����������� ��� ����������; 
� �����������, ����������� � �������� ��������� �-������ (������������� ������� ������); � ����������� �����������; 
� ����������; 
�������������� ��������� �������� (����� ������ ���������� ����� ����� ������� �� �����;
� ������ ������������� ����� �������� ������� ������ ����������� ����� �������� ��������): 
� ������������ (=);
� �������� (+) � �������������� ����� �����; 
� �������� (==) � �������� �� ���������. 
����������� ������ ������� ����� (� ������������ �������������) ����� �������������� ����� � �������. 
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

	void Size(const char* str) //��������� ����� ������;
	{
		cout << "����� ������ " << strlen(str) << endl;
	}
	void Clear(const char* str) //������� ������(������� ������ ������);
	{
		memset((void*)str, NULL, n);
		cout << endl << "������� ������ obj2  " << str << endl;

	}
	void show_str() { cout << "s = " << s; cin.get(); }

protected:
	char *s; //��������� �� char � ������ ����� ����������� ���������� ������ ��� ���������� �������� ������;
	int n; //�������� ���� int � ������ ����� ������ � ������.
};

String::String() //����������� ��� ����������
{
	s = 0;
	n = 0;
	cout << endl << "��� ����������� ����������� ��� ����������" << endl;
	cin.get();
}

String::String( char *str) //�����������, ����������� � �������� ��������� � - ������(������������� ������� ������)
{

	cout << endl << "��� ����������� �����������, ����������� � �������� ��������� � - ������(������������� ������� ������)" << endl;
	cout << "������ " << str << endl;
	n = strlen(str);
	s = new char[n + 1];		// +1
	strcpy(s, str);
	cout << "s =" << s << endl;
	cin.get();
}

String::String(char ch)	//�����������, ����������� � �������� ��������� ������
{
	cout << endl << endl << "��� ����������� �����������, ����������� � �������� ��������� ������" << endl;
	cout << "Symbol " << ch << endl;
	s = new char[2];
	s[0] = ch;
	s[1] = '\0';
	n = 1;
	cout << "s =" << s << endl;
	cin.get();
}

String::String(String &T) //����������� �����������
{
	cout << "��� ����������� ����������� �����������" << endl;
	n = T.n;
	s = new char[n + 1];
	strcpy(s, T.s);
	cout << "s =" << s << endl;
	cin.get();
}

String::~String() //����������
{
	cout << "Destructor";
	delete[] s;
	cin.get();
}

String &String:: operator= (const String &operand2)
{
	cout << "\n��� ��������� ������������";
	n = operand2.n;
	s = new char[n + 1];
	strcpy(s, operand2.s);
	cin.get();
	return *this;
}
String &String:: operator== (const String &operand2)
{
	cout << "\n��� ��������� ���������";
	int k = strcmp(s, operand2.s);
	if (k == 0) { cout << "/n������� ������ �����\n"; }
	else cout << "/n������� ������ �� �����\n";
	cin.get();
	return *this;
}

class StringID : public String   // ����������� �����
{
public:
	StringID() : String() {};
	StringID( char *str) : String(str) 
	{
		cout << "�������� ������� ������\n";
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
	////�������� �����
	cout << "DOCHERNI CLASS\n";
	char str2[] = "1100";
	StringID obj4;
	StringID o1(str2);
	o1.show_str();
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	//����������
	////////////////////////������������ (=)
	StringID test1("4t");
	StringID test2("double");
	test2 = test1;
	test2.show_str();
	////////////////////////��������� (==)
	test2 == test1;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cin.get();
	return 0;
}

