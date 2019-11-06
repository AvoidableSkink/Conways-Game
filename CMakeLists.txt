# CMakeList.txt : CMake project for Conways Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(HEADER_FILES
	rlutil.h
    LifeSimulator.hpp Renderer.hpp 
	Pattern.hpp PatternAcorn.hpp)

set(SOURCE_FILES
    LifeSimulator.cpp PatternAcorn.cpp)

# Add source to this project's executable.
add_executable (ConwaysLife  "main.cpp" ${HEADER_FILES} ${SOURCE_FILES})

#
# We want the C++ 17 standard for our project
#
set_property(TARGET ConwaysLife PROPERTY CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(ConwaysLife PRIVATE /W4 /permissive-)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic)
endif()

