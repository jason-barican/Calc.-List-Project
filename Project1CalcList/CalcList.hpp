//Jason Barican U18728557
//Samuel Sau U44954874

#ifndef CALCLIST_H
#define CALCLIST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "CalcListInterface.hpp"

/*
File for function declarations + macro definitions and creation of Circular Linked List Class
*/

class CalcNode {

	/*class of a circular list node*/
	friend class CalcList;

	CalcNode* next;

	FUNCTIONS node_operator;

	double total;

	double operand;
};

class CalcList:public CalcListInterface
{
private:
    //current pointer that traverses through the linked list
	CalcNode* current;

	//counts how many operations were done
	int operation_count = 0;

public:
	//Constructor
	CalcList();

	//Destructor
	~CalcList();

	/*functions*/
	//returns current total of CalcList
	double total() const;

	//creates new total and adds operation to CalcList
	void newOperation(const FUNCTIONS func, const double operand);

	//Restores previous total and removes last operation - "undo feature"
	void removeLastOperation();

	//returns operations as strings with fixed precision
	std::string toString(unsigned short precision) const;
};
#endif //!CALCLIST_H


