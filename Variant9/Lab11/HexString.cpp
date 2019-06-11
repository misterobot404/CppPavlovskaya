#include "HexString.h"

void HexString::printObject() {
	cout << "Идентификатор объекта: ID" << id_ << endl;
	cout << "Значение объекта: " << string_ << endl;
}

const HexString operator+(const HexString& left, const HexString& right)
{
	HexString hexString;
	int num1 = stoi(left.string_, 0, 16);
	int num2 = stoi(right.string_, 0, 16);

	string hexBase = "0123456789ABCDEF";

	int resDec = num1 + num2;
	string resHex;

	while (resDec > 0)
	{
		resHex = hexBase[resDec % 16] + resHex;
		resDec /= 16;
	}

	hexString.string_ = resHex;
	return hexString;
}

int HexString::HexString_ID_SEQUENCE = 0;