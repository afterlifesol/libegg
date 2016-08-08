#include <stdio.h>

#ifdef NDEBUG
    #define LOG(ignore) ((void)0)
#else
    #define LOG(priority, message) eggLog(priority, message, __FILE__, __LINE__, __func__)
#endif

#include <string>

void
eggLog(const int priority, const std::string& msg, const std::string& file, const int line, const std::string& func)

{

    cout << "*** LOG:" << priority << "*** " << msg << " (" << file << ":" << line << "):" << func << "(...)"
         << "\n";
}
