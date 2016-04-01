// This Project Will Allow Me To Generate CPP Classes By Command Line

#include "programState.h"
#include "lazy.h"
#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int main(int argc,char** argv) {
	cout << "Hello Lord Firal" << endl;
	int i;
	// create program state
	ProgramState* state = new ProgramState();
	state->setRunning(true);
	// read in flags
	while((i=getopt(argc,argv,"tu:")) != EOF) {
		switch(i) {
			case 'u': {
				state->setRunning(false);
				break;
			}
			default:
				break;
		}
	}
	// process flags
	// run the program
	if(state->getRunning()) {
		Lazy* program = new Lazy(state);
		program->run();
		delete program;
	}
	return 0;
}
