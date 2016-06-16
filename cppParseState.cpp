#include "cppParseState.h"

CppParseState::CppParseState() {
  inClass = false;
  blockDepth = 0;
  inGetterMode = false;
  inSetterMode = false;
  inArguementMode = false;
  inDecFile = false;
  inDefFile = false;
  inComment = false;
  inLineComment = false;
  prevSlash = false;
  inMethod = false;
  inConstructor = false;
  inDeconstructor = false;
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

void CppParserState::changeToDefFile() {
  inDecFile = false;
  inDefFile = true;
}

void CppParserSate::changeToDecFile() {
  inDecFile = true;
  inDefFile = false;
}

void CppParserState::incrementBlockDepth() {
  blockDepth++;
}

void CppParserState::decrementBlockDepth() {
  if(blockDepth > 0) blockDepth--;
}

bool CppParserState::isInBlock() {
  return blockDepth > 0;
}

bool CppParserState::getInClass() { return inClass; }
bool CppParserState::getInDecFile() { return inDecFile; }
bool CppParserState::getInDefFile() { return inDefFile; }
bool CppParserState::getInGetterMode() { return inGetterMode; }
bool CppParserState::getInSetterMode() { return inSetterMode; }
bool CppParserState::getInArguementMode() { return inArguementMode; }
bool CppParserState::getInComment() { return inComment; }
bool CppParserState::getInLineComment() { return inLineComment; }
bool CppParserState::getPrevSlash() { return prevSlash; }
bool CppParserState::getInMethod() { return inMethod; }
bool CppParserState::getInConstructor() { return inConstructor; }
bool CppParserState::getInDeconstructor() { return inDeconstructor; }
Scope CppParserState::getCurrentScope() { return currentScope; }

void CppParserState::setInClass(bool param) { inClass = param; }
void CppParserState::setInComment(bool param) { inComment = param; }
void CppParserState::setInLineComment(bool param) { inLineComment = param; }
void CppParserState::setPrevSlash(bool param) { prevSlash = param; }
void CppParserState::setInMethod(bool param) { inMethod = param; }
void CppParserState::setInConstructor(bool param) { inConstructor = param; }
void CppParserState::setInDeconstructor(bool param) { inDeconstructor = param; }
