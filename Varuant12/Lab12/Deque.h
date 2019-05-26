#pragma once
#include "Vect.h"

template < typename T, typename Container = Vect<T> >
class Deque : public Vect <T>
{
private:
	Container container_;
public:
	explicit Deque(const Container& container = Container())
		: container_(container)
	{
	}
	bool empty() const;
	void push_begin(T* _P, const T& _x);
	void pop_begin(); // удаление элемента из конца вектора
};

template<typename T, typename Container>
bool Deque<T, Container>::empty() const
{
	return container_.size() == 0 ? true : false;
}

template<typename T, typename Container>
void Deque<T, Container>::push_begin(T* _P, const T& _x)
{
	Deque<T, Container>::insert(_P, _x);
}

template<typename T, typename Container>
void Deque<T, Container>::pop_begin()
{
	if (this->last == this->first) 
		throw underflow_error("Исключение: При удалении элемента очереди произошла ошибка. Двусторонняя очередь пуста.");;

	size_t n = this->size() - 1; // новый размер
	T* new_first = new T[n * sizeof(T)];
	T* new_last = new_first + n;
	for (size_t i = 0; i < n; ++i)*
		(new_first + i) = *(this->first + i + 1);
	this->Destroy();
	this->first = new_first;
	this->last = new_last;
}


