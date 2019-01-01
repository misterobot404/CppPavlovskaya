#include <iostream>
#include <conio.h>
using namespace std;

struct Human
{
	char *name;
	int zarplata;
	int propuski;
};
void inputRab(Human *s)
{
	cout << "Введите имя работника " << endl;
	s->name = new char[20];
	cin.get();
	cin.getline(s->name,20);

	cout << "Введите зарплату работника " << endl;
	cin >> s->zarplata;

	cout << "Введите количество пропусков работника " << endl;
	cin >> s->propuski;
}

void del(Human *s)
{
	if(s->propuski > 5) cout << "Уволить " << s->name;
}

void clear(Human s[], int n)
{
	for(int i(0); i < n; i++)
	{
		delete [] s[i].name;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	Human rab[2];

	for(int i(0); i < 2; i++)
	{
		cout << "Работник " << i+1 << endl;
		inputRab(&rab[i]);
	}

	for(int i(0); i < 2; i++)
	del(&rab[i]);

	clear(rab,2);
	_getch();
	return 0;
}?