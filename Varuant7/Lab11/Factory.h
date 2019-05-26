#include <vector>
#include "SymbString.h"
#include "DecString.h"

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

class FactoryDecString {
public:
	FactoryDecString() {}
	void addObject(string);
	void addObject(DecString);
	void deleteObject();
	void printContainer();
private:
	vector <DecString> decStringContainers_;
};
