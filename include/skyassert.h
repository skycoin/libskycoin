#ifndef LIBSKY_ASSERT_H
#define LIBSKY_ASSERT_H

#include "libskycoin.h"
#include "skyerrors.h"

extern GoInt_ isAddressEq(cipher__Address* addr1, cipher__Address* addr2);
extern GoInt_ isAddressEqPtr(cipher__Address addr1, cipher__Address addr2);

extern GoInt_ isPubKeyEq(cipher__PubKey* pubkey1, cipher__PubKey* pubkey2);
extern GoInt_ isSigEq(cipher__Sig* sig1, cipher__Sig* sig2);

extern GoInt_ isSecKeyEq(cipher__SecKey* seckey1, cipher__SecKey* seckey2);
extern GoInt_ isU8Eq(unsigned char p1[], unsigned char p2[], size_t len);

extern GoInt_ isGoSliceEq(GoSlice* slice1, GoSlice* slice2);
extern GoInt_ isGoSlice_Eq(GoSlice_* slice1, GoSlice_* slice2);

extern GoInt_ isUxOutEq(coin__UxOut* x1, coin__UxOut* x2);

extern GoInt_ isUxArrayEq(coin__UxArray* x1, coin__UxArray* x2);

extern GoInt_ isTransactionEq(coin__Transaction* x1, coin__Transaction* x2);

extern GoInt_ isTransactionsEq(coin__Transactions* x1, coin__Transactions* x2);

extern GoInt_ isTransactionOutputEq(coin__TransactionOutput* x1, coin__TransactionOutput* x2);

extern GoInt_ isGoStringEq(GoString string1, GoString string2);

#endif // LIBSKY_ASSERT_H
