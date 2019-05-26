#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class VectError {
public:
	VectError() {}
	virtual void ErrMsg() const { std::cerr << "Error with Vect object.\n"; }
	void Continue() const {
#ifdef DEBUG
		std::cerr << "Debug: program is being continued.\n";
#else
		throw;
#endif
	}
};
class VectRangeErr : public VectError {
public:
	VectRangeErr(int _min, int _max, int _actual) :
		min(_min), max(_max), actual(_actual) {}
	void ErrMsg() const {
		std::cerr << "Error of index: ";
		std::cerr << "possible range: " << min << " - " << max << ", ";
		std::cerr << "actual index: " << actual << std::endl;
		Continue();
	}
private:
	int min, max;
	int actual;
};
class VectPopErr : public VectError {
public:
	void ErrMsg() const { std::cerr << "Error of pop\n"; Continue(); }
};

template<class T> class Vect { // ------------------------ Template class Vect
public:
	explicit Vect() : first(0), last(0), markName("class Deque") {}
	explicit Vect(size_t _n, const T& _v = T()) {
		Allocate(_n);
		for (size_t i = 0; i < _n; ++i)* (first + i) = _v;
	}
	Vect(const Vect&); // ����������� �����������
	Vect& operator =(const Vect&); // �������� ������������
	~Vect() {
		cout << "Destructor of " << markName << endl;
		Destroy();
		first = 0, last = 0;
	}
	void mark(string& name) { markName = name; } // ���������� ���������� ���
	string mark() const { return markName; } // �������� ���������� ���
	size_t size() const; // �������� ������ �������
	T* begin() const { return first; } // �������� ��������� �� 1-� �������
	T* end() const { return last; } // �������� ��������� �� �������,
	// ��������� �� ���������
	T& operator[](size_t i); // �������� ��������������
	void insert(T* _P, const T& _x); // ������� �������� � ������� _P
	void push_back(const T& _x); // ������� �������� � ����� �������
	void pop_back(); // �������� �������� �� ����� �������
	void show() const; // ����� � cout ����������� �������
protected:
	void Allocate(size_t _n) {
		first = new T[_n * sizeof(T)];
		last = first + _n;
	}
	void Destroy() {
		for (T* p = first; p != last; ++p) p->~T();
		delete[] first;
	}
	T* first; // ��������� �� 1-� �������
	T* last; // ��������� �� �������, ��������� �� ���������
	string markName;
};
template<class T>
Vect<T>::Vect(const Vect& other) { // ------------------- ����������� �����������
	size_t n = other.size();
	Allocate(n);
	for (size_t i = 0; i < n; ++i)* (first + i) = *(other.first + i);
	markName = string("Copy of ") + other.markName;
	cout << "Copy constructor: " << markName << endl;
}
template<class T>
Vect<T>& Vect<T>::operator =(const Vect& other) { // -------- �������� ������������
	if (this == &other) return *this;
	Destroy();
	size_t n = other.size();
	Allocate(n);
	for (size_t i = 0; i < n; ++i)* (first + i) = *(other.first + i);
	return *this;
}
template<class T>
size_t Vect<T>::size() const { // ---------------------- ��������� ������� �������
	if (first > last) throw VectError();
	return (0 == first ? 0 : last - first);
}
template<class T>
T& Vect<T>::operator[](size_t i) { // ---------------- �������� ������� �� �������
	if (i < 0 || i >(size() - 1))
		throw VectRangeErr(0, last - first - 1, i);
	return (*(first + i));
}
template<class T> // ------------- ������� �������� �� ��������� _x � ������� _P
void Vect<T>::insert(T* _P, const T& _x) {
	size_t n = size() + 1; // ����� ������
	T* new_first = new T[n * sizeof(T)];
	T* new_last = new_first + n;
	size_t offset = _P - first;
	for (size_t i = 0; i < offset; ++i)* (new_first + i) = *(first + i);
	*(new_first + offset) = _x;
	for (size_t i = offset; i < n; ++i)* (new_first + i + 1) = *(first + i);
	Destroy();
	first = new_first;
	last = new_last;
}
template<class T>
void Vect<T>::push_back(const T& _x) { // ------- ������� �������� � ����� �������
	if (!size()) { Allocate(1); *first = _x; }
	else insert(end(), _x);
}
template<class T>
void Vect<T>::pop_back() { // ----------------- �������� �������� �� ����� �������
	if (last == first) throw VectPopErr();
	T* p = end() - 1;
	p->~T();
	last--;
}
template<class T>
void Vect<T>::show() const { // ---------------- ����� � cout ����������� �������
	if (size() > 0)
	{
		cout << "�������� ������������ �������:  ";
		size_t n = size();
		for (size_t i = 0; i < n; ++i)
			cout << *(first + i) << " ";
		cout << endl;
		cout << endl;
	}
	else
	{
		cout << "������������� ������� �����";
		cout << endl;
		cout << endl;
	}
}