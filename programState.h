#ifndef __PROGRAMSTATE_H__
#define __PROGRAMSTATE_H__

class ProgramState {
private:
	bool running;
public:
	ProgramState();
	~ProgramState();
	// getter methods
	bool getRunning();
	// setter methods
	void setRunning(bool param);
};

#endif
