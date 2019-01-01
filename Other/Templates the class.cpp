
//������� ������ ������ ����������������� �������� ������.
//������������ ��� ��� ������� ������ 3 �� ������� ������������� ��������� �������(��.���������� � ������ �����).

// ������� 3 ��������� ���������, ������� �������� ������� ���������� � ������� �� ����������.
// ������ ������ ��������: 
//� ����� ����������; 
//� ����� �����; 
//� ������� � �������� ���������; 
//� �������� ���� ������. 
// ��������� ������ ������������: 
//� �������� ���� ������ � ���� ������; 
//� ���������� ������ � ������; 
//� �������� ������; 
//� ����� ������ �� ��������� ������ ����� � ���� ������; 
//� ����� ���� ������.

#include <iostream>
#include <clocale>
#include <iomanip>
#include <string>
using namespace std;

template<class Type>
struct ListNode {
	Type        data;   // ������.
	ListNode*   next;   // ������ �� ����. �������.
};

struct RequestData {
	string destination; // ����� ����������.
	string reisNumber;  // ����� �����.
	string fullName;    // ���.
	string date;        // ����.

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
	ListNode<RequestData>*  _tail;  // ��������� �� ����� ������.
	ListNode<RequestData>*  _head;  // ��������� �� ������ ������.
public:
	List() : _tail(NULL), _head(NULL) { }
	~List() { Del(); }

	int GetMenuKey(void);   // ������� ��������� ����������������� ������.
	void CoutOne();         // ������� ������ �������� �� ������ � ���� ������.
	void CoutAll();         // ������� ������ ����� ������.
	void Add();             // ������� ���������� ��������.
	void Del(void);         // ������� ������.
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	List    list;   // ������ �������.
	short   key;    // ���������� ��� ����.

					/* ���� ������������. */
	while ((key = list.GetMenuKey()) != 0) {
		switch (key) {
		case 1: list.Add(); break;
		case 2: list.CoutAll(); break;
		case 3: list.Del(); break;
		case 4: list.CoutOne(); break;
		case 5: break;
		default: cout << "������� �� 1 �� 5" << endl; break;
		}
	}
	return 0;
}
/************** ����������� **************/
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
	return key; // ������� ���������� ��������, ������� ������ ������������.
}
void List::CoutOne()
{
	/* ���� ������������� ������ ����� � ���� ������: */
	string num;
	cout << "Enter number reisa:" << "\n";
	cin >> num;
	string d;
	cout << "Enter date vilita (DD.MM.YY):" << "\n";
	cin >> d;
	cout << endl;

	int count = 0;
	// ���� ��������� ���������.
	for (ListNode<RequestData>* t = _head; t->next != NULL; t = t->next) {
		RequestData data = t->data;
		// ������� ������ ��������.
		if ((data.reisNumber == num) && (data.date == d)) {
			/* � ������ ���������� ��������� �������: */
			cout << "Zayvka naidena:" << "\n";
			cout << "Punkt naznachenia:" << setw(8) << "Reis:" << setw(13)
				<< "FIO:" << setw(15) << "Date vilita:" << endl;
			cout << setw(17) << data.destination << setw(8) << data.reisNumber << setw(13)
				<< data.fullName << setw(15) << data.date << "\t" << "\n" << endl;
			++count; // ������� ���������� ��������� ������.
		}
	}

	if (!count) // ���� ������ �� �������.
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
	/*���������� ������ ��������:*/
	cout << "������� ����� ����������:" << endl;
	cin >> node.destination;
	cout << "������� ����� �����:" << endl;
	cin >> node.reisNumber;
	cout << "������� ��� ���������:" << endl;
	cin >> node.fullName;
	cout << "������� ���� ������ (� ������� DD.MM.YY):" << endl;
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