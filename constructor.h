#ifndef __CONSTRUCTOR_H__
#define __CONSTRUCTOR_H__

#include "array.h"
#include "member.h"
#include "arguementInstance.h"
#include <string>

using namespace std;

class Constructor : public Member{
private:
	Array<ArguementInstance*>* arguements;
	bool definedInDec;
public:
	Constructor();
	Constructor(Array<ArguementInstance*>* param);
	~Constructor();
	void display();
	void lineInfo();
	// getter methods
	Array<ArguementInstance*>* getArguements();
	bool getDefinedInDec();
	// setter methods
	void setArguements(Array<ArguementInstance*>* param);
	void setDefinedInDec(bool param);
};

#endif
