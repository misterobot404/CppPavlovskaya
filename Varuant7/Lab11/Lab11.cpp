/*
�������� ���������, ��������������� ������ � ��������� ���� �����, SymbString � DecString, ��� ���� ������� ������� ��������������� �������.
������ ������ ������ ����� ������������� (� ���� ������������ ������ ��������) � ���� ��� ��������� ����� ��� �������� ��������� (�������� ��������) �������.
������� (������� main) ������ ���� �������� ��������� �������� �������� (������): ������� ������, ������� ������, �������� �������� �������, operator +(SymbString, SymbString), operator +(DecString, DecString).
�������� �� �������� � �������� �������� ��������������� � ������ Factory.
������������� ����, ����������� ������������������ �������� ��������.
��� ������������� � ��������������� ������ ����������� �������������� ������ (��������, ����������� �����������, �������� ������������ � �.�.) ��� ����������� ����������� ���������������� ���� �������.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ������������ ������� SymbString � DecString" << endl;
	char Control;
	while (true)
	{
		cout << endl << "��������� ���������:" << endl;
		cout << "1. ������ SymbString (���������� ������)" << endl;
		cout << "2. ������ DecString (���������� ������)" << endl;
		cout << ">";
		cin >> Control;
		switch (Control)
		{
		case '1':
		{
			FactorySymbString factorySymbString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nSymbString (���������� ������)" << endl;
				cout << "1. �������� ������" << endl;
				cout << "2. ������� ������" << endl;
				cout << "3. �������� ��������� �������" << endl;
				cout << "4. ������� �������" << endl;
				cout << "5. ��������� � ������ ���� �������" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					cout << "������� ������: ";
					cin.ignore();
					string symbString;
					getline(cin, symbString);
					factorySymbString.addObject(symbString);
					break;
				}
				case '2':
					factorySymbString.deleteObject();
					break;
				case '3':
					factorySymbString.printContainer();
					break;
				case '4':
				{
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					SymbString symbString1(str);
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					getline(cin, str);
					SymbString symbString2(str);
					SymbString symbString = symbString1 + symbString2;
					cout << "���������" << endl;
					symbString.printObject();
					cout << "�������� �������� � ���� ��������" << endl;
					factorySymbString.addObject(symbString);
					break;
				}
				case '5':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		case '2':
		{
			FactoryDecString factoryDecString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nDecString (���������� ������)" << endl;
				cout << "1. �������� ������" << endl;
				cout << "2. ������� ������" << endl;
				cout << "3. �������� ��������� �������" << endl;
				cout << "4. ������� �������" << endl;
				cout << "5. ��������� � ������ ���� �������" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos))
					{
						cout << "� ������ ����� �������������� ������� ������ �� 0 �� 9 ��� ��������";
						break;
					};
					factoryDecString.addObject(str);
					break;
				}
				case '2':
					factoryDecString.deleteObject();
					break;
				case '3':
					factoryDecString.printContainer();
					break;
				case '4':
				{
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos) && str.find(' ') != string::npos)
					{
						cout << "� ������ ����� �������������� ������� ������ �� 0 �� 9 ��� ��������";
						break;
					};
					DecString decString1(str);
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					getline(cin, str);
					if ((str.find_first_not_of("1234567890.-") != string::npos) && str.find(' ') != string::npos)
					{
						cout << "� ������ ����� �������������� ������� ������ �� 0 �� 9 ��� ��������";
						break;
					};
					DecString decString2(str);
					DecString decString = decString1 + decString2;
					cout << "���������" << endl;
					decString.printObject();
					cout << "�������� �������� � ���� ��������" << endl;
					factoryDecString.addObject(decString);
					break;
				}
				case '5':
					breakCheck = false;
					break;
				default: continue;
				}
			}
			break;
		}
		default: continue;
		}
	}
	return 0;
}