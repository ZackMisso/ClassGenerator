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

	      if(state->isInBlock() || state->getInLineComment()) currentIndex++;
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
        // 1. If the character is in a line comment or block ignore it.
        // 2. If the character is preceded by a slash, set the state
        //    to be inside a comment.
        // 3. If the character is inside a comment, set the prev
        //    slash state to true
        // 4  Otherwise set prev slash to false and carry on

        if(state->getInLineComment() || state->isInBlock()) currentIndex++;
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

        if(state->getInComment() || state->getInLineComment() || state->isInBlock()) {
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

        if(state->getInComment() || state->getInLineComment() || state->isInBlock()) {
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
	      // 1. If the character is in a comment, ignore it
        // 2. Otherwise increment the block depth

        if(state->getInComment() || state->getInLineComment()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else {
          state->setPrevSlash(false);
          state->incrementBlockDepth();
          currentIndex++;
        }
        break;
      }
      case '}': {
        // If the character is a '}' then it can be one of 3 cases:
        // 1. If the character is in a comment, ignore it
        // 2. If the character is in a block, decrement the depth
        // 3. Otherwise it is in the end of a class
        // 3rd case is not implemented yet

        if(state->getInComment() || state->getInLineComment()) {
          state->setPrevSlash(false);
          currentIndex++;
        } else if(state->isInBlock()) {
          state->decrementBlockDepth();
          if(!state->isInBlock()) {
            keyFound = ENDBLOCK;
          }
        } else {
          keyFound = UNKNOWN; // <-- could be end of class later
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

  // Now we have reduced it to a specific set of possible states.
  // Here is a switch that handles each one's logic
  switch(keyFound) {
    case ENDBLOCK:
    case METHOD_VARIABLE_CONS_DECONS: {
      // to be implemented <-- convoluted one
      // Logic:
      //  - Find the first non-space character
      //  - If it is a '~', it is a destructor
      //  - Else traverse until you hit a ';' or a '('
      //  - While you traverse keep track of the number of gaps
      //  - If you hit a ';' first, then it is a variable
      //  - Otherwise it is either a method or a constructor
      //  - If the number of spaces between the '(' and first character
      //    is one then it is a method, because it has a type.
      //  - If the number of spaces is zero, it is a constructor

      int index = ZSTR::getFirstNonSpacePos(file,startIndex);
      if(file[index] == '~') type = TOKEN_DESTRUCTOR;
      else {
        int index = ZSTR::getNextPosForCharacters(';','(');
        if(file[index] == ';') type = TOKEN_VARIABLE;
        else {
          int spaces = ZSTR::getSpacesBetween(file,startIndex,index);
          if(spaces == 0) type = TOKEN_CONSTRUCTOR;
          else type = TOKEN_FUNC;
        }
      }
      break;
    }
    case PRAGMA_OR_INCLUDE: {
      // find the end of the line
      int indexOfPound = currentIndex;
      while(file[currentIndex] != '\n') currentIndex++;
      if(file[indexOfPound+1] == 'i' && file[indexOfPound+2] == 'n') type = TOKEN_INCLUDE;
      else type = TOKEN_PRAGMA;
      // TODO :: implement define, ifndef, etc.
      break;
    }
    case COMMENT: {
      type = TOKEN_COMMENT;
      break;
    }
    case LINE_COMMENT: {
      type = TOKEN_COMMENT;
      // find the end of the line
      while(file[currentIndex] != '\n') currentIndex++;
      break;
    }
    case SCOPE: {
      type = TOKEN_SCOPE;
      break;
    }
    case GETTER_OR_SETTER: {
      // not going to be used for now
      type = TOKEN_UNKNOWN;
      break;
    }
    case UNKNOWN: {
      type = TOKEN_UNKNOWN;
      break;
    }
    case ENDCLASS: {
      // not going to be used for now
      type = TOKEN_UNKNOWN;
      break;
    }
    case END: {
      type = TOKEN_UNKNOWN;
      break;
    }
    default: {
      // this should not be reached, throw error...
      type = TOKEN_UNKNOWN;
      break;
    }
  }

  return currentIndex;
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
