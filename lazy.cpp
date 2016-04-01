#include "lazy.h"

Lazy::Lazy(ProgramState* param) {
	programState = param;
}

Lazy::~Lazy() {
	delete programState;
}

void Lazy::drawTitle() {
	// to be implemented
}

void Lazy::run() {
	// to be implemented
}
