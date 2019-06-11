#include <iostream>
#include <string>
using namespace std;

class BinString
{
	friend class FactoryDecString;
public:
	static int DecString_ID_SEQUENCE;
	BinString() { id_ = DecString_ID_SEQUENCE++; }
	BinString(string str) { id_ = DecString_ID_SEQUENCE++; string_ = str; }
	void printObject();
	friend const BinString operator+(const BinString& left, const BinString& right);
private:
	int id_;
	string string_;
};

