#ifndef __LANGUAGE_H__
#define __LANGUAGE_H__

#include "classInstance.h"
#include <string>

using namespace std;

class Language {
private:
public:
	Language();
	~Language();
	void writeClassInstance();
	ClassInstance* readClassInstance(string name);
};

#endif
