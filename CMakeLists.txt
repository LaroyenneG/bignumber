cmake_minimum_required(VERSION 3.12)
project(Bignumber)

set(CMAKE_CXX_STANDARD 17)


add_executable(Bignumber src/rsa_algo.cpp src/rsa_algo.h src/prime_numbers_factory.h src/prime_numbers_factory.cpp src/biginteger.cpp src/biginteger.h test/main.cpp test/TestAddBiginteger.cpp test/TestAddBiginteger.h test/TestSubBiginteger.cpp test/TestSubBiginteger.h test/TestCompBiginteger.cpp test/TestCompBiginteger.h test/TestNegBiginteger.cpp test/TestNegBiginteger.h test/TestMultBiginteger.cpp test/TestMultBiginteger.h test/TestDivBiginteger.cpp test/TestDivBiginteger.h test/TestModBiginteger.cpp test/TestModBiginteger.h test/TestPrimeFactory.h test/TestPrimeFactory.cpp)
target_link_libraries(Bignumber cppunit)
target_link_libraries(Bignumber pthread)



