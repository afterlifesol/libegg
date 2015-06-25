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
	cout << endl << "Simple Testing for LinkedList" << endl;

	
	LinkedList<int> numbers;
	
	// ### Adding numbers to list
	cout << endl << "Adding Numbers" << endl;
	numbers.push(7);
	numbers.push_back(8);
	numbers.push(6);
	numbers.push(5);
	numbers.push_back(9);
	numbers.push(4);
	numbers.push(3);
	numbers.push_back(10);
	numbers.push(2);
	numbers.push(1);
	numbers.push(0);
	
	// ### Checking Stored Numbers
	cout << endl << "MSG\tStored\tExpected" << endl;
	int ti = 0;
	for (const int i : numbers)
	{
		cout << ( (ti==i) ? "[OK]" : "*ERROR*") << "\t" << i << "\t" << ti << endl;
		ti++;
		
	}
	cout << endl << ( (11==numbers.size()) ? "[OK]" : "*ERROR*") <<"\tsize() correct? Expected:11  Found:" << numbers.size() << endl;
	
	
	cout << endl << endl << "[LList Tests Complete]" << endl << endl;
	return 0;
}
