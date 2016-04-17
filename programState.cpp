#include "programState.h"
#include <iostream>

using namespace std;

ProgramState::ProgramState() {
	classes = new Array<ClassInstance*>();
	currentClass = 0x0;
	currentMethod = 0x0;
	currentVariable = 0x0;
	currentConstructor = 0x0;
	running = false;
	acceptingTypeInput = true;
	scrolling = false;
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

void ProgramState::displayAll() {
	for(int i=0;i<classes->getSize();i++)
		classes->get(i)->display();
}

void ProgramState::displayAllMethods(ClassInstance* instance) {
	Array<MethodInstance*>* methods = instance->getMethods();
	for(int i=0;i<methods->getSize();i++)
		methods->get(i)->display();
}

void ProgramState::displayAllVariables(ClassInstance* instance) {
	Array<VariableInstance*>* variables = instance->getVariables();
	for(int i=0;i<variables->getSize();i++)
		variables->get(i)->display();
}

void ProgramState::displayAllConstructors(ClassInstance* instance) {
	Array<Constructor*>* constructors = instance->getConstructors();
	for(int i=0;i<constructors->getSize();i++)
		constructors->get(i)->display();
}

void ProgramState::chooseAndDisplayClass(Input* input) {
	// info logic
	for(int i=0;i<classes->getSize();i++) {
		cout << i << " ";
		classes->get(i)->lineInfo();
	}
	// choose logic
	int choice = input->getIntInput();
	if(choice < 0 || choice >= classes->getSize())
		cout << "Please choose a valid choice" << endl;
	else
		classes->get(choice)->display();
}

void ProgramState::chooseAndDisplayMethod(Input* input) {
	if(!currentClass) {
		cout << "Please choose a class first" << endl;
		return;
	}
	// info logic
	Array<MethodInstance*>* methods = currentClass->getMethods();
	for(int i=0;i<methods->getSize();i++) {
		cout << i << " ";
		methods->get(i)->lineInfo();
	}
	// choose logic
	int choice = input->getIntInput();
	if(choice >= methods->getSize() || choice < 0)
		cout << "Please choose a valid item" << endl;
	else
		methods->get(choice)->display();
}

void ProgramState::chooseAndDisplayVariable(Input* input) {
	if(!currentClass) {
		cout << "Please choose a class first" << endl;
		return;
	}
	// info logic
	Array<VariableInstance*>* variables = currentClass->getVariables();
	for(int i=0;i<variables->getSize();i++) {
		cout << i << " ";
		variables->get(i)->lineInfo();
	}
	// choose logic
	int choice = input->getIntInput();
	if(choice < 0 || choice >= variables->getSize())
		cout << "Please make a valid choice" << endl;
	else
		variables->get(choice)->display();
}

void ProgramState::chooseAndDisplayConstructor(Input* input) {
	if(!currentClass) {
		cout << "Please choose a class first" << endl;
		return;
	}
	// info logic
	Array<Constructor*>* constructors = currentClass->getConstructors();
	for(int i=0;i<constructors->getSize();i++) {
		cout << i << " ";
		constructors->get(i)->lineInfo();
	}
	// choose logic
	int choice = input->getIntInput();
	if(choice < 0 || choice >= constructors->getSize())
		cout << "Please make a valid choice" << endl;
	else
		constructors->get(choice)->display();
}

Array<ClassInstance*>* ProgramState::getClasses() { return classes; }
ClassInstance* ProgramState::getCurrentClass() { return currentClass; }
MethodInstance* ProgramState::getCurrentMethod() { return currentMethod; }
VariableInstance* ProgramState::getCurrentVariable() { return currentVariable; }
Constructor* ProgramState::getCurrentConstructor() { return currentConstructor; }
bool ProgramState::getRunning() { return running; }
bool ProgramState::getAcceptingTypeInput() { return acceptingTypeInput; }
bool ProgramState::getScrolling() { return scrolling; }

void ProgramState::setClasses(Array<ClassInstance*>* param) { classes = param; }
void ProgramState::setCurrentClass(ClassInstance* param) { currentClass = param; }
void ProgramState::setCurrentMethod(MethodInstance* param) { currentMethod = param; }
void ProgramState::setCurrentVariable(VariableInstance* param) { currentVariable = param; }
void ProgramState::setCurrentConstructor(Constructor* param) { currentConstructor = param; }
void ProgramState::setRunning(bool param) { running = param; }
void ProgramState::setAcceptingTypeInput(bool param) { acceptingTypeInput = param; }
void ProgramState::setScrolling(bool param) { scrolling = param; }
