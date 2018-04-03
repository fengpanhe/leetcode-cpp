cmake_minimum_required(VERSION 3.5)

project(leetcode-cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(testa src/test.cpp)
add_executable(L75_Sort_Colors src/L75_Sort_Colors.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)