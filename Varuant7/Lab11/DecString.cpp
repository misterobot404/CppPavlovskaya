#include "DecString.h"

void DecString::printObject() {
	cout << "Идентификатор объекта: ID" << id_ << endl;
	cout << "Значение объекта: " << string_ << endl;
}

const DecString operator+(const DecString& left, const DecString& right)
{
	DecString decString;
	double d1 = atof(left.string_.c_str());
	double d2 = atof(right.string_.c_str());
	double d = d1 + d2;
	decString.string_ = to_string(d);
	return decString;
}

int DecString::DecString_ID_SEQUENCE = 0;