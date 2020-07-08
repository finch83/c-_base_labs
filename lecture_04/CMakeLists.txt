cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

project(lecture_04)

option(USE_STRING_FUNC "USE_STRING_FUNC" OFF)
if(${USE_STRING_FUNC})
	set (CMAKE_CXX_FLAGS "-D USE_STRING_FUNC")
endif()

set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(lmakedouble_src 
	${lib_dir}/libMakeDouble.hpp
	${lib_dir}/libMakeDouble.cpp)

set(lprintstring_src
	${lib_dir}/libPrintString.hpp
	${lib_dir}/libPrintString.cpp)

set(array_src
    ${lib_dir}/array.hpp
    ${lib_dir}/array.cpp)

set(main_src main.cpp)

add_library(libmakedouble SHARED ${lmakedouble_src})
add_library(libprintstring STATIC ${lprintstring_src})

add_executable(lecture_04
    ${main_src}
    ${array_src})

target_link_libraries(lecture_04 libmakedouble libprintstring)


