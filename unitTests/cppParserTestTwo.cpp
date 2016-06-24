#include "cppParserTestTwo.h"

CppParserTestTwo::CppParserTestTwo() {
  correct = 0x0;
}

CppParserTestTwo::~CppParserTestTwo() {
  if(correct) delete correct;
}

void CppParserTestTwo::runTest() {
  const char* file = ZSTR::readfile("unitTests/cppParserTestTwo.txt");
  CppToken* parsed = parseTokensCpp(file);
  // print out all the tokens
  Debug::printAllTokens(parsed);
  // check if the wrong number of tokens were parsed
  if(token->length() != parsed->length()) {
    setError("Size MisMatch");
    setPassed(false);
    return;
  }
  CppToken* tmpCorrect = correct;
  CppToken* tmpParsed = parsed;
  // check each token for a type mismatch
  while(tmpCorrect) {
    if(tmpCorrect->getType() != tmpParsed->getType()) {
      setError("Type MisMatch");
      setPassed(false);
      return;
    }
    tmpCorrect = tmpCorrect->getNext();
    tmpParsed = tmpParsed->getNext();
  }
  // if no mismatch, the test passed
  setPassed(true);
  //delete file;
}

void CppParserTestTwo::setUpTest() {
  correct = new CppToken(TOKEN_INCLUDE);              // #include "testClass.h"
  correct->addToBack(new CppToken(TOKEN_CONSTRUCTOR));// TestClass::TestClass() { }
  correct->addToBack(new CppToken(TOKEN_DESTRUCTOR)); // TestClass::~TestClass() { }
  correct->addToBack(new CppToken(TOKEN_FUNC));       // TestClass::thisIsATest() { }
  correct->addToBack(new CppToken(TOKEN_FUNC));       // TestClass::thisIsAVirtualTest() { }
}
