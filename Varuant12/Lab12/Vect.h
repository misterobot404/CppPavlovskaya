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
	Vect(const Vect&); // конструктор копирования
	Vect& operator =(const Vect&); // операция присваивания
	~Vect() {
		cout << "Destructor of " << markName << endl;
		Destroy();
		first = 0, last = 0;
	}
	void mark(string& name) { markName = name; } // установить отладочное имя
	string mark() const { return markName; } // получить отладочное имя
	size_t size() const; // получить размер вектора
	T* begin() const { return first; } // получить указатель на 1-й элемент
	T* end() const { return last; } // получить указатель на элемент,
	// следующий за последним
	T& operator[](size_t i); // операция индексирования
	void insert(T* _P, const T& _x); // вставка элемента в позицию _P
	void push_back(const T& _x); // вставка элемента в конец вектора
	void pop_back(); // удаление элемента из конца вектора
	void show() const; // вывод в cout содержимого вектора
protected:
	void Allocate(size_t _n) {
		first = new T[_n * sizeof(T)];
		last = first + _n;
	}
	void Destroy() {
		for (T* p = first; p != last; ++p) p->~T();
		delete[] first;
	}
	T* first; // указатель на 1-й элемент
	T* last; // указатель на элемент, следующий за последним
	string markName;
};
template<class T>
Vect<T>::Vect(const Vect& other) { // ------------------- Конструктор копирования
	size_t n = other.size();
	Allocate(n);
	for (size_t i = 0; i < n; ++i)* (first + i) = *(other.first + i);
	markName = string("Copy of ") + other.markName;
	cout << "Copy constructor: " << markName << endl;
}
template<class T>
Vect<T>& Vect<T>::operator =(const Vect& other) { // -------- Операция присваивания
	if (this == &other) return *this;
	Destroy();
	size_t n = other.size();
	Allocate(n);
	for (size_t i = 0; i < n; ++i)* (first + i) = *(other.first + i);
	return *this;
}
template<class T>
size_t Vect<T>::size() const { // ---------------------- Получение размера вектора
	if (first > last) throw VectError();
	return (0 == first ? 0 : last - first);
}
template<class T>
T& Vect<T>::operator[](size_t i) { // ---------------- Операция доступа по индексу
	if (i < 0 || i >(size() - 1))
		throw VectRangeErr(0, last - first - 1, i);
	return (*(first + i));
}
template<class T> // ------------- Вставка элемента со значением _x в позицию _P
void Vect<T>::insert(T* _P, const T& _x) {
	size_t n = size() + 1; // новый размер
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
void Vect<T>::push_back(const T& _x) { // ------- Вставка элемента в конец вектора
	if (!size()) { Allocate(1); *first = _x; }
	else insert(end(), _x);
}
template<class T>
void Vect<T>::pop_back() { // ----------------- Удаление элемента из конца вектора
	if (last == first) throw VectPopErr();
	T* p = end() - 1;
	p->~T();
	last--;
}
template<class T>
void Vect<T>::show() const { // ---------------- Вывод в cout содержимого вектора
	if (size() > 0)
	{
		cout << "Элементы двусторонней очереди:  ";
		size_t n = size();
		for (size_t i = 0; i < n; ++i)
			cout << *(first + i) << " ";
		cout << endl;
		cout << endl;
	}
	else
	{
		cout << "Двухсторонняя очередь пуста";
		cout << endl;
		cout << endl;
	}
}