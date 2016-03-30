#ifndef __CPP_H__
#define __CPP_H__

#include "language.h"

class Cpp : public Language {
private:
public:
	Cpp();
	~Cpp();
	virtual ClassInstance* readClassInstance(string name);
  virtual void writeClassInstance(ClassInstance* instance);
	void writeH(ClassInstance* instance);
	void writeCpp(ClassInstance* instance);
};

#endif
