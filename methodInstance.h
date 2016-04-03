#ifndef __METHODINSTANCE_H__
#define __METHODINSTANCE_H__

#include "member.h"
#include "arguementInstance.h"
#include "array.h"
#include <string>
#include <vector>

using namespace std;

class MethodInstance : public Member {
private:
	Array<ArguementInstance*>* arguements;
	string name;
	string type;
	bool isStatic;
public:
	MethodInstance();
	~MethodInstance();
	static MethodInstance* createMethod(string methodName,string flags,vector<string>* input);
	// getter methods
	Array<ArguementInstance*>* getArguements();
	string getName();
	string getType();
	bool getIsStatic();
	// setter methods
	void setArguements(Array<ArguementInstance*>* param);
	void setName(string param);
	void setType(string param);
	void setIsStatic(bool param);
};

#endif
