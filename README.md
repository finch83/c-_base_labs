   1st lecture task:
1. Create a Cmake project with 3 targets: executable and 2 shared libraries (name them anyhow you like).
2. Implement next functions:
   a. in the 1st library: int makeDouble(int)
   b. in the second library void printString(const std::string&) which simply prints given string anyway you like (i.e. using cout, printf or something else)
3. Inside main.cpp check if USE_STRING_FUNC is passed to a compiler and if yes, run printString function from the 2nd library, run makeDouble() and print its result otherwise. Try compiling it with and without this flag and check results.
4. (optional) try to change CMakeLists.txt to build 1st library as static and 2nd as shared one.

