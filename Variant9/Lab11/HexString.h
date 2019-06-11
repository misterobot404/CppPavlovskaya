#include <iostream>
#include <string>
using namespace std;

class HexString
{
	friend class FactoryHexString;
public:
	static int HexString_ID_SEQUENCE;
	HexString() { id_ = HexString_ID_SEQUENCE++; }
	HexString(string str) { id_ = HexString_ID_SEQUENCE++; string_ = str; }
	void printObject();
	friend const HexString operator+(const HexString& left, const HexString& right);
private:
	int id_;
	string string_;
};

