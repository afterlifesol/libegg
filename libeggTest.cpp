#include <iostream>
using std::cout;
using std::endl;
using std::flush;

#include "TestList.h"
#include "TestStack.h"

int main()
{
    cout << "Running Test on libegg" << endl << flush;
    cout << "libeggStack" << endl << flush;
    TestStack();
    cout << "libeggList" << endl << flush;
    TestList();
    return 0;
}