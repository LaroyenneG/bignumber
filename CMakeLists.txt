cmake_minimum_required(VERSION 3.12)
project(Bignumber)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(Bignumber src/biginteger.cpp src/biginteger.h src/number.cpp src/number.h)

if (UNIX)
    add_executable(Bignumbertest src/biginteger.cpp src/biginteger.h test/TestBiginteger.cpp test/TestBiginteger.h test/main.cpp)
    target_link_libraries(Bignumbertest pthread)
    target_link_libraries(Bignumbertest cppunit)
endif (UNIX)