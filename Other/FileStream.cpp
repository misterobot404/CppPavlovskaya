#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	//библ. для организации ввода-вывода
#define GLAS "AEIOUYaeiouy"  //макросс после которого все нахождения GLAS заменяться на "AEIOUYaeiouy"
#define DELIMITERS  " .,:;\n\t" //макросс после которого все нахождения DELIMITERS заменяться на " .,:;\n\t"
using namespace std;	//пространство имён std

int main()
{
	setlocale(LC_ALL, "rus"); //ввод руской локали для консоли
	FILE * f; // указатель на объект типа FILE, который идентифицирует поток, из которого будут считываются символы
	char line[500], *word; //line для записи туда всех символов из потока, word для записи слов
	if ((f = fopen("text.txt", "rt")) == NULL) { //открывает text.txt для чтения и записивает указатель потока в f, если не удалось открыть файл то (ниже)
		cout<<"file error" <<endl; 
		system("pause"); //останавливает выполнение, до нажатии клавиши
		return 1; //Программа завершается (возвращет главной функции 1)
	}
	while (fgets(line, 500, f) != NULL) //line - указатель на массив типа char, в который сохраняются считанные символы
										//500 - максимальное количество символов для чтения, включая нулевой символ
										//f - указатель на объект типа FILE, который идентифицирует поток, из которого считываются символы
										//цикл извлекает из потока f по 500 символов и записывает из в line..в данном случае он выполнится один раз
	{
		word = strtok(line, DELIMITERS); //разделение строки line на лексемы символами разделителями DELIMITERS, запись всех найденных лексем в word // лексемы представляют собой последовательности символов, разделенных символами разделителями
		while (word != NULL)	//пока есть лексемы
		{
			if (strchr(GLAS, word[0]) && strchr(GLAS, word[strlen(word) - 1])) //проверка первой и последней буквы лексемы на гласность 
				cout << word << endl; //если да выводим лексему
			word = strtok(NULL, DELIMITERS); //переход к следующей лексеме
		}
	}
	fclose(f); //закрываем поток
	system("pause");
	return 0;
}