#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip> 
#include <Windows.h>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A ");

	ifstream fin("text.txt");
	if (!fin)
	{
		cout << "Файл не может быть открыт!" << endl << endl;
	}
	else
	{
		fin.seekg(0, ios::end);
		long len = fin.tellg();
		char *str1 = new char[len + 1];
		fin.seekg(0, ios::beg);
		fin.read(str1, len);
		str1[len] = '\0';

		int k = 0, i = 0, j = 0;     // k - начало нового предложения, i - счетчик циклов, j - счетчик найденных слов
		char *token;
		char deliteli[] = ",.!?\|/<>)(*;:' ";

		const int bukvy = 15;
		char slovo[bukvy];

		const int max = 10000;
		char predlojeniya[max], rezerv[max];


		cout << "Здравствуйте, Вы находитесь в программе, которая ищет в установленном текстовом файле предложения c введенным Вами словом.\n\nВведите искомое слово: ";
		cin >> setw(bukvy) >> slovo;
		OemToCharA(slovo, slovo);
		cout << "Слово, введенное Вами: " << slovo << endl;


		// считаем кол-во точек/вопр/воскл в исходном тексте, ведь в тексте может вообще не быть предложений
		int n = 0;
		for (i = 0; i < strlen(str1); i++)
			if (str1[i] == '.' || str1[i] == '!' || str1[i] == '?') n++;
		if (n == 0) cout << endl << "Текст в файле вообще не содержит предложений" << endl << endl;


		// основная часть
		else
		{
			cout << endl << "Предложения с введенным Вами словом:" << endl;
			for (i = 0; i < strlen(str1); i++)
			{
				if (str1[i] == '.' || str1[i] == '!' || str1[i] == '?')
				{
					strncpy(predlojeniya, str1 + k, i - k + 1);
					predlojeniya[i - k + 1] = '\0';
					strcpy(rezerv, predlojeniya);           // функция strtok вычленяет токены, разделяемые любым из символов ",.!?\|/<>)(*;:' ",
					token = strtok(predlojeniya, deliteli);  // из исходной строки (при этом разрушая ее!!!). Поэтому я сделал её дубликат (rezerv)
					while (token != NULL)
					{
						if (!strcmp(token, slovo)) { cout << rezerv; j++; }
						token = strtok(NULL, deliteli);
					}
					k = i + 1;
				}
			}

			if (j == 0) cout << endl << "К сожалению, текст не содержит предложений со словом <" << slovo << ">" << endl;
			cout << endl << "--------------------------------------------------------------------------------" << endl;
		}
	}

	system("pause");
	return 0;
}