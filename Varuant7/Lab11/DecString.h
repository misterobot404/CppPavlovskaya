#include <iostream>
#include <string>
using namespace std;

class DecString
{
	friend class FactoryDecString;
public:
	static int DecString_ID_SEQUENCE;
	DecString() { id_ = DecString_ID_SEQUENCE++; }
	DecString(string str) { id_ = DecString_ID_SEQUENCE++; string_ = str; }
	void printObject();
	friend const DecString operator+(const DecString& left, const DecString& right);
private:
	int id_;
	string string_;
};