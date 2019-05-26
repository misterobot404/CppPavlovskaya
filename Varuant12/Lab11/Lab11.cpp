/*
�������� ���������, ��������������� ������ � ��������� ���� �����, Quadrate � Pentagon, ��� ���� ������� ������� ��������������� �������.
������ ������ ������ ����� ������������� (� ���� ������������ ������ ��������) � ���� ��� ��������� ����� ��� �������� ��������� (�������� ��������) �������.
������� (������� main) ������ ���� �������� ��������� �������� �������� (������): ������� ������, ������� ������, �������� �������� �������, Move(), IsIntersect(T&, T&).
�������� �� �������� � �������� �������� ��������������� � ������ Factory.
������������� ����, ����������� ������������������ �������� ��������.
��� ������������� � ��������������� ������ ����������� �������������� ������ (��������, ����������� �����������, �������� ������������ � �.�.) ��� ����������� ����������� ���������������� ���� �������.
*/
#include "Factory.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ������������ ������� Quadrate(�������) � Pentagon(������������)" << endl;

	char Control;
	while (true)
	{
		cout << endl << "��������� ���������:" << endl;
		cout << "1. ������ Quadrate (�������)" << endl;
		cout << "2. ������ Pentagon (������������)" << endl;
		cout << ">";
		cin >> Control;
		switch (Control)
		{
		case '1':
		{
			FactoryQuadrate factoryQuadrate;
			cout << "�������� �������� � ������������ �� ���������.." << endl;
			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nQuadrate (�������)" << endl;
				cout << "1. ������� ������� � ������ ������������" << endl;
				cout << "2. ������� �������" << endl;
				cout << "3. �������� ���������� ��������" << endl;
				cout << "4. ����������� �������" << endl;
				cout << "5. �������� �� �����������" << endl;
				cout << "6. ��������� � ������ ������" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					factoryQuadrate.addObject();
				}
				break;
				case '2':
				{
					factoryQuadrate.deleteObject();
				}
				break;
				case '3':
				{
					factoryQuadrate.quadrate_.Result();
				}
				break;
				case '4':
				{
					factoryQuadrate.quadrate_.Move();
				}
				break;
				case '5':
				{
					factoryQuadrate.quadrate_.IsIntersect();
				}
				break;
				case '6':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		case '2':
		{
			FactoryPentagon factoryPentagon;

			bool breakCheck = true;
			while (breakCheck)
			{
				cout << "\nPentagon (������������)" << endl;
				cout << "1. ������� ������������ � ������ ������������" << endl;
				cout << "2. ������� ������������" << endl;
				cout << "3. �������� ���������� �������������" << endl;
				cout << "4. ����������� ������������" << endl;
				cout << "5. �������� �� �����������" << endl;
				cout << "6. ��������� � ������ ������" << endl;
				cout << ">";
				cin >> Control;
				switch (Control)
				{
				case '1':
				{
					factoryPentagon.addObject();
				}
				break;
				case '2':
				{
					factoryPentagon.deleteObject();
				}
				break;
				case '3':
				{
					factoryPentagon.pentagon_.Result();
				}
				break;
				case '4':
				{
					factoryPentagon.pentagon_.Move();
				}
				break;
				case '5':
				{
					factoryPentagon.pentagon_.IsIntersect();
				}
				break;
				case '6':
					breakCheck = false;
					break;
				default: continue;
				}
			}
		}
		break;
		}
	}
	return 0;
}