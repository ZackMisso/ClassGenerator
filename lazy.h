#ifndef __LAZY_H__
#define __LAZY_H__

#include "programState.h"

class Lazy {
private:
	ProgramState* programState;
	Input* input;
	void drawTitle();
public:
	Lazy(ProgramState* param);
	~Lazy();
	void run();
};

#endif
