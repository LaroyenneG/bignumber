//
// Created by Guillaume LAROYENNE on 28/10/18.
//

#ifndef ARIDZUKA_TESTPRIMEFACTORY_H
#define ARIDZUKA_TESTPRIMEFACTORY_H


#include <cppunit/TestCase.h>
#include "../src/prime_numbers_factory.h"

using namespace bignumber;

class TestPrimeFactory : public CppUnit::TestCase {

public:
    explicit TestPrimeFactory(std::string string);

    void runTest() override;

};


#endif //ARIDZUKA_TESTPRIMEFACTORY_H
