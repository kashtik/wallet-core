#pragma once
#include "../PrivateKey.h"
#include "Transaction.h"


namespace TW::ARK{
    class Signer{
        public: 
            static void sign(PrivateKey &pk, TW::ARK::Transaction &t);
    };
};

// Wrapper for C interface.
struct TWARKSigner {
    TW::ARK::Signer impl;
};