#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include <string>

using namespace std;

class Include {
private:
	string name;
	bool quotes; // ""
	bool signs; // <>
public:
	Include();
	~Include();
	// getter methods
	string getName();
	bool getQuotes();
	bool getSigns();
	// setter methods
	void setName(string param);
	void setQuotes(bool param);
	void setSigns(bool param);
};

#endif

