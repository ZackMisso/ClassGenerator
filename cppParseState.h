#pragma once

#include "cppToken.h"

class CppParseState {
private:
  bool inClass;
  bool inDecFile;
  bool inDefFile;
  bool inGetterMode;
  bool inSetterMode;
  bool inArguementMode;
  bool inComment;
  bool inLineComment;
  bool prevSlash;
  bool inMethod;
  bool inConstructor;
  bool inDeconstructor;
  int blockDepth;
  Scope currentScope;
  void falsifyModes();
public:
  CppParseState();
  void changeScope(Scope scope);
  void modifyState(TokenType lastToken);
  void changeToDefFile();
  void chengeToDecFile();
  void incrementBlockDepth();
  void decrementBlockDepth();
  bool isInBlock();
  // getter methods
  bool getInClass();
  bool getInDefFile();
  bool getInDecFile();
  bool getInGetterMode();
  bool getInSetterMode();
  bool getInArguementMode();
  bool getInComment();
  bool getInLineComment();
  bool getPrevSlash();
  bool getInMethod();
  bool getInConstructor();
  bool getInDeconstructor();
  Scope getCurrentScope();
  // setter methods
  void setInClass(bool param);
  void setInComment(bool param);
  void setInLineComment(bool param);
  void setPrevSlash(bool param);
  void setInMethod(bool param);
  void setInConstructor(bool param);
  void setInDeconstructor(bool param);
};
