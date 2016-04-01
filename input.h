#ifndef __INPUT_H__
#define __INPUT_H__

#include <string>
#include <vector>

using namespace std;

class Input {
private:
public:
	Input();
	~Input();
	int getIntInput();
	string getStringInput();
	string getLineInput();
	vector<string>* breakLineInput(string line);
};

#endif
