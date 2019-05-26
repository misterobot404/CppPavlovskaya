#include "Figures.h"

class FactoryQuadrate {
public:
	FactoryQuadrate() {}
	void addObject();
	void deleteObject();
	Quadrate quadrate_;
};

class FactoryPentagon {
public:
	FactoryPentagon() {}
	void addObject();
	void deleteObject();
	Pentagon pentagon_;
};
