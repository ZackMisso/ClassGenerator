#pragma once

// this test tests the 'parseTokensH' method in CppParser

#include "unitTest.h"
#include "../cppToken.h"

class CppParserTestOne : UnitTest {
private:
  CppToken* correct;
public:
  CppParserTestOne();
  ~CppParserTestOne();
  virtual void runTest();
  virtual void setUpTest();
};
