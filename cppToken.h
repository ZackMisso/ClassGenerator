#pragma once

// Represents a Linked List of Tokens

#include <string>

using namespace std;

enum TokenType {
  TOKEN_START,
  TOKEN_COMMENT,
  TOKEN_PRAGMA,
  TOKEN_INCLUDE,
  TOKEN_SCOPE,
  TOKEN_VARIABLE,
  TOKEN_FUNC,
  TOKEN_ARGUEMENT,
  TOKEN_ARGUEMENT_START,
  TOKEN_ARGUEMENT_END,
  TOKEN_CONSTRUCTOR,
  TOKEN_DESTRUCTOR,
  TOKEN_GETTER_START,
  TOKEN_SETTER_START,
  TOKEN_GETTER,
  TOKEN_SETTER,
  TOKEN_CLASS,
  TOKEN_UNKNOWN, // since this doesn't support everything
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
  CppToken(TokenType t);
  CppToken(string str);
  ~CppToken();
  void insertNext(CppToken* other);
  void insertPrev(CppToken* other);
  void addToBack(CppToken* tok);
  void addToFront(CppToken* tok);
  int length();
  CppToken* remove();
  CppToken* getFirst();
  CppToken* getLast();
  // getter methods
  TokenType getType();
  CppToken* getNext();
  CppToken* getPrev();
  string getContents();
  // setter methods
  void setTokenType(TokenType param);
  void setContents(string param);
protected:
  void setNext(CppToken* param);
  void setPrev(CppToken* param);
};
