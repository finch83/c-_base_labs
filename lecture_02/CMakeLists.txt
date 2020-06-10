cmake_minimum_required(VERSION 2.4)
set(CMAKE_CXX_STANDARD 11)

project(lecture_02)

set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(main_src ${src_dir}/main.cpp
	${lib_dir}/lecture_02.hpp
	${src_dir}/lecture_02.cpp)


add_executable(lecture_02 ${main_src})

