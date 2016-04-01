#ifndef __PROGRAMSTATE_H__
#define __PROGRAMSTATE_H__

#include "classInstance.h"
#include "array.h"

class ProgramState {
private:
	Array<ClassInstance*>* classes;
	bool running;
public:
	ProgramState();
	~ProgramState();
	// getter methods
	Array<ClassInstance*>* getClasses();
	bool getRunning();
	// setter methods
	void setClasses(Array<ClassInstance*>* param);
	void setRunning(bool param);
};

#endif
