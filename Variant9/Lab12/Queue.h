#pragma once
#include "Vect.h"

template < typename T, typename Container = Vect<T> >
class Queue : public Vect <T>
{
private:
	Container container_;
public:
	explicit Queue(const Container& container = Container())
		: container_(container)
	{
	}
	bool empty() const;
	void push_begin(T* _P, const T& _x);
	void pop_begin(); // удаление элемента из конца вектора
	void show();
};

template<typename T, typename Container>
bool Queue<T, Container>::empty() const
{
	return this->size() == 0 ? true : false;
}

template<typename T, typename Container>
void Queue<T, Container>::push_begin(T* _P, const T& _x)
{
	Queue<T, Container>::insert(_P, _x);
}

template<typename T, typename Container>
void Queue<T, Container>::pop_begin()
{
	if (this->last == this->first)
		throw underflow_error("Исключение: При удалении элемента очереди произошла ошибка. Очередь пуста.");;

	size_t n = this->size() - 1; // новый размер
	T* new_first = new T[n * sizeof(T)];
	T* new_last = new_first + n;
	for (size_t i = 0; i < n; ++i)*
		(new_first + i) = *(this->first + i + 1);
	this->Destroy();
	this->first = new_first;
	this->last = new_last;
}

template<typename T, typename Container>
inline void Queue<T, Container>::show()
{
	if (this->size() > 0)
	{
		size_t n = this->size();
		for (size_t i = 0; i < n; ++i)
			cout << *(this->first + i) << " ";
	}
	else
	{
		cout << "void";
	}

	cout << endl;
}