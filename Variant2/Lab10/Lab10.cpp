/*
������� �����, ����������� �������� ������, ���������� ������������:
1) ���������� ����� ���������,
2) �������� ������������,
3) ������ �������� �� �����,
4) ����������������� ������� �� ���� ���������,
5) �������� ������� �� ����� � � ����������.
�������� ���������, ������������ ���� ����� ��� ������������� ����� - �������� �������.
��������� ������ ��������� ����, ����������� ��������� �������� ���� ������� ������.
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
	node* Tree; //��������� �� ������ ������.
	void Search(string, string, node**);
public:
	TREE()
	{
		Tree = NULL;
	}
	node** GetTree()
	{
		return &Tree;
	} //��������� ������� ������.
	node* GetTreee()
	{
		return Tree;
	} //��������� ������� ������.
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
	cout << "���������� �����: "; cin >> Key;
	cout << "������� �����: "; cin >> Count;
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
	cout << "������ ������� ��������� �� �����" << endl;
}
int main()
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251. ����� ������ ����� �������� ����� ������� �� Lucida Console ��� Consolas
	TREE A;
	string eng;
	string rus;
	char key;
	while (true)
	{
		cout << endl;
		cout << "�����-������� �������" << endl
			<< "�������� ��������:" << endl
			<< "1. �������� ����." << endl
			<< "2. ������� ����." << endl
			<< "3. ����� ���� �� �����." << endl
			<< "4. ����� ������� {����-���}." << endl
			<< "5. ��������� ������� � ����." << endl
			<< "6. ��������� ������� �� �����." << endl
			<< "7. �����." << endl
			<< ">";
		cin >> key;
		switch (key)
		{
		case '1':
			A.BuildTree();
			break;
		case '2':
			cout << "������� ���������� �����: "; cin >> eng;
			cout << "������� ������� �����: "; cin >> rus;
			A.pairRemove(eng, rus, A.GetTreee());
			break;
		case '3':
			cout << "������� ���������� �����: "; cin >> eng;
			A.searchPair(eng, A.GetTree());
			break;
		case '4':
			cout << "\n����� ��������� ������:\n";
			A.VyvodPair(A.GetTree(), 0);
			break;
		case '5':
		{
			ofstream out("database.txt", ios_base::trunc);
			A.to_file(A.GetTreee(), out);
			cout << "������ � ���������� ��������� � ���� database.txt (����� ��� ����� � ����� �������)" << endl;
			cout << "������� ���� � ������������?\n1. ��\n2. ���" << endl;
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