#include "runState.h"

RunState::RunState() {
	isRunning = false;
}

RunState::~RunState() {
	// to be implemented
}

bool RunState::getIsRunning() { return isRunning; }

void RunState::setIsRunning(bool param) { isRunning = param; }
