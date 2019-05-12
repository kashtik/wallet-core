#include "Transaction.h"
#include "../Data.h"
#include "../BinaryCoding.h"
#include "../Base58.h"
#include "../Hash.h"
#include "../HexCoding.h"
#include <nlohmann/json.hpp>


using json = nlohmann::json;

using namespace TW;

ARK::Transaction::Transaction(){
    type=0; // transfer
    fee = 10000000; // default fee
}

Data ARK::Transaction::to_bytes(){
    
    Data result = Data();

    // type should be 0 for transfer
    result.insert(result.end(), type);

    // timestamp
    encode32LE(timestamp, result);
    
    append(result, publicKey);

    append(result, Base58::bitcoin.decodeCheck(recipientId.string()));
    
    // vendor field
    std::vector<uint8_t> empty(64, 0);
    append(result, empty);

    encode64LE(amount, result);
    encode64LE(fee, result);

    if( signature.size() > 0 ){
        append(result, signature);
    }
    return result;
}

std::string ARK::Transaction::to_json(){
    json j = {
        {"amount", amount},
        {"asset", {}},
        {"fee", fee},
        {"id", hex(Hash::sha256(to_bytes()))},
        {"recipientId", recipientId.string()},
        {"senderPublicKey", hex(publicKey)},
        {"signature", hex(signature)},
        {"timestamp", timestamp},
        {"type", type}
    };
    return j.dump();
}