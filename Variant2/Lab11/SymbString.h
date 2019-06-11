#include <iostream>
#include <string>

using namespace std;

class SymbString
{
	friend class FactorySymbString;
public:
	static int SymbString_ID_SEQUENCE;
	SymbString() { id_ = SymbString_ID_SEQUENCE++; }
	SymbString(string str) { id_ = SymbString_ID_SEQUENCE++; string_ = str; }
	void printObject();
	friend const SymbString operator+(const SymbString& left, const SymbString& right);
private:
	int id_;
	string string_;
};


