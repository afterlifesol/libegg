/*
 * Needs to be completly rewriten. with 
/* basic testing file for the Linked List */

#include <stdio.h>

#include <iostream>
#include <string>

#include "eggList.hpp"

using std::string;
using std::cout;
using std::endl;


string working_location = ".";

int main(int argc, char **argv)
{
	cout << "- START: main()-" << endl;

	
	LinkedList<int> numbers;
	
	numbers.Push(1);
	numbers.Push(20);
	numbers.Push(35);
	numbers.Push(4);
	numbers.Push(500);
	numbers.Push(605);
	numbers.Push(777);
	numbers.Push(81);
	numbers.Push(900);
	numbers.Push(10);


	cout << "Linked List is curretly storing: " << endl;


	for (const int i : numbers)
		cout << "    " << i << endl;
	
	
	cout << "- END: main()-" << endl;
	return 0;
}
