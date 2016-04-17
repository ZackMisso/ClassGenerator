#ifndef __PROGRAMSTATE_H__
#define __PROGRAMSTATE_H__

#include "classInstance.h"
#include "methodInstance.h"
#include "variableInstance.h"
#include "constructor.h"
#include "input.h"
#include "array.h"

class ProgramState {
private:
	Array<ClassInstance*>* classes;
	ClassInstance* currentClass;
	MethodInstance* currentMethod;
	VariableInstance* currentVariable;
	Constructor* currentConstructor;
	bool running;
	bool acceptingTypeInput;
	bool scrolling;
public:
	ProgramState();
	~ProgramState();
	void help();
	void bake();
	void displayAll();
	void displayAllMethods(ClassInstance* instance);
	void displayAllVariables(ClassInstance* instance);
	void displayAllConstructors(ClassInstance* instance);
	void chooseAndDisplayClass(Input* input);
	void chooseAndDisplayMethod(Input* input);
	void chooseAndDisplayVariable(Input* input);
	void chooseAndDisplayConstructor(Input* input);
	// getter methods
	Array<ClassInstance*>* getClasses();
	ClassInstance* getCurrentClass();
	MethodInstance* getCurrentMethod();
	VariableInstance* getCurrentVariable();
	Constructor* getCurrentConstructor();
	bool getRunning();
	bool getAcceptingTypeInput();
	bool getScrolling();
	// setter methods
	void setClasses(Array<ClassInstance*>* param);
	void setCurrentClass(ClassInstance* param);
	void setCurrentMethod(MethodInstance* param);
	void setCurrentVariable(VariableInstance* param);
	void setCurrentConstructor(Constructor* param);
	void setRunning(bool param);
	void setAcceptingTypeInput(bool param);
	void setScrolling(bool param);
};

#endif
