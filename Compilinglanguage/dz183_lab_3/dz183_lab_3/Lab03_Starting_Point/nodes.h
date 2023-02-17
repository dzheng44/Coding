//*****************************************************************************
// purpose:  This file contains the classes and methods that we will be using.
//
//  author: David Zheng
// netID: dz183
//*****************************************************************************

#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <string>

using namespace std;

// Abstract class. Base class for StringNode, IntegerNode, and FloatNode
//
// Do NOT change this class
class DataNode {
public:
    virtual void printTo(ostream &os) = 0; // pure virtual method, makes the class Abstract
    virtual ~DataNode(); // labeling the destructor as virtual allows 
	                     // the subclass destructors to be called
};

// Uses double dispatch to call the overloaded method printTo in the 
// DataNodes: StringNode, IntegerNode, and FloatNode
//
// Do NOT change this method
ostream& operator<<(ostream& os, DataNode& fn) {
	os << "Data: ";
	fn.printTo(os);
	return os;
}

// Do NOT change this method
DataNode::~DataNode() {}


class StringNode : public DataNode {
public:
    string* mystring = nullptr;

    //constructor
    StringNode(string str_input) {
	mystring = new string;
	*mystring = str_input;
    }
    
    //destructor
    ~StringNode(void) {
    	cout << "Deleting DataNode:StringNode:" << *mystring << endl;
   	}
	
    //printTo
    void printTo(ostream &os) {
	cout << "(string: " << *mystring << ") ";
	}

    // Add constructor, destructor, and printTo methods
};

class IntegerNode : public DataNode {
public:
    int myinteger = 0;
	
    //constructor
    IntegerNode(int int_input) {
	myinteger = int_input;
	}
	
    //destructor
    ~IntegerNode(void) {
	cout << "Deleting DataNode:IntegerNode:" << myinteger << endl;
	}

    //printTo
    void printTo(ostream &os) {
	cout << "(integer: " << myinteger << ") ";
	}
    // Add constructor, destructor, and printTo methods
};

class FloatNode : public DataNode {
public:	
    float myfloat = 0.0;

    //constructor
    FloatNode(float float_input) {
	myfloat = float_input;
	}

    //destructor
    ~FloatNode(void) {
	cout << "Deleting DataNode:FloatNode:" << myfloat << endl;
	}
	
    //printTo
    void printTo(ostream &os) {
	cout << "(float: " << myfloat << ") ";
	}

    // Add constructor, destructor, and printTo methods
};

#endif /* NODES_H */
