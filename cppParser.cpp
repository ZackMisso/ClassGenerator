#include "cppParser.h"
#include "zstr.h"

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
  state->changeToDecFile();

  while(currentToken != TOKEN_NONE) {
    lastToken = currentToken;
    int nextIndex = getNextToken(fileC,index,currentToken,state);
    state->modifyState(currentToken);
    if(currentToken != TOKEN_NONE) {
      CppToken* newToken = new CppToken();
      newToken->setType(currentToken);
      newToken->setContents(ZSTR::getSubString(fileC,index,nextIndex));

      if(lastToken) lastToken->insertNext(newToken);
      else {
        lastToken = newToken;
	tokens = newToken;
      }
    }
    index = nextIndex;
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
  state->changeToDefFile();

  while(currentToken != TOKEN_NONE) {
    lastToken = currentToken;
    int nextIndex = getNextToken(fileC,index,currentToken,state);
    state->modifyState(currentToken);
    if(currentToken != TOKEN_NONE) {
      CppToken* newToken = new CppToken();
      newToken->setType(currentToken);
      newToken->setContents(ZSTR::getSubString(fileC,index,nextIndex));

      if(lastToken) lastToken->insertNext(newToken);
      else {
        lastToken = newToken;
	tokens = newToken;
      }
    }
    index = nextIndex;
  }
}

// parses a little bit into the file and returns the next token type,
// as well as where it ends
int CppParser::getNextToken(const char* file,int startIndex,TokenType& type,CppParseState* state) {
  int currentIndex = startIndex;
  // possible end states for the next token
  const char* keys = "#:;\n\0";
  int keyFound = -1;
  // find the potential end of the next token
  while(keyFound==-1) {
    switch(file[currentIndex]) {
      case '/': {
        if(state->getInBlock() || state->getInLineComment()) currentIndex++;
        else if(state->getInComment()) {
          if(state->getPrevSlash()) keyFound = 'c';
        }
        else if(state->getPrevSlash()) keyFound = '/';
        else if(state->getInBlock()) currentIndex++;
        else {
          state->setPrevSlash(true);
          currentIndex++;
        }
        break;
      }
      case '*': {
        if(state->getInLineComment()) currentIndex++;
        else if(state->getPrevSlash() && !state->getInComment()) {
          state->setPrevSlash(false);
          state->setInComment(true);
          currentIndex++;
        } else if(!state->getPrevSlash() && state->getInComment()) {
          state->setPrevSlash(true);
          currentIndex++;
        } else {
          state->setPrevSlash(false);
          currentIndex++;
        }
        break;
      }
      case ':': {
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implemented
          currentIndex++;
        } else if(state->getInBlock()) {
          currentIndex++;
        } else {
          keyFound = ':';
        }
        break;
      }
      case ';': {
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implementefd
          currentIndex++;
        } else if(state->getInBlock()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else {
          keyFound = ':';
        }
        break;
      }
      case '\n': {
        if(!state->getInComment() && !state->getInLineComment()) {
          // to be implemented
        } else {
          //keyFound = '\n';
        }
        break;
      }
      case '\0': {
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implemented
          keyFound = '\0';
        } else {
          keyFound = ':';
        }
        break;
      }
      case '{': {
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implemented
          currentIndex++;
        } else {
          //keyFound = ':';
        }
        break;
      }
      case '}': {
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implemented
          currentIndex++;
        } else {
          keyFound = '}';
        }
        break;
      }
      default: {
        state->setPrevSlash(false);
        // to be implemented
        currentIndex++;
        break;
      }
    }
  }
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
