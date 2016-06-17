#pragma once

#include "../array.h"

class UnitTestManager {
private:
  Array<UnitTest*> unitTests;
  void initializeUnitTests();
  void runUnitTests();
  void reportResults();
public:
  UnitTestManager();
  ~UnitTestManager();
  void start();
};
