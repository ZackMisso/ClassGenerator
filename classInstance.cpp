#include "classInstance.h"

ClassInstance::ClassInstance() {
	constructors = new Array<Constructor*>();
	variables = new Array<VariableInstance*>();
	methods = new Array<MethodInstance*>();
	isSingleton = false;
}

ClassInstance::~ClassInstance() {
	while(constructors->getSize())
		delete constructors->removeLast();
	while(variables->getSize())
		variables->removeLast();
	while(methods->getSize())
		methods->removeLast();
	delete constructors;
	delete methods;
	delete variables;
}

Array<Constructor*>* ClassInstance::getConstructors() { return constructors; }
Array<VariableInstance*>* ClassInstance::getVariables() { return variables; }
Array<MethodInstance*>* ClassInstance::getMethods() { return methods; }
string ClassInstance::getName() { return name; }
bool ClassInstance::getIsSingleton() { return isSingleton; }

void ClassInstance::setConstructors(Array<Constructor*>* param) { constructors = param; }
void ClassInstance::setVariables(Array<VariableInstance*>* param) { variables = param; }
void ClassInstance::setMethods(Array<MethodInstance*>* param) { methods = param; }
void ClassInstance::setName(string param) { name = param; }
void ClassInstance::setIsSingleton(bool param) { isSingleton = param; }

