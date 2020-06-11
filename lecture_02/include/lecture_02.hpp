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

        extern const std::string strUsageMain;

        extern const std::string strUsageEquals;
        bool equals(double, double, int precision);
        void wrapEquals();

        extern const std::string strUsageSetBit;
        void setBit(int& src, uint8_t bit);
        void wrapSetBit();

        extern const std::string strUsageRevertBit;
        void revertBit(int& src, uint8_t bit);
        void wrapRevertBit();

        extern const std::string strUsageAddVector;
        bool addVector(const int* src1, const int* src2, int* dst, std::size_t size);
        void wrapAddVector();
    }
}

#endif
