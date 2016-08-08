#ifndef _libeggCheck_h_INCLUDED_
#define _libeggCheck_h_INCLUDED_

#include <iostream>
using std::cout;
using std::endl;
using std::flush;

#include <iomanip>
using std::setw;

#include <typeinfo>
// FOR: typeid;

#include <limits>
// FOR: std::numeric_limits<Type>::min() / max()

namespace egg
{

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


static int TestCol=6;
static int TestMCol=25;

template <typename T> void eggChk(T expected, T got, const char* Message, int mcolw = TestMCol, int colw = TestCol)
{
    bool good = (expected == got);

    if(typeid(expected) == typeid(bool))
        cout << "chk "
             << " ##/##  "
             << " \"" << setw(mcolw) << Message << "\"   " << setw(colw) << (expected ? "true" : "false") << " = '"
             << setw(colw) << (got ? "true" : "false") << "'";
    else
        cout << "chk "
             << " ##/##  "
             << " \"" << setw(mcolw) << Message << "\"   " << setw(colw) << expected << " = '" << setw(colw) << got
             << "'";

    if(good)
        cout << COLOR_BOLD_GREEN << setw(8) << "[OK]" << COLOR_RESET << endl << flush;
    else {
        cout << COLOR_BOLD_RED << setw(8) << "[FAIL]" << COLOR_RESET << endl << flush;
        cout << COLOR_BOLD_YELLOW << setw(20) << "[ERR]   " << COLOR_RESET << "Exptected '" << setw(colw) << expected
             << "'   Got '" << setw(colw) << got << "'" << endl << flush;
    }
    return;
}

} // close namespace egg

#endif // _libeggCheck_h_INCLUDED_