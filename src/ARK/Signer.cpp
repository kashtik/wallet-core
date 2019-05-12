#include "Signer.h"
#include "../PrivateKey.h"
#include "../PublicKey.h"
#include "../Hash.h"
#include <TrustWalletCore/TWPublicKeyType.h>

using namespace TW;

void TW::ARK::Signer::sign(PrivateKey &pk, Transaction &t){
    PublicKey pub = pk.getPublicKey(TWPublicKeyTypeSECP256k1);
    t.publicKey = pub.bytes;
    Data hash = Hash::sha256(t.to_bytes());
    t.signature = pk.signAsDER(hash, TWCurveSECP256k1);
}
