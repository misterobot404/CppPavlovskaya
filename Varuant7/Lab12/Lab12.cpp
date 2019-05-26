/*
��������� ������� ������ ���������� �������� ������ Stack.
� ������ �������� ���������� ���������� � ���������� � ��������� �� ���������� ���������� ���������� ������ std::list.
��� ��������, ��� ������ ������ std::list ������������ ��� ������� ������ Stack.
�� ���� ��������� �������� � ������� main ������������� ���������� ������, ������� ��������, ���������� � ��������� ����������.
�������� ��������������� ������� ��� ����� int, double, std::string.
*/
#include "Stack.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ �������� ���������� ������ Stack � ����� int" << endl;
	try
	{
		// ��� int(��� ����� ���������� �������� ����������)
		Stack<int> stackInt;

		cout << "���������� � ���� �������� ���� int �� 0 �� 9" << endl;
		for (int i = 0; i < 10; ++i)
			stackInt.push(i);

		cout << "����� �����" << endl;
		while (!stackInt.empty())
		{
			std::cout << stackInt.top() << ' ';
			stackInt.pop();
		}
		cout << "\n������� �����...���� ����" << endl;

		cout << "������� ������� ��� ���� ������� �� �����.." << endl;
		// ���������� �.�. ���� ��� ����
		stackInt.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Stack<double> stackDouble;

		cout << "���������� � ���� �������� ���� double �� 0.5 �� 9.5" << endl;
		for (double i = 0.5; i < 10; ++i)
			stackDouble.push(i);

		cout << "����� �����" << endl;
		while (!stackDouble.empty())
		{
			std::cout << stackDouble.top() << ' ';
			stackDouble.pop();
		}
		cout << "\n������� �����...���� ����" << endl;

		cout << "������� ������� ��� ���� ������� �� �����.." << endl;
		// ���������� �.�. ���� ��� ����
		stackDouble.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	try
	{
		Stack<string> stackString;

		cout << "���������� � ���� �������� ���� string �� '0' �� '9'" << endl;
		for (int i = 0; i < 10; ++i)
		{
			string s = "'" + to_string(i) + "'";
			stackString.push(s);
		}

		cout << "����� �����" << endl;
		while (!stackString.empty())
		{
			std::cout << stackString.top() << ' ';
			stackString.pop();
		}
		cout << "\n������� �����...���� ����" << endl;

		cout << "������� ������� ��� ���� ������� �� �����.." << endl;
		// ���������� �.�. ���� ��� ����
		stackString.pop();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	system("pause");
	return 0;
}
