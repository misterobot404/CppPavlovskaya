/*
Создать шаблон класса «бинарное дерево».
Использовать его при решении задачи 2 из раздела «Динамические структуры данных»(см.упражнения к первой части).
Составить программу, которая содержит текущую информацию о книгах в библиотеке. 
Сведения о книгах содержат: 
• номер УДК; 
• фамилию и инициалы автора; 
• название; 
• год издания; 
• количество экземпляров данной книги в библиотеке.
Программа должна обеспечивать: 
• начальное формирование данных о всех книгах в библиотеке в виде двоичного дерева; 
• добавление данных о книгах, вновь поступающих в библиотеку; 
• удаление данных о списываемых книгах; 
• по запросу выдаются сведения о наличии книг в библиотеке, упорядоченные по годам издания.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

template <class Type>
struct node {
	Type udk;
	char fio[25];
	char naz[25];
	int god;
	Type kol;
	node *l, *r;
};

template <class Type>
class BinTree {


public:

	////////////СОЗДАНИЕ КОРНЯ ДЕРЕВА
	node <Type> *first(int udk, char fio[25], char naz[25], int god, int kol)
	{
		node <Type> *pv = new node <Type>;
		pv->udk = udk;
		strcpy(pv->fio, fio);
		strcpy(pv->naz, naz);
		pv->god = god;
		pv->kol = kol;
		pv->l = pv->r = 0;
		return pv;
	}

	////////////ДОБАВЛЯЕМ КНИГУ
	void incer(node <Type> **pv, int udk, char fio[25], char naz[25], int god, int kol)
	{
		if (!(*pv)) {
			node <Type> *pnew = new node <Type>;
			pnew->udk = udk;
			strcpy(pnew->fio, fio);
			strcpy(pnew->naz, naz);
			pnew->god = god;
			pnew->kol = kol;
			pnew->l = pnew->r = 0;
			(*pv) = pnew;
		}
		else if (udk == (*pv)->udk && !strcmp(fio, (*pv)->fio) && !strcmp((*pv)->naz, naz) && god == (*pv)->god)
			(*pv)->kol += kol;
		else if ((*pv)->god > god)
			incer(&((*pv)->l), udk, fio, naz, god, kol);
		else
			incer(&((*pv)->r), udk, fio, naz, god, kol);
	}

	////////////УДАЛЯЕМ ВСЁ ДЕРЕВО
	void delall(node <Type> **p) {
		if (!(*p)) return;
		delall(&((*p)->l));
		(*p)->l = NULL;
		delall(&((*p)->r));
		(*p)->r = NULL;
		(*p) = 0;
	}

	///////////ВЫВОД ДЕРЕВА И СПИСКА КНИГ ПО ГОДАМ ИЗДАНИЯ
	void printT(node <Type> *p)
	{
		if (p) {
			printT(p->l);
			cout << p->udk << "\t" << p->fio << "\t" << p->naz << "\t" << p->god << "\t" << p->kol << endl;
			printT(p->r);
		}
	}

	///////////ВЫВОД ДЕРЕВА
	void printT(node <Type> *p, int level)
	{
		if (p) {
			printT(p->l, level + 1);
			for (int i = 0; i < level; i++)
				cout << "\t";
			cout << p->udk << " - " << p->fio << " - " << p->naz << " - " << p->god << " - " << p->kol << endl;
			printT(p->r, level + 1);
		}
	};

	///////////УДАЛЕНИЕ ОДНОЙ КНИГИ
	node <Type> *delet(node <Type> *root, int udk, char fio[25], char naz[25], int god, int kol)
	{
		node <Type> *P = new node <Type>, *v = new node <Type>;
		if (!root)
			cout << "net takou knigi" << endl;
		else if (udk == root->udk && !strcmp(fio, root->fio) && !strcmp(root->naz, naz) && god == root->god) {
			if (kol >= root->kol) {
				if (!root->r)
					root = root->l;
				else
					if (!root->l) root = root->r;
					else {
						v = root->l;
						while (v->r->r)
							v = v->r;
						root->udk = v->r->udk;
						strcpy(root->fio, v->r->fio);
						strcpy(root->naz, v->r->naz);
						root->god = v->r->god;
						root->kol = v->r->kol;
						P = v->r; v->r = v->r->l;
					}
					free(P);
			}
			else
				root->kol -= kol;
		}
		else if (god < root->god) root->l = delet(root->l, udk, fio, naz, god, kol);
		else if (god >= root->god) root->r = delet(root->r, udk, fio, naz, god, kol);
		return root;
	}

};

int main() {

	setlocale(LC_ALL, "rus");

	BinTree <int>  One;
	char c;
	int udk;
	char fio[25];
	char naz[25];
	int god;
	int kol;

	// Начальное формирование данных обо всех книгах в виде двоичного дерева
	node<int> *root = One.first(123, "Petrov I. G", "cxemotexnika", 2000, 55);
	One.incer(&root, 123, "Petrov I. G.", "cxemotexnika", 2000, 5);
	One.incer(&root, 125, "Ivanov D. A.", "CeTu komp", 1999, 20);
	One.incer(&root, 127, "Sidorov A.L.", "zashita inf", 1998, 33);
	One.incer(&root, 128, "Kyzmeko E.P.", "komp. grafika", 2001, 40);
	One.incer(&root, 134, "Petrov I. G", "cxemotexnika", 2000, 210);

	llp:cout << "Вывод в виде дерева: " << endl;
	cout << endl;
	One.printT(root, 0);
	cout << endl;
	cout << "Книги упорядоченные по годам издания: " << endl;
	cout << endl;
	cout << "УДК" << "\t" << "ФИО автора\t" << "" << "Название" << "\t" << "Год" << "\t" << "Кол-во" << endl;
	One.printT(root);
	cout << endl;

	lop:cout << "Введите номер меню и нажмите <ENTER>: " << endl <<
	"\t1 - Добавить книгу" << endl <<
	"\t2 - Списать книгу" << endl <<
	"\t3 - Вывод книг упорядоченых по годам" << endl <<
	"\t4 - Удаление дерева" << endl <<
	"\t5 - Выход из программы" << endl;
	cin >> c;
	switch (c) {

	case '1':
		cout << "УДК :"; cin >> udk; cin.get();
		cout << "ФИО автора :"; cin.getline(fio, 255);
		cout << "Название :"; cin.getline(naz, 255);
		cout << "Год издания :"; cin >> god;
		cout << "Количество :"; cin >> kol;
		One.incer(&root, udk, fio, naz, god, kol);
		goto lop;

	case '2':
		cout << "УДК :"; cin >> udk; cin.get();
		cout << "ФИО автора :"; cin.getline(fio, 255);
		cout << "Название :"; cin.getline(naz, 255);
		cout << "Год издания :"; cin >> god;
		cout << "Количество :"; cin >> kol;
		One.delet(root, udk, fio, naz, god, kol);
		goto lop;

	case '3':
		goto llp;

	case '4':
		One.delall(&root);
		goto lop;

	case '5':
		break;
	}
	return 0;
}