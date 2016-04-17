#ifndef __JAVA_H__
#define __JAVA_H__

#include "language.h"

class Java : public Language {
private:
public:
  Java();
  ~Java();
  virtual ClassInstance* readClassInstance(string name);
  virtual void writeClassInstance(ClassInstance* instance);
  void writeJava(ClassInstance* instance);
};

#endif
