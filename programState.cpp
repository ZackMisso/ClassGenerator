#include "programState.h"

ProgramState::ProgramState() {
	running = false;
}

ProgramState::~ProgramState() { }

bool ProgramState::getRunning() { return running; }

void ProgramState::setRunning(bool param) { running = param; }

