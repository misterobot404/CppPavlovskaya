#include "BinString.h"

void BinString::printObject() {
	cout << "Идентификатор объекта: ID" << id_ << endl;
	cout << "Значение объекта: " << string_ << endl;
}

const BinString operator+(const BinString& left, const BinString& right)
{
	BinString decString;
	int len1 = left.string_.size();
	int len2 = right.string_.size();
	// Выровняем длины строк
	string ls1 = len1 < len2 ? left.string_ : right.string_;
	string ls2 = len1 < len2 ? right.string_ : left.string_;
	for (int i = ls1.size(); i < ls2.size(); ++i) ls1 = '0' + ls1;

	string result;
	int carry = 0;
	for (int i = ls2.size() - 1; i >= 0; --i) {
		int bit1 = ls1.at(i) - '0'; // '0' => 0, '1' => 1
		int bit2 = ls2.at(i) - '0';
		char sum = (bit1 ^ bit2 ^ carry) + '0';
		result = sum + result;
		carry = (bit1 & carry) | (bit2 & carry) | (bit1 & bit2);
	}
	if (carry) result = '1' + result;

	decString.string_ = result;
	return decString;
}

int BinString::DecString_ID_SEQUENCE = 0;