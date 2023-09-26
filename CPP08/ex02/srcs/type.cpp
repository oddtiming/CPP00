// Reference
//https://stackoverflow.com/questions/281818/
#ifdef __GNUG__
#include <cstdlib>
#include <string>
#include <memory>
#include <cxxabi.h>

struct handle {
    char* p;
    handle(char* ptr) : p(ptr) { }
    ~handle() { std::free(p); }
};

std::string demangle(const char* name) {

    int status = -4; // some arbitrary value to eliminate the compiler warning

    handle result( abi::__cxa_demangle(name, NULL, NULL, &status) );

    std::string trim(result.p);    
    std::string toErase("std::__1::");    

    size_t pos = trim.find(toErase);;
    // Search for the substring in string
    // size_t pos = trim.find(toErase);
    while (pos != std::string::npos) {
        trim.erase(pos, toErase.length());
        pos = trim.find(toErase);
    }
    return (status==0) ? result.p : name ;
}

#else

// does nothing if not g++
std::string demangle(const char* name) {
    return name;
}

#endif
