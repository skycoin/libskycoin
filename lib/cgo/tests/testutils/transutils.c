
#include <stdio.h>
#include <string.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytxn.h"
#include <check.h>

GoUint32_ zeroFeeCalculator(Transaction__Handle handle, GoUint64_ *pFee,
                            void *context)
{
  *pFee = 0;
  return SKY_OK;
}

GoUint32_ makeKeysAndAddress(cipher__PubKey *ppubkey, cipher__SecKey *pseckey,
                             cipher__Address *paddress)
{
  GoUint32_ result;
  result = SKY_cipher_GenerateKeyPair(ppubkey, pseckey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");
  result = SKY_cipher_AddressFromPubKey(ppubkey, paddress);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
  return result;
}

GoUint32_ makeUxBodyWithSecret(coin__UxBody *puxBody, cipher__SecKey *pseckey) {
  cipher__PubKey pubkey;
  cipher__Address address;
  GoUint32_ result;

  memset(puxBody, 0, sizeof(coin__UxBody));
  puxBody->Coins = 1000000;
  puxBody->Hours = 100;

  result = SKY_cipher_GenerateKeyPair(&pubkey, pseckey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");
  result = SKY_cipher_PubKey_Verify(&pubkey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_PubKey_Verify failed");
  result = SKY_cipher_SecKey_Verify(pseckey);
  ck_assert_msg(result == SKY_OK, "Fail SKY_cipher_SecKey_Verify ");
  char buff[1024];
  GoSlice slice = {buff, 0, 1024};
  cipher__SHA256 hash;

  randBytes(&slice, 128);
  registerMemCleanup(slice.data);
  result = SKY_cipher_SumSHA256(slice, &puxBody->SrcTransaction);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");

  result = SKY_cipher_AddressFromPubKey(&pubkey, &puxBody->Address);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
  result = SKY_cipher_Address_Verify(&puxBody->Address,&pubkey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_Address_Verify failed");
  return result;
}

GoUint32_ makeUxOutWithSecret(coin__UxOut *puxOut, cipher__SecKey *pseckey) {
  GoUint32_ result;
  memset(puxOut, 0, sizeof(coin__UxOut));
  result = makeUxBodyWithSecret(&puxOut->Body, pseckey);
  puxOut->Head.Time = 100;
  puxOut->Head.BkSeq = 2;
  result = SKY_cipher_SecKey_Verify(pseckey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_SecKey_Verify failed");
  return result;
  
}

GoUint32_ makeUxBody(coin__UxBody *puxBody) {
  cipher__SecKey seckey;
  return makeUxBodyWithSecret(puxBody, &seckey);
}

GoUint32_ makeUxOut(coin__UxOut *puxOut) {
  cipher__SecKey seckey;
  return makeUxOutWithSecret(puxOut, &seckey);
}

GoUint32_ makeAddress(cipher__Address *paddress) {
  cipher__PubKey pubkey;
  cipher__SecKey seckey;
  cipher__Address address;
  GoUint32_ result;

  result = SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");

  result = SKY_cipher_AddressFromPubKey(&pubkey, paddress);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
  return result;
}

coin__Transaction *makeTransactionFromUxOut(coin__UxOut *puxOut,
                                            cipher__SecKey *pseckey,
                                            Transaction__Handle *handle)
{
   GoUint32_ result;
  coin__Transaction *ptransaction = NULL;
  *handle = 0;
  result = SKY_coin_Create_Transaction(handle);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transaction failed");
  registerHandleClose(*handle);
  
  cipher__SHA256 sha256;
  result = SKY_coin_UxOut_Hash(puxOut, &sha256);
  ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
  GoUint16 r;
  result = SKY_coin_Transaction_PushInput(*handle, &sha256);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushInput failed");

  cipher__Address address1, address2;
  result = makeAddress(&address1);
  ck_assert_msg(result == SKY_OK, "makeAddress failed");
  result = makeAddress(&address2);
  ck_assert_msg(result == SKY_OK, "makeAddress failed");

  result = SKY_coin_Transaction_PushOutput(*handle, &address1, 1000000, 50);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushOutput failed");
  result = SKY_coin_Transaction_PushOutput(*handle, &address2, 5000000, 50);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushOutput failed");

  GoSlice secKeys = {pseckey, 1, 1};
  result = SKY_coin_Transaction_SignInputs(*handle, secKeys);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_SignInputs failed");
  result = SKY_coin_Transaction_UpdateHeader(*handle);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_UpdateHeader failed");
  result = SKY_coin_GetTransactionObject(*handle, &ptransaction);
  ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionObject failed");
  registerMemCleanup(ptransaction);
  return ptransaction;
}

coin__Transaction *makeTransaction(Transaction__Handle *handle)
{
  GoUint32_ result;
  *handle = 0;
  coin__UxOut uxOut;
  memset(&uxOut,0,sizeof(coin__UxOut));
  cipher__SecKey seckey;
  result = makeUxOutWithSecret(&uxOut, &seckey);
  ck_assert_msg(result == SKY_OK, "makeUxOutWithSecret failed");
  coin__Transaction *rest = makeTransactionFromUxOut(&uxOut, &seckey, handle);
  return rest;
}

coin__Transaction *makeEmptyTransaction(Transaction__Handle *handle)
{
  GoUint32_ result;
  coin__Transaction *ptransaction = NULL;
  *handle = 0;
  result = SKY_coin_Create_Transaction(handle);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transaction failed");
  result = SKY_coin_GetTransactionObject(*handle, &ptransaction);
  ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionObject failed");
  return ptransaction;
}

GoUint32_ makeTransactions(GoInt32 n, Transactions__Handle *handle) {
  GoUint32_ result = SKY_coin_Create_Transactions(handle);
  ck_assert(result == SKY_OK);
  GoInt32 i;
  for (i = 0; i < n; i++)
  {
    Transaction__Handle thandle = 0 ;
    makeTransaction(&thandle);
    registerHandleClose(thandle);
    result = SKY_coin_Transactions_Add(*handle, thandle);
    ck_assert(result == SKY_OK);
  }
  return result;
}

typedef struct
{
  cipher__SHA256 hash;
  Transaction__Handle handle;
} TransactionObjectHandle;

GoUint32_ sortTransactions(Transactions__Handle txns_handle,
                           Transactions__Handle *sorted_txns_handle)
{
  GoUint32_ result = SKY_coin_Create_Transactions(sorted_txns_handle);
  ck_assert(result == SKY_OK);
  registerHandleClose(*sorted_txns_handle);
  GoInt n, i, j;
  result = SKY_coin_Transactions_Length(txns_handle, &n);
  ck_assert(result == SKY_OK);
  TransactionObjectHandle *pTrans = malloc(n * sizeof(TransactionObjectHandle));
  ck_assert(pTrans != NULL);
  registerMemCleanup(pTrans);
  memset(pTrans, 0, n * sizeof(TransactionObjectHandle));
  int *indexes = malloc(n * sizeof(int));
  ck_assert(indexes != NULL);
  registerMemCleanup(indexes);
  for (i = 0; i < n; i++)
  {
    indexes[i] = i;
    result = SKY_coin_Transactions_GetAt(txns_handle, i, &pTrans[i].handle);
    ck_assert(result == SKY_OK);
    registerHandleClose(pTrans[i].handle);
    result = SKY_coin_Transaction_Hash(pTrans[i].handle, &pTrans[i].hash);
    ck_assert(result == SKY_OK);
  }

  // Swap sort.
  cipher__SHA256 hash1, hash2;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      int cmp = memcmp(&pTrans[indexes[i]].hash, &pTrans[indexes[j]].hash,
                       sizeof(cipher__SHA256));
      if (cmp > 0)
      {
        // Swap
        int tmp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = tmp;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    result = SKY_coin_Transactions_Add(*sorted_txns_handle,
                                       pTrans[indexes[i]].handle);
    ck_assert(result == SKY_OK);
  }
  return result;
}

coin__Transaction *copyTransaction(Transaction__Handle handle,
                                   Transaction__Handle *handle2)
{
  coin__Transaction *ptransaction = NULL;
  GoUint32_ result = 0;
  result = SKY_coin_Transaction_Copy(handle, handle2);
  ck_assert(result == SKY_OK);
  registerHandleClose(*handle2);
  result = SKY_coin_GetTransactionObject(*handle2, &ptransaction);
  registerMemCleanup(ptransaction);
  ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionObject failed");
  return ptransaction;
}

void makeRandHash(cipher__SHA256 *phash)
{
  char buff[1024];
  GoSlice slice = {buff, 0, 1024};
  randBytes(&slice, 128);
  registerMemCleanup(slice.data);
  GoUint32_ result = SKY_cipher_SumSHA256(slice, phash);
  ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
}

GoUint32_ makeUxArray(coin__UxArray *parray, GoUint32_ n)
{
  parray->data = malloc(sizeof(coin__UxOut) * n);
  if (!parray->data)
    return SKY_ERROR;
  registerMemCleanup(parray->data);
  parray->cap = parray->len = n;
  coin__UxOut *p = (coin__UxOut *)parray->data;
  GoUint32_ result = SKY_OK;
  GoUint32_ i;
  for (i = 0; i < n; i++)
  {
    result = makeUxOut(p);
    if (result != SKY_OK)
      break;
    p++;
  }
  return result;
}
