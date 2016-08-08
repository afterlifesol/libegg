#include <iostream>
using std::cout;
using std::endl;

#include <iomanip> 
using std::setw;

#include <limits>

#include <typeinfo>
// for typeid 

#include <cxxabi.h>
// for demangled

std::string demangled(char const* tname) {
    std::unique_ptr<char, void(*)(void*)>
        name{abi::__cxa_demangle(tname, 0, 0, nullptr), std::free};
    return {name.get()};
}

template<typename T>
void typeInfo()
{
    if (typeid(char)==typeid(T) ||  typeid(unsigned char)==typeid(T))
        cout << setw(20) << demangled(typeid(T).name())
            << setw(25) << (int)std::numeric_limits<T>::min() 
            << setw(25) << (int)std::numeric_limits<T>::max() 
            << setw(10) << sizeof(T) << endl;    
    else
        cout << setw(20) << demangled(typeid(T).name())
            << setw(25) << std::numeric_limits<T>::min() 
            << setw(25) << std::numeric_limits<T>::max() 
            << setw(10) << sizeof(T) << endl;
}

 
 
int main(int argc, char **argv)
{
    cout << endl << endl << endl;
	cout << "###### [eggInfo] ######" << endl;
	cout << "(bool)True printed = " << true << endl;
	cout << "(bool)False printed = " << false << endl;
    
    cout << endl;
    cout << "[Int Types]" << endl;
	cout << setw(20) << "Type" << setw(25) <<"Min" << setw(25) << "Max" << setw(10) << "Size(Bytes)"<< endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    typeInfo<char>();
    typeInfo<unsigned char>();
    typeInfo<short>();
    typeInfo<unsigned short>();
    typeInfo<int>();
    typeInfo<unsigned int>();
    typeInfo<long>();
    typeInfo<unsigned long>();
    typeInfo<long long>();
    typeInfo<unsigned long long>();

    cout << endl;
    cout << endl;
    cout << "[Float Types]" << endl;
	cout << setw(20) << "Type" << setw(25) <<"Min" << setw(25) << "Max" << setw(10) << "Size(Bytes)"<< endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    
    typeInfo<float>();
    typeInfo<double>();
    typeInfo<long double>();


	return 0;
}
