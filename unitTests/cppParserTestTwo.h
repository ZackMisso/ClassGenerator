#pragma once

// this test tests the 'parseTokensCpp' method in CppParser

#include "unitTest.h"
#include "../cppToken.h"

class CppParserTestTwo : UnitTest {
private:
  CppToken* correct;
public:
  CppParserTestTwo();
  ~CppParserTestTwo();
  virtual void runTest();
  virtual void setUpTest();
};
