/*
��������� ������� ������ ���������� �������� ������ List.
�� ���� ��������� �������� � ������� main ������������� ���������� ������, ������� ��������, ���������� � ��������� ����������.
�������� ��������������� ������� ��� ����� int, double, std::string.
*/
#include "List.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "List ������������ ����� ���������, ������� ������������ ������� �������" << endl
		<< "� �������� ��������� �� ����� ������� � ����������." << endl
		<< "������� ������������ ������ �� �������������� (�.� �������� ����������� � ������ � ��������� �������)." << endl
		<< "List ���������� � ���� ����������� ������." << endl << endl;
	cout << "������������ �������� ���������� ������ List � ����� int" << endl;
	try
	{
		// ��� int(��� ����� ���������� �������� ����������)
		List<int> listInt(0);

		cout << "���������� � ������ �������� ���� int �� 0 �� 9" << endl;
		for (int i = 0; i < 10; ++i)
			listInt.push_back(i);

		cout << "����� ������" << endl;
		listInt.output();

		cout << "������� ������� ��� �������� ";
		int el; cin >> el;
		listInt.remove(el);
		cout << "������������ ������" << endl;
		listInt.output();

		cout << "������� ������� ��� ������� � ������ ";
		cin >> el;
		listInt.push_front(el);
		cout << "������������ ������" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\n������� ������...������ ����" << endl;

		cout << "������� ������� ��� ���� ������� �� ������.." << endl;
		// ���������� �.�. ���� ��� ����
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	cout << endl;
	cout << "������������ �������� ���������� ������ List � ����� double" << endl;
	try
	{
		// ��� int(��� ����� ���������� �������� ����������)
		List<double> listInt(0);

		cout << "���������� � ������ �������� ���� double �� 0.5 �� 9.5" << endl;
		for (double i = 0.5; i < 10; ++i)
			listInt.push_back(i);

		cout << "����� ������" << endl;
		listInt.output();

		cout << "������� ������� ��� �������� ";
		double el; cin >> el;
		listInt.remove(el);
		cout << "������������ ������" << endl;
		listInt.output();

		cout << "������� ������� ��� ������� � ������ ";
		cin >> el;
		listInt.push_front(el);
		cout << "������������ ������" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\n������� ������...������ ����" << endl;

		cout << "������� ������� ��� ���� ������� �� ������.." << endl;
		// ���������� �.�. ���� ��� ����
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	cout << endl;

	cout << "������������ �������� ���������� ������ List � ����� string" << endl;
	try
	{
		List<string> listInt(0);

		cout << "���������� � ������ �������� ���� string �� '0' �� '9'" << endl;
		for (int i = 0; i < 10; ++i)
		{
			string s = "'" + to_string(i) + "'";
			listInt.push_back(s);
		}

		cout << "����� ������" << endl;
		listInt.output();

		cout << "������� ������� ��� �������� ";
		string el; cin >> el;
		listInt.remove(el);
		cout << "������������ ������" << endl;
		listInt.output();

		cout << "������� ������� ��� ������� � ������";
		cin >> el;
		listInt.push_front(el);
		cout << "������������ ������" << endl;
		listInt.output();

		while (listInt.size() > 0)
		{
			listInt.pop_back();
		}
		cout << "\n������� ������...������ ����" << endl;

		cout << "������� ������� ��� ���� ������� �� ������.." << endl;
		// ���������� �.�. ���� ��� ����
		listInt.pop_back();
	}
	catch (std::underflow_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	cout << endl;

	system("pause");
	return 0;
}
