/*
�������� ���������, ��������������� ������ � ��������� ���� �����, SymbString � HexString, ��� ���� ������� ������� ��������������� �������.
������ ������ ������ ����� ������������� (� ���� ������������ ������ ��������) � ���� ��� ��������� ����� ��� �������� ��������� (�������� ��������) �������.
������� (������� main) ������ ���� �������� ��������� �������� �������� (������): ������� ������, ������� ������, �������� �������� �������, operator +(SymbString, SymbString), operator +(HexString, HexString).
�������� �� �������� � �������� �������� ��������������� � ������ Factory.
������������� ����, ����������� ������������������ �������� ��������.
��� ������������� � ��������������� ������ ����������� �������������� ������ (��������, ����������� �����������, �������� ������������ � �.�.) ��� ����������� ����������� ���������������� ���� �������.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ������������ ������� SymbString � HexString" << endl;
	char Control;
	while (true)
	{
		cout << endl << "��������� ���������:" << endl;
		cout << "1. ������ SymbString (���������� ������)" << endl;
		cout << "2. ������ HexString (����������������� ������)" << endl;
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
			FactoryHexString factoryHexString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nHexString (����������������� ������)" << endl;
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
					cout << "����������: � ������ ����� �������������� ����� �� 0 �� 9 � ����� A,B,C,D,E,F ��� ��������" << endl;
					cout << "������: 5CD8" << endl << endl;

					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "������ �����." << endl;
						break;
					};
					factoryHexString.addObject(str);
					break;
				}
				case '2':
					factoryHexString.deleteObject();
					break;
				case '3':
					factoryHexString.printContainer();
					break;
				case '4':
				{
					cout << "����������: � ������ ����� �������������� ����� �� 0 �� 9 � ����� A,B,C,D,E,F ��� ��������" << endl;
					cout << "������: 5CD8" << endl << endl;
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "������ �����." << endl;
						break;
					};
					HexString decString1(str);
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					getline(cin, str);
					if ((str.find_first_not_of("0123456789ABCDEF") != string::npos))
					{
						cout << "������ �����." << endl;
						break;
					};
					HexString decString2(str);
					HexString decString = decString1 + decString2;
					cout << "���������" << endl;
					decString.printObject();
					cout << "�������� �������� � ���� ��������" << endl;
					factoryHexString.addObject(decString);
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