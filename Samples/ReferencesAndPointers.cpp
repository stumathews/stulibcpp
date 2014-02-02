// ReferencesAndPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

/* Forward declrations to make our following intentions clear */
void printVector(const std::vector<std::string>* const list);
const std::string* getLastValueOfVector(const std::vector<std::string>* const vector);
const std::string* getLastValueOfVector(const std::vector<std::string>& rVector);

int _tmain(int argc, _TCHAR* argv[])
{
	std::string myName("Stuart");
	std::string yourName = "Jenny";
	std::vector<std::string> names;

	names.push_back(myName);
	names.push_back(yourName);
		
	// Lets pass the list to a function, but function please dont modify it ok?
	printVector(&names);
	
	// lets get the last value of the list. Pass it as a constand pointer to a constant
	const std::string* last_value = getLastValueOfVector(&names);
	// last value is not a constant pointer so it can be reassigned...

	// pass vector, names as a reference, specifically as a constant reference.
	// NB:** note that the argument is cast to the function specified argument type...
	last_value = getLastValueOfVector(names);
	// get the last value	
	std::cout << "The last character in the vector is : " << *last_value << std::endl;
	std::cout << "Its memory location is " << last_value << std::endl;
	// assigning value that a pointer points to to a normal variable, copies the value to new variable..
	const std::string COPYlast_value  = *last_value;
	// Varify that we got a copy, address should be diffirent but value should be the same.
	std::cout << "copy of last value is " << COPYlast_value << std::endl;
	std::cout << "Its memory location is " << &COPYlast_value << std::endl;
	// create a reference to a variable...you cant change the value on the other end of reference
	// as its a constant reference.
	const std::string& rCOPYlast_value = COPYlast_value;
	std::cout << "reference to last value is " << rCOPYlast_value << std::endl;
	
	// Lets just hang about until someones pressess something...hey isn't that a big red button over there?
	char any;
	std::cin >> any;

	return 0;
}

// prints a vector of strings, passing it as a pointer which cannot change or be changed.
void printVector(const std::vector<std::string>* const list)
{
	std::cout << "Printing all the names in list, it was passed as a constant pointer to a constant\n";
	for (std::vector<std::string>::const_iterator c_iter = list->begin(); c_iter != list->end(); c_iter++)
	{
		std::cout << *c_iter << std::endl;
	}
}

/**
Gets the last value of a vector. Cannot modify vector in anyway. cannot modify returned value
in any way.
*/
const std::string* getLastValueOfVector(const std::vector<std::string>* const vector)
{
	return &((*vector)[vector->size()-1]);
}

// Overload
const std::string* getLastValueOfVector(const std::vector<std::string>& rVector)
{
	// cant change value that the reference references!
	// also references by defualt cannot be reassigned.
	// references should be treated just like any other variable, no dereferencing!
	return &(rVector[rVector.size() - 1]);
}
