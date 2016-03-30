#ifndef __CLASSINSTANCE_H__
#define __CLASSINSTANCE_H__

#include "array.h"
#include "variableInstance.h"
#include "methodInstance.h"
#include "constructor.h"
#include "include.h"
#include <string>

using namespace std;

class ClassInstance {
private:
	Array<Constructor*>* constructors;
	Array<VariableInstance*>* variables;
	Array<MethodInstance*>* methods;
	Array<Include*>* includes;
	string name;
	string parent;
	bool isSingleton;
	bool extends;
public:
	ClassInstance();
	~ClassInstance();
	// getter methods
	Array<Constructor*>* getConstructors();
	Array<VariableInstance*>* getVariables();
	Array<MethodInstance*>* getMethods();
	Array<Include*>* getIncludes();
	string getName();
	string getParent();
	bool getIsSingleton();
	bool getExtends();
	// setter methods
	void setConstructors(Array<Constructor*>* param);
	void setVariables(Array<VariableInstance*>* param);
	void setMethods(Array<MethodInstance*>* param);
	void setIncludes(Array<Include*>* param);
	void setName(string param);
	void setParent(string param);
	void setIsSingleton(bool param);
	void setExtends(bool param);
};

#endif

