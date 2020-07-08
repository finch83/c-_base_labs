#include <iostream>
#include "libMakeDouble.hpp"

namespace libmakedouble {
    int makeDouble(int x)
    {
        return x;
    }

    void printName()
    {
        std::cout << "!!!double lib!!!\n"
                  << __func__ << std::endl
                  << __FUNCTION__ << std::endl
                  << __PRETTY_FUNCTION__ << std::endl;
    }
}
