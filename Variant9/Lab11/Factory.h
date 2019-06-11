#include <vector>
#include "SymbString.h"
#include "HexString.h"

class FactorySymbString {
public:
	FactorySymbString() {}
	void addObject(string);
	void addObject(SymbString);
	void deleteObject();
	void printContainer();
private:
	vector <SymbString> symbStringContainers_;
};

class FactoryHexString {
public:
	FactoryHexString() {}
	void addObject(string);
	void addObject(HexString);
	void deleteObject();
	void printContainer();
private:
	vector <HexString> hexStringContainers_;
};
