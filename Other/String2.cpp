//�������� ���������, ������� ��������� ���������� ����� �� ����� � ������� �� ����� �����, ������������ � ������� ����.
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
bool isVowel(string c)
{
	
	return c[0] == 'A' || c[0] == 'a' || c[0] == 'E' || c[0] == 'e' ||
		c[0] == 'Y' || c[0] == 'y' || c[0] == 'U' || c[0] == 'u' ||
		c[0] == 'I' || c[0] == 'i' || c[0] == 'O' || c[0] == 'o';
}

int main() {
	setlocale(LC_ALL, "Russian");
	string curword, way;
	cout << "���� � �����: ";
	cin >> way;
	ifstream fin(way);
	if (!fin) {
		cout << "������ �������� �����." << endl;
		cin.get(); cin.get();
		return 1;
	} 
	int count = 0;    
	while ( !fin.eof() ) {   
		fin >> curword;       
		if (isVowel(curword)) {
			cout << curword << endl;
			++count;
		}
	}
	cout << "��� ���������� ��������� ������� ����� �������";
	cin.get(); cin.get();
} 