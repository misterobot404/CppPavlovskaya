/*
�������� ���������, ������� ��������� ����� �� ����� � ������� �� ����� ������ �����������, ��������� �� ��������� ���������� ����.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//system("color 0A ");
	string path;
	cout << "������� ������ ���� � ����� "; cin >> path;
	ifstream fin(path);
	if (!fin)
	{
		cout << "���� �� ����� ���� ������!" << endl;
		system("pause");
		return -1;
	}

	int count;
	cout << "������� ���������� ���� � ����������� (����������� ����������� ��������� .!?): "; 	cin >> count;
	string text;

	while (getline(fin, text))
	{

		int pos1 = 0;
		int pos2 = -1;

		while (pos2 != 0)
		{
			stringstream sentence;
			string sentenceTemp;

			// ���������� ������� ����� ����������� (������ ����������� pos1)
			pos2 = text.find_first_of(".?!", pos1) + 1;

			// ������ ���������� ����������� � string �����
			if (pos2 == 0)
			{
				sentence << text.substr(pos1);
			}
			else
			{
				sentence << text.substr(pos1, pos2);
			}

			// ����������� ���������� ���� � ����������� � �����
			bool entryCheck = false;
			int countTemp = 0;
			while (!sentence.eof())
			{
				sentence >> sentenceTemp;
				countTemp++;
			}
			if (count == countTemp)
			{
				cout << sentence.str() << endl;
			}

			// �������� ��������� �� ���� �����������
			pos1 = pos2;
		}
	}
	cout << endl;

	fin.close();
	system("pause");
	return 0;
}