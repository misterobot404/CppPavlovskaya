#include "SymbString.h"
void SymbString::printObject() {
	cout << "Идентификатор объекта: ID" << id_ << endl;
	cout << "Значение объекта: " << string_ << endl;
}

const SymbString operator+(const SymbString& left, const SymbString& right)
{
	SymbString symbString;
	symbString.string_ = left.string_ + right.string_;
	return symbString;
}

int SymbString::SymbString_ID_SEQUENCE = 0;

