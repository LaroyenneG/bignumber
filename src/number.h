//
// Created by Guillaume LAROYENNE on 14/11/18.
//

#ifndef BIGNUMBER_NUMBER_H
#define BIGNUMBER_NUMBER_H

#include <ostream>
#include <string>

namespace bignumber {

    class number {

    public:
        virtual std::string to_string() const = 0;

        friend std::ostream &operator<<(std::ostream &os, const number &n);
    };
}


#endif //BIGNUMBER_NUMBER_H
