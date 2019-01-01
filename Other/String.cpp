/*
 �������� ���������, ������� ��������� ����� �� ����� 
 � ������� �� ����� ������ �����������, ������������ � ����, 
 ����� ������� ����� ���������� ������ ���������� �������. 
 ��������� ������� ��������� ��������� ������.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
		while ((c = in.get()) && isspace(c)) // ������� ��������
			;
		std::cout << c;
		while ((c = in.get()) && state) {
			std::cout << c;
			if (c == '.' || c == '!' || c == '?')
				state = false;
		}
		std::cout << std::endl;
	}
}

int main()
{
	system("color 0A ");
	string file_name;

	cout << "file name: ";
	cin >> file_name;

	ifstream in;
	in.open(file_name.c_str(), ios::in);
	if (!in.good()) {
		cout << "Couldn't read file.\n";
		system("pause");
		exit(1);
	}
	while (!in.eof())
		sentence(in);

	in.close();

	system("pause");
	return 0;
}