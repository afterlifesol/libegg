#include <iostream>
using std::cout;
using std::endl;
using std::flush;
#include <functional>


/*
template<typename Functor>
void _eggChecksetup(Functor Func)
{
    
    
}
*/

class _eggTester {
    public:
    
        const char *name = nullptr;
        std::function< void() > tests;
        _eggTester(const char *name): name(name) {}
    
};
    
    
    
    




#define eggTest(x)                                  \
    _eggTester _eggTest(x);                         \
    _eggTest.tests = []()

//auto lambda = [] (int x) { cout << x * 50 << endl; return x * 100; };

//#define CHECK(x) cout << "CHECK: " << #x << " is " << ((x)? "true" : "false");


int main ()
{
    const int x=2;


    /*    
    eggTest("SIMPLE") {
        
        CHECK(x == 2);
        
    }
    */
    
    _eggTester _eggTest("SIMPLE");                         \
    _eggTest.tests = [x]() {
        
        //CHECK(true);
        
    }
    
    
    return 0;
}