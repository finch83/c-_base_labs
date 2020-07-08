#include <iostream>
#include "include/libPrintString.hpp"
#include "include/libMakeDouble.hpp"
#include "include/array.hpp"

int main(int argc, char **argv)
{

    libprintstring::printString("\nString: 42");
    libprintstring::printName();

    std::cout << "\nNumber: " << libmakedouble::makeDouble(42) << std::endl;
    libmakedouble::printName();

    std::cout << "\nUse Array class\n";
    Array arr1, arr2;
    Array arr3(arr1);
    arr1.print();
    arr2.print();
    arr3.print();

    // Compare //////////////////////
    std::string sCmp = (arr1.isEqual(arr2) ? "Equal" : "Not equal");
    std::cout << "Compare arr1 & arr2: " << sCmp << std::endl;
    sCmp = (arr1.isEqual(arr3) ? "Equal" : "Not equal");
    std::cout << "Compare arr1 & arr3: " << sCmp << std::endl;

    // add //////////////////////
    std::cout << "\n!!!add!!!\n";
    std::cout << "arr1 & arr2: " << std::endl;
    if (arr1.add(arr2))
        arr1.print();
    else
        std::cout << "Not equal\n";
    std::cout << "arr1 & arr3: " << std::endl;
    if (arr1.add(arr3))
        arr1.print();
    else
        std::cout << "Not equal\n";

    // subtract //////////////////////
    std::cout << "\n!!!subtract!!!\n";
    std::cout << "arr1 & arr2: " << std::endl;
    if (arr1.subtract(arr2))
        arr1.print();
    else
        std::cout << "Not equal\n";

    std::cout << "arr1 & arr3: " << std::endl;
    if (arr1.subtract(arr3))
        arr1.print();
    else
        std::cout << "Not equal\n";

    // transpose //////////////////////
    std::cout << "\n!!!transponse!!!\n";
    std::cout << "Source Array\n";
    arr1.print();
    std::cout << "Destanation Array\n";
    arr1.transpose().print();




return 0;
}
