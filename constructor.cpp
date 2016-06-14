#include "constructor.h"
#include <iostream>

using namespace std;

Constructor::Constructor() {
	arguements = new Array<ArguementInstance*>();
	definedInDec = false;
}

Constructor::Constructor(Array<ArguementInstance*>* param) {
	arguements = param;
	definedInDec = false;
}

Constructor::~Constructor() {
	while(arguements->getSize())
		delete arguements->removeLast();
	delete arguements;
}

void Constructor::display() {
	cout << "Constructor :: " << endl;
	for(int i=0;i<arguements->getSize();i++) {
		cout << "  ";
		arguements->get(i)->display();
	}
}

void Constructor::lineInfo() {
	// to be implemented
}

Array<ArguementInstance*>* Constructor::getArguements() { return arguements; }
bool Constructor::getDefinedInDec() { return definedInDec; }

void Constructor::setArguements(Array<ArguementInstance*>* param) { arguements = param; }
void Constructor::setDefinedInDec(bool param) { definedInDec = param; }
