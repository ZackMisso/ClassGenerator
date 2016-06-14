#pragma once

#include "classInstance.h"
#include "cppToken.h"

class CppParser {
private:
public:
  static void readClass(string file,ClassInstance* clas);
  static CppToken* parseTokensH(string file);
  static CppToken* parseTokensCpp(string file);
};
