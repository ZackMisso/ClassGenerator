#include "lazy.h"
#include <iostream>
#include <vector>

using namespace std;

Lazy::Lazy(ProgramState* param) {
	programState = param;
	input = new Input();
}

Lazy::~Lazy() {
	delete programState;
	delete input;
}

void Lazy::drawTitle() {
	// to be implemented
}

void Lazy::run() {
	cout << "About To Run" << endl;
	while(programState->getRunning()) {
		vector<string>* readLineP = input->breakLineInput(input->getLineInput());
		vector<string> readLine = *readLineP;
		if(readLine.size() == 0)
			programState->setRunning(false);
		else if(readLine.size() == 1) {
			if(readLine[0] == "help") {
				programState->help();
			}
			else if(readLine[0] == "quit") {
				programState->setRunning(false);
			}
			else if(readLine[0] == "bake") {
				programState->bake();
			}
			else if(readLine[0] == "da") {
				// display all
				programState->displayAll();
			}
			else if(readLine[0] == "dcl") {
				// displays the current class
				programState->getCurrentClass()->display();
			}
			else if(readLine[0] == "dm") {
				// displays all methods in current class
				programState->displayAllMethods(programState->getCurrentClass());
			}
			else if(readLine[0] == "dv") {
				// displays all variables in current class
				programState->displayAllVariables(programState->getCurrentClass());
			}
			else if(readLine[0] == "dco") {
				// displays all constructors in current class
				programState->displayAllConstructors(programState->getCurrentClass());
			}
			else if(readLine[0] == "dcm") {
				// displays current method
				programState->getCurrentMethod()->display();
			}
			else if(readLine[0] == "dcv") {
				// displays current variable
				programState->getCurrentVariable()->display();
			}
			else if(readLine[0] == "dcc") {
				// displays current constructor
				programState->getCurrentConstructor()->display();
			}
			else if(readLine[0] == "dcli") {
				// displays list of classes and user chooses which one to display
				programState->chooseAndDisplayClass(input);
			}
			else if(readLine[0] == "dmi") {
				// displays list of methods and user chooses which one to display
				programState->chooseAndDisplayMethod(input);
			}
			else if(readLine[0] == "dvi") {
				// displays list of variables and user chooses which one to display
				programState->chooseAndDisplayVariable(input);
			}
			else if(readLine[0] == "dcoi") {
				// displays list of constructors and user chooses which one to display
				programState->chooseAndDisplayConstructor(input);
			}
			else {
				cout << "Input Not Recognized" << endl;
			}
		}
		else {
			if(readLine[0] == "cr") {
				// logic for creating a class
				string className = readLine[1];
				string flags = "";
				if(readLine.size()>2)
					flags = readLine[2];
				ClassInstance* newClass = ClassInstance::createClass(className,flags,readLineP);
				programState->getClasses()->add(newClass);
			}
			else if(readLine[0] == "am") {
				// logic for adding a method
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				string methodName = readLine[1];
				string flags = "";
				if(readLine.size()>2)
					flags = readLine[2];
				MethodInstance* newMethod = MethodInstance::createMethod(methodName,flags,readLineP);
				programState->getCurrentClass()->getMethods()->add(newMethod);
			}
			else if(readLine[0] == "av") {
				// logic for adding a variable
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				string variableName = readLine[1];
				string flags = "";
				if(readLine.size()>2)
					flags = readLine[2];
				VariableInstance* newVariable = VariableInstance::createVariable(variableName,flags,readLineP);
				programState->getCurrentClass()->getVariables()->add(newVariable);
			}
			else if(readLine[0] == "ac") {
				// logic for adding a constructor
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				Array<ArguementInstance*>* newArguements = new Array<ArguementInstance*>();
				int num = (readLine.size() - 1) / 2;
				for(int i=0;i<num;i++)
					newArguements->add(new ArguementInstance(readLine[i*2+1],readLine[i*2+2]));
				Constructor* newConstructor = new Constructor(newArguements);
				programState->getCurrentClass()->getConstructors()->add(newConstructor);
			}
			else if(readLine[0] == "ad") {
				// logic for adding a deconstructor
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				programState->getCurrentClass()->setHasDeconstructor(true);
			}
			else if(readLine[0] == "vcl") {
				// logic for viewing a class
				programState->setCurrentClass(0x0);
				string className = readLine[1];
				for(int i=0;i<programState->getClasses()->getSize();i++)
					if(programState->getClasses()->get(i)->getName() == className)
						programState->setCurrentClass(programState->getClasses()->get(i));
				if(programState->getCurrentClass())
					cout << "Now Viewing Class" << endl;
				else
					cout << "Class Could Not be Found" << endl;
			}
			else if(readLine[0] == "vm") {
				// logic for viewing a method
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				programState->setCurrentMethod(0x0);
				string methodName = readLine[1];
				Array<MethodInstance*>* methods = programState->getCurrentClass()->getMethods();
				for(int i=0;i<methods->getSize();i++)
					if(methods->get(i)->getName() == methodName)
						programState->setCurrentMethod(methods->get(i));
				if(programState->getCurrentMethod())
					cout << "Now Viewing Method" << endl;
				else
					cout << "Method Could Not be Found" << endl;
			}
			else if(readLine[0] == "vv") {
				// logic for viewing a variable
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				programState->setCurrentVariable(0x0);
				string variableName = readLine[1];
				Array<VariableInstance*>* variables = programState->getCurrentClass()->getVariables();
				for(int i=0;i<variables->getSize();i++)
					if(variables->get(i)->getName() == variableName)
						programState->setCurrentVariable(variables->get(i));
				if(programState->getCurrentVariable())
					cout << "Now Viewing Variable" << endl;
				else
					cout << "Variable Could Not be Found" << endl;
			}
			else if(readLine[0] == "vco") {
				// logic for viewing a constructor
				// not sure how to do this yet
			}
			else if(readLine[0] == "rcl") {
				// logic for deleting a class
				string className = readLine[1];
				Array<ClassInstance*>* classes = programState->getClasses();
				bool removed = false;
				for(int i=0;i<classes->getSize();i++)
					if(classes->get(i)->getName() == className) {
						ClassInstance* clas = classes->remove(i);
						delete clas;
						removed = true;
						i = classes->getSize();
					}
				if(removed)
					cout << "Class Removed Successfully" << endl;
				else
					cout << "Could Not Find Class" << endl;
			}
			else if(readLine[0] == "rm") {
				// logic for deleting a method
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				string methodName = readLine[1];
				Array<MethodInstance*>* methods = programState->getCurrentClass()->getMethods();
				bool removed = false;
				for(int i=0;i<methods->getSize();i++)
					if(methods->get(i)->getName() == methodName) {
						MethodInstance* method = methods->remove(i);
						delete method;
						removed = true;
						i = methods->getSize();
					}
				if(removed)
					cout << "Method was Removed Successfully" << endl;
				else
					cout << "Could Not Find Method" << endl;
			}
			else if(readLine[0] == "rv") {
				// logic for deleting a variable
				if(!programState->getCurrentClass()) {
					cout << "You must choose a class first" << endl;
					return;
				}
				string variableName = readLine[1];
				Array<VariableInstance*>* variables = programState->getCurrentClass()->getVariables();
				bool removed = false;
				for(int i=0;i<variables->getSize();i++)
					if(variables->get(i)->getName() == variableName) {
						VariableInstance* variable = variables->remove(i);
						delete variable;
						removed = true;
						i = variables->getSize();
					}
				if(removed)
					cout << "Variable was Removed Successfully" << endl;
				else
					cout << "Could Not Find Variable" << endl;
			}
			else if(readLine[0] == "rco") {
				// logic for deleting a constructor
				// not sure how to do this yet
			}
			else {
				cout << "First Arguement Not Recognized" << endl;
			}
		}
		delete readLineP;
	}
}
