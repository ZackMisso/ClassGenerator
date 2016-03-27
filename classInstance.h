#ifndef __CLASSINSTANCE_H__
#define __CLASSINSTANCE_H__

#include "array.h"
#include "variableInstance.h"
#include "methodInstance.h"
#include "constructor.h"
#include <string>

using namespace std;

class ClassInstance {
private:
	Array<Constructor*>* constructors;
	Array<VariableInstance*>* variables;
	Array<MethodInstance*>* methods;
	string name;
	bool isSingleton;
public:
	ClassInstance();
	~ClassInstance();
	// getter methods
	Array<Constructor*>* getConstructors();
	Array<VariableInstance*>* getVariables();
	Array<MethodInstance*>* getMethods();
	string getName();
	bool getIsSingleton();
	// setter methods
	void setConstructors(Array<Constructor*>* param);
	void setVariables(Array<VariableInstance*>* param);
	void setMethods(Array<MethodInstance*>* param);
	void setName(string param);
	void setIsSingleton(bool param);
};

#endif

