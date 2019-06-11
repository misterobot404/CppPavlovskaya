#include "Figures.h"

class FactoryQuadrate {
public:
	FactoryQuadrate() {}
	void addObject();
	void deleteObject();
	Quadrate quadrate_;
};

class FactoryTriangle {
public:
	FactoryTriangle() {}
	void addObject();
	void deleteObject();
	Triangle pentagon_;
};
