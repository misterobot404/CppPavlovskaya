#pragma once
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
using namespace std;

template < typename T, typename Container = std::list<T> >
class Queue
{
private:
	Container container_;
public:
	explicit Queue(const Container& container = Container())
		: container_(container)
	{
	}
	// ������ � �������
	T front();
	// ��������� � �������
	T back();
	void push_back(const T& item);
	void pop_front();
	void show();
	int size();
	bool empty() const;
};

template<typename T, typename Container>
inline T Queue<T, Container>::front()
{
	return container_.front();
}
template<typename T, typename Container>
inline T Queue<T, Container>::back()
{
	return container_.back();
}
template<typename T, typename Container>
void Queue<T, Container>::push_back(const T& item)
{
	container_.push_back(item);
}
template<typename T, typename Container>
void Queue<T, Container>::pop_front()
{
	if (container_.empty()) throw std::underflow_error("����������: ��� �������� ���������� �������� ������� ��������� ������. ������� �����.");
	container_.pop_front();
}
template<typename T, typename Container>
inline void Queue<T, Container>::show()
{
	for (auto el : container_)
	{
		cout << el << " ";
	}
	cout << endl;
}
template<typename T, typename Container>
inline int Queue<T, Container>::size()
{
	return container_.size();
}
template<typename T, typename Container>
bool Queue<T, Container>::empty() const
{
	return container_.empty();
}