#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ListNode
{
public:
	T value;
	ListNode<T>* next;
	ListNode<T>* prev;
public:
	ListNode(T data)
	{
		value = data;
		next = 0;
		prev = 0;
	}
};

template <typename T>
class List
{
private:
	ListNode<T>* _pBegin;
	ListNode<T>* _pEnd;
	unsigned int _size;

	static const int defaultValue = 0;
public:
	List();
	List(int size);
	List(int size, T data);
	ListNode<T>* back(); //��������� �� �����
	ListNode<T>* begin(); // ��������� �� ������
	bool empty(); // �������� �� �������
	ListNode<T>* erase(ListNode<T>* pWhere); // ������� ����
	ListNode<T>* find(T data); // ����� ������ ����, ���������� data
	ListNode<T>* insertBefore(ListNode<T>* Where, T data); // ������� ��
	ListNode<T>* insert�fter(ListNode<T>* Where, T data); // ������� �����
	void assign(T data);
	void output(); // �����
	bool pop_back(); // �������� � �����
	bool pop_front(); // �������� � ������
	void push_back(T data); // ���������� � �����
	void push_front(T data); // ���������� � ������
	void remove(T data); // ������� ��� ����, ���������� ����� data
	void resize(unsigned int newLen); // �������� ������
	unsigned int size(); // ������ ������
private:
	inline void Next(ListNode<T>** pCurNode)
	{
		*pCurNode = (*pCurNode)->next;
	}
	inline void Prev(ListNode<T>** pCurNode)
	{
		*pCurNode = (*pCurNode)->prev;
	}
};

template<typename T>
List<T> ::List() :_pBegin(NULL),
_pEnd(NULL),
_size(0)
{
}
template<typename T>
List<T>::List(int size) : _pBegin(NULL),
_pEnd(NULL),
_size(0)
{
	resize(size);
}
template<typename T>
List<T>::List(int size, T data) :_pBegin(NULL),
_pEnd(NULL),
_size(0)
{
	resize(size);
	assign(data);
}
template<typename T>
ListNode<T>* List<T>::back()
{
	return _pEnd;
}
template<typename T>
ListNode<T>* List<T>::begin()
{
	return _pBegin;
}
template<typename T>
bool List<T>::empty()
{
	return _size == 0;
}
template<typename T>
ListNode<T>* List<T>::erase(ListNode<T>* pWhere)
{
	if (pWhere == NULL)
		return false;

	if (pWhere == _pBegin)
		Next(&_pBegin);
	else if (pWhere == _pEnd)
		Prev(&_pEnd);

	ListNode<T>* pPrevNode = pWhere->prev;
	ListNode<T>* pNextNode = pWhere->next;
	if (pNextNode)
		pNextNode->prev = pPrevNode;
	if (pPrevNode)
		pPrevNode->next = pNextNode;

	delete pWhere;
	_size--;
	return pNextNode;
}
template<typename T>
ListNode<T>* List<T>::find(T data)
{
	ListNode<T>* cur = NULL;
	for (cur = _pBegin; cur; Next(&cur))
		if (cur->value == data)
			break;
	return cur;
}
template<typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T>* pWhere, T data)
{
	if (pWhere == NULL && _size != 0) // ����������� ���������
		return NULL;

	ListNode<T>* pNewNode = new ListNode<T>(data);

	if (pWhere == NULL && _size == 0) // ������ ����
	{
		_pBegin = pNewNode;
		_pEnd = pNewNode;
	}
	else
	{
		// ���� ���������� ����
		if (pWhere->prev)
		{
			ListNode<T>* pPrevNode = pWhere->prev;
			pPrevNode->next = pNewNode;
			pNewNode->prev = pPrevNode;
			pNewNode->next = pWhere;
			pWhere->prev = pNewNode;
		}
		// Where = _pBegin
		else
		{
			_pBegin->prev = pNewNode;
			pNewNode->next = _pBegin;
			_pBegin = pNewNode;
		}
	}
	_size++;
	return pNewNode;
}
template<typename T>
ListNode<T>* List<T>::insert�fter(ListNode<T>* Where, T data)
{
	if (Where == NULL && _size != 0) // ������������ ���������
		return NULL;

	ListNode<T>* pNewNode = new ListNode<T>(data);
	if (Where == NULL && _size == 0)
	{
		_pBegin = pNewNode;
		_pEnd = pNewNode;
	}
	else
	{
		// ���� ��������� �������
		if (Where->next)
		{
			ListNode<T>* pNextNode = Where->next;
			Where->next = pNewNode;
			pNewNode->prev = Where;
			pNewNode->next = pNextNode;
			pNextNode->prev = pNewNode;
		}
		// Where = _pEnd
		else
		{
			_pEnd->next = pNewNode;
			pNewNode->prev = _pEnd;
			_pEnd = pNewNode;
		}
	}
	_size++;
	return pNewNode;
}
template<typename T>
void List<T>::assign(T data)
{
	for (ListNode<T>* cur = _pBegin; cur; Next(&cur))
		cur->value = data;
}
template<typename T>
void List<T>::output()
{
	for (ListNode<T>* cur = _pBegin; cur; Next(&cur))
		cout << cur->value << ' ';
	cout << endl;
}
template<typename T>
bool List<T>::pop_back()
{
	if(empty()) throw underflow_error("����������: ��� �������� ���������� �������� ������ ��������� ������. ������ ����.");
	return erase(_pEnd);
}
template<typename T>
bool List<T>::pop_front()
{
	return erase(_pBegin);
}
template<typename T>
void List<T>::push_back(T data)
{
	insert�fter(_pEnd, data);
}
template<typename T>
void List<T>::push_front(T data)
{
	insertBefore(_pBegin, data);
}
template<typename T>
void List<T>::remove(T data)
{
	bool nodesExist = false;;
	for (ListNode<T>* cur = _pBegin; cur;)
		if (cur->value == data)
		{
			cur = erase(cur);
			nodesExist = true;
		}
		else
			Next(&cur);
	if(!nodesExist) throw underflow_error("����������: ��������� ������� �����������.");
}
template<typename T>
void List<T>::resize(unsigned int newLen)
{
	if (_size > newLen)
		while (_size != newLen)
			pop_back();
	else if (_size < newLen)
		while (_size != newLen)
			push_back(defaultValue);
}
template<typename T>
unsigned int List<T>::size()
{
	return _size;
}
