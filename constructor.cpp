#include "constructor.h"

Constructor::Constructor() {
	arguements = new Array<ArguementInstance*>();
}

Constructor::~Constructor() {
	while(arguements->getSize())
		delete arguements->removeLast();
	delete arguements;
}

Array<ArguementInstance*>* Constructor::getArguements() { return arguements; }

void Constructor::setArguements(Array<ArguementInstance*>* param) { arguements = param; }

