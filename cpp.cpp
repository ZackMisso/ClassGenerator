#include "cpp.h"
#include <iostream>
#include <algorithm>
#include "zstr.h"

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
	//fout <<"#ifndef __"<<capFileName<<"_H__"<< endl;
	//fout <<"#define __"<<capFileName<<"_H__"<< endl;
	fout << "#pragma once" << endl;
	fout << endl;
	// write includes
	// write class
	fout << "class " << instance->getName();
	if(instance->getExtends()) {
		fout << " : public " << instance->getParent();
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
	fout<<"// getter methods"<<endl;
	// write setter methods
	fout<<"// setter methods"<<endl;
	fout <<"}"<< endl;
	fout << endl;
	//fout <<"#endif"<< endl;
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
	// create fout
	string fileName = instance->getName() + ".cpp";
	ofstream fout(fileName);

	Array<Constructor*>* cons = instance->getConstructors();
	Array<MethodInstance*>* methods = instance->getMethods();
	Array<VariableInstance*>* vars = instance->getVariables();

	for(int i=0;i<cons->getSize();i++) {
		writeConstructorCpp(instance,cons->get(i),fout);
		fout << endl;
	}
	for(int i=0;i<methods->getSize();i++) {
		writeMethodCpp(instance,methods->get(i),fout);
		fout << endl;
	}
	for(int i=0;i<vars->getSize();i++)
		if(vars->get(i)->getHasGetter())
			writeGetterCpp(instance,vars->get(i),fout);
	fout << endl;
	for(int i=0;i<vars->getSize();i++)
		if(vars->get(i)->getHasSetter())
			writeSetterCpp(instance,vars->get(i),fout);
	fout << endl;

	fout.close();
}

void Cpp::writeConstructorCpp(ClassInstance* clas,Constructor* cons,ofstream& fout) {
	fout << clas->getName() << "::" << clas->getName() << "(";
	Array<ArguementInstance*>* args = cons->getArguements();
	for(int i=0;i<args->getSize();i++) {
		args->get(i)->writeArguement(fout);
		if(i != args->getSize()-1)
			fout << ",";
	}
	fout << ") {" << endl;
	fout << "\t// to be implemented" << endl;
	fout << "}" << endl;
}

void Cpp::writeMethodCpp(ClassInstance* clas,MethodInstance* method,ofstream& fout) {
	fout << method->getType() << " " << clas->getName() << "::" << method->getName() << "(";
	Array<ArguementInstance*>* args = method->getArguements();
	for(int i=0;i<args->getSize();i++) {
		args->get(i)->writeArguement(fout);
		if(i != args->getSize()-1)
			fout << ",";
	}
	fout << ") {" << endl;
	fout << "\t// to be implemented" << endl;
	fout << "}" << endl;
}

void Cpp::writeGetterCpp(ClassInstance* clas,VariableInstance* var,ofstream& fout) {
	fout << var->getType() << " " << clas->getName() << "::get";
	fout << ZSTR::convertToProper(var->getName()) << "() { return ";
	fout << var->getName() << "; }";
	fout << endl;
}

void Cpp::writeSetterCpp(ClassInstance* clas,VariableInstance* var,ofstream& fout) {
	fout << var->getType() << " " << clas->getName() << "::set";
	fout << ZSTR::convertToProper(var->getName()) << "() { return ";
	fout << var->getName() << "; }";
	fout << endl;
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
		fout << "static ";
	fout << method->getType();
	fout << " ";
	fout << method->getName();
	fout << "(";
	Array<ArguementInstance*>* arguements = method->getArguements();
	for(int i=0;i<arguements->getSize();i++) {
		if(i == arguements->getSize()-1)
			arguements->get(i)->writeArguement(fout);
		else {
			arguements->get(i)->writeArguement(fout);
			fout << ",";
		}
	}
	fout << ");";
	fout << endl;
}

void Cpp::writeVariableH(VariableInstance* variable,ofstream& fout) {
	if(variable->getIsStatic())
		fout << "static ";
	if(variable->getIsConst())
		fout << "const ";
	fout << variable->getType();
	fout << " ";
	fout << variable->getName();
	fout << ";";
	fout << endl;
}
