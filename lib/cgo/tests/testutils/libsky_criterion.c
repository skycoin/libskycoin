
#include <string.h>
#include "skycriterion.h"
#include "skystring.h"

int equalSlices(GoSlice *slice1, GoSlice *slice2, int elem_size)
{
  if (slice1->len != slice2->len)
    return 0;
  return (memcmp(slice1->data, slice2->data, slice1->len * elem_size) == 0);
}

int equalSlices_(GoSlice_ *slice1, GoSlice_ *slice2, int elem_size)
{
  if (slice1->len != slice2->len)
    return 0;
  return (memcmp(slice1->data, slice2->data, slice1->len * elem_size) == 0);
}

int equalTransactions(coin__Transactions *pTxs1, coin__Transactions *pTxs2)
{
  if (pTxs1->len != pTxs2->len)
    return 0;
  coin__Transaction *pTx1 = pTxs1->data;
  coin__Transaction *pTx2 = pTxs2->data;
  int i;
  for (i = 0; i < pTxs1->len; i++)
  {
    if (!isTransactionEq(pTx1, pTx2))
      return 0;
    pTx1++;
    pTx2++;
  }
  return 1;
}

int isAddressEq(cipher__Address *addr1, cipher__Address *addr2)
{
  return (addr1->Version == addr2->Version && memcmp((void *)addr1, (void *)addr2, sizeof(cipher__Address)) == 0);
}

int isGoStringEq(GoString string1, GoString string2)
{
  return (string1.n == string2.n) &&
         (strcmp(string1.p, string2.p) == 0);
}

int isGoString_Eq(GoString_ string1, GoString_ string2)
{
  return (string1.n == string2.n) &&
         (strcmp(string1.p, string2.p) == 0);
}

int isSecKeyEq(cipher__SecKey *seckey1, cipher__SecKey *seckey2)
{
  return memcmp((void *)seckey1, (void *)seckey2, sizeof(cipher__SecKey)) == 0;
}

int isPubKeyEq(cipher__PubKey *pubkey1, cipher__PubKey *pubkey2)
{
  return (memcmp((void *)pubkey1, (void *)pubkey2, sizeof(cipher__PubKey)) == 0);
}

int isSigEq(cipher__Sig *sig1, cipher__Sig *sig2)
{
  return memcmp((void *)sig1, (void *)sig2, sizeof(cipher__Sig)) == 0;
}

int isU8Eq(unsigned char p1[], unsigned char p2[], int len)
{
  size_t i;
   for (i= 0; i < len; i++) {
    if (p1[i] != p2[i])
    {
      return 0;
    }
  }

  return 1;
}

int isSHA256Eq(cipher__SHA256 *sh1, cipher__SHA256 *sh2)
{
  return (memcmp((void *)sh1, (void *)sh1, sizeof(cipher__SHA256)) == 0);
}

int isGoSliceEq(GoSlice *slice1, GoSlice *slice2)
{
  return (slice1->len == slice2->len) &&
         (memcmp(slice1->data, slice2->data, slice1->len) == 0);
}

int isGoSlice_Eq(GoSlice_ *slice1, GoSlice_ *slice2)
{
  return (slice1->len == slice2->len) &&
         (memcmp(slice1->data, slice2->data, slice1->len) == 0);
}

int isTransactionsEq(coin__Transactions *x1, coin__Transactions *x2)
{
  return equalTransactions(x1, x2);
}

int isUxOutEq(coin__UxOut *x1, coin__UxOut *x2)
{
  return memcmp(x1, x2, sizeof(coin__UxOut)) == 0;
}

int isTransactionEq(coin__Transaction *x1, coin__Transaction *x2)
{
  if (x1->Length != x2->Length ||
      x1->Type != x2->Type)
  {
    return 0;
  }
  if (!isSHA256Eq(&x1->InnerHash, &x2->InnerHash))
    return 0;
  if (!equalSlices_(&x1->Sigs, &x2->Sigs, sizeof(cipher__Sig)))
    return 0;
  if (!equalSlices_(&x1->In, &x2->In, sizeof(cipher__SHA256)))
    return 0;
  if (!equalSlices_(&x1->Out, &x2->Out, sizeof(coin__TransactionOutput)))
    return 0;
  return 1;
}

int isTransactionOutputEq(coin__TransactionOutput *x1, coin__TransactionOutput *x2)
{
  if (x1->Coins != x2->Coins ||
      x1->Hours != x2->Hours)
  {
    return 0;
  }

  if (!isAddressEq(&x1->Address, &x2->Address))
    return 0;
  return 1;
}

int isUxArrayEq(coin__UxArray *slice1, coin__UxArray *slice2)
{
  return (memcmp(slice1->data, slice2->data, slice1->len) == 0) && ((slice1->len == slice2->len));
}
