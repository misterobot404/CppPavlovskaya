/*
��������� �������� ������ ��� ����������� ���������� �������� ����� ������������� �����.

������������� ����������� ��������� � ��������� ������� ������� �� ��������, 
�������� ������ �� ������� �������, 
���������� �������� ������������� ��������� ���� �������� � ������������ ������ �������, 
������� ���� �������� � ����������� ������������� ���������, 
������ �� ����� �������� ������� �� ��������� ������� � ����� �������.

�������� ���������, ��������������� ������ � ���� �������. 
��������� ������ ��������� ����, ����������� ����������� �������� ���� ������� ������.
*/
#include <iostream>
#include <iomanip> 

using namespace std;
class PointerArray
{
private:
	char** _string;
	int _stringLength;
	int _size;
public:
	void create();
	void initialize();
	void merge(int n1, int n2);
	void mergeNotRepeatingElements(int n3, int n4);
	void show();
	void showByIndex(int number);
	void search(int rec, int field);
};
//�������� ������� �����
void PointerArray::create() 
{
	// ��������� ������ ��� �������
	cout << endl;
	cout << "���������� �����: "; cin >> _size;
	_string = new char* [_size];

	// ����������� ����� �����
	cout << "������ ������������� �����." << endl;
	cout << "������� ���������� �������� ��� �����: ";
	cin >> _stringLength; _stringLength += 1;


	// �������� ������ ��� ������ ������
	for (int i = 0; i < _size; i++) {
		
		*(_string + i) = new char[_stringLength];
	}
	cout << endl;
}
// ������������� ��������
void PointerArray::initialize()
{
	create();
	cin.ignore();
	cout << "���� ����� ������������� �����. ������������ ���������� ��������: " << _stringLength - 1 << endl;
	for (int i = 0; i < _size; i++)
	{
		cout << "���� " << i + 1 << " ������: ";
		cin.getline(*(_string + i), _stringLength); // char*, int
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			throw exception();
		}
	}
}
// ������ ���� �����
void PointerArray::show()
{
	for (int i = 0; i < _size; i++)
	{
		cout << *(_string + i);
		cout << endl;
	}
}
// ������ ����� �� �������
void PointerArray::showByIndex(int number)
{
	if (number < _size)
	{
		for (int i = 0; i < _size; i++)
		{
			if (i == number)
			{
				cout << *(_string + i) << endl;
			}
		}
	}
	else
	{
		cout << "����� �� ������� ��������� �����." << endl;
	}
}
void PointerArray::search(int rec, int field)//������ ����������� �������� ���������� ������ (rec � ����� ������ ���������� �������, field � ����� �������� � ������)
{
	if (rec < _size && field < _stringLength)
	{
			cout << *(_string + rec) + field << endl;
	}
	else
	{
		cout << "����� �� ������� ��������� ����� ������������� ����� ��� ���������." << endl;
	}
}
//��������� ���� ��������. ��������� �������������� ���������� m1 � m2 ������������� ����� �����, ������� ���������� �������. �� ����� ���� ����� ������ �������.
void PointerArray::merge(int n1, int n2)
{
	if (n1 < _size && n2 < _size)
	{
		cout << *(_string + n1) << *(_string + n2) << endl;
	}
	else
	{
		cout << "����� �� ������� ��������� �����." << endl;
	}
}
//������� ���� ��������
void PointerArray::mergeNotRepeatingElements(int n1, int n2)
{
	if (n1 < _size && n2 < _size)
	{
		cout << *(_string + n1);

		for (size_t i = 0; i < _stringLength; i++)
		{
			bool checkEntry = false;
			for (size_t j = 0; j < _stringLength; j++)
			{

				if (*(*(_string + n1) + j)  == *(*(_string + n2) + i))
				{
					checkEntry = true;
					break;
				}
			}
			if (!checkEntry)
			{
				cout << *(*(_string + n2) + i);
			}
		}
	}
	else
	{
		cout << "����� �� ������� ��������� �����." << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	PointerArray _string;
	int number, punkt, rec, field, n1, n2;
	while (true)
	{
		cout << "  ����" << endl;
		cout << "1 �������� ������� ����� ����. �����"; cout << endl;
		cout << "2 ����� ���� �����"; cout << endl;
		cout << "3 ����� ������ �� �������"; cout << endl;
		cout << "4 ��������� ���� �������� (������������, � ������������)"; cout << endl;
		cout << "5 ������� ���� ������� (���������� ������������� ��������� � ��������� �������)"; cout << endl;
		cout << "6 ����� ����������� �������� ���������� ������"; cout << endl;
		cout << "7 �����"; cout << endl;
		cout << "������� ����� ������ ����: "; cin >> punkt;
		switch (punkt)
		{
		case 1:
		{
			try
			{
				_string.initialize();
				cout << endl;
			}
			catch (const exception&)
			{
				cout << "bad alloc. Program error" << endl;
				system("pause");
				exit(-1);
			}
		}
		break;
		case 2:
		{
			_string.show();
			cout << endl;
		}
		break;
		case 3:
		{
			cout << "������� ����� ������ (��������� ����������� � 0!): "; cin >> number;
			_string.showByIndex(number);
			cout << endl;
		}
		break;
		case 4:
		{
			cout << "����������: ��������� ����� ����������� � 0!" << endl;
			cout << "������� ����� 1-�� ������: "; cin >> n1;
			cout << "������� ����� 2-�� ������: "; cin >> n2;
			_string.merge(n1, n2);
			cout << endl;
		}
		break;
		case 5:
		{
			cout << "����������: ��������� ����� ����������� � 0!" << endl;
			cout << "������� ����� 1-�� ������: "; cin >> n1;
			cout << "������� ����� 2-�� ������: "; cin >> n2;
			_string.mergeNotRepeatingElements(n1, n2);
			cout << endl;
			cout << endl;
		}
		break;
		case 6:
		{
			cout << "����������: ��������� ����� � ������� ����������� � 0!" << endl;
			cout << "������� ����� ������ �������: "; cin >> rec;
			cout << "������� ����� �������: "; cin >> field;
			_string.search(rec, field);
			cout << endl;
		}
		break;
		case 7:
			exit(0);
			break;
		}
	}
}