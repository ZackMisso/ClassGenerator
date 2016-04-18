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
		writeConstructorH(instance,privCon->get(i),fout);
	for(int i=0;i<privMet->getSize();i++)
		writeMethodH(privMet->get(i),fout);
	// write protected members
	fout <<"protected:"<< endl;
	for(int i=0;i<protVar->getSize();i++)
		writeVariableH(protVar->get(i),fout);
	for(int i=0;i<protCon->getSize();i++)
		writeConstructorH(instance,protCon->get(i),fout);
	for(int i=0;i<protMet->getSize();i++)
		writeMethodH(protMet->get(i),fout);
	// write public members
	fout <<"public:"<< endl;
	for(int i=0;i<pubVar->getSize();i++)
		writeVariableH(pubVar->get(i),fout);
	for(int i=0;i<pubCon->getSize();i++)
		writeConstructorH(instance,pubCon->get(i),fout);
	for(int i=0;i<pubMet->getSize();i++)
		writeMethodH(pubMet->get(i),fout);
	// write getter methods
	// write setter methods
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

void Cpp::writeConstructorH(ClassInstance* instance,Constructor* constructor,ofstream& fout) {
	fout<<instance->getName();
	fout<<"(";
	for(int i=0;i<constructor->getArguements()->getSize();i++) {
		if(i == constructor->getArguements()->getSize()-1)
			constructor->getArguements()->get(i)->writeArguement(fout);
		else {
			constructor->getArguements()->get(i)->writeArguement(fout);
			fout<<",";
		}
	}
	fout<<");";
	fout<<endl;
}

void Cpp::writeMethodH(MethodInstance* method,ofstream& fout) {
	if(method->getIsStatic())
		fout <<"static ";
	fout<<type;
	fout<<" ";
	fout<<name;
	fout<<"(";
	for(int i=0;i<arguements->getSize();i++) {
		if(i==arguements->getSize()-1)
			fout<<arguements->get(i)->writeArguement(fout);
		else {
			fout<<arguements->get(i)->writeArguement(fout);
			fout<<",";
		}
	}
	fout<<";";
	fout<<endl;
}

void Cpp::writeVariableH(VariableInstance* variable,ofstream& fout) {
	if(variable->getIsStatic())
		fout<<"static ";
	if(variable->getIsConst())
		fout<<"const ";
	fout<<type;
	fout<<" ";
	fout<<name;
	fout<<";"
	fout<<endl;
}
