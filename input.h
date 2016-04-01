#ifndef __INPUT_H__
#define __INPUT_H__

#include <string>

using namespace std;

class Input {
private:
public:
	Input();
	~Input();
	int getIntInput();
	string getStringInput();
};

#endif
