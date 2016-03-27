#include "constructor.h"

Constructor::Constructor() {
	arguementNames = new Array<string>();
	arguementTypes = new Array<string>();
}

Constructor::~Constructor() {
	while(arguementNames->getSize())
		arguementNames->removeLast();
	while(arguementTypes->getSize())
		arguementTypes->removeLast();
	delete arguementNames;
	delete arguementTypes;
}

Array<string>* Constructor::getArguementNames() { return arguementNames; }
Array<string>* Constructor::getArguementTypes() { return arguementTypes; }

void Constructor::setArguementNames(Array<string>* param) { arguementNames = param; }
void Constructor::setArguementTypes(Array<string>* param) { arguementTypes = param; }

