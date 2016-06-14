#include "cppParseState.h"

CppParseState::CppParseState() {
  inGetterMode = false;
  inSetterMode = false;
  inArguementMode = false;
  Scope currentScope = SCOPE_PUBLIC;
}

void CppParseState::falsifyModes() {
  inGetterMode = false;
  inSetterMode = false;
  //inArguementMode = false;
}

void CppParseState::changeScope(Scope scope) {
  currentScope = scope;
}

void CppParseState::modifyState(TokenType lastToken) {
  if(lastToken == TOKEN_GETTER_START) {
    falsifyModes();
    inGetterMode = true;
  }
  if(lastToken == TOKEN_SETTER_START) {
    falsifyModes();
    inSetterMode = true;
  }
  if(lastToken == TOKEN_ARGUEMENT_START) {
    inArguementMode = true;
  }
  if(lastToken == TOKEN_ARGUEMENT_END) {
    inArguementMode = false;
  }
  if(lastToken == TOKEN_SCOPE) {
    if(lastToken.getContents() == "public") changeScope(SCOPE_PUBLIC);
    else if(lastToken.getContents() == "private") changeScope(SCOPE_PRIVATE);
    else if(lastToken.getContents() == "protected") changeScope(SCOPE_PROTECTED);
    else changeScope(SCOPE_PUBLIC);
  }
}

bool CppParserState::getInGetterMode() { return inGetterMode; }
bool CppParserState::getInSetterMode() { return inSetterMode; }
bool CppParserState::getInArguementMode() { return inArguementMode; }
Scope CppParserState::getCurrentScope() { return currentScope; }
