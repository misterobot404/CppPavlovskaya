/*
��������� ������� ������ ���������� �������� ������ Deque.
� ������ �������� ���������� ���������� � ���������� � ��������� �� ���������� ���������� ���������� ������ Vect.
��� ��������, ��� ������ ������ Vect ������������ ��� ������� ������ Deque.
� �������� ���������� ������ ����� ���� ������ ���� �����, ��������� ������������� � ������ ���� �� �������, ���� ����� ����������� ����������.
Deque - ������������ ������� (��������� ������� � �������� �� ����� ������);
*/
#include "Deque.h"
#include "string"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Deque - ������������ �������(��������� ������� � �������� �� ����� ������)" << endl;
	cout << "������������ ���������� �������� ���������� ������ Deque, ���������� �� \n" 
		<< "���������� ���������� ������ Vect, �� ���������� ������ �����" << endl << endl;
	try
	{
		Deque<int> dequeInt;

		cout << "���������� �������� ���� int �� 0 �� 1 � ������" << endl;

		for (int i = 0; i < 2; ++i)
			dequeInt.push_back(i);
		dequeInt.show();

		cout << "���������� �������� ���� int �� 0 �� 1 � ������ ������" << endl;
		for (int i = 0; i < 2; ++i)
			dequeInt.push_begin(dequeInt.begin(),i);
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ �������" << endl;
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

		cout << "���������� �������� ���� double �� 0.5 �� 1.5 � ������" << endl;

		for (double i = 0.5; i < 2.5; ++i)
			dequeInt.push_back(i);
		dequeInt.show();

		cout << "���������� �������� ���� double �� 0.5 �� 1.5 � ������ ������" << endl;
		for (int i = 0.5; i < 2.5; ++i)
			dequeInt.push_begin(dequeInt.begin(), i);
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ �������" << endl;
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

		cout << "���������� �������� ���� string �� '0' �� '1' � ������" << endl;

		for (int i = 0; i < 2; ++i)
			dequeInt.push_back("'" + to_string(i) + "'");
		dequeInt.show();

		cout << "���������� �������� ���� string �� '0' �� '1' � ������ ������" << endl;
		for (int i = 0; i < 2; ++i)
			dequeInt.push_begin(dequeInt.begin(), "'" + to_string(i) + "'");
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ � ����� �������" << endl;
		dequeInt.pop_back();
		dequeInt.pop_begin();
		dequeInt.show();

		cout << "�������� ������ �������� � ������ �������" << endl;
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
