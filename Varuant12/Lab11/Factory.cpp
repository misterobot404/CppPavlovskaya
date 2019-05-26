#include "Factory.h"

void FactoryQuadrate::addObject() {
	quadrate_.Input();
}
void FactoryQuadrate::deleteObject() {
	quadrate_.Delete();
}

void FactoryPentagon::addObject() {
	pentagon_.Input();
}
void FactoryPentagon::deleteObject() {
	pentagon_.Delete();
}