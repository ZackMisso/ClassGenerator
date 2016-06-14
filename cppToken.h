#pragma once

#include <string>

using namespace std;

enum TokenType {
  TOKEN_COMMENT,
  TOKEN_NONE
};

class CppToken {
private:
  TokenType type;
  CppToken* next;
  CppToken* prev;
  string contents;
public:
  CppToken();
  CppToken(string str);
  ~CppToken();
  // getter methods
  TokenType getType();
  CppToken* getNext();
  CppToken* getPrev();
  string getContents();
  // setter methods
  void setTokenType(TokenType param);
  void setNext(CppToken* param);
  void setPrev(CppToken* param);
};
