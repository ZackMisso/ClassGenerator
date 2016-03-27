#ifndef __CONSTRUCTOR_H__
#define __CONSTRUCTOR_H__

#include "array.h"
#include <string>

using namespace std;

class Constructor {
private:
	Array<string>* arguementNames;
	Array<string>* arguementTypes;
public:
	Constructor();
	~Constructor();
	// getter methods
	Array<string>* getArguementNames();
	Array<string>* getArguementTypes();
	// setter methods
	void setArguementNames(Array<string>* param);
	void setArguementTypes(Array<string>* param);
};

#endif

