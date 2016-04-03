#include "methodInstance.h"

MethodInstance::MethodInstance() {
	arguements = new Array<ArguementInstance*>();
}

MethodInstance::~MethodInstance() {
	while(arguements->getSize())
		delete arguements->removeLast();
	delete arguements;
}

MethodInstance* MethodInstance::createMethod(string methodName,string flags,vector<string>* input) {
	// to be implemented
	return 0x0;
}

Array<ArguementInstance*>* MethodInstance::getArguements() { return arguements; }
string MethodInstance::getName() { return name; }
string MethodInstance::getType() { return type; }
bool MethodInstance::getIsStatic() { return isStatic; }

void MethodInstance::setArguements(Array<ArguementInstance*>* param) { arguements = param; }
void MethodInstance::setName(string param) { name = param; }
void MethodInstance::setType(string param) { type = param; }
void MethodInstance::setIsStatic(bool param) { isStatic = param; }
