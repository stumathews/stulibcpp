// vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> names;
	names.push_back("Stuart");
	names.push_back("Rene");
	names.push_back("Leon");
	names.push_back("Bruce");
	names.push_back("Jenny");

	cout << names[0] << endl;
	typedef unsigned short int uint;

	vector<string>::iterator iter;
	list<string> listOfNames;
	listOfNames.push_back("Jessie");
	listOfNames.push_back("Thomas");
	listOfNames.push_back("Lassie");
	listOfNames.push_back("Lassie");
	listOfNames.push_back("Flash");
	listOfNames.push_back("Bella");
	listOfNames.push_back("Beauty");

	cout << "What is the name you'd likeus to find?";
	string nameToFind;
	cin >> nameToFind;
	if (find(listOfNames.begin(), listOfNames.end(), nameToFind) != listOfNames.end())
		cout << "We found " << nameToFind << endl;
	else
		cout << "We couldn't find it. Sorry." << endl;
	
	list<string>::iterator list_iter = adjacent_find(listOfNames.begin(), listOfNames.end());
	if (list_iter == listOfNames.end())
		cout << "Could not find the first adjacent set of items." << endl;
	else
	{			
		cout << "Found the first set of ajdacent items" << *list_iter << endl;
	}

	names.insert(names.begin(), "luke skywalker");
	iter = find(names.begin(), names.end(), "bruce");
	if (iter != names.end())
		cout << "We found bruce" << endl; 
	

	srand(static_cast<uint>(time(0)));
	random_shuffle(names.begin(), names.end()); 
	sort(names.begin(), names.end());
	for (iter = names.begin(); iter != names.end(); iter++)
	{
		
		cout <<  *iter << " has a length of " << iter->length() << endl;
	}

	uint digit = 0;
	cin >> digit;

	return 0;
}

