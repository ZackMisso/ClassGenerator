#ifndef __CPP_H__
#define __CPP_H__

#include "language.h"
#include <fstream>

using namespace std;

class Cpp : public Language {
private:
	void writeConstructorCpp(ClassInstance* clas,Constructor* cons,ofstream& fout);
	void writeMethodCpp(ClassInstance* clas,MethodInstance* method,ofstream& fout);
	void writeGetterCpp(ClassInstance* clas,VariableInstance* var,ofstream& fout);
	void writeSetterCpp(ClassInstance* clas,VariableInstance* var,ofstream& fout);
public:
	Cpp();
	~Cpp();
	virtual ClassInstance* readClassInstance(string name);
  virtual void writeClassInstance(ClassInstance* instance);
	void writeH(ClassInstance* instance);
	void writeCpp(ClassInstance* instance);
	void writeConstructorH(ClassInstance* instance,Constructor* constructor,ofstream& fout);
	void writeMethodH(MethodInstance* method,ofstream& fout);
	void writeVariableH(VariableInstance* variable,ofstream& fout);
};

#endif
