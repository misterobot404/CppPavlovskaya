
//Создать шаблон класса «однонаправленный линейный список».
//Использовать его при решении задачи 3 из раздела «Динамические структуры данных»(см.упражнения к первой части).

// Вариант 3 Составить программу, которая содержит текущую информацию о заявках на авиабилеты.
// Каждая заявка содержит: 
//• пункт назначения; 
//• номер рейса; 
//• фамилию и инициалы пассажира; 
//• желаемую дату вылета. 
// Программа должна обеспечивать: 
//• хранение всех заявок в виде списка; 
//• добавление заявок в список; 
//• удаление заявок; 
//• вывод заявок по заданному номеру рейса и дате вылета; 
//• вывод всех заявок.

#include <iostream>
#include <clocale>
#include <iomanip>
#include <string>
using namespace std;

template<class Type>
struct ListNode {
	Type        data;   // Данные.
	ListNode*   next;   // Ссылка на след. элемент.
};

struct RequestData {
	string destination; // Пункт назначения.
	string reisNumber;  // Номер рейса.
	string fullName;    // ФИО.
	string date;        // Дата.

	RequestData(const string& destination = "", const string& reisNumber = "", const string& fullName = "", const string& date = "") :
		destination(destination),
		reisNumber(reisNumber),
		fullName(fullName),
		date(date) { }

	RequestData(const RequestData& data) :
		destination(data.destination),
		reisNumber(data.reisNumber),
		fullName(data.fullName),
		date(data.date) { }
};

class List {
private:
	ListNode<RequestData>*  _tail;  // Указатель на конец списка.
	ListNode<RequestData>*  _head;  // Указатель на начало списка.
public:
	List() : _tail(NULL), _head(NULL) { }
	~List() { Del(); }

	int GetMenuKey(void);   // Функция получения пользовательского выбора.
	void CoutOne();         // Функция вывода элемента по номеру и дате вылета.
	void CoutAll();         // Функция вывода всего списка.
	void Add();             // Функция добавления элемента.
	void Del(void);         // Очистка списка.
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	List    list;   // Список заказов.
	short   key;    // Переменная для меню.

					/* Меню пользователя. */
	while ((key = list.GetMenuKey()) != 0) {
		switch (key) {
		case 1: list.Add(); break;
		case 2: list.CoutAll(); break;
		case 3: list.Del(); break;
		case 4: list.CoutOne(); break;
		case 5: break;
		default: cout << "Введите от 1 до 5" << endl; break;
		}
	}
	return 0;
}
/************** Реализациия **************/
int List::GetMenuKey(void)
{
	cout << setfill('=') << setw(50) << "\n";
	cout << "1 - Dobavit' Zayvky" << endl;
	cout << "2 - Vivesti vse zayvki na ekran" << endl;
	cout << "3 - Delete zayvky" << endl;
	cout << "4 - Vivod po nomery reisa" << endl;
	cout << "0 - Closed" << "\n" << setfill('=') << setw(50) << "\n" << endl;
	cout << setfill(' ');
	int key;
	cin >> key;
	cout << "\n";
	return key; // Функция возвращает значение, которое выбрал пользователь.
}
void List::CoutOne()
{
	/* Ввод пользователем номера рейса и даты вылета: */
	string num;
	cout << "Enter number reisa:" << "\n";
	cin >> num;
	string d;
	cout << "Enter date vilita (DD.MM.YY):" << "\n";
	cin >> d;
	cout << endl;

	int count = 0;
	// Цикл просмотра элементов.
	for (ListNode<RequestData>* t = _head; t->next != NULL; t = t->next) {
		RequestData data = t->data;
		// Условие поиска элемента.
		if ((data.reisNumber == num) && (data.date == d)) {
			/* В случае совпадения выводится элемент: */
			cout << "Zayvka naidena:" << "\n";
			cout << "Punkt naznachenia:" << setw(8) << "Reis:" << setw(13)
				<< "FIO:" << setw(15) << "Date vilita:" << endl;
			cout << setw(17) << data.destination << setw(8) << data.reisNumber << setw(13)
				<< data.fullName << setw(15) << data.date << "\t" << "\n" << endl;
			++count; // Счетчик количества найденных заявок.
		}
	}

	if (!count) // Если ничего не найдено.
		cout << "Nichego ne naidena!" << "\n" << endl;
}

void List::CoutAll()
{
	if (!_head)
		return;

	for (ListNode<RequestData>* node = _head; node != NULL; node = node->next) {
		RequestData data = node->data;
		cout << setw(17) << data.destination << setw(8) << data.reisNumber << setw(13) << data.fullName << setw(15) << data.date << "\t" << endl;
	}
}

void List::Del(void)
{
	for (ListNode<RequestData>* node = _head; node != NULL;) {
		ListNode<RequestData>* next = node->next;
		delete node;
		node = next;
	}
	_head = NULL;
	_tail = NULL;
}

void List::Add()
{
	RequestData node;
	/*заполнение нового элемента:*/
	cout << "Введите пункт назначения:" << endl;
	cin >> node.destination;
	cout << "Введите номер рейса:" << endl;
	cin >> node.reisNumber;
	cout << "Введите ФИО пассажира:" << endl;
	cin >> node.fullName;
	cout << "Введите дату вылета (в формате DD.MM.YY):" << endl;
	cin >> node.date;
	cout << "\n";
	ListNode<RequestData>* newNode = new ListNode<RequestData>;
	newNode->data = node;
	newNode->next = NULL;
	if (_tail)
		_tail->next = newNode;
	if (!_head)
		_head = newNode;
	_tail = newNode;
}