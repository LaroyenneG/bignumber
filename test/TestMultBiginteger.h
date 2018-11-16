//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#ifndef BIGNUMBER_TESTMULTBIGINTEGER_H
#define BIGNUMBER_TESTMULTBIGINTEGER_H


#include <cppunit/TestCase.h>
#include "../src/biginteger.h"


using namespace bignumber;

class TestMultBiginteger : public CppUnit::TestCase {

public:
    explicit TestMultBiginteger(std::string string);

    void runTest() override;
};


#endif //BIGNUMBER_TESTMULTBIGINTEGER_H
