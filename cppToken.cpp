#include "cppToken.h"

CppToken::CppToken() {
  type = TOKEN_NONE;
  next = 0x0;
  prev = 0x0;
}

CppToken::CppToken(string str) {
  type = TOKEN_NONE;
  next = 0x0;
  prev = 0x0;
  contents = str;
}

CppToken::~CppToken() {
  if(next) delete next;
  prev = 0x0;
}

void CppToken::insertNext(CppToken* other) {
  if(next) next->setPrev(other);
  next = other;
}

void CppToken::insertPrev(CppToken* other) {
  if(prev) prev->setNext(other);
  prev = other;
}

CppToken* CppToken::remove() {
  if(prev) prev->setNext(next);
  if(next) next->setPrev(prev);
  return this;
}

CppToken* CppToken::getFirst() {
  return !prev ? this : prev->getFirst();
}

CppToken* CppToken::getLast() {
  return !next ? this : next->getLast();
}

TokenType CppToken::getType() { return type; }
CppToken* CppToken::getNext() { return next; }
CppToken* CppToken::getPrev() { return prev; }
string CppToken::getContents() { return contents; }

void CppToken::setType(TokenType param) { type = param; }
void CppToken::setNext(CppToken* param) { next = param; }
void CppToken::setPrev(CppToken* param) { prev = param; }
void CppToken::setContents(string param) { contents = param; }
