//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#ifndef BIGNUMBER_BIGINTEGER_H
#define BIGNUMBER_BIGINTEGER_H

#include <string>
#include <cmath>

namespace bignumber {

    class biginteger {

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

        std::string to_string() const;

        bool equals(const biginteger &obj) const;

        unsigned int length() const;

        /**********************************************************************
         * Operators
         **********************************************************************/

        biginteger operator+(const biginteger &number) const;

        biginteger operator-(const biginteger &number) const;

        biginteger &operator-();

        biginteger operator/(const biginteger &number) const;

        biginteger operator%(const biginteger &number) const;

        biginteger operator*(const biginteger &number) const;

        bool operator==(const biginteger &number) const;

        bool operator!=(const biginteger &number) const;

        bool operator>(const biginteger &number) const;

        bool operator<(const biginteger &number) const;

        bool operator<=(const biginteger &number) const;

        bool operator>=(const biginteger &number) const;

        biginteger &operator+=(const biginteger &number);

        biginteger &operator-=(const biginteger &number);

        biginteger &operator/=(const biginteger &number);

        biginteger &operator*=(const biginteger &number);

        const biginteger operator++(int);

        biginteger &operator++();

        biginteger &operator--();

        const biginteger operator--(int);

        biginteger &operator=(const biginteger &number);
    };
}

#endif
