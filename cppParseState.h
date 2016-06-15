#pragma once

#include "cppToken.h"

class CppParseState {
private:
  bool inDecFile;
  bool inDefFile;
  bool inGetterMode;
  bool inSetterMode;
  bool inArguementMode;
  bool inComment;
  bool inMethod;
  bool inConstructor;
  bool inDeconstructor;
  Scope currentScope;
  void falsifyModes();
public:
  CppParseState();
  void changeScope(Scope scope);
  void modifyState(TokenType lastToken);
  void changeToDefFile();
  void chengeToDecFile();
  // getter methods
  bool getInDefFile();
  bool getInDecFile();
  bool getInGetterMode();
  bool getInSetterMode();
  bool getInArguementMode();
  bool getInComment();
  bool getInMethod();
  bool getInConstructor();
  bool getInDeconstructor();
  Scope getCurrentScope();
  // setter methods
  void setInComment(bool param);
  void setInMethod(bool param);
  void setInConstructor(bool param);
  void setInDeconstructor(bool param);
};
