#include <iostream>
#include "include/libPrintString.hpp"
#include "include/libMakeDouble.hpp"

int main(int argc, char **argv)
{
    #ifdef USE_STRING_FUNC
        printString("String: 42");
    #else
        std::cout << "Number: " << makeDouble(42) << std::endl;
    #endif

return 0;
}
