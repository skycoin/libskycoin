
#include <string.h>
#include "skycriterion.h"
#include "skystring.h"

int equalSlices(GoSlice_ *slice1, GoSlice_ *slice2, int elem_size)
{
  if (slice1->len != slice2->len)
    return 0;
  return memcmp(slice1->data, slice2->data, slice1->len * elem_size) == 0;
}

int equalTransactions(coin__Transactions *pTxs1, coin__Transactions *pTxs2)
{
  if (pTxs1->len != pTxs2->len)
    return 0;
  coin__Transaction *pTx1 = pTxs1->data;
  coin__Transaction *pTx2 = pTxs2->data;
  for (int i = 0; i < pTxs1->len; i++)
  {
    if (!cr_user_coin__Transaction_eq(pTx1, pTx2))
      return 0;
    pTx1++;
    pTx2++;
  }
  return 1;
}

int isAddressEq(cipher__Address *addr1, cipher__Address *addr2)
{
  if (addr1->Version != addr2->Version)
    return 0;
  return memcmp((void *)addr1, (void *)addr2, sizeof(cipher__Address)) == 0;
}



int isGoStringEq(GoString *string1, GoString *string2)
{
  return (string1->n == string2->n) &&
         (strcmp((char *)string1->p, (char *)string2->p) == 0);
}

int isGoString_Eq(GoString_ *string1, GoString_ *string2)
{
  return (string1->n == string2->n) &&
         (strcmp((char *)string1->p, (char *)string2->p) == 0);
}



int isSecKeyEq(cipher__SecKey *seckey1, cipher__SecKey *seckey2)
{
  return memcmp((void *)seckey1, (void *)seckey2, sizeof(cipher__SecKey)) == 0;
}

int isPubKeyEq(cipher__PubKey *pubkey1, cipher__PubKey *pubkey2)
{
  return memcmp((void *)pubkey1, (void *)pubkey2, sizeof(cipher__PubKey)) == 0;
}

int cr_user_cipher__Ripemd160_noteq(cipher__Ripemd160 *rp1, cipher__Ripemd160 *rp2)
{
  return memcmp((void *)rp1, (void *)rp2, sizeof(cipher__Ripemd160)) != 0;
}

int cr_user_cipher__Ripemd160_eq(cipher__Ripemd160 *rp1, cipher__Ripemd160 *rp2)
{
  return memcmp((void *)rp1, (void *)rp2, sizeof(cipher__Ripemd160)) == 0;
}


int cr_user_cipher__SHA256_noteq(cipher__SHA256 *sh1, cipher__SHA256 *sh2)
{
  return memcmp((void *)sh1, (void *)sh1, sizeof(cipher__SHA256)) != 0;
}

int cr_user_cipher__SHA256_eq(cipher__SHA256 *sh1, cipher__SHA256 *sh2)
{
  return memcmp((void *)sh1, (void *)sh1, sizeof(cipher__SHA256)) == 0;
}

int cr_user_GoSlice_eq(GoSlice *slice1, GoSlice *slice2)
{
  return (slice1->len == slice2->len) &&
         (memcmp(slice1->data, slice2->data, slice1->len) == 0);
}


int cr_user_GoSlice__eq(GoSlice_ *slice1, GoSlice_ *slice2)
{
  return ((slice1->len == slice2->len)) && (memcmp(slice1->data, slice2->data, slice1->len) == 0);
}


int cr_user_coin__Transactions_eq(coin__Transactions *x1, coin__Transactions *x2)
{
  return equalTransactions(x1, x2);
}

int cr_user_coin__Transactions_noteq(coin__Transactions *x1, coin__Transactions *x2)
{
  return !equalTransactions(x1, x2);
}


int cr_user_coin__BlockBody_eq(coin__BlockBody *b1, coin__BlockBody *b2)
{
  return equalTransactions(&b1->Transactions, &b2->Transactions);
}

int cr_user_coin__BlockBody_noteq(coin__BlockBody *b1, coin__BlockBody *b2)
{
  return !equalTransactions(&b1->Transactions, &b2->Transactions);
}

int cr_user_coin__UxOut_eq(coin__UxOut *x1, coin__UxOut *x2)
{
  return memcmp(x1, x2, sizeof(coin__UxOut)) == 0;
}

int cr_user_coin__UxOut_noteq(coin__UxOut *x1, coin__UxOut *x2)
{
  return memcmp(x1, x2, sizeof(coin__UxOut)) != 0;
}


int cr_user_coin__Transaction_eq(coin__Transaction *x1, coin__Transaction *x2)
{
  if (x1->Length != x2->Length ||
      x1->Type != x2->Type)
  {
    return 0;
  }
  if (!cr_user_cipher__SHA256_eq(&x1->InnerHash, &x2->InnerHash))
    return 0;
  if (!equalSlices((GoSlice *)&x1->Sigs, (GoSlice *)&x2->Sigs, sizeof(cipher__Sig)))
    return 0;
  if (!equalSlices((GoSlice *)&x1->In, (GoSlice *)&x2->In, sizeof(cipher__SHA256)))
    return 0;
  if (!equalSlices((GoSlice *)&x1->Out, (GoSlice *)&x2->Out, sizeof(coin__TransactionOutput)))
    return 0;
  return 1;
}

int cr_user_coin__Transaction_noteq(coin__Transaction *x1, coin__Transaction *x2)
{
  return !cr_user_coin__Transaction_eq(x1, x2);
}


int cr_user_coin__TransactionOutput_eq(coin__TransactionOutput *x1, coin__TransactionOutput *x2)
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

int cr_user_coin__TransactionOutput_noteq(coin__TransactionOutput *x1, coin__TransactionOutput *x2)
{
  return !cr_user_coin__TransactionOutput_eq(x1, x2);
}

int cr_user_coin__UxArray_eq(coin__UxArray *slice1, coin__UxArray *slice2)
{
   return (memcmp(slice1->data, slice2->data, slice1->len) == 0) && ((slice1->len == slice2->len));
}

int cr_user_coin__UxArray_noteq(coin__UxArray *slice1, coin__UxArray *slice2)
{
  return (memcmp(slice1->data, slice2->data, slice1->len) != 0) && ((slice1->len != slice2->len));
}


int cr_user_Number_eq(Number *n1, Number *n2)
{
  return (equalSlices((GoSlice *)&n1->nat, (GoSlice *)&n2->nat, sizeof(GoInt)) &&
          ((GoInt)n1->neg == (GoInt)n2->neg));
}

int cr_user_Number_noteq(Number *n1, Number *n2)
{
  return (!(equalSlices((GoSlice *)&n1->nat, (GoSlice *)&n2->nat, sizeof(GoInt))) ||
          ((GoInt)n1->neg != (GoInt)n2->neg));
}

