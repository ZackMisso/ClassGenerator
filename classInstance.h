#ifndef __CLASSINSTANCE_H__
#define __CLASSINSTANCE_H__

#include "array.h"
#include "variableInstance.h"
#include "methodInstance.h"
#include "constructor.h"
#include "include.h"
#include "input.h"
#include <string>
#include <vector>

using namespace std;

class ClassInstance {
private:
	Array<Constructor*>* constructors;
	Array<VariableInstance*>* variables;
	Array<MethodInstance*>* methods;
	Array<Include*>* includes;
	string name;
	string parent;
	bool hasDeconstructor;
	bool isSingleton;
	bool extends;
public:
	ClassInstance();
	~ClassInstance();
	void display();
	void lineInfo();
	static ClassInstance* createClass(string className,string flags,vector<string>* input);
	// members by access method
	Array<Constructor*>* getPrivateConstructors();
	Array<Constructor*>* getProtectedConstructors();
	Array<Constructor*>* getPublicConstructors();
	Array<MethodInstance*>* getPrivateMethods();
	Array<MethodInstance*>* getProtectedMethods();
	Array<MethodInstance*>* getPublicMethods();
	Array<VariableInstance*>* getPrivateVariables();
	Array<VariableInstance*>* getProtectedVariables();
	Array<VariableInstance*>* getPublicVariables();
	// getter methods
	Array<Constructor*>* getConstructors();
	Array<VariableInstance*>* getVariables();
	Array<MethodInstance*>* getMethods();
	Array<Include*>* getIncludes();
	string getName();
	string getParent();
	bool getHasDeconstructor();
	bool getIsSingleton();
	bool getExtends();
	// setter methods
	void setConstructors(Array<Constructor*>* param);
	void setVariables(Array<VariableInstance*>* param);
	void setMethods(Array<MethodInstance*>* param);
	void setIncludes(Array<Include*>* param);
	void setName(string param);
	void setParent(string param);
	void setHasDeconstructor(bool param);
	void setIsSingleton(bool param);
	void setExtends(bool param);
};

#endif
