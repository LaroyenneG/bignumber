//
// Created by Guillaume LAROYENNE on 15/11/18.
//

#ifndef BIGNUMBER_TESTNEGBIGINTEGER_H
#define BIGNUMBER_TESTNEGBIGINTEGER_H


#include <cppunit/TestCase.h>
#include <biginteger.h>

using namespace bignumber;

class TestNegBiginteger : public CppUnit::TestCase {

public:
    explicit TestNegBiginteger(std::string string);

    void runTest() override;
};


#endif
