#pragma once

class UnitTest {
private:
  string name;
  string error;
  bool passed;
public:
  UnitTest();
  virtual void runTest();
  virtual void setUpTest();
  void reportTestResult();
  // getter methods
  string getName();
  string getError();
  bool getPassed();
  // setter methods
  void setName(string param);
  void setError(string param);
  void setPassed(bool param);
};
