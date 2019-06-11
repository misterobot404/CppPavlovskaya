#define _CRT_SECURE_NO_WARNINGS
/*
�������� ���������, ������� ��������� ����� �� ����� � ������� �� ����� ������ ������, �� ���������� ���������� �����.
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
	cout << "������� ������ ���� � ����� ";
	cin >> path;
	ifstream fin(path);
	if (!fin)
	{
		cout << "���� �� ����� ���� ������!" << endl << endl;
	}
	else
	{
		string line;
		string word;
		double found;

		while (getline(fin, line))
		{
			stringstream ss;
			ss << line;

			bool entryCheck = false;

			while (!ss.eof())
			{
				ss >> word;

				if (stringstream(word) >> found)
				{
					double temp = found == 0 ? 1 : int(log10(found) + 1);
					if (temp == 2)
					{
						entryCheck = true;
						break;
					}
				}
			}

			if (!entryCheck)
			{
				cout << line << endl;
			}
		}
	}
	system("pause");
	return 0;
}