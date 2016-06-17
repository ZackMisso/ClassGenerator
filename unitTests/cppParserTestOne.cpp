#include "cppParserTestOne.h"
#include "cppParser.h"
#include "debug.h"

CppParserTestOne::CppParserTestOne() {
  correct = 0x0;
}

CppParserTestOne::~CppParserTestOne() {
  if(correct) delete correct;
}

void CppParserTestOne::runTest() {
  const char* file = ZSTR::readFile("unitTests/cppParserTestOne.txt");
  CppToken* parsed = parseTokensH(file);
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
    tmpParsed - tmpParsed->getNext();
  }
  // if no mismatch, the test is passed
  setPassed(true);
  delete parsed;
  //delete file;
}

void CppParserTestOne::setUpTest() {
  correct = new CppToken(TOKEN_PRAGMA);               // #pragma once
  correct->addToBack(new CppToken(TOKEN_CLASS));      // class TestClass {
  correct->addToBack(new CppToken(TOKEN_SCOPE));      // private:
  correct->addToBack(new CppToken(TOKEN_VARIABLE));   // int num;
  correct->addToBack(new CppToken(TOKEN_VARIABLE));   // float numf;
  correct->addToBack(new CppToken(TOKEN_VARIABLE));   // Object* obk;
  correct->addToBack(new CppToken(TOKEN_SCOPE));      // public:
  correct->addToBack(new CppToken(TOKEN_CONSTRUCTOR));// TestClass();
  correct->addToBack(new CppToken(TOKEN_DESTRUCTOR)); // ~TestClass();
  correct->addToBack(new CppToken(TOKEN_FUNC));       // void thisIsATest();
  correct->addToBack(new CppToken(TOKEN_FUNC));       // void thisIsAVirtualTest();
  correct->addToBack(new CppToken(TOKEN_COMMENT));    // // this is a test line comment
  correct->addToBack(new CppToken(TOKEN_COMMENT));    // /* this is a test comment */
  correct->addToBack(new CppToken(TOKEN_UNKNOWN));    // };
}
