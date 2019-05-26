#include "Factory.h"

void FactorySymbString::addObject(string str) {
	SymbString symbString(str);
	symbStringContainers_.push_back(symbString);
}
void FactorySymbString::addObject(SymbString symbString)
{
	symbStringContainers_.push_back(symbString);
}
void FactorySymbString::deleteObject() {
	if (!symbStringContainers_.empty())
	{
		auto a =  symbStringContainers_.size() - 1;
		symbStringContainers_.erase(symbStringContainers_.begin() + a);
		cout << "Последний созданный объект удалён" << endl;
	}
	else cout << "Объекты не найдены" << endl;
}
void FactorySymbString::printContainer()
{
	if (!symbStringContainers_.empty())
	{
		for (SymbString var : symbStringContainers_)
		{
			var.printObject();
			cout << endl;
		}
	}
	else cout << "Список объектов пуст" << endl;
}

void FactoryDecString::addObject(string str) {
	DecString symbString(str);
	decStringContainers_.push_back(symbString);
}
void FactoryDecString::addObject(DecString symbString)
{
	decStringContainers_.push_back(symbString);
}
void FactoryDecString::deleteObject() {
	if (!decStringContainers_.empty())
	{
		auto a = decStringContainers_.size() - 1;
		decStringContainers_.erase(decStringContainers_.begin() + a);
		cout << "Последний созданный объект удалён" << endl;
	}
	else cout << "Объекты не найдены" << endl;
}
void FactoryDecString::printContainer()
{
	if (!decStringContainers_.empty())
	{
		for (DecString var : decStringContainers_)
		{
			var.printObject();
			cout << endl;
		}
	}
	else cout << "Список объектов пуст" << endl;
}