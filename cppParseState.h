#pragma once

#include "cppToken.h"

class CppParseState {
private:
  bool inGetterMode;
  bool inSetterMode;
  bool inArguementMode;
  Scope currentScope;
  void falsifyModes();
public:
  CppParseState();
  void changeScope(Scope scope);
  void modifyState(TokenType lastToken);
  // getter methods
  bool getInGetterMode();
  bool getInSetterMode();
  bool getInArguementMode();
  Scope getCurrentScope();
};
