#pragma once

#include "../Data.h"
#include "Address.h"

namespace TW::ARK {

  class Transaction {
    public:
      
      uint8_t type;
      uint32_t timestamp;
      Data publicKey;
      Address recipientId;
      uint64_t amount;
      uint64_t fee;    

      /// Transaction signature.
      Data signature;

      Transaction();

      /// Encodes the transaction.
      Data to_bytes();
      std::string to_json();
  };
}