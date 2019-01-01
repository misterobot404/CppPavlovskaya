/*20.Выполнить задание 11 с использованием класса string и регулярных выражений.
Задание 11. Выполнить задание 6 используя функции библиотеки для работы со строками и символами.
Задание 6. Разработать программу обработки текстового файла с использованием строк в стиле С и символов.
Написать программу, которая считывает текст из файла и выводит его на экран, меняя местами каждые два соседних слова.*/
#include	<fstream> 
#include	<string>
#include	<iostream>
#include	<regex>
using  namespace  std;

void ShowInversionWordInSentence(ifstream& file) {
	string FirstWord, SecondWord;
	while (!file.eof())
	{
		file >> FirstWord;
		file >> SecondWord;
		cout << SecondWord << ' ' << FirstWord<< ' ';
		FirstWord.clear(); 
		SecondWord.clear();
	}
	cout << endl;
	file.clear();
	file.seekg(0);
}

void ValidationSentence(string str) {
	regex regular("[\\s]{0,2}[A-Z]{1}[A-Za-z\\s]*(\\.|\\?|!|[\\.]{3})");
	if (regex_match(str.c_str(), regular))
	{
		cout << "validation completed\n";
	}
	else cout << "validation errors!\n";
}
	
int  main()
{
	string path;
	string str;
	while (true)
	{
		cout << "Enter infile name\n";
		cin >> path;
		ifstream ifs(path);
		if (!ifs)
		{
			cout << "Can` t open file " << path << '\n';
			return false;
		}
		path.clear();
		int ch = 0;
		while (ch != EOF) {
			while (!((ifs.peek() == '!') || (ifs.peek() == '?') || (ifs.peek() == '.')))
			{
				if (ifs.eof())
				{
					ifs.clear();
					ifs.seekg(0);
					ShowInversionWordInSentence(ifs);
					system("pause");
					exit(-1);
				}
				str += ifs.get();
			}
			str += ifs.get();
			ValidationSentence(str);
			str.clear();
			ch = ifs.peek();
		}	
	}
	return  0;
}