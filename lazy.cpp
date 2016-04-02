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
			else {
				cout << "Input Not Recognized" << endl;
			}
		}
		else {
			if(readLine[0] == "cr") {
				// logic for creating a class
			}
			else if(readLine[0] == "am") {
				// logic for adding a method
			}
			else if(readLine[0] == "av") {
				// logic for adding a variable
			}
			else if(readLine[0] == "ac") {
				// logic for adding a constructor
			}
			else if(readLine[0] == "ad") {
				// logic for adding a deconstructor
			}
			else if(readLine[0] == "vcl") {
				// logic for viewing a class
			}
			else if(readLine[0] == "vm") {
				// logic for viewing a method
			}
			else if(readLine[0] == "vv") {
				// logic for viewing a variable
			}
			else if(readLine[0] == "vco") {
				// logic for viewing a constructor
			}
			else if(readLine[0] == "rcl") {
				// logic for deleting a class
			}
			else if(readLine[0] == "rm") {
				// logic for deleting a method
			}
			else if(readLine[0] == "rv") {
				// logic for deleting a variable
			}
			else if(readLine[0] == "rco") {
				// logic for deleting a constructor
			}
			else {
				cout << "First Arguement Not Recognized" << endl;
			}
		}
		delete readLineP;
	}
}
