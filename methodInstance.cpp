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
bool MethodInstance::getPriv() { return priv; }
bool MethodInstance::getProt() { return prot; }
bool MethodInstance::getPub() { return pub; }
bool MethodInstance::getIsStatic() { return isStatic; }

void MethodInstance::setArguements(Array<ArguementInstance*>* param) { arguements = param; }
void MethodInstance::setName(string param) { name = param; }
void MethodInstance::setType(string param) { type = param; }
void MethodInstance::setPriv(bool param) { priv = param; }
void MethodInstance::setProt(bool param) { prot = param; }
void MethodInstance::setPub(bool param) { pub = param; }
void MethodInstance::setIsStatic(bool param) { isStatic = param; }
