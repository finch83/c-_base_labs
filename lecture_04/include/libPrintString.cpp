#include <iostream>
#include <string>
#include "libPrintString.hpp"

namespace libprintstring {
    void printString(const std::string& str)
    {
        std::cout << str << std::endl;
    }

    void printName()
    {
        std::cout << "!!!string lib!!!\n"
                  << __func__ << std::endl
                  << __FUNCTION__ << std::endl
                  << __PRETTY_FUNCTION__ << std::endl;
    }
}
