#include "Address.h"
#include "../Base58.h"
#include "../Hash.h"

using namespace TW;

bool TW::ARK::Address::isValid(const Data &data){
    return isValid(Base58::bitcoin.encodeCheck(data));
}

bool TW::ARK::Address::isValid(const std::string &string ){
    Data decoded = Base58::bitcoin.decodeCheck(string);

    if ( decoded.size() == 0 ){
        return false;
    }
    
    // mainnet
    if (decoded[0]!=0x17){
        return false;
    }
    
    return true;
}

TW::ARK::Address::Address(const std::string &string){
    address = string;
}

TW::ARK::Address::Address(const Data &data){
    address = Base58::bitcoin.encodeCheck(data);
}

TW::ARK::Address::Address(const PublicKey &pub){
    Data hash = Data();

    hash.insert(hash.end(), 0x17);
    append(hash, Hash::ripemd(pub.bytes));

    address = Base58::bitcoin.encodeCheck(hash);
}

std::string TW::ARK::Address::string() const{
    return address;
}

Data TW::ARK::Address::bytes(){
    return Base58::bitcoin.decodeCheck(address);
}

