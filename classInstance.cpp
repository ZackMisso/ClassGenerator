#include "classInstance.h"
#include <iostream>

using namespace std;

ClassInstance::ClassInstance() {
	constructors = new Array<Constructor*>();
	variables = new Array<VariableInstance*>();
	methods = new Array<MethodInstance*>();
	includes = new Array<Include*>();
	isSingleton = false;
	extends = false;
}

ClassInstance::~ClassInstance() {
	while(constructors->getSize())
		delete constructors->removeLast();
	while(variables->getSize())
		delete variables->removeLast();
	while(methods->getSize())
		delete methods->removeLast();
	while(includes->getSize())
		delete includes->removeLast();
	delete constructors;
	delete methods;
	delete variables;
	delete includes;
}

void ClassInstance::display() {
	cout << "Class :: " << name << " ";
	if(extends)
		cout << "Parent :: " << parent << " ";
	if(isSingleton)
		cout << "Singleton :: " << isSingleton;
	cout << endl;
	cout << "Constructors :: " << endl;
	for(int i=0;i<constructors->getSize();i++) {
		cout << "  " << endl;
		constructors->get(i)->display();
	}
	cout << endl;
	cout << "Methods :: " << endl;
	for(int i=0;i<methods->getSize();i++) {
		cout << "  " << endl;
		methods->get(i)->display();
	}
	cout << endl;
	cout << "Variables :: " << endl;
	for(int i=0;i<variables->getSize();i++) {
		cout << "  " << endl;
		variables->get(i)->display();
	}
}

void ClassInstance::lineInfo() {
	// to be implemented
}

ClassInstance* ClassInstance::createClass(string className,string flags,vector<string>* input) {
	// to be implemented
	return 0x0;
}

Array<Constructor*>* ClassInstance::getConstructors() { return constructors; }
Array<VariableInstance*>* ClassInstance::getVariables() { return variables; }
Array<MethodInstance*>* ClassInstance::getMethods() { return methods; }
Array<Include*>* ClassInstance::getIncludes() { return includes; }
string ClassInstance::getName() { return name; }
string ClassInstance::getParent() { return parent; }
bool ClassInstance::getHasDeconstructor() { return hasDeconstructor; }
bool ClassInstance::getIsSingleton() { return isSingleton; }
bool ClassInstance::getExtends() { return extends; }

void ClassInstance::setConstructors(Array<Constructor*>* param) { constructors = param; }
void ClassInstance::setVariables(Array<VariableInstance*>* param) { variables = param; }
void ClassInstance::setMethods(Array<MethodInstance*>* param) { methods = param; }
void ClassInstance::setIncludes(Array<Include*>* param) { includes = param; }
void ClassInstance::setName(string param) { name = param; }
void ClassInstance::setParent(string param) { parent = param; }
void ClassInstance::setHasDeconstructor(bool param) { hasDeconstructor = param; }
void ClassInstance::setIsSingleton(bool param) { isSingleton = param; }
void ClassInstance::setExtends(bool param) { extends = param; }
