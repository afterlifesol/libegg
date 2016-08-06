/* Basic testing file..
*/

#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::flush;
using std::endl;
using std::ostream;

#include "eggStack.hpp"

using namespace egg;

#define COLOR_BOLD_BLACK "\033[1;30m"
#define COLOR_BOLD_RED "\033[1;31m"
#define COLOR_BOLD_GREEN "\033[1;32m"
#define COLOR_BOLD_YELLOW "\033[1;33m"
#define COLOR_BOLD_BLUE "\033[1;34m"
#define COLOR_BOLD_MAGENTA "\033[1;35m"
#define COLOR_BOLD_CYAN "\033[1;36m"
#define COLOR_BOLD_WHITE "\033[1;37m"

#define COLOR_BLACK "\033[0;30m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_WHITE "\033[0;37m"

#define COLOR_RESET "\033[0m"

template <typename value_type> void checkline(bool Test, const char* Message, value_type val)
{
    if(Test == true)
        cout << COLOR_BOLD_GREEN << "[OK]" << COLOR_RESET;
    else
        cout << COLOR_BOLD_RED << "*ERROR*" << COLOR_RESET;
    cout << Message << "\t" << val << endl;
    cout << flush;
}

string check(bool Test)
{
    if(Test == true)
        return string("\033[1;32m[OK]\033[0m");
    else
        return string("\033[1;31m*ERROR*\033[0m");
}

void section(string msg)
{
    cout << endl << COLOR_BOLD_WHITE << msg << COLOR_RESET << endl << flush;
}

void header(string msg)
{
    cout << COLOR_BOLD_BLUE << msg << COLOR_RESET << endl << flush;
}

void note(string msg)
{
    cout << COLOR_BOLD_YELLOW << msg << COLOR_RESET << endl << flush;
}

int main(int argc, char** argv)
{
    cout << endl << endl << endl << endl;
    note("[Testing Stack]");
    cout << endl;

    Stack<int> S;

    checkline(true == S.empty(), "\tIs list empty? \tExpected:1 (true) \tFound:", S.empty());
    checkline(0 == S.size(), "\tsize() Test \tExpected:0 \tFound:", S.size());

    note("Starting");

    section("Pushing numbers to list: push(*)");

    for(int i = 0; i < 10000; i++)
        S.push(i);

    checkline(10000 == S.size(), "\tsize() Test \tExpected:10000 \tFound:", S.size());

    for(int i = 0; i < 11000; i++)
        S.pop();

    S.clear();

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    S.pop();
    S.pop();
    checkline(3 == S.size(), "\tsize() Test \tExpected:3 \tFound:", S.size());

    S.pop();
    S.pop();
    checkline(1 == S.size(), "\tsize() Test \tExpected:1 \tFound:", S.size());

    S.pop();
    checkline(0 == S.size(), "\tsize() Test \tExpected:0 \tFound:", S.size());

    checkline(true == S.empty(), "\tIs list empty? \tExpected:1 (true) \tFound:", S.empty());

    S.pop();
    checkline(0 == S.size(), "\tsize() Test \tExpected:0 \tFound:", S.size());

    S.push(10);
    checkline(10 == S.peek(), "\tsize() Test \tExpected:10 \tFound:", S.peek());
    checkline(1 == S.size(), "\tsize() Test \tExpected:1 \tFound:", S.size());

    S.push(20);
    checkline(20 == S.peek(), "\tsize() Test \tExpected:20 \tFound:", S.peek());
    checkline(2 == S.size(), "\tsize() Test \tExpected:2 \tFound:", S.size());

    S.push(30);
    checkline(30 == S.peek(), "\tsize() Test \tExpected:30 \tFound:", S.peek());

    S.pop();
    checkline(20 == S.peek(), "\tsize() Test \tExpected:20 \tFound:", S.peek());

    S.pop();
    checkline(10 == S.peek(), "\tsize() Test \tExpected:10 \tFound:", S.peek());

    S.pop();
    S.clear();

    cout << endl;
    note("[Stack Tests Complete]");
    cout << endl << endl;

    return 0;
}
