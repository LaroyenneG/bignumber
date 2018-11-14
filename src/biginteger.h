//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#ifndef BIGNUMBER_BIGINTEGER_H
#define BIGNUMBER_BIGINTEGER_H

#include <string>
#include <cmath>
#include "number.h"

namespace bignumber {

    class biginteger : number {

    private:
        unsigned short *table;
        unsigned int size;
        bool sign;

        void realloc(unsigned int size);

        static biginteger simple_add(const biginteger &n1, const biginteger &n2);

        static biginteger simple_sub(const biginteger &n1, const biginteger &n2);

        static biginteger simple_mult(const biginteger &n1, const biginteger &n2);

        static bool simple_is_sup(const biginteger &n1, const biginteger &n2);

        static bool simple_is_inf(const biginteger &n1, const biginteger &n2);

    public:
        static const unsigned short BASE;

        biginteger(const biginteger &number);

        biginteger(const std::string &value);

        biginteger(long long int n);

        biginteger();

        ~biginteger();

        std::string to_string() const override;

        bool equals(const biginteger &n) const;

        unsigned int length() const;

        /**********************************************************************
         * Operators
         **********************************************************************/

        bool operator==(const biginteger &n) const;

        bool operator!=(const biginteger &n) const;

        biginteger operator+(const biginteger &n) const;

        biginteger operator-(const biginteger &n) const;

        biginteger &operator-();

        biginteger operator/(const biginteger &n) const;

        biginteger operator%(const biginteger &n) const;

        biginteger operator*(const biginteger &n) const;

        bool operator>(const biginteger &n) const;

        bool operator<(const biginteger &n) const;

        bool operator<=(const biginteger &n) const;

        bool operator>=(const biginteger &n) const;

        biginteger &operator+=(const biginteger &n);

        biginteger &operator-=(const biginteger &n);

        biginteger &operator/=(const biginteger &n);

        biginteger &operator*=(const biginteger &n);

        const biginteger operator++(int);

        biginteger &operator++();

        biginteger &operator--();

        const biginteger operator--(int);

        biginteger &operator=(const biginteger &n);
    };
}

#endif
