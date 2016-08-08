#include <iostream>
using std::cout;
using std::endl;
using std::flush;

#include "libeggStack.hpp"
#include "libeggCheck.h"

using namespace egg;

int TestStack()
{
    
    TestCol=5;
    TestMCol=15;    
    
    cout << endl << endl;
    cout << "Testing Stack [START]" << endl;

    Stack<int> S;
    
    eggChk(true,S.empty(),"Stack Empty");
    eggChk(0,S.size(),"Size");

    cout << "Running large allocation." << endl;
    #define LARGEALLOCATION 50000
    #define DOTNUM 1000
    for(int i = 0; i < LARGEALLOCATION; i++)
    { 
        S.push(i);
        if (i%DOTNUM == 0) cout << '.' << flush;
    }
    cout << endl;
    eggChk(LARGEALLOCATION,S.size(),"Size");

    cout << "Running large deallocation and data check" << endl;
    bool BadData = false;
    for(int i = LARGEALLOCATION-1; i >= 0; i--) {
        if (i%DOTNUM == 0) cout << '.' << flush;
        if(S.peek() != i) {
            BadData = true;
            eggChk(i,S.peek(),"S.peek()");
            break;
        }
        S.pop();
    }
    cout << endl;
    eggChk(true,!BadData,"Verified data");
    cout << "deallocation complete." << endl;

    S.clear();
    eggChk(0,S.size(),"Clear Stack");

    S.pop();
    S.pop();
    eggChk(0,S.size(),"Double pop() on empty");

    cout << "Stack Tests [DONE]" << endl;

    return 0;
}
