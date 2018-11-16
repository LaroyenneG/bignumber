//
// Created by Guillaume LAROYENNE on 16/11/18.
//

#ifndef BIGNUMBER_TESTMODBIGINTEGER_H
#define BIGNUMBER_TESTMODBIGINTEGER_H

#include <cppunit/TestCase.h>
#include "../src/biginteger.h"

using namespace bignumber;

class TestModBiginteger : public CppUnit::TestCase {

public:
    explicit TestModBiginteger(std::string string);

    void runTest() override;
};


#endif //BIGNUMBER_TESTMODBIGINTEGER_H
