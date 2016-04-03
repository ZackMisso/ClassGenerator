#include "include.h"

Include::Include() {
	quotes = true;
	signs = false;
}

Include::~Include() { }

string Include::getName() { return name; }
bool Include::getQuotes() { return quotes; }
bool Include::getSigns() { return signs; }

void Include::setName(string param) { name = param; }
void Include::setQuotes(bool param) { quotes = param; }
void Include::setSigns(bool param) { signs = param; }
