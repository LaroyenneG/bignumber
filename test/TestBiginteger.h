//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#ifndef ARIDZUKA_TESTBIGNUMBER_H
#define ARIDZUKA_TESTBIGNUMBER_H

#include <cppunit/TestCase.h>
#include <biginteger.h>

using namespace bignumber;

class TestBignumber : public CppUnit::TestCase {

public:

    TestBignumber(std::string string);

    void runTest() override;

};


#endif //ARIDZUKA_TESTBIGNUMBER_H
