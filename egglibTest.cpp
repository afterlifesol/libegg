#include <iostream>
using std::cout;
using std::endl;
using std::flush;

#include "TestList.h"
#include "TestStack.h"

int main(int argc, char** argv)
{
    cout << "Running Test on egglib" << endl << flush;
    cout << "egglibStack" << endl << flush;
    //TestStack();
    cout << "egglibList" << endl << flush;
    TestList();
    return 0;
}