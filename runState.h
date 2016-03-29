#ifndef __RUNSTATE_H__
#define __RUNSTATE_H__

class RunState {
private:
	bool isRunning;
public:
	RunState();
	~RunState();
	// getter methods
	bool getIsRunning();
	// setter methods
	void setIsRunning(bool param);
};

#endif
