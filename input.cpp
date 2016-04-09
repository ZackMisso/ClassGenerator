#include "input.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

Input::Input() { }

Input::~Input() { }

int Input::getIntInput() {
	int num;
	cin >> num;
	return num;
}

string Input::getStringInput() {
	string str;
	cin >> str;
	return str;
}

string Input::getLineInput() {
	string line;
	getline(cin,line);
	return line;
}

vector<string>* Input::breakLineInput(string line) {
	vector<string>* strings = new vector<string>();
	istringstream iss(line);
	copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(*strings));
	return strings;
}
