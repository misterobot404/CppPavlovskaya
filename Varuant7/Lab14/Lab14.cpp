/*
�������� ���������, ������� ��������� ����� �� ����� � ����������, ������� � ��� ����, ��������� �� �� ����� ��� ������� �������.
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "���� � �����: ";
	string path;
	getline(cin, path);
	ifstream input(path);

	if (input.fail() == true)
	{
		cout << "�� ������ ������� ����" << endl;
		system("pause");
		return 0;
	}

	string word;

	cout << "����� ����, ��������� �� �� ����� ��� 4 ����.." << endl;
	bool inp = false;
	while (input >> word)
	{
		if (word.length() < 5)
		{
			cout << word << endl;
			inp = true;
		}
	}
	if (inp == false) cout << "�����, ��������� �� �� ����� ��� 4 ����, �� �������" << endl;

	input.close();
	system("pause");
	return 0;
}