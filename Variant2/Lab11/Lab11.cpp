/*
�������� ���������, ��������������� ������ � ��������� ���� �����, SymbString � BinString, ��� ���� ������� ������� ��������������� �������.
������ ������ ������ ����� ������������� (� ���� ������������ ������ ��������) � ���� ��� ��������� ����� ��� �������� ��������� (�������� ��������) �������.
������� (������� main) ������ ���� �������� ��������� �������� �������� (������): ������� ������, ������� ������, �������� �������� �������, operator +(SymbString, SymbString), operator +(BinString, BinString).
�������� �� �������� � �������� �������� ��������������� � ������ Factory.
������������� ����, ����������� ������������������ �������� ��������.
��� ������������� � ��������������� ������ ����������� �������������� ������ (��������, ����������� �����������, �������� ������������ � �.�.) ��� ����������� ����������� ���������������� ���� �������.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ������������ ������� SymbString � BinString" << endl;
	char Control;
	while (true)
	{
		cout << endl << "��������� ���������:" << endl;
		cout << "1. ������ SymbString (���������� ������)" << endl;
		cout << "2. ������ BinString (�������� ������)" << endl;
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
			FactoryBinString factoryBinString;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nBinString (�������� ������)" << endl;
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
					if ((str.find_first_not_of("01") != string::npos))
					{
						cout << "� ������ ����� �������������� ������� 0 � 1 ��� ��������";
						break;
					};
					factoryBinString.addObject(str);
					break;
				}
				case '2':
					factoryBinString.deleteObject();
					break;
				case '3':
					factoryBinString.printContainer();
					break;
				case '4':
				{
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					cin.ignore();
					string str;
					getline(cin, str);
					if ((str.find_first_not_of("01") != string::npos))
					{
						cout << "� ������ ����� �������������� ������� 0 � 1 ��� ��������";
						break;
					};
					BinString decString1(str);
					cout << "������ ������" << endl;
					cout << "������� ������: ";
					getline(cin, str);
					if ((str.find_first_not_of("01") != string::npos))
					{
						cout << "� ������ ����� �������������� ������� 0 � 1 ��� ��������";
						break;
					};
					BinString decString2(str);
					BinString decString = decString1 + decString2;
					cout << "���������" << endl;
					decString.printObject();
					cout << "�������� �������� � ���� ��������" << endl;
					factoryBinString.addObject(decString);
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