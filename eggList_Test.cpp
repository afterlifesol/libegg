/* Basic LList testing file.. 
*/ 

#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;



#include "eggList.hpp"









#define COLOR_BOLD_BLACK 	"\033[1;30m"
#define COLOR_BOLD_RED	 	"\033[1;31m"
#define COLOR_BOLD_GREEN 	"\033[1;32m"
#define COLOR_BOLD_YELLOW	"\033[1;33m"
#define COLOR_BOLD_BLUE 	"\033[1;34m"
#define COLOR_BOLD_MAGENTA	"\033[1;35m"
#define COLOR_BOLD_CYAN		"\033[1;36m"
#define COLOR_BOLD_WHITE	"\033[1;37m"

#define COLOR_BLACK 	"\033[0;30m"
#define COLOR_RED 		"\033[0;31m"
#define COLOR_GREEN 	"\033[0;32m"
#define COLOR_YELLOW 	"\033[0;33m"
#define COLOR_BLUE 		"\033[0;34m"
#define COLOR_MAGENTA 	"\033[0;35m"
#define COLOR_CYAN 		"\033[0;36m"
#define COLOR_WHITE		"\033[0;37m"

#define COLOR_RESET "\033[0m"

template <typename value_type>
bool checkline(bool Test, const char *Message, value_type val)
{
	if (Test == true)
		cout << COLOR_BOLD_GREEN << "[OK]" << COLOR_RESET;
	  else
		cout << COLOR_BOLD_RED << "*ERROR*" << COLOR_RESET;
	cout << Message << "\t" << val << endl;
}

string check(bool Test)
{
	if (Test == true)
		return string("\033[1;32m[OK]\033[0m");
	  else
		return string("\033[1;31m*ERROR*\033[0m");
}

void section(string msg)
{ cout << endl << COLOR_BOLD_WHITE << msg << COLOR_RESET << endl; }

void header(string msg)
{ cout << COLOR_BOLD_BLUE << msg << COLOR_RESET << endl; }







int main(int argc, char **argv)
{
	cout << endl << endl << endl << endl;
	header("Simple Testing for LinkedList");
	cout << endl;

	LinkedList<int> numbers;




	
	// ### Adding numbers to list
	section("Pushing numbers to list: push(*) and push_back(*)");
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
	header("Test\tStored\tExpected");
	int ti = 0;
	for (const int i : numbers)
	{
		cout << check( ti==i ) << "\t" << i << "\t" << ti << endl;
		ti++;
		
	}
	cout << endl;
	checkline( 11==numbers.size() , "\tsize() Test \tExpected:11 \tFound:",numbers.size() );





	
	section("Removed Front and Back");
	numbers.pop_front();
	numbers.pop_back();
	// ### Checking Stored Numbers
	header("MSG\tStored\tExpected");
	ti = 1;
	for (const int i : numbers)
	{
		cout << check( ti==i ) << "\t" << i << "\t" << ti << endl;
		ti++;
	}
	cout << endl;
	checkline( 9==numbers.size() , "\tsize() Test \tExpected:9 \tFound:",numbers.size() );
	




	section("Removed Front x3");
	numbers.pop_front();
	numbers.pop_front();
	numbers.pop_front();
	// ### Checking Stored Numbers
	header("MSG\tStored\tExpected");
	ti = 4;
	for (const int i : numbers)
	{
		cout << check( ti==i ) << "\t" << i << "\t" << ti << endl;
		ti++;
	}
	cout << endl;
	checkline( 6==numbers.size() , "\tsize() Test \tExpected:6 \tFound:",numbers.size() );





	section("Removed Back x3");
	numbers.pop_back();
	numbers.pop_back();
	numbers.pop_back();
	// ### Checking Stored Numbers
	header("MSG\tStored\tExpected");
	ti = 4;
	for (const int i : numbers)
	{
		cout << check( ti==i ) << "\t" << i << "\t" << ti << endl;
		ti++;
	}
	cout << endl;
	checkline( 3==numbers.size() , "\tsize() Test \tExpected:3 \tFound:",numbers.size() );
	checkline( false==numbers.empty() , "\tIs list empty? Expected:0 (false)  Found:", numbers.empty() );



	section("Clearing List");
	numbers.clear();
	checkline( true==numbers.empty() , "\tIs list empty? Expected:1 (true)  Found:", numbers.empty() );
	




	
	cout << endl << endl << "[LList Tests Complete]" << endl << endl;
	return 0;
}
