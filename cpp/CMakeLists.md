### tree
yshi@DESKTOP-1K9M5OV:~/cmake_list$ tree
.
├── CMakeLists.txt
├── build
├── include
│   ├── so1.h
│   └── so2.h
├── libs
├── so1
│   ├── CMakeLists.txt
│   └── so1.cpp
├── so2
│   ├── CMakeLists.txt
│   └── so2.cpp
└── test
    ├── CMakeLists.txt
    └── test.cpp

6 directories, 9 files


### ./CMakelists.txt
cmake_minimum_required(VERSION 3.0)
project(soTest)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_BINARY_DIR}/libs /usr/lib)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_subdirectory(so1)
add_subdirectory(so2)
add_subdirectory(test)

### ./so1/CMakeLists.txt
project(soTest)
set(so1 so1.cpp)
add_library(so1 SHARED ${so1})

### ./so2/CMakeLists.txt
project(soTest)
set(so2 so2.cpp)
add_library(so2 SHARED ${so2})
target_link_libraries(so2 so1)

### ./test/CMakeLists.txt
project(soTest)
set(test test.cpp)
add_executable(test test.cpp)
target_link_libraries(test so2 so1)

### so1.h
#include <iostream>
int addFunc(int a, int b);

### so2.h
int funcTest(int a);

### so1.cpp
#include "so1.h"

int funcTest(int a)
{
    std::cout << "funcTest " << a << "  addsum with 10 is:  " << addFunc(a, 10) << std::endl;
    return a;
}

### so2.cpp
int addFunc(int a, int b)
{
    return a + b;
}

### test.cpp
#include "so2.h"

int main()
{
    funcTest(10);
    return 0;
}

### build command:   mkdir build cd build cmake .. && make
