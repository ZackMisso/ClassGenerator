#include "unitTestManager.h"

UnitTestManager::UnitTestManager() {
  unitTests = new Array<UnitTest*>();
}

void UnitTestManager::initializeUnitTests() {
  // to be implemented
}

void UnitTestManager::runUnitTests() {
  for(int i=0;i<unitTests->getSize();i++) {
    unitTests->get(i)->setUpTest();
    unitTests->get(i)->runTest();
  }
}

void UnitTestManager::reportResults() {
  for(int i=0;i<unitTests->getSize();i++) {
    unitTests->reportTestResult();
  }
}

void UnitTestManager::start() {
  initializeUnitTests();
  runUnitTests();
  reportResults();
}
