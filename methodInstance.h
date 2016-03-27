#ifndef __METHODINSTANCE_H__
#define __METHODINSTANCE_H__

#include <string>

using namespace std;

class MethodInstance {
private:
	string name;
	string type;
	bool priv;
	bool prot;
	bool pub;
	bool isStatic;
public:
	MethodInstance();
	~MethodInstance();
	// getter methods
	string getName();
	string getType();
	bool getPriv();
	bool getProt();
	bool getPub();
	bool getIsStatic();
	// setter methods
	void setName(string param);
	void setType(string param);
	void setPriv(bool param);
	void setProt(bool param);
	void setPub(bool param);
	void setIsStatic(bool param);
};

#endif

