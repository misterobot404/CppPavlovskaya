/*
Написать программу, которая считывает текст из файла и определяет, сколько в нем слов, состоящих из не более чем четырех буквами.
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Путь к файлу: ";
	string path;
	getline(cin, path);
	ifstream input(path);

	if (input.fail() == true)
	{
		cout << "Не удаётся открыть файл" << endl;
		system("pause");
		return 0;
	}

	string word;

	cout << "Поиск слов, состоящих из не более чем 4 букв.." << endl;
	bool inp = false;
	while (input >> word)
	{
		if (word.length() < 5)
		{
			cout << word << endl;
			inp = true;
		}
	}
	if (inp == false) cout << "Слова, состоящие из не более чем 4 букв, не найдены" << endl;

	input.close();
	system("pause");
	return 0;
}