#ifndef __CS_H__
#define __CS_H__

#include "language.h"

class CS : public Language {
private:
public:
  CS();
  ~CS();
  virtual ClassInstance* readClassInstance(string name);
  virtual void writeClassInstance(ClassInstance* instance);
  void writeCS(ClassInstance* instance);
};

#endif
