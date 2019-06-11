/*
Описать класс, реализующий бинарное дерево, обладающее возможностью:
1) добавления новых элементов,
2) удаления существующих,
3) поиска элемента по ключу,
4) последовательного доступа ко всем элементам,
5) создания словаря из файла и с клавиатуры.
Написать программу, использующую этот класс для представления англо - русского словаря.
Программа должна содержать меню, позволяющее выполнить проверку всех методов класса.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
struct node
{
	string Key;
	string Count;
	node* Left;
	node* Right;
};

class TREE
{
private:
	node* Tree; //Указатель на корень дерева.
	void Search(string, string, node**);
public:
	TREE()
	{
		Tree = NULL;
	}
	node** GetTree()
	{
		return &Tree;
	} //Получение вершины дерева.
	node* GetTreee()
	{
		return Tree;
	} //Получение вершины дерева.
	void BuildTree();
	node* pairRemove(string, string, node*);
	void searchPair(string, node**);
	void VyvodPair(node**, int);
	void to_file(node*, ofstream&);
	void from_file();
};
void TREE::BuildTree()
{
	string Key;
	string Count;
	cout << "Английское слово: "; cin >> Key;
	cout << "Русское слово: "; cin >> Count;
	Search(Key, Count, &Tree);
}
node* TREE::pairRemove(string key, string count, node* Node)
{
	if (Node == NULL)
		return Node;

	if (key == Node->Key) {
		node* tmp;
		if (Node->Right == NULL)
		{
			tmp = Node->Left;
		}
		else {
			node* ptr = Node->Right;
			if (ptr->Left == NULL) {
				ptr->Left = Node->Left;
				tmp = ptr;

			}
			else {
				node* pmin = ptr->Left;
				while (pmin->Left != NULL) {
					ptr = pmin;
					pmin = ptr->Left;
				}
				ptr->Left = pmin->Right;
				pmin->Left = Node->Left;
				pmin->Right = Node->Right;
				tmp = pmin;
			}
		}
		if (Tree == Node)
		{
			Tree = tmp;
		}
		delete Node;
		return tmp;
	}
	else if (key < Node->Key)
		Node->Left = pairRemove(key, count, Node->Left);
	else
		Node->Right = pairRemove(key, count, Node->Right);
	return Node;
}
void TREE::Search(string key, string count, node** p)
{
	if (*p == NULL)
	{
		*p = new(node);
		(**p).Key = key; (**p).Count = count;
		(**p).Left = NULL; (**p).Right = NULL;
	}
	else
		if (key < (**p).Key) Search(key, count, &((**p).Left));
		else
			if (key > (**p).Key) Search(key, count, &((**p).Right));
			else if ((**p).Key == key) Search(key, count, &((**p).Right));
}
void TREE::searchPair(string key, node** w)
{
	if (*w != NULL)
	{
		if ((**w).Key == key)
		{
			cout << (**w).Key << "-" << (**w).Count << endl;
		}
		searchPair(key, &(**w).Right);
		searchPair(key, &(**w).Left);
	}
}
void TREE::VyvodPair(node** w, int l)
{
	int i;
	if (*w != NULL)
	{
		VyvodPair(&((**w).Right), l + 1);
		for (i = 1; i <= l; i++) cout << "           ";
		cout << (**w).Key << "-" << (**w).Count << endl;
		VyvodPair(&((**w).Left), l + 1);
	}
}
void TREE::to_file(node* w, ofstream &out)
{
	if (w != NULL)
	{
		out << w->Key;
		out << endl;
		out << w->Count;
		out << endl;
		to_file((*w).Right, out);
		to_file((*w).Left, out);
	}
}
void TREE::from_file()
{
	ifstream in("database.txt");
	string eng;
	string rus;
	while (getline(in, eng) && getline(in, rus))
	{
		Search(eng, rus, &Tree);
	};
	cout << "Данные успешно загружены из файла" << endl;
}
int main()
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251. Нужно только будет изменить шрифт консоли на Lucida Console или Consolas
	TREE A;
	string eng;
	string rus;
	char key;
	while (true)
	{
		cout << endl;
		cout << "Англо-русский словарь" << endl
			<< "Выберите действие:" << endl
			<< "1. Добавить пару." << endl
			<< "2. Удалить пару." << endl
			<< "3. Найти пары по ключу." << endl
			<< "4. Вывод словаря {англ-рус}." << endl
			<< "5. Сохранить словать в файл." << endl
			<< "6. Загрузить словарь из файла." << endl
			<< "7. Выход." << endl
			<< ">";
		cin >> key;
		switch (key)
		{
		case '1':
			A.BuildTree();
			break;
		case '2':
			cout << "Введите английское слово: "; cin >> eng;
			cout << "Введите русское слово: "; cin >> rus;
			A.pairRemove(eng, rus, A.GetTreee());
			break;
		case '3':
			cout << "Введите английское слово: "; cin >> eng;
			A.searchPair(eng, A.GetTree());
			break;
		case '4':
			cout << "\nВывод бинарного дерева:\n";
			A.VyvodPair(A.GetTree(), 0);
			break;
		case '5':
		{
			ofstream out("database.txt", ios_base::trunc);
			A.to_file(A.GetTreee(), out);
			cout << "Данные о работниках сохранены в файл database.txt (найти его можно в папке проекта)" << endl;
			cout << "Открыть файл с сотрудниками?\n1. Да\n2. Нет" << endl;
			char a;
			cin >> a;
			if (a == '1')
			{
				ShellExecute(0, 0, "notepad.exe", "database.txt", 0, SW_SHOW);
			}
		}
			break;
		case '6':
			A.from_file();
			break;
		case '7':
			exit(1);
			break;
		}
	}
	return 0;
}