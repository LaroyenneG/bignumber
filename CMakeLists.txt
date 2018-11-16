cmake_minimum_required(VERSION 3.12)
project(Bignumber)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(Bignumber src/biginteger.cpp src/biginteger.h)

if (UNIX)
    add_executable(Bignumbertest src/biginteger.cpp src/biginteger.h test/main.cpp test/TestAddBiginteger.cpp test/TestAddBiginteger.h test/TestSubBiginteger.cpp test/TestSubBiginteger.h test/TestCompBiginteger.cpp test/TestCompBiginteger.h test/TestNegBiginteger.cpp test/TestNegBiginteger.h test/TestMultBiginteger.cpp test/TestMultBiginteger.h)
    target_link_libraries(Bignumbertest pthread)
    target_link_libraries(Bignumbertest cppunit)
endif (UNIX)