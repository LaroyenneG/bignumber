//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#ifndef BIGNUMBER_BIGINTEGER_H
#define BIGNUMBER_BIGINTEGER_H

#include <string>

namespace bignumber {

    class biginteger {

    private:
        explicit biginteger(bool _infinity, bool _sign, unsigned int _size, unsigned short *_table);

        unsigned short *table;
        unsigned int size;
        bool sign;
        bool infinity;

        void realloc(unsigned int size);

        void alloc(unsigned int size);

        static biginteger simple_add(const biginteger &n1, const biginteger &n2);

        static biginteger simple_sub(const biginteger &n1, const biginteger &n2);

        static biginteger simple_mult(const biginteger &n1, const biginteger &n2);

        static bool simple_is_sup(const biginteger &n1, const biginteger &n2);

        static bool simple_is_inf(const biginteger &n1, const biginteger &n2);

        static biginteger simple_div(const biginteger &n1, const biginteger &n2);

    public:
        static const unsigned long long BASE;

        static const biginteger INFINITY;

        static biginteger sqrt(const biginteger &n);

        static biginteger pow(const biginteger &n, unsigned long long int p);

        biginteger(const biginteger &number);

        explicit biginteger(const std::string &value);

        biginteger(long long n);

        biginteger();

        ~biginteger();

        std::string to_string() const;

        bool equals(const biginteger &n) const;

        unsigned int length() const;

        /**********************************************************************
         * Operators
         **********************************************************************/

        bool operator==(const biginteger &n) const;

        bool operator!=(const biginteger &n) const;

        biginteger operator+(const biginteger &n) const;

        biginteger operator-(const biginteger &n) const;

        biginteger operator-() const;

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

        unsigned short &operator[](unsigned int n) const;

        biginteger &operator=(const biginteger &n);

        explicit operator long long();

        friend std::ostream &operator<<(std::ostream &os, const biginteger &n);
    };
}

#endif
