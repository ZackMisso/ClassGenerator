#include "cppToken.h"

CppToken::CppToken() {
  // to be implemented
}

CppToken::CppToken(string str) {
  // to be implemented
}

CppToken::~CppToken() {
  // to be implmeneted
}

TokenType CppToken::getType() { return type; }
CppToken* CppToken::getNext() { return next; }
CppToken* CppToken::getPrev() { return prev; }
string CppToken::getContents() { return contents; }

void CppToken::setType(TokenType param) { type = param; }
void CppToken::setNext(CppToken* param) { next = param; }
void CppToken::setPrev(CppToken* param) { prev = param; }
void CppToken::setContents(string param) { contents = param; }
