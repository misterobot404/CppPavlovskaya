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
		auto a = symbStringContainers_.size() - 1;
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

void FactoryHexString::addObject(string str) {
	HexString symbString(str);
	hexStringContainers_.push_back(symbString);
}
void FactoryHexString::addObject(HexString symbString)
{
	hexStringContainers_.push_back(symbString);
}
void FactoryHexString::deleteObject() {
	if (!hexStringContainers_.empty())
	{
		auto a = hexStringContainers_.size() - 1;
		hexStringContainers_.erase(hexStringContainers_.begin() + a);
		cout << "Последний созданный объект удалён" << endl;
	}
	else cout << "Объекты не найдены" << endl;
}
void FactoryHexString::printContainer()
{
	if (!hexStringContainers_.empty())
	{
		for (HexString var : hexStringContainers_)
		{
			var.printObject();
			cout << endl;
		}
	}
	else cout << "Список объектов пуст" << endl;
}
