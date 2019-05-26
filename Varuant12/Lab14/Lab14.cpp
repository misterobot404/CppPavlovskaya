/*
�������� ���������, ������� ��������� ����� �� ����� � ������� �� ����� ������ �����������, ������������ � ����, ����� ������� ����� ���������� ������ ���������� �������.
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
	if (c == '-') // ������ ���� ���� "�����"
		state = true;
	else
		state = false;

	if (state) { 
		while ((c = in.get()) && isspace(c)); // ������� ��������
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

	std::cout << "������ ���� � �����: ";
	std::cin >> file_name;

	std::ifstream in;
	in.open(file_name.c_str(), std::ios::in);
	if (!in.good()) {
		std::cout << "�� ������ ������� ����.\n";
		exit(1);
	}

	while (!in.eof())
		sentence(in);

	in.close();
	system("pause");
	return 0;
}