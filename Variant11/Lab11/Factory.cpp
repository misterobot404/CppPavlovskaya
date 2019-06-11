#include "Factory.h"

void FactoryQuadrate::addObject() {
	quadrate_.Input();
}
void FactoryQuadrate::deleteObject() {
	quadrate_.Delete();
}

void FactoryTriangle::addObject() {
	pentagon_.Input();
}
void FactoryTriangle::deleteObject() {
	pentagon_.Delete();
}