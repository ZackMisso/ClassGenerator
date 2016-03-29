#ifndef __CPP_H__
#define __CPP_H__

#include "language.h"

class Cpp : public Language {
private:
	Cpp();
	~Cpp();
  void writeClassInstance(ClassInstance* instance);
	ClassInstance* readClassInstance(string name);
public:
};

#endif
