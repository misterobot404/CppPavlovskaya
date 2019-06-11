/*
Написать программу, которая считывает текст из файла и выводит на экран только предложения, состоящие из заданного количества слов.
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
	cout << "Введите полный путь к файлу "; cin >> path;
	ifstream fin(path);
	if (!fin)
	{
		cout << "Файл не может быть открыт!" << endl;
		system("pause");
		return -1;
	}

	int count;
	cout << "Введите количество слов в предложении (предложения разделяются символами .!?): "; 	cin >> count;
	string text;

	while (getline(fin, text))
	{

		int pos1 = 0;
		int pos2 = -1;

		while (pos2 != 0)
		{
			stringstream sentence;
			string sentenceTemp;

			// нахождение позиции конца предложения (начало предложения pos1)
			pos2 = text.find_first_of(".?!", pos1) + 1;

			// запись найденного предложения в string поток
			if (pos2 == 0)
			{
				sentence << text.substr(pos1);
			}
			else
			{
				sentence << text.substr(pos1, pos2);
			}

			// определение количества слов в предложении и вывод
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

			// смещение указателя на одно предложение
			pos1 = pos2;
		}
	}
	cout << endl;

	fin.close();
	system("pause");
	return 0;
}