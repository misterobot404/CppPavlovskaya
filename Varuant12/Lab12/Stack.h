#pragma once
#include "Vect.h"

template < typename T, typename Container = Vect<T> >
class Stack
{
private:
	Container container_;
public:
	explicit Stack(const Container& container = Container())
		: container_(container)
	{
	}
	void push(const T& item);
	void pop();
	T& top();
	const T& top() const;
	bool empty() const;
};

template<typename T, typename Container>
void Stack<T, Container>::push(const T& item)
{
	container_.push_back(item);
}

template<typename T, typename Container>
void Stack<T, Container>::pop()
{
	if (container_.empty()) throw underflow_error("Исключение: При удалении последнего элемента стека произошла ошибка. Стек пуст.");
	container_.pop_back();
}

template<typename T, typename Container>
T& Stack<T, Container>::top()
{
	if (container_.empty()) throw underflow_error("Исключение: При установки ссылки на последний элемента стека произошла ошибка. Стек пуст.");
	return container_.back();
}

template<typename T, typename Container>
inline const T& Stack<T, Container>::top() const
{
	if (container_.empty()) throw underflow_error("Исключение: При установки ссылки на последний элемента стека произошла ошибка. Стек пуст.");
	return container_.back();
}

template<typename T, typename Container>
bool Stack<T, Container>::empty() const
{
	return container_.empty();
}

