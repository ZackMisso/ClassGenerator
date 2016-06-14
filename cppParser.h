#pragma once

#include "classInstance.h"
#include "cppToken.h"
#include "cppParseState.h"

class CppParser {
private:
public:
  static void readClass(string file,ClassInstance* clas);
  static CppToken* parseTokensH(string file);
  static CppToken* parseTokensCpp(string file);
  static int getNextToken(const char* file,int startIndex,TokenType& type,CppParseState* state);
  static void parseClassH(CppToken* htok,ClassInstance* clas);
  static void parseClassCpp(CppToken* cpptok,ClassInstance* clas);
};
