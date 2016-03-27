#include "variableInstance.h"

VariableInstance::VariableInstance() {
	// to be implemented
}

VariableInstance::~VariableInstance() {
	// to be implemented
}

string VariableInstance::getType() { return type; }
string VariableInstance::getName() { return name; }
bool VariableInstance::getIsStatic() { return isStatic; }
bool VariableInstance::getIsConst() { return isConst; }

void VariableInstance::setType(string param) { type = param; }
void VariableInstance::setName(string param) { name = param; }
void VariableInstance::setIsStatic(bool param) { isStatic = param; }
void VariableInstance::setIsConst(bool param) { isConst = param; }

