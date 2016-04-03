#include "variableInstance.h"

VariableInstance::VariableInstance() {
	// to be implemented
}

VariableInstance::~VariableInstance() {
	// to be implemented
}

VariableInstance* VariableInstance::createVariable(string variableName,string flags,vector<string>* input) {
	// to be implemented
	return 0x0;
}

string VariableInstance::getType() { return type; }
string VariableInstance::getName() { return name; }
bool VariableInstance::getIsStatic() { return isStatic; }
bool VariableInstance::getIsConst() { return isConst; }
bool VariableInstance::getHasGetter() { return hasGetter; }
bool VariableInstance::getHasSetter() { return hasSetter; }
bool VariableInstance::getPriv() { return priv; }
bool VariableInstance::getProt() { return prot; }
bool VariableInstance::getPub() { return pub; }

void VariableInstance::setType(string param) { type = param; }
void VariableInstance::setName(string param) { name = param; }
void VariableInstance::setIsStatic(bool param) { isStatic = param; }
void VariableInstance::setIsConst(bool param) { isConst = param; }
void VariableInstance::setHasGetter(bool param) { hasGetter = param; }
void VariableInstance::setHasSetter(bool param) { hasSetter = param; }
void VariableInstance::setPriv(bool param) { priv = param; }
void VariableInstance::setProt(bool param) { prot = param; }
void VariableInstance::setPub(bool param) { pub = param; }
