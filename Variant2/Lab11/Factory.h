#include <vector>
#include "SymbString.h"
#include "BinString.h"

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

class FactoryBinString {
public:
	FactoryBinString() {}
	void addObject(string);
	void addObject(BinString);
	void deleteObject();
	void printContainer();
private:
	vector <BinString> decStringContainers_;
};


