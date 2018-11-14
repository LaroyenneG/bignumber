//
// Created by Guillaume LAROYENNE on 14/11/18.
//

#include "number.h"


std::ostream &bignumber::operator<<(std::ostream &os, const bignumber::number &n) {

    os << n.to_string();

    return os;
}
