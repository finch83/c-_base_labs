   1st lecture task:
1. Create a Cmake project with 3 targets: executable and 2 shared libraries (name them anyhow you like).
2. Implement next functions:
   a. in the 1st library: int makeDouble(int)
   b. in the second library void printString(const std::string&) which simply prints given string anyway you like (i.e. using cout, printf or something else)
3. Inside main.cpp check if USE_STRING_FUNC is passed to a compiler and if yes, run printString function from the 2nd library, run makeDouble() and print its result otherwise. Try compiling it with and without this flag and check results.
4. (optional) try to change CMakeLists.txt to build 1st library as static and 2nd as shared one.

lecture_02
Please implement next functions:
bool equals(double, double, unit8_t precision) // return true if two given numbers are equal. use precision co control the comparison
void setBit(int& src, uint8_t bit) // take a integer and set specific bit to 0 or 1
void revertBit(int& src, uint8_t bit) // take an integer and revert specified bit in it
bool addVector(const int* src1, const int* src2, size, int* dts, std::size_t size); // take 2 arrays (with size elements, add each item of array 1 to corresponding element of array 2 and put the result in array dst)

lecture_03
1. Implement any sorting algorithm you like using cycles. Function should take an array as a parameter (and a size of it) and modify the array without creating a new one.
2. Create a recursive function which prints given number (long) backwards, splitting it with spaces (for example  123456789 --> 9 8 7 6 5 4 3 2 1)

lecture_04
1.1 Modify your 1st homework: take both libraries and add next function to each of them:
void printName()
which prints info about library used (use can use __PRETTY_FUNCTION__ macro for example, but feel free to do it your way)
1.2 inside main.cpp call this function from each library (you don't need to use USE_STRING_FUNC flag for this part). Resolve any name conflict if it appears.

2. Implement a class representation for 2-dimensional arrays (for int data).
Let's assume class name is Array (but it's up to you to pick a name)
Set dimensions and size at the moment of creation of a class instance (assuming it won't be changed afterwards).
Implement next methods:
void fillData -- to randomly fill the data
bool equal -- to check if arrays are equal in size and values
bool add - for adding values of an equal (in dimensions) array.
bool subtract - the same as previous, but subtracting
Array transpose - to change places column with rows and create a new object with these values

