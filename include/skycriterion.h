#ifndef LIBCRITERION_H
#define LIBCRITERION_H

#include "libskycoin.h"
#include "skyerrors.h"

extern int isAddressEq(cipher__Address *addr1, cipher__Address *addr2);
extern int isAddressEqPtr(cipher__Address addr1, cipher__Address addr2);

extern int isGoStringEq(GoString *string1, GoString *string2);
extern int isGoString_Eq(GoString_ *string1, GoString_ *string2);

extern int isPubKeyEq(cipher__PubKey *pubkey1, cipher__PubKey *pubkey2);
extern int isSigEq(cipher__Sig *sig1, cipher__Sig *sig2);

extern int isSecKeyEq(cipher__SecKey *seckey1, cipher__SecKey *seckey2);
extern int isU8Eq(unsigned char p1[], unsigned char p2[], int len);
extern char *cr_user_cipher__SecKey_tostr(cipher__SecKey *seckey1);

extern int cr_user_cipher__Ripemd160_noteq(cipher__Ripemd160 *rp1, cipher__Ripemd160 *rp2);
extern int cr_user_cipher__Ripemd160_eq(cipher__Ripemd160 *rp1, cipher__Ripemd160 *rp2);
extern char *cr_user_cipher__Ripemd160_tostr(cipher__Ripemd160 *rp1);

extern int isGoSliceEq(GoSlice *slice1, GoSlice *slice2);
extern int isGoSlice_Eq(GoSlice_ *slice1, GoSlice_ *slice2);
extern char *cr_user_GoSlice_tostr(GoSlice *slice1);
extern int cr_user_GoSlice_noteq(GoSlice *slice1, GoSlice *slice2);

extern int cr_user_GoSlice__eq(GoSlice_ *slice1, GoSlice_ *slice2);
extern char *cr_user_GoSlice__tostr(GoSlice_ *slice1);
extern int cr_user_GoSlice__noteq(GoSlice_ *slice1, GoSlice_ *slice2);

extern int cr_user_cipher__SHA256_noteq(cipher__SHA256 *sh1, cipher__SHA256 *sh2);
extern int cr_user_cipher__SHA256_eq(cipher__SHA256 *sh1, cipher__SHA256 *sh2);
extern char *cr_user_cipher__SHA256_tostr(cipher__SHA256 *sh1);

extern int cr_user_secp256k1go__Field_eq(secp256k1go__Field *f1, secp256k1go__Field *f2);

extern int cr_user_coin__BlockBody_eq(coin__BlockBody *b1, coin__BlockBody *b2);
extern int cr_user_coin__BlockBody_noteq(coin__BlockBody *b1, coin__BlockBody *b2);
extern char *cr_user_coin__BlockBody_tostr(coin__BlockBody *b);

extern int cr_user_coin__UxOut_eq(coin__UxOut *x1, coin__UxOut *x2);
extern int cr_user_coin__UxOut_noteq(coin__UxOut *x1, coin__UxOut *x2);
extern char *cr_user_coin__UxOut_tostr(coin__UxOut *x1);

extern int isUxArrayEq(coin__UxArray *x1, coin__UxArray *x2);
extern int cr_user_coin__UxArray_noteq(coin__UxArray *x1, coin__UxArray *x2);
extern char *cr_user_coin__UxArray_tostr(coin__UxArray *x1);

extern int isTransactionEq(coin__Transaction *x1, coin__Transaction *x2);
extern int cr_user_coin__Transaction_noteq(coin__Transaction *x1, coin__Transaction *x2);
extern char *cr_user_coin__Transaction_tostr(coin__Transaction *x1);

extern int isTransactionsEq(coin__Transactions *x1, coin__Transactions *x2);
extern int cr_user_coin__Transactions_noteq(coin__Transactions *x1, coin__Transactions *x2);
extern char *cr_user_coin__Transactions_tostr(coin__Transactions *x1);

extern int cr_user_coin__TransactionOutput_eq(coin__TransactionOutput *x1, coin__TransactionOutput *x2);
extern int cr_user_coin__TransactionOutput_noteq(coin__TransactionOutput *x1, coin__TransactionOutput *x2);
extern char *cr_user_coin__TransactionOutput_tostr(coin__TransactionOutput *x1);

extern int cr_user_Number_eq(Number *n1, Number *n2);
extern int cr_user_Number_noteq(Number *n1, Number *n2);
extern char *cr_user_Number_tostr(Number *n1);

#endif //LIBCRITERION_H
