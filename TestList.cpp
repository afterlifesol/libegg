#include <iostream>
using std::cout;
using std::flush;
using std::endl;


#include "libeggList.hpp"
#include "libeggCheck.h"

using namespace egg;


int TestList()
{

    //eggChk output ajustment
    TestCol=5;
    TestMCol=15;    


	cout << endl << endl;
    cout << "LinkedList Test [START]" << endl;

	LinkedList<int> list;

    list.pop_front();
    list.pop_back();

	eggChk(true,list.empty(),"empty()");
	eggChk(0,list.size(),"size()");

    #define LARGEALLOCATION 50000
    #define DOTNUM 1000

    cout << "Testing push(...), front() and pop_frount()" << endl;
    cout << "pushing..." << endl;
    for(int i = 0; i < LARGEALLOCATION; i++)
    { 
        list.push(i);
        if (i%DOTNUM == 0) { cout << '.'; cout.flush(); }
    }
    cout << endl << endl << endl;
    cout << "verifing..." << endl;
    
/*
    eggChk(LARGEALLOCATION,list.size(),"size()");
    
    cout << "frount()" << endl << flush;
    eggChk(49999,list.front(),"list.front()");

    cout << "pop_front()" << endl << flush;
    list.pop_front();

    eggChk(LARGEALLOCATION-1,list.size(),"size()");


    cout << "frount()" << endl << flush;
    eggChk(49998,list.front(),"list.front()");

    cout << "pop_front()" << endl << flush;
    list.pop_front();

    eggChk(LARGEALLOCATION-2,list.size(),"size()");
*/

    eggChk(LARGEALLOCATION,list.size(),"size()");
    bool BadData = false;
    for(int i = LARGEALLOCATION-1; i > 0; i--) 
        {

        eggChk(i,list.front(),"list.front()");
        cout << endl << flush;

        if (i%DOTNUM == 0) { cout << '.'; cout.flush(); }
        if(list.front() != i) {
            BadData = true;
            eggChk(i,list.front(),"list.front() error on index[expected] = expected");
            break;
        }
        list.pop_front();
    }
    cout << endl;
    eggChk(true,!BadData,"Data verified");



/*    
    
    eggChk(LARGEALLOCATION,list.size(),"size()");
    bool BadData = false;
    for(int i = LARGEALLOCATION-1; i >= 0; i--) {
        if (i%DOTNUM == 0) { cout << '.'; cout.flush(); }
        if(list.front() != i) {
            BadData = true;
            eggChk(i,list.front(),"list.front() error on index[expected] = expected");
            break;
        }
        list.pop_front();
    }
    cout << endl;
    eggChk(true,!BadData,"Data verified");

/*

 
/*
	eggChk(0,list.size(),"size()");
    list.push(1);
	eggChk(1,list.size(),"size()");
	eggChk(false,list.empty(),"empty()");
    list.clear();
	eggChk(0,list.size(),"size()");


    cout << "Testing push_back(...), back() and pop_back()" << endl;
    cout << "push_backing...";
    for(int i = 0; i < LARGEALLOCATION; i++)
    { 
        list.push_back(i);
        if (i%DOTNUM == 0) { cout << '.'; cout.flush(); }
    }
    cout << endl;

    cout << "verifing...";
    eggChk(LARGEALLOCATION,list.size(),"size()");
    BadData = false;
    for(int i = LARGEALLOCATION-1; i >= 0; i--) {
        if (i%DOTNUM == 0) cout << '.' << flush;
        if(list.back() != i) {
            BadData = true;
            eggChk(i,list.back(),"list.back()");
            break;
        }
        list.pop_back();
    }
    cout << endl;
    eggChk(true,!BadData,"Data verified");



	eggChk(0,list.size(),"size()");
    list.push(1);
    eggChk(1,list.size(),"size()");
	eggChk(false,list.empty(),"empty()");
    list.clear();
	eggChk(0,list.size(),"size()");

	cout << "LinkedList Test [DONE]" << endl;
*/
	return 0;
}
