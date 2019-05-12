#include "PublicKey.h"
#include <gtest/gtest.h>
#include "PrivateKey.h"
#include "Data.h"
#include "HexCoding.h"
#include "ARK/Transaction.h"
#include "ARK/Signer.h"
#include "ARK/Address.h"

using namespace TW;
using namespace TW::ARK;

TEST(ARKSigner, sign){
    std::string s = "d8839c2432bfd0a67ef10a804ba991eabba19f154a3d707917681d45822a5712";
    PrivateKey priv = PrivateKey(parse_hex(s));

    Transaction t = Transaction();
    t.type = 0;
    t.timestamp = 67447770;
    t.amount = 123123123;
    t.fee = 10000000;
    t.recipientId = Address("ARkMaRcjcwRgr6vmDtAWo7bFqUgy9wG3NU");
    
    ARK::Signer::sign(priv, t);

    std::string expected_sig = "304402205e6365f4c3b49c28f03afd89d308736dca56671ea707dd3dd5af42272a0cc8ed02207fa7fc015fba7ae527d22a058cc4ebd8e9867c563ace7effc2dbaad2af8976c3";
    
    ASSERT_EQ(t.publicKey, parse_hex("034151a3ec46b5670a682b0a63394f863587d1bc97483b1b6c70eb58e7f0aed192"));
    ASSERT_EQ(hex(t.to_bytes()), "00"
    "da2b0504"
    "034151a3ec46b5670a682b0a63394f863587d1bc97483b1b6c70eb58e7f0aed192"
    "176d67bd926e417336456be869bc16a268b3705cbe"
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "b3b5560700000000"
    "8096980000000000"
    "304402205e6365f4c3b49c28f03afd89d308736dca56671ea707dd3dd5af42272a0cc8ed02207fa7fc015fba7ae527d22a058cc4ebd8e9867c563ace7effc2dbaad2af8976c3");
    ASSERT_EQ(t.signature, parse_hex(expected_sig));
}