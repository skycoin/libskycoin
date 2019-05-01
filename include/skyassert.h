#ifndef LIBSKY_ASSERT_H
#define LIBSKY_ASSERT_H

#include "libskycoin.h"
#include "skyerrors.h"

extern int isAddressEq(cipher__Address *addr1, cipher__Address *addr2);
extern int isAddressEqPtr(cipher__Address addr1, cipher__Address addr2);

extern int isPubKeyEq(cipher__PubKey *pubkey1, cipher__PubKey *pubkey2);
extern int isSigEq(cipher__Sig *sig1, cipher__Sig *sig2);

extern int isSecKeyEq(cipher__SecKey *seckey1, cipher__SecKey *seckey2);
extern int isU8Eq(unsigned char p1[], unsigned char p2[], int len);

extern int isGoSliceEq(GoSlice *slice1, GoSlice *slice2);
extern int isGoSlice_Eq(GoSlice_ *slice1, GoSlice_ *slice2);

extern int isUxOutEq(coin__UxOut *x1, coin__UxOut *x2);

extern int isUxArrayEq(coin__UxArray *x1, coin__UxArray *x2);

extern int isTransactionEq(coin__Transaction *x1, coin__Transaction *x2);

extern int isTransactionsEq(coin__Transactions *x1, coin__Transactions *x2);

extern int isTransactionOutputEq(coin__TransactionOutput *x1, coin__TransactionOutput *x2);

#endif // LIBSKY_ASSERT_H
