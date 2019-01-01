//Написать программу, которая считывает текст из файла и выводит на экран только предложения, не содержащие запятых.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	string str;
	cout << "Enter infile name\n";
	cin >> str;
	ifstream ifs(str);
	if (!ifs)
	{
		cerr << "Can` t open file " << str << '\n';
		system("pause");
		return 1;
	}
	str.clear();
	int ch = 0;
	while (ch != EOF) {
		while (!((ifs.peek() == '!') || (ifs.peek() == '?') || (ifs.peek() == '.')))
		{
			if (ifs.eof())
			{
				system("pause");
				return 1;
			}
			str += ifs.get();
		}
		str += ifs.get();
		if (str.find(',') == string::npos) {
			cout << str;
		}
		str.clear();
		ch = ifs.peek();
	}
	ifs.close();
	cout << endl;
	system("pause");
	return 0;
}