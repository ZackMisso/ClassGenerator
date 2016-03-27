#include "methodInstance.h"

MethodInstance::MethodInstance() {
	// to be implemented
}

MethodInstance::~MethodInstance() {
	// to be implemented
}

string MethodInstance::getName() { return name; }
string MethodInstance::getType() { return type; }
bool MethodInstance::getPriv() { return priv; }
bool MethodInstance::getProt() { return prot; }
bool MethodInstance::getPub() { return pub; }
bool MethodInstance::getIsStatic() { return isStatic; }

void MethodInstance::setName(string param) { name = param; }
void MethodInstance::setType(string param) { type = param; }
void MethodInstance::setPriv(bool param) { priv = param; }
void MethodInstance::setProt(bool param) { prot = param; }
void MethodInstance::setPub(bool param) { pub = param; }
void MethodInstance::setIsStatic(bool param) { isStatic = param; }

