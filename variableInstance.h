#ifndef __VARIABLEINSTANCE_H__
#define __VARIABLEINSTANCE_H__

#include <string>

using namespace std;

class VariableInstance {
private:
	string type;
	string name;
	bool isStatic;
	bool isConst;
	bool hasGetter;
	bool hasSetter;
public:
	VariableInstance();
	~VariableInstance();
	// getter methods
	string getType();
	string getName();
	bool getIsStatic();
	bool getIsConst();
	bool getHasGetter();
	bool getHasSetter();
	// setter methods
	void setType(string param);
	void setName(string param);
	void setIsStatic(bool param);
	void setIsConst(bool param);
	void setHasGetter(bool param);
	void setHasSetter(bool param);
};

#endif

