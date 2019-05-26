/*
�������� ��������� ���� �������� ������.
������������� ����������� ������ � ������������ ������ �������,
������ ������ �� ������-���� �������� (��������, �� �������, ���� �������� ��� ������ ��������),
���������� � �������� �������,
���������� �� ������ �����.
�������� ������ ������������ � ������� ������ map ��� multimap.
*/
#include "Notebook.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "��� �������� ������" << endl;
	int num;
	while (true)
	{
		cout << "������� c�������� ���������� �������: ";
		cin >> num;
		cin.ignore(256, '\n');
		if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			cin.clear(); // �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << "������� ������ ����� �����!" << endl;
		}
		else break;
	}
	Notebook notebook(num);
	system("cls");

	while (true)
	{	
		size_t selectedMenuItem;
		while (true)
		{
			cout << "\n��� �������� ������ (������� ���������� ������� " << notebook.getSize() << ")" << endl;
			cout << "1.����� ���� �������" << endl;
			cout << "2.���������� ������" << endl;
			cout << "3.�������� ������" << endl;
			cout << "4.����� �������" << endl;
			cout << "5.���������� ������� " << endl;
			cout << "6.�������� �������" << endl;
			cout << "> ";
			cin >> selectedMenuItem;
			cin.ignore(256, '\n');
			if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
			{
				cin.clear(); // �� ���������� cin � '�������' ����� ������
				cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
				cout << "������� ������ ����� �����!" << endl;
			}
			else break;
		}
		switch (selectedMenuItem)
		{
		case 1:
		{
			notebook.printNotebook();
		}
		break;
		case 2:
		{
			notebook.addNote();
		}
		break;
		case 3:
		{
			cout << "����� ��������� ������: ";
			size_t number;
			cin >> number;
			notebook.eraseNote(number);
		}
		break;
		case 4:
		{
			bool exit = false;
			while (!exit)
			{
				cout << "�������� ������ ������:" << endl;
				cout << "1.����� �� ������" << endl;
				cout << "2.����� �� �������" << endl;
				cout << "3.����� �� ���� ��������" << endl;
				cout << "4.����� �� ������ ��������" << endl;
				cout << "5.����� � ��. ����" << endl;
				cout << ">";
				size_t t;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					cout << "������� �����: ";
					size_t recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByNumber(recNumber);
				}
					break;
				case 2:
				{
					cout << "������� �������: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByLastName(recNumber);
				}
					break;
				case 3:
				{
					cout << "������� ���� ��������: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByDateOfBirth(recNumber);
				}
					break;
				case 4:
				{
					cout << "������� ����� ��������: ";
					string recNumber;
					cin >> recNumber;
					notebook.searchAndPrintNoteByPhoneNumber(recNumber);
				}
					break;
				case 5:
					exit = true;
					break;
				}
			}
		}
		break;
		case 5:
		{
			bool exit = false;
			while (!exit)
			{
				cout << "�������� ���������� �������:" << endl;
				cout << "1.�� ��������" << endl;
				cout << "2.�� ���� ��������" << endl;
				cout << "3.����� � ��. ����" << endl;
				cout << ">";
				size_t t;
				cin >> t;
				switch (t)
				{
				case 1:
				{
					notebook.sortAndPrintNotebookByLastName();
				}
				break;
				case 2:
				{
					notebook.sortAndPrintNotebookByDateOfBirth();
				}
				break;
				case 3:
					exit = true;
					break;
				}
			}
		}
		break;
		case 6:
		{
			system("cls");
		}
		break;
		default: system("cls");
		}
	}
	return 0;
}