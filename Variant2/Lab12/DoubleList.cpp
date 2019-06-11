#include "DoubleList.h"

DoubleList::DoubleList(int value) :List(value)
{
	myPrevus = 0;
	/*
   Обьект класса DoubleList-состоит из полей листа и своих,поэтому:
   Сначало начинает работать конструктор базового класса(List), после него
   начинает работать конструктор производного класса(DoubleList)...
   деструкторы будут вызываться в обратном порядке...
	*/
}
DoubleList::~DoubleList()
{
	if (myPrevus != 0)
		delete myPrevus;
	// Удаляем выделеную память под  myPrevus
}
void DoubleList::push_back(int value)
{
	DoubleList* arrant = this;
	while (arrant->myNext != 0)
	{
		arrant = (DoubleList*)arrant->myNext;  //Тут нужно было приведение типов
	}
	arrant->myNext = new DoubleList(value);   //анологично как в List                                         
	((DoubleList*)arrant->myNext)->myPrevus = arrant;
	/*
	  указателем arrant(который указывает на предпоследний элемент) идем в следуший элемент(arrant->myNext),
	  потом вызываем поле, адрес которого указывает на NULL(myPrevus) и присваием ему адрес указателя
	  arrant который опять же указывает на предпоследний элемент...
	  так получаем указатель на превыдуший элемент....
	*/
}
void  DoubleList::pop_back()
{

	DoubleList* arrant = this;                    //На голову
	int counter = 0;                         //счетчик чтобы остановится на предпоследним элементи
	while (counter < arrant->lentgh() - 1)
	{
		arrant = (DoubleList*)arrant->myNext;
		++counter;
	}
	DoubleList* carrant = (DoubleList*)arrant->myNext;         //указателю адрес на последним элемент
	arrant->myNext = 0;       //нулим указатель
	carrant->myPrevus = 0;      //нулим указатель удаленного элемента на arrant
	delete carrant;           //высвобождаем память занимаемую удаленным последним элемент
}
