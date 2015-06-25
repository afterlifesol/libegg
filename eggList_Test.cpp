/* Basic LList testing file.. 
*/ 

#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;



#include "eggList.hpp"

string working_location = ".";

int main(int argc, char **argv)
{
	cout << endl << "Tests for LList" << endl;

	
	LinkedList<int> numbers;
	
	// ### Adding numbers to list
	cout << endl << "Adding Numbers" << endl;
	numbers.Push_Back(8);
	numbers.Push(7);
	numbers.Push(6);
	numbers.Push(5);
	numbers.Push_Back(9);
	numbers.Push(4);
	numbers.Push(3);
	numbers.Push_Back(10);
	numbers.Push(2);
	numbers.Push(1);
	numbers.Push(0);
	
	// ### Checking Stored Numbers
	cout << endl << "MSG\tStored\tExpected" << endl;
	int ti = 0;
	for (const int i : numbers)
	{
		cout << ( (ti==i) ? "[OK]" : "*ERROR*") << "\t" << i << "\t" << ti << endl;
		ti++;
		
	}
	
	cout << endl << ( (11==numbers.Size()) ? "[OK]" : "*ERROR*") <<"\tLList Size containts corrent value after ADD. Expected:11  Found:" << numbers.Size() << endl;
	
	
	cout << endl << endl << "[LList Tests Complete]" << endl << endl;
	return 0;
}
