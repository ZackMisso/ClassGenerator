#include "programState.h"

ProgramState::ProgramState() {
	classes = new Array<ClassInstance*>();
	running = false;
}

ProgramState::~ProgramState() {
	while(classes->getSize())
		delete classes->removeLast();
	delete classes;
}

Array<ClassInstance*>* ProgramState::getClasses() { return classes; }
bool ProgramState::getRunning() { return running; }

void ProgramState::setClasses(Array<ClassInstance*>* param) { classes = param; }
void ProgramState::setRunning(bool param) { running = param; }

