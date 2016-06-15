#pragma once

#include <string>

using namespace std;

class ZSTR {
public:
  static string convertToProper(string str);
  static string convertToLower(string str);
  static string convertToUpper(string str);
  static string getSubString(const char* str,int start,int end);
};
