#include <iomanip>
#include <bitset>
#include <climits>
#include <algorithm>
#include <iterator>
#include <cmath>

#include "../include/lecture_02.hpp" 

namespace amelnyk
{
    namespace input
    {
        template <typename T>
        void inputVal(const std::string& strVal, T& TVal)
        {
            std::cout << strVal;
            std::cin >> TVal;
        }
        template void inputVal<double>(const std::string& strVal, double&);
        template void inputVal<int>(const std::string& strVal, int&);

         void usage(const std::string& strInput)
         {
             std::cout << strInput;
         }
    }

    namespace lecture02
    {
        // equals
        bool equals(double A, double B, int precision)
        {
            double eps = 1;
            for (int x = 0; x < precision; x++)
            {
                eps /=10;
            }
            return (fabs(A - B) < eps) ? true : false;
        }

        void wrapEquals()
        {
            amelnyk::input::usage(amelnyk::lecture02::strUsageEquals);

            int prec{};
            amelnyk::input::inputVal("Set precision: ", prec);

            double A{};
            amelnyk::input::inputVal("Set number A: ", A);

            double B{};
            amelnyk::input::inputVal("Set number B: ", B);

            std::cout << (amelnyk::lecture02::equals(A, B, prec) ?
                              "\tValues are equal\n" :
                              "\tValues are not equal\n");
        }


        // setBit
        void setBit(int& src, uint8_t bit)
        {
            uint8_t mask = 1 << (bit % CHAR_BIT);
            src |= mask;
        }

        void wrapSetBit()
        {
            amelnyk::input::usage(amelnyk::lecture02::strUsageSetBit);

            int nSrc{};
            amelnyk::input::inputVal("Set source value: ", nSrc);
            std::cout << std::bitset<sizeof(int) * CHAR_BIT>(nSrc) << std::endl;

            uint8_t nBit{};
            amelnyk::input::inputVal("Set bit number: ", nBit);

            setBit(nSrc, nBit);

            std::cout << std::bitset<sizeof(int) * CHAR_BIT>(nSrc) << std::endl;
            std::cout << nSrc << std::endl << std::endl;
        }


        // revertBit
        void revertBit(int& src, uint8_t bit)
        {
            uint8_t mask = 1 << (bit % CHAR_BIT);
            src ^= mask;
        }

        void wrapRevertBit()
        {
            amelnyk::input::usage(amelnyk::lecture02::strUsageRevertBit);

            int nSrc{};
            amelnyk::input::inputVal("Set source value: ", nSrc);
            std::cout << std::bitset<sizeof(int) * CHAR_BIT>(nSrc) << std::endl;

            uint8_t nBit{};
            amelnyk::input::inputVal("Set bit number: ", nBit);

            revertBit(nSrc, nBit);

            std::cout << std::bitset<sizeof(int) * CHAR_BIT>(nSrc) << std::endl;
            std::cout << nSrc << std::endl << std::endl;
        }


        // addVector
        bool addVector(const int* src1, const int* src2, int* dst, std::size_t size)
        {
            int* startDst = dst;
            int* endtDst = dst + size;
            while ((dst >= startDst) && (dst < endtDst))
            {
                *dst++ = *(src1++) + *(src2++);
            }

            return true;
        }

        void wrapAddVector()
        {
            amelnyk::input::usage(amelnyk::lecture02::strUsageAddVector);
            std::size_t nSize{};
            amelnyk::input::inputVal("Set arrays size: ", nSize);

            int * arr1 = new int [nSize];
            std::generate(arr1, arr1 + nSize, []() { return rand() % 10; });
            std::copy(arr1, arr1 + nSize, std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;

            int * arr2 = new int [nSize];
            std::generate(arr2, arr2 + nSize, []() {return rand() % 10; });
            std::copy(arr2, arr2 + nSize, std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl;

            int * dst = new int [nSize];
            addVector(arr1, arr2, dst, nSize);
            std::copy(dst, dst + nSize, std::ostream_iterator<int>(std::cout, " "));
            std::cout << std::endl << std::endl;

            delete [] arr1;
            delete [] arr2;
            delete [] dst;
        }
    }
}
