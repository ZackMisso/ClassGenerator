#include "programState.h"

ProgramState::ProgramState() {
	classes = new Array<ClassInstance*>();
	currentClass = 0x0;
	currentMethod = 0x0;
	currentVariable = 0x0;
	currentConstructor = 0x0;
	running = false;
}

ProgramState::~ProgramState() {
	while(classes->getSize())
		delete classes->removeLast();
	delete classes;
}

void ProgramState::help() {
	// to be implemented
}

void ProgramState::bake() {
	// this method writes out the files
	// to be implemented
}

Array<ClassInstance*>* ProgramState::getClasses() { return classes; }
ClassInstance* ProgramState::getCurrentClass() { return currentClass; }
MethodInstance* ProgramState::getCurrentMethod() { return currentMethod; }
VariableInstance* ProgramState::getCurrentVariable() { return currentVariable; }
Constructor* ProgramState::getCurrentConstructor() { return currentConstructor; }
bool ProgramState::getRunning() { return running; }

void ProgramState::setClasses(Array<ClassInstance*>* param) { classes = param; }
void ProgramState::setCurrentClass(ClassInstance* param) { currentClass = param; }
void ProgramState::setCurrentMethod(MethodInstance* param) { currentMethod = param; }
void ProgramState::setCurrentVariable(VariableInstance* param) { currentVariable = param; }
void ProgramState::setCurrentConstructor(Constructor* param) { currentConstructor = param; }
void ProgramState::setRunning(bool param) { running = param; }

