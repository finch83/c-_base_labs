#ifndef _LECTURE_02_H_
#define _LECTURE_02_H_

#include <iostream>
#include <string>

namespace amelnyk
{
    namespace input
    {

        template <typename T>
        extern void inputVal(const std::string& strVal, T&);

        void usage(const std::string& strInput);
    }

    namespace lecture02
    {
        enum Tasks
        {
            EXIT_TASK = 0,
            EQUALS,
            SETBIT,
            REVERTBIT,
            ADDVECTOR,
            LAST_TASK = 5
        };

        static const std::string strUsageMain{"Select one of available functions using numbers [1..4] or 0 for exit:\n"
                                          "\t0: Exit\n"
                                          "\t1: equals\n"
                                          "\t2: setBit\n"
                                          "\t3: revertBit\n"
                                          "\t4: addVector\n"
                                         "function#: "};

        static const std::string strUsageEquals{"\n\treturn true if two given numbers are equal.\n"
                                           "\tuse precision co control the comparison\n"};
        void wrapEquals();
        bool equals(double, double, int precision);

        static const std::string strUsageSetBit{"\n\ttake an integer and set specific bit to 0 or 1.\n"};
        void wrapSetBit();
        void setBit(int& src, uint8_t bit);

        static const std::string strUsageRevertBit{"\n\ttake an integer and revert specified bit in it.\n"};
        void wrapRevertBit();
        void revertBit(int& src, uint8_t bit);

        static const std::string strUsageAddVector{"\n\ttake 2 arrays (with size elements, add each item of array 1 to corresponding\n"
                                                   "\telement of array 2 and put the result in array dst).\n"};
        void wrapAddVector();
        bool addVector(const int* src1, const int* src2, int* dst, std::size_t size);
    }
}

#endif
