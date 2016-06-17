#pragma once

// These are all helper methods for dealing with strings and char*s

#include <string>

using namespace std;

class ZSTR {
public:
  static string convertToProper(string str);
  static string convertToLower(string str);
  static string convertToUpper(string str);
  static string getSubString(const char* str,int start,int end);
  static int getFirstNonSpacePos(const char* str,int start);
  static int getNextPosForCharacters(const char* str,int start,char one,char two);
  static int getSpacesBetween(const char* str,int start,int end);
};
