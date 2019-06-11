#include "DoubleList.h"

DoubleList::DoubleList(int value) :List(value)
{
	myPrevus = 0;
	/*
   ������ ������ DoubleList-������� �� ����� ����� � �����,�������:
   ������� �������� �������� ����������� �������� ������(List), ����� ����
   �������� �������� ����������� ������������ ������(DoubleList)...
   ����������� ����� ���������� � �������� �������...
	*/
}
DoubleList::~DoubleList()
{
	if (myPrevus != 0)
		delete myPrevus;
	// ������� ��������� ������ ���  myPrevus
}
void DoubleList::push_back(int value)
{
	DoubleList* arrant = this;
	while (arrant->myNext != 0)
	{
		arrant = (DoubleList*)arrant->myNext;  //��� ����� ���� ���������� �����
	}
	arrant->myNext = new DoubleList(value);   //���������� ��� � List                                         
	((DoubleList*)arrant->myNext)->myPrevus = arrant;
	/*
	  ���������� arrant(������� ��������� �� ������������� �������) ���� � �������� �������(arrant->myNext),
	  ����� �������� ����, ����� �������� ��������� �� NULL(myPrevus) � ��������� ��� ����� ���������
	  arrant ������� ����� �� ��������� �� ������������� �������...
	  ��� �������� ��������� �� ���������� �������....
	*/
}
void  DoubleList::pop_back()
{

	DoubleList* arrant = this;                    //�� ������
	int counter = 0;                         //������� ����� ����������� �� ������������� ��������
	while (counter < arrant->lentgh() - 1)
	{
		arrant = (DoubleList*)arrant->myNext;
		++counter;
	}
	DoubleList* carrant = (DoubleList*)arrant->myNext;         //��������� ����� �� ��������� �������
	arrant->myNext = 0;       //����� ���������
	carrant->myPrevus = 0;      //����� ��������� ���������� �������� �� arrant
	delete carrant;           //������������ ������ ���������� ��������� ��������� �������
}
