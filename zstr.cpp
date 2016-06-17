#include "zstr.h"

string ZSTR::convertToProper(string str) {
  // to be implemented
  return "test";
}

string ZSTR::convertToLower(string str) {
  // to be implemented
  return "test";
}

string ZSTR::convertToUpper(string str) {
  // to be implemented
  return "test";
}

string ZSTR::getSubString(const char* str,int start,int end) {
  // to be implemented
  return "test";
}

string ZSTR::getFirstNonSpacePos(const char* str,int start) {
  // to be implemented
  return start;
}

int ZSTR::getNextPosForCharacters(const char* str,int start,char one,char two) {
  int index = start;
  while(str[index] != one && str[index] != two && str[index] != '\0') index++;
  return index;
}

int ZSTR::getSpacesBetween(const char* str,int start,int end) {
  int index = start;
  int spaces = 0;
  bool prevSpace = false;
  while(index != end) {
    if((str[index] == ' ' || str[index] == '\t') && !prevSpace) {
      spaces++;
      prevSpace = true;
    }
    else prevSpace = false;
  }
  return spaces;
}

const char* ZSTR::readFile(string fileName) {
  // to be implemented
  return "test";
}
