#pragma once

#include "../Data.h"
#include "../PublicKey.h"
#include "../HexCoding.h"


namespace TW::ARK{

    class Address{

        public:
            std::string address;
        
            static bool isValid(const Data &data);

            static bool isValid(const std::string &string);

            Address(const std::string &string);

            Address(const Data &data);

            Address(const PublicKey &publicKey);

            Address(){};

            std::string string() const;
            Data bytes();

        
    };
    inline bool operator==(const Address& lhs, const Address& rhs) {
        return lhs.address == rhs.address;
    }
};

// Wrapper for C interface.
struct TWARKAddress {
    TW::ARK::Address impl;
};