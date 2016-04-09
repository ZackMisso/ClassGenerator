#include "constructor.h"
#include <iostream>

using namespace std;

Constructor::Constructor() {
	arguements = new Array<ArguementInstance*>();
}

Constructor::Constructor(Array<ArguementInstance*>* param) {
	arguements = param;
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

void Constructor::setArguements(Array<ArguementInstance*>* param) { arguements = param; }
