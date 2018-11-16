//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#ifndef BIGNUMBER_TESTSUBBIGINTEGER_H
#define BIGNUMBER_TESTSUBBIGINTEGER_H


#include <cppunit/TestCase.h>
#include "../src/biginteger.h"

using namespace bignumber;

class TestSubBiginteger : public CppUnit::TestCase {

public:
    explicit TestSubBiginteger(std::string string);

    void runTest() override;

};


#endif //BIGNUMBER_TESTSUBBIGINTEGER_H
