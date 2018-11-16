//
// Created by Guillaume LAROYENNE on 29/10/18.
//

#ifndef ARIDZUKA_RSA_ALGO_H
#define ARIDZUKA_RSA_ALGO_H


#include "prime_numbers_factory.h"
#include "biginteger.h"

namespace bignumber {

    class rsa_algo {

    private:
        rsa_algo() = delete;

    public:
        typedef struct {
            biginteger p;
            biginteger q;
        } private_key;

        typedef struct {
            biginteger n;
            biginteger e;
        } public_key;

        static private_key generate_private_key();

        static public_key generate_public_key(private_key pkey);
    };
}

#endif //ARIDZUKA_RSA_ALGO_H
