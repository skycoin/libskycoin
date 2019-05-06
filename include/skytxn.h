
#include <stdio.h>
#include <string.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytypes.h"

GoUint32_ zeroFeeCalculator(Transaction__Handle handle, GoUint64_* pFee, void* context);

GoUint32_ makeKeysAndAddress(cipher__PubKey* ppubkey, cipher__SecKey* pseckey, cipher__Address* paddress);

GoUint32_ makeUxBodyWithSecret(coin__UxBody* puxBody, cipher__SecKey* pseckey);

GoUint32_ makeUxOutWithSecret(coin__UxOut* puxOut, cipher__SecKey* pseckey);

GoUint32_ makeUxBody(coin__UxBody* puxBody);

GoUint32_ makeUxOut(coin__UxOut* puxOut);

GoUint32_ makeAddress(cipher__Address* paddress);

coin__Transaction* makeTransactionFromUxOut(coin__UxOut* puxOut, cipher__SecKey* pseckey, Transaction__Handle* handle);

coin__Transaction* makeTransaction(Transaction__Handle* handle);

coin__Transaction* makeEmptyTransaction(Transaction__Handle* handle);

GoUint32_ makeTransactions(int n, Transactions__Handle* handle);

coin__Transaction* copyTransaction(Transaction__Handle handle, Transaction__Handle* handle2);

void makeRandHash(cipher__SHA256* phash);

GoUint32_ makeUxArray(coin__UxArray* parray, GoUint32_ n);

GoUint32_ sortTransactions(Transactions__Handle txns_handle, Transactions__Handle* sorted_txns_handle);
