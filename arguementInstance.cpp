#include "arguementInstance.h"

ArguementInstance::ArguementInstance() {
	isConst = false;
	type = "";
	name = "";
}

ArguementInstance::ArguementInstance(string t,string n) {
	isConst = false;
	type = t;
	name = n;
}

ArguementInstance::~ArguementInstance() { }

string ArguementInstance::getType() { return type; }
string ArguementInstance::getName() { return name; }
bool ArguementInstance::getIsConst() { return isConst; }

void ArguementInstance::setType(string param) { type = param; }
void ArguementInstance::setName(string param) { name = param; }
void ArguementInstance::setIsConst(bool param) { isConst = param; }
