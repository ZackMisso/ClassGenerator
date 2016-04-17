#include "cpp.h"
#include <iostream>
#include <algorithm>

Cpp::Cpp() {
	// to be implemented
}

Cpp::~Cpp() {
	// to be implemented
}

void Cpp::writeClassInstance(ClassInstance* instance) {
	writeH(instance);
	writeCpp(instance);
}

ClassInstance* Cpp::readClassInstance(string name) {
	// to be implemented
	return 0x0;
}

void Cpp::writeH(ClassInstance* instance) {
	string fileName = instance->getName() + ".h";
	ofstream fout(fileName);
	string capFileName = instance->getName();
	transform(capFileName.begin(),capFileName.end(),capFileName.begin(),::toupper);
	// write Header
	fout <<"#ifndef __"<<capFileName<<"_H__"<< endl;
	fout <<"#define __"<<capFileName<<"_H__"<< endl;
	fout << endl;
	// write includes
	// write class
	fout << "class "<<instance->getName();
	if(instance->getExtends()) {
		fout <<" : public "<<instance->getParent();
	}
	fout << " {" << endl;
	// get private members
	Array<Constructor*>* privCon = instance->getPrivateConstructors();
	Array<MethodInstance*>* privMet = instance->getPrivateMethods();
	Array<VariableInstance*>* privVar = instance->getPrivateVariables();
	// get protected members
	Array<Constructor*>* protCon = instance->getProtectedConstructors();
	Array<MethodInstance*>* protMet = instance->getProtectedMethods();
	Array<VariableInstance*>* protVar = instance->getProtectedVariables();
	// get public members
	Array<Constructor*>* pubCon = instance->getPublicConstructors();
	Array<MethodInstance*>* pubMet = instance->getPublicMethods();
	Array<VariableInstance*>* pubVar = instance->getPublicVariables();
	// write private members
	fout <<"private:"<< endl;
	for(int i=0;i<privVar->getSize();i++)
		writeVariableH(privVar->get(i),fout);
	for(int i=0;i<privCon->getSize();i++)
		writeConstructorH(privCon->get(i),fout);
	for(int i=0;i<privMet->getSize();i++)
		writeMethodH(privMet->get(i),fout);
	// write protected members
	fout <<"protected:"<< endl;
	for(int i=0;i<protVar->getSize();i++)
		writeVariableH(protVar->get(i),fout);
	for(int i=0;i<protCon->getSize();i++)
		writeConstructorH(protCon->get(i),fout);
	for(int i=0;i<protMet->getSize();i++)
		writeMethodH(protMet->get(i),fout);
	// write public members
	fout <<"public:"<< endl;
	for(int i=0;i<pubVar->getSize();i++)
		writeVariableH(pubVar->get(i),fout);
	for(int i=0;i<pubCon->getSize();i++)
		writeConstructorH(pubCon->get(i),fout);
	for(int i=0;i<pubMet->getSize();i++)
		writeMethodH(pubMet->get(i),fout);
	fout <<"}"<< endl;
	fout << endl;
	fout <<"#endif"<< endl;
	// clean up
	while(privCon->getSize())
		privCon->removeLast();
	while(privMet->getSize())
		privMet->removeLast();
	while(privVar->getSize())
		privVar->removeLast();
	while(protCon->getSize())
		protCon->removeLast();
	while(protMet->getSize())
		protMet->removeLast();
	while(protVar->getSize())
		protVar->removeLast();
	while(pubCon->getSize())
		pubCon->removeLast();
	while(pubMet->getSize())
		pubMet->removeLast();
	while(pubVar->getSize())
		pubVar->removeLast();
	delete privCon;
	delete privMet;
	delete privVar;
	delete protCon;
	delete protMet;
	delete protVar;
	delete pubCon;
	delete pubMet;
	delete pubVar;
	fout.close();
}

void Cpp::writeCpp(ClassInstance* instance) {
	// to be implemented
}

void Cpp::writeConstructorH(Constructor* constructor,ofstream& fout) {
	// to be implemented
}

void Cpp::writeMethodH(MethodInstance* method,ofstream& fout) {
	// to be implemented
}

void Cpp::writeVariableH(VariableInstance* variable,ofstream& fout) {
	// to be implemented
}
