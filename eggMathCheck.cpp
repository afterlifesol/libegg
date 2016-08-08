#include <iostream>
using std::cout;
using std::endl;

//#include <iomanip>
// using std::setw;

//#include <typeinfo>
// FOR: typeid;

#include <limits>
// OFOR: std::numeric_limits<Type>::min() / max()

#include "egglibCheck.h"
using namespace egg;

template <typename A, typename B> bool addsafe(A a, B b)
{
    if(a >= 0)
        return ((std::numeric_limits<decltype(a + b)>::max() - a) >= b); // a is pos
    if(b >= 0)
        return ((std::numeric_limits<decltype(a + b)>::max() - b) >= a); // b is pos
    return ((std::numeric_limits<decltype(a + b)>::min() - a) <= b);     // a and b are neg.
}

int main(int argc, char** argv)
{
    const int max = std::numeric_limits<int>::max();
    const int min = std::numeric_limits<int>::min();

    cout << endl << "should be 0" << endl;

    eggChk(false, addsafe(max - 10, max - 10), "(max-10) + (max-10)");
    eggChk(false, addsafe(max, max), "max + max");
    eggChk(false, addsafe(min, min), "min + min");
    eggChk(false, addsafe(min, -1), "min + (-1)");
    eggChk(false, addsafe(((max / 2) + 2), max / 2), "((max/2)+2) + (max/2)");
    eggChk(false, addsafe(max, -(min + 1)), "max + -(min+1)");
    eggChk(false, addsafe(-(min + 1), max), "-(min+1) + max");
    eggChk(false, addsafe(min, -max), "min + -max");
    eggChk(false, addsafe(-max, min), "-max + min");

    cout << endl << "should be 1" << endl;

    eggChk(true, addsafe(min + 1, -1), "(min+1) + (-1)");
    eggChk(true, addsafe(-max, -1), "-max + (-1)");
    eggChk(true, addsafe(max, -max), "max + (-max)");
    eggChk(true, addsafe(max, 0), "max + 0");
    eggChk(true, addsafe(0, max), "0 + max");
    eggChk(true, addsafe(max, min), "max + (-max)");
    eggChk(-1, max + min, "max + min");
    eggChk(true, addsafe(max / 2, max / 2), "max/2 + max/2");
    eggChk(true, addsafe((max / 2) + 1, max / 2), "((max/2)+1) + (max/2)");
    eggChk(max, ((max / 2) + 1 + max / 2), "((max/2)+1) + (max/2)");

    return 0;
}
