/*
��������� ������� ������ ���������� �������� ������ Queue.
� ������ �������� ���������� ���������� � ���������� � ��������� �� ���������� ���������� ���������� ������ std::list.
��� ��������, ��� ������ ������ std::list ������������ ��� ������� ������ Queue.
�� ���� ��������� �������� � ������� main ������������� ���������� ������, ������� ��������, ���������� � ��������� ����������.
�������� ��������������� ������� ��� ����� int, double, std::string.
*/
#include "Queue.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Queue ����������� ��� ������ � ����������� ������� � ��������� ������� ������ � ������ �����." << endl;
	cout << "���������� �������� �������� ���� � ����� �������, ������� � ������ �� ������ �������." << endl << endl;
	cout << "������������ �������� ���������� ������ Queue � ������� ������ ������" << endl << endl;

	try
	{
		// ��� int(��� ����� ���������� �������� ����������)
		Queue<int> queueInt;

		cout << "���������� � ������� �������� ���� int �� 1 �� 5" << endl;
		for (int i = 1; i < 6; ++i)
			queueInt.push_back(i);

		cout << "����� �������: ";
		queueInt.show();

		cout << "���������� � ������� �������� 1" << endl;
		queueInt.push_back(1);

		cout << "������ ������� �������: " << queueInt.front() << endl;
		cout << "��������� ������� �������: " << queueInt.back() << endl;

		cout << "������������ �������" << endl;
		while (!queueInt.empty())
		{		
			cout << "������������� �������: " << queueInt.front() << endl;
			queueInt.pop_front();
		}

		cout << "������� ������� ��� ���� ������� �� �������.." << endl;
		// ���������� �.�. ���� ��� ����
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

		cout << "���������� � ������� �������� ���� double �� 1.5 �� 5.5" << endl;
		for (double i = 1.5; i < 6; ++i)
			queueDouble.push_back(i);

		cout << "����� �������: ";
		queueDouble.show();

		cout << "���������� � ������� �������� 1.5" << endl;
		queueDouble.push_back(1.5);

		cout << "������ ������� �������: " << queueDouble.front() << endl;
		cout << "��������� ������� �������: " << queueDouble.back() << endl;

		cout << "������������ �������" << endl;
		while (!queueDouble.empty())
		{
			cout << "������������� �������: " << queueDouble.front() << endl;
			queueDouble.pop_front();
		}

		cout << "������� ������� ��� ���� ������� �� �������.." << endl;
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

		cout << "���������� � ������� �������� ���� string �� Hello1 �� Hello5" << endl;
		for (int i = 1; i < 6; ++i)
		{
			string str = "Hello" + to_string(i);
			queueString.push_back(str);
		}

		cout << "����� �������: ";
		queueString.show();

		cout << "���������� � ������� �������� Hello1" << endl;
		queueString.push_back("Hello1");

		cout << "������ ������� �������: " << queueString.front() << endl;
		cout << "��������� ������� �������: " << queueString.back() << endl;

		cout << "������������ �������" << endl;
		while (!queueString.empty())
		{
			cout << "������������� �������: " << queueString.front() << endl;
			queueString.pop_front();
		}

		cout << "������� ������� ��� ���� ������� �� �������.." << endl;
		queueString.pop_front();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
