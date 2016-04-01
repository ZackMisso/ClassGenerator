#ifndef __CONSTRUCTOR_H__
#define __CONSTRUCTOR_H__

#include "array.h"
#include "arguementInstance.h"
#include <string>

using namespace std;

class Constructor {
private:
	Array<ArguementInstance*>* arguements;
public:
	Constructor();
	~Constructor();
	// getter methods
	Array<ArguementInstance*>* getArguements();
	// setter methods
	void setArguements(Array<ArguementInstance*>* param);
};

#endif

