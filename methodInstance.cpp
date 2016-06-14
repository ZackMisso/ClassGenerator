#include "methodInstance.h"
#include <iostream>

using namespace std;

MethodInstance::MethodInstance() {
	arguements = new Array<ArguementInstance*>();
	name = "";
	type = "";
	isStatic = false;
	isConst = false;
	definedInDec = false;
}

MethodInstance::~MethodInstance() {
	while(arguements->getSize())
		delete arguements->removeLast();
	delete arguements;
}

void MethodInstance::display() {
	cout << "Method :: " << name << " Return :: " << type;
	cout << " ";
	if(isStatic)
		cout << "s";
	if(isConst)
		cout << "c";
	if(getPriv())
		cout << "1";
	else if(getProt())
		cout << "2";
	else if(getPub())
		cout << "3";
	cout << endl;
	for(int i=0;i<arguements->getSize();i++) {
		cout << "  ";
		arguements->get(i)->display();
	}
}

void MethodInstance::lineInfo() {
	// to be implemented
}

MethodInstance* MethodInstance::createMethod(string methodName,string flags,vector<string>* input) {
	// to be implemented
	return 0x0;
}

Array<ArguementInstance*>* MethodInstance::getArguements() { return arguements; }
string MethodInstance::getName() { return name; }
string MethodInstance::getType() { return type; }
bool MethodInstance::getIsStatic() { return isStatic; }
bool MethodInstance::getIsConst() { return isConst; }
bool MethodInstance::getDefinedInDec() { return definedInDec; }

void MethodInstance::setArguements(Array<ArguementInstance*>* param) { arguements = param; }
void MethodInstance::setName(string param) { name = param; }
void MethodInstance::setType(string param) { type = param; }
void MethodInstance::setIsStatic(bool param) { isStatic = param; }
void MethodInstance::setIsConst(bool param) { isConst = param; }
void MethodInstance::setDefinedInDec(bool param) { definedInDec = param; }
