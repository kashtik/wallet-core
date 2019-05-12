
#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWARKProto.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWARKSigner;

/// Signs a transaction.
TW_EXPORT_STATIC_METHOD
TW_ARK_Proto_SigningOutput TWARKSignerSign(TW_ARK_Proto_SigningInput input);

TW_EXTERN_C_END
