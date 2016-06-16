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
  // this first part narrows down the next potential token by looking at the contents
  // of the file.
  //
  // pragmas, ifndef, include, etc can be located by reading a '#'.
  // Variables, Methods, Constructors, and Deconstructors will all have a ';' or '{ }'
  // Comments will have '/* */' and Line Comments will have '//'
  // Scope changes will have a ':'
  //
  // By looking for these key characters or pairs of characters we can narrow down the
  // potential token type and then do a simple parse of the selected content afterwards
  // to get the exact token.

  int currentIndex = startIndex; // current index in the file
  PossibleState keyFound = NONE; // current possible state
  while(keyFound == NONE) {
    // switch depending on the character

    switch(file[currentIndex]) {
      case '/': {
        // If the character is a '/' then it can be one of four cases:
	// 1. If the character is in a block or a line comment, ignore it
	// 2. If the character is in a comment, check if it was preceded
	//    by a '*', if so, declare that the possible token is comment
	// 3. If the character is not in a line or regular comment, check
	//    if it was preceeded by a '/'. If so, this is a line comment
	// 4. Otherwise, set the prev slash to true and continue parsing
        
	if(state->getInBlock() || state->getInLineComment()) currentIndex++;
        else if(state->getInComment()) {
          if(state->getPrevSlash()) keyFound = COMMENT;
        }
        else if(state->getPrevSlash()) keyFound = LINE_COMMENT;
        else {
          state->setPrevSlash(true);
          currentIndex++;
        }
        break;
      }
      case '*': {
        // If the character is a '*' then it can be one of 4 cases:
	// 1. If the character is in a line comment, ignore it.
	// 2. If the character is preceded by a slash, set the state
	//    to be inside a comment.
	// 3. If the character is inside a comment, set the prev
	//    slash state to true
	// 4  Otherwise set prev slash to false and carry on

        if(state->getInLineComment()) currentIndex++;
        else if(state->getPrevSlash() && !state->getInComment()) {
          state->setPrevSlash(false);
          state->setInComment(true);
          currentIndex++;
        } else if(state->getInComment()) {
          state->setPrevSlash(true);
          currentIndex++;
        } else {
          state->setPrevSlash(false);
          currentIndex++;
        }
        break;
      }
      case ':': { // TODO : Incorporate using ':' for inheritence
        // If the character is a ':' then it can be one of 3 cases:
	// 1. If the character is in a block or comment, ignore it
	// 2. If the character is in a .cpp file, ignore it
	// 3. Otherwise it is at the end of a scope declaration

        if(state->getInComment() || state->getInLineComment() || state->getInBlock()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else if(state->getInDef()) { 
	  state->setPrevSlash(false);
	  currentIndex++;
	}else {
          keyFound = SCOPE;
        }
        break;
      }
      case ';': { // TODO : Incorporate using ';' for static setting
        // If the character is a ';' then it can be one of 3 cases:
	// 1. If the character is in a block or comment, ignore it
	// 2. If the character is in a .cpp file, ignore it
	// 3. Other wise it is at the end of a method/variable dec.

        if(state->getInComment() || state->getInLineComment() || state->getInBlock()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else if(state->getInDef()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else {
          keyFound = METHOD_VARIABLE_CONST_DECONS;
        }
        break;
      }
      case '\n': { // Still not sure if this should be used. The parser
                   // shouldn't have to depend on individual lines
        //if(!state->getInComment() && !state->getInLineComment()) {
        //  // to be implemented
        //} else {
        //  //keyFound = '\n';
        //}
	currentIndex++;
        break;
      }
      case '\0': {
        // If the character is a '\0' then it can be one of 2 cases:
	// 1. If the character is in a block or comment, ignore it
	// 2. Otherwise it represents the end of the file

        if(state->getInComment() || state->getInLineComment() || state->getInBlock()) {
          state->setPrevSlash(false);
          currentIndex++;
	} else {
          keyFound = END;
	}  
        break;
      }
      case '{': {
        // If the character is a '{' then it can be one of 2 cases:
	// 1. If the character is in a block or comment, ignore it
	// 2. Otherwise it represents the beginning of a block

        if(state->getInComment() || state->getInLineComment() || state->getInBlock()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else {
	  state->setPrevSlash(false);
	  state->setInBlock(true);
	  currentIndex++;
        }
        break;
      }
      case '}': {
        // TODO :: ERROR IN LOGIC, BLOCK WILL EXIT INCORRECTLY AT THE
	// FIRST '}' THAT APPEARS..... make a counter
        if(!state->getInComment() && !state->getInLineComment()) {
          state->setPrevSlash(false);
          // to be implemented
          currentIndex++;
        } else {
          keyFound = ENDBLOCK;
        }
        break;
      }
      default: {
        state->setPrevSlash(false);
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
