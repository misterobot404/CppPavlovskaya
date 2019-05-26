/*
Написать программу, которая считывает текст из файла и выводит на экран только предложения, начинающиеся с тире, перед которым могут находиться только пробельные символы.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

void sentence(std::istream& in)
{
	bool state = false;
	char c;

	while ((c = in.get()) && isspace(c))
		;
	if (c == '-') // вместо тире знак "минус"
		state = true;
	else
		state = false;

	if (state) { 
		while ((c = in.get()) && isspace(c)); // пропуск пробелов
		std::cout << c;
		while ((c = in.get()) && state && !in.eof()) {
			std::cout << c;
			if (c == '.' || c == '!' || c == '?')
				state = false;
		}
		std::cout << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::string file_name;

	std::cout << "Полный путь к файлу: ";
	std::cin >> file_name;

	std::ifstream in;
	in.open(file_name.c_str(), std::ios::in);
	if (!in.good()) {
		std::cout << "Не удаётся открыть файл.\n";
		exit(1);
	}

	while (!in.eof())
		sentence(in);

	in.close();
	system("pause");
	return 0;
}