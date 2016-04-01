#ifndef __ARGUEMENTINSTANCE_H__
#define __ARGUEMENTINSTANCE_H__

#include <string>

using namespace std;

class ArguementInstance {
private:
	string type;
	string name;
	bool isConst;
public:
	ArguementInstance();
	~ArguementInstance();
	// getter methods
	string getType();
	string getName();
	bool getIsConst();
	// setter methods
	void setType(string param);
	void setName(string param);
	void setIsConst(bool param);
};

#endif
