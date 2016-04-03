#ifndef __METHODINSTANCE_H__
#define __METHODINSTANCE_H__

#include "arguementInstance.h"
#include "array.h"
#include <string>
#include <vector>

using namespace std;

class MethodInstance {
private:
	Array<ArguementInstance*>* arguements;
	string name;
	string type;
	bool priv;
	bool prot;
	bool pub;
	bool isStatic;
public:
	MethodInstance();
	~MethodInstance();
	static MethodInstance* createMethod(string methodName,string flags,vector<string>* input);
	// getter methods
	Array<ArguementInstance*>* getArguements();
	string getName();
	string getType();
	bool getPriv();
	bool getProt();
	bool getPub();
	bool getIsStatic();
	// setter methods
	void setArguements(Array<ArguementInstance*>* param);
	void setName(string param);
	void setType(string param);
	void setPriv(bool param);
	void setProt(bool param);
	void setPub(bool param);
	void setIsStatic(bool param);
};

#endif
