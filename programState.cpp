#include "programState.h"

ProgramState::ProgramState() {
	running = false;
}

ProgramState::~ProgramState() { }

bool ProgramState::getRunning() { return running; }

void ProgramState::setRunnint(bool param) { running = param; }
