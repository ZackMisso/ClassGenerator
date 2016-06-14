#include "cppParser.h"

void CppParser::readClass(string file,ClassInstance* clas) {
  // attach extensions to fine name
  string hfile = file;   // add extension
  string cppfile = file; // add extension
  // read both .h and .cpp files as tokens
  CppToken* htoks = parseTokensH(hfile);
  CppToken* cpptoks = parseTokensCpp(cppfile);
  // create the class by parsing the tokens
  parseClassH(htoks,clas);
  parseClassCpp(cpptoks,clas);
}

CppToken* CppParser::parseTokensH(string file) {
  const char* fileC; // convert file to char*
  int index = 0;
  TokenType lastToken = TOKEN_START;
  TokenType currentToken = TOKEN_START;
  CppParseState* state = new CppParseState();
  CppTokens* tokens = 0x0;
  CppTokens* lastToken = 0x0; // keep a reference to last for speed

  while(currentToken != TOKEN_NONE) {
    lastToken = currentToken;
    int nextIndex = getNextToken(fileC,index,currentToken,state);
    state->modifyState(currentToken);
    if(currentToken != TOKEN_NONE) {
      CppToken* newToken = new CppToken();

      // to be implemented
      
      if(lastToken) lastToken->insertNext(newToken);
      else {
        lastToken = newToken;
	tokens = newToken;
      }
    }
  }
}

CppToken* CppParser::parseTokensCpp(string file) {
  const char* fileC; // convert file to char*
  int index = 0;
  TokenType lastToken = TOKEN_START;
  TokenType currentToken = TOKEN_START;
  CppParseState* state = new CppParseState();
  CppToken* tokens = 0x0;
  CppToken* lastToken = 0x0; // keep a reference to last for speed

  while(currentToken != TOKEN_NONE) {
    lastToken = currentToken;
    int nextIndex = getNextToken(fileC,index,currentToken,state);
    state->modifyState(currentToken);
    if(currentToken != TOKEN_NONE) {
      CppToken* newToken = new CppToken();
      
      // to be implemented
      
      if(lastToken) lastToken->insertNext(newToken);
      else {
        lastToken = newToken;
	tokens = newToken;
      }
    }
  }
}

// parses a little bit into the file and returns the next token type,
// as well as where it ends
int CppParser::getNextToken(const char* file,int startIndex,TokenType& type,CppParseState* state) {
  // to be implemented
  // this will be a doozy
  return -1;
}

// starts to initialize the class instance from what is known from
// parsing the .h file
void CppParser::parseClassH(CppToken* htok,ClassInstance* clas) {
  // to be implemented
}

// finishes initializing the class instance from what is known from
// parsing the .cpp file
void CppParser::parseClassCpp(CppToken* cpptok,ClassInstance* clas) {
  // to be implemented
}
