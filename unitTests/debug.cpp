#include "debug.h"
#include <iostream>

using namespace std;


void Debug::printAllTokens(CppToken* token) {
  CppToken* tmp = token;
  while(tmp) {
    switch(tmp->getType()) {
      case TOKEN_COMMENT: {
        cout << "Comment Token" << endl;
	break;
      }
      case TOKEN_PRAGMA: {
        cout << "Pragma Token" << endl;
	break;
      }
      case TOKEN_INCLUDE: {
        cout << "Include Token" << endl;
	break;
      }
      case TOKEN_SCOPE: {
        cout << "Scope Token" << endl;
	break;
      }
      case TOKEN_VARIABLE: {
        cout << "Variable Token" << endl;
	break;
      }
      case TOKEN_FUNC: {
        cout << "Method Token" << endl;
	break;
      }
      case TOKEN_ARGUEMENT: {
        cout << "Arguement Token" << endl;
	break;
      }
      case TOKEN_ARGUEMENT_START: {
        cout << "Arguement Start Token" << endl;
	break;
      }
      case TOKEN_ARGUEMENT_END: {
        cout << "Arguement End Token" << endl;
	break;
      }
      case TOKEN_CONSTRUCTOR: {
        cout << "Constructor Token" << endl;
	break;
      }
      case TOKEN_DESTRUCTOR: {
        cout << "Destructor Token" << endl;
	break;
      }
      case TOKEN_GETTER_START: {
        cout << "Getter Start Token" << endl;
	break;
      }
      case TOKEN_SETTER_START: {
        cout << "Setter Start Token" << endl;
	break;
      }
      case TOKEN_GETTER: {
        cout << "Getter Token" << endl;
	break;
      }
      case TOKEN_SETTER: {
        cout << "Setter Token" << endl;
	break;
      }
      case TOKEN_CLASS: {
        cout << "Class Token" << endl;
	break;
      }
      case TOKEN_UNKNOWN: {
        cout << "Unknown Token" << endl;
	break;
      }
      default: {
        cout << "Invalid Token" << endl;
	break;
      }
    }
    tmp = tmp->getNext();
  }
}
