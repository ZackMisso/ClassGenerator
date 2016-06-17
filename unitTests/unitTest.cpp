#include "unitTest.h"
#include <iostream>

using namespace std;

UnitTest::UnitTest() {
  name = "undefined name";
  error = "no error";
  passed = false;
}

void UnitTest::runTest() {
  passed = false;
  error = "test not implemented";
}

void UnitTest::setUpTest() {
  // does nothing. Only extended if needed
}

void UnitTest::reportTestResult() {
  cout << name << endl;
  if(passed) {
    cout << "Passed" << endl;
    cout << "No Error" << endl;
  } else {
    cout << "Failed" << endl;
    cout << error << endl;
  }
}

string UnitTest::getName() { return name; }
string UnitTest::getError() { return error; }
bool UnitTest::getPassed() { return passed; }

void UnitTest::setName(string param) { name = param; }
void UnitTest::setError(string param) { error = param; }
void UnitTest::setPassed(bool param) { passed = param; }
