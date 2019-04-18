#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include "libskycoin.h"
#include "skyerrors.h"
#include "skycriterion.h"
#include "skystring.h"
#include "skytxn.h"
#include "skytest.h"
#include "time.h"

Transactions__Handle makeTestTransactions()
{
    Transactions__Handle transactions = 0;
    Transaction__Handle transaction = 0;

    GoInt32 result = SKY_coin_Create_Transactions(&transactions);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transactions failed");
    registerHandleClose(transactions);
    result = SKY_coin_Create_Transaction(&transaction);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transaction failed");
    registerHandleClose(transaction);
    result = SKY_coin_Transactions_Add(transactions, transaction);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Add failed");
    return transactions;
}

GoUint32 makeNewBlock(cipher__SHA256 *uxHash, Block__Handle *newBlock) {
  GoUint32 result;
  cipher__SHA256 bodyhash;
  BlockBody__Handle block;
  Transactions__Handle transactions = makeTestTransactions();

  result = SKY_coin_NewEmptyBlock(transactions, &block);
  ck_assert_msg(result == SKY_OK, "SKY_coin_NewEmptyBlock failed");
  registerHandleClose(block);
  coin__Block *pBlock;
  result = SKY_coin_GetBlockObject(block, &pBlock);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Get_Block_Object failed");
  BlockBody__Handle body_handle = 0;
  pBlock->Head.Version = 0x02;
  pBlock->Head.BkSeq = 0;
  SKY_coin_NewBlockHeader(&pBlock->Head, &pBlock->Head.BodyHash, 100, 10, block,
                          &pBlock->Head);

  BlockBody__Handle body = 0;
  result = SKY_coin_GetBlockBody(block, &body);
  ck_assert_msg(result == SKY_OK, "SKY_coin_Get_Block_Body failed");
  result = SKY_coin_BlockBody_Hash(body, &bodyhash);
  ck_assert_msg(result == SKY_OK, "SKY_coin_BlockBody_Hash failed");
  FeeCalculator zf = {zeroFeeCalculator, NULL};
  result =
      SKY_coin_NewBlock(block, 100 + 200, uxHash, transactions, &zf, newBlock);
  ck_assert_msg(result == SKY_OK, "SKY_coin_NewBlock failed");
  registerHandleClose(*newBlock);
  return result;
}

GoUint32_ fix121FeeCalculator(Transaction__Handle handle, GoUint64_ *pFee, void *context)
{
    *pFee = 121;
    return SKY_OK;
}

START_TEST(TestNewBlock)
{
    Block__Handle prevBlock = 0;
    Block__Handle newBlock = 0;
    coin__Block *pPrevBlock = NULL;
    coin__Block *pNewBlock = NULL;
    GoUint32 result = 0;

    Transactions__Handle transactions = makeTestTransactions();
    result = SKY_coin_NewEmptyBlock(transactions, &prevBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewEmptyBlock failed");
    registerHandleClose(prevBlock);
    result = SKY_coin_GetBlockObject(prevBlock, &pPrevBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed");
    unsigned char bufferSlice[1024];
    GoSlice slice = {bufferSlice, 0, 1024};
    cipher__SHA256 hash = "";

    randBytes(&slice, 128);
    registerMemCleanup(slice.data);
    result = SKY_cipher_SumSHA256(slice, &hash);
    BlockBody__Handle body_handle = 0;
    SKY_coin_NewBlockHeader(&pPrevBlock->Head, &pPrevBlock->Head.BodyHash, 100,
                            98, body_handle, &pPrevBlock->Head);
    
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    FeeCalculator zf = {zeroFeeCalculator, NULL};
    result = SKY_coin_NewBlock(prevBlock, 133, &hash, 0, &zf, &newBlock);
    ck_assert_msg(result != SKY_OK, "SKY_coin_NewBlock has to fail with no  transactions"); 
    registerHandleClose(newBlock);

    transactions = 0;
    Transaction__Handle tx = 0;
    result = SKY_coin_Create_Transactions(&transactions);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transactions failed");
    registerHandleClose(transactions);
    makeEmptyTransaction(&tx);
    registerHandleClose(tx);
    result = SKY_coin_Transactions_Add(transactions, tx);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Add failed");

    GoUint64 fee = 121;
    GoUint64 currentTime = 133;

    FeeCalculator f121 = {fix121FeeCalculator, NULL};
    result = SKY_coin_NewBlock(prevBlock, currentTime, &hash, transactions, &f121, &newBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewBlock failed");
    registerHandleClose(newBlock);
    result = SKY_coin_GetBlockObject(newBlock, &pNewBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed");
    coin__UxArray *pTransactions = NULL;
    result = SKY_coin_GetTransactionsObject(transactions, &pTransactions);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionsObject failed");
    BlockBody__Handle pBlockBody_Han = 0;
    result = SKY_coin_GetBlockBody(newBlock, &pBlockBody_Han);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
    Transactions__Handle Trans_Handle =0;
     result = SKY_coin_BlockBody_Transactions(pBlockBody_Han, &Trans_Handle);
     ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
     coin__UxArray *pTrans = NULL;
    result = SKY_coin_GetTransactionsObject(Trans_Handle,&pTrans);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionsObject failed");
    ck_assert(isTransactionsEq(pTrans, pTransactions));
    BlockHeader__Handle pBlockHeader_Han = 0;
    result = SKY_coin_Block_GetBlockHeader(newBlock, &pBlockHeader_Han);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");
    GoUint64 pValue, pPrevValue;
    result = SKY_coin_BlockHeader_Fee(pBlockHeader_Han,&pValue);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Fee failed");
    ck_assert_int_eq(pValue, fee * (GoUint64)(pTransactions->len));
    result = SKY_coin_BlockHeader_Time(pBlockHeader_Han, &pValue);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Time failed");
    ck_assert_int_eq(pValue, currentTime);
    result = SKY_coin_BlockHeader_BkSeq(pBlockHeader_Han, &pValue);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_BkSeq failed");
    BlockHeader__Handle pPrevBlockHeader_Han = 0;
    result = SKY_coin_Block_GetBlockHeader(prevBlock, &pPrevBlockHeader_Han);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");
    result = SKY_coin_BlockHeader_BkSeq(pPrevBlockHeader_Han, &pPrevValue);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_BkSeq failed");
    ck_assert_int_eq(pValue, (pPrevValue + 1));
    cipher__SHA256 pHash = "";
    result = SKY_coin_BlockHeader_UxHash(pBlockHeader_Han, &pHash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_UxHash failed");
    ck_assert(isU8Eq(pHash, hash, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestBlockHashHeader)
{
    GoUint32 result;
    Block__Handle block = 0;
    coin__Block *pBlock = NULL;
    GoUint8 bufferslice[1024];
    GoSlice slice={bufferslice,0,1024};
    cipher__SHA256 hash;

    randBytes(&slice, 128);
    registerMemCleanup(slice.data);
    result = SKY_cipher_SumSHA256(slice, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    result = makeNewBlock(&hash, &block);
    ck_assert_msg(result == SKY_OK, "makeNewBlock failed");
    result = SKY_coin_GetBlockObject(block, &pBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed, block handle : %d", block);

    cipher__SHA256 hash1 = "";
    cipher__SHA256 hash2 = "";
    result = SKY_coin_Block_HashHeader(block, &hash1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_HashHeader failed");
    result = SKY_coin_BlockHeader_Hash(&pBlock->Head, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Hash failed");
    ck_assert(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
    strcpy(hash2,"");
    ck_assert(!isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestBlockHashBody)
{
    GoUint32 result;
    Block__Handle block = 0;
    GoUint8 bufferslice[1024];
    GoSlice slice = {bufferslice, 0, 1024};
    cipher__SHA256 hash;

    randBytes(&slice, 128);
    registerMemCleanup(slice.data);
    result = SKY_cipher_SumSHA256(slice, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    result = makeNewBlock(&hash, &block);
    ck_assert_msg(result == SKY_OK, "makeNewBlock failed");

    cipher__SHA256 hash1, hash2;
    result = SKY_coin_Block_HashBody(block, &hash1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockBody_Hash failed");
    BlockBody__Handle blockBody = 0;
    result = SKY_coin_GetBlockBody(block, &blockBody);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
    result = SKY_coin_BlockBody_Hash(blockBody, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockBody_Hash failed");
    ck_assert(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestNewGenesisBlock)
{
    cipher__PubKey pubkey = "";
    cipher__SecKey seckey = "";
    cipher__Address address;
    GoUint64 genTime = 1000;
    GoUint64 genCoins = 1000 * 1000 * 1000;
    GoUint64 genCoinHours = 1000 * 1000;
    Block__Handle block = 0;
    coin__Block *pBlock = NULL;
    registerHandleClose(block);
    GoUint32_ result = makeKeysAndAddress(&pubkey, &seckey, &address);
    ck_assert_msg(result == SKY_OK, "makeKeysAndAddress failed");
    result = SKY_coin_NewGenesisBlock(&address, genCoins, genTime, &block);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewGenesisBlock failed");
    result = SKY_coin_GetBlockObject(block, &pBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed");

    BlockHeader__Handle pHead_handle = 0;
    coin__BlockHeader *pHead = NULL;
    result = SKY_coin_Block_GetBlockHeader(block, &pHead_handle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");
    result = SKY_coin_GetBlockHeaderObject(pHead_handle, &pHead);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockHeaderObject failed");
    cipher__SHA256 nullHash = "";
    ck_assert(isU8Eq(nullHash, pHead->PrevHash, sizeof(cipher__SHA256)));
    GoUint64 pTime;
    result = SKY_coin_BlockHeader_Time(pHead_handle, &pTime);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Time failed");
    ck_assert_int_eq(genTime, pTime);
    ck_assert_int_eq(0, pHead->BkSeq);
    ck_assert_int_eq(0, pHead->Version);
    ck_assert_int_eq(0, pHead->Fee);
    cipher__SHA256 pHeadUxHash;
    result = SKY_coin_BlockHeader_UxHash(pHead_handle,&pHeadUxHash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_UxHash failed");
    ck_assert(isU8Eq(nullHash, pHeadUxHash, sizeof(cipher__SHA256)));

    BlockBody__Handle pBody_Handle = 0;
    result = SKY_coin_GetBlockBody(block, &pBody_Handle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
    Transactions__Handle pTrans_Handle = 0;
    result = SKY_coin_BlockBody_Transactions(pBody_Handle, &pTrans_Handle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
    GoInt pLenght;
    result = SKY_coin_Transactions_Length(pTrans_Handle, &pLenght);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Length failed");
    ck_assert_int_eq(1 , pLenght);
    Transaction__Handle pTran_Handle = 0;
    result = SKY_coin_Transactions_GetAt(pTrans_Handle, 0, &pTran_Handle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_GetAt failed");
    coin__Transaction *ptransaction = NULL;
    result = SKY_coin_GetTransactionObject(pTran_Handle, &ptransaction);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetTransactionObject failed");
    ck_assert(0 == ptransaction->In.len);
    ck_assert(0 == ptransaction->Sigs.len);
    ck_assert(1 == ptransaction->Out.len);

    coin__TransactionOutput *poutput =
        (coin__TransactionOutput *)ptransaction->Out.data;
    ck_assert(isAddressEq(&address, &poutput->Address));
    ck_assert(genCoins == poutput->Coins);
    ck_assert(genCoins == poutput->Hours);
}
END_TEST

typedef struct
{
    int index;
    int failure;
} testcase_unspent;

START_TEST(TestCreateUnspent)
{
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__Address address;
    int result = makeKeysAndAddress(&pubkey, &seckey, &address);

    cipher__SHA256 hash;
    coin__Transaction *ptx;
    Transaction__Handle handle;
    ptx = makeEmptyTransaction(&handle);
    result = SKY_coin_Transaction_PushOutput(handle, &address, 11000000, 255);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushOutput failed");
    coin__BlockHeader bh;
    memset(&bh, 0, sizeof(coin__BlockHeader));
    bh.Time = time(0);
    bh.BkSeq = 1;

    testcase_unspent t[] = {
        {0, 0},
        {10, 1},
    };
    coin__UxOut ux;
    int tests_count = sizeof(t) / sizeof(testcase_unspent);
    for (int i = 0; i < tests_count; i++)
    {
        memset(&ux, 0, sizeof(coin__UxOut));
        result = SKY_coin_CreateUnspent(&bh, handle, t[i].index, &ux);
        if (t[i].failure)
        {
            ck_assert_msg(result == SKY_ERROR, "SKY_coin_CreateUnspent should have failed");
            continue;
        }
        else
        {
            ck_assert_msg(result == SKY_OK, "SKY_coin_CreateUnspent failed");
        }
        ck_assert_int_eq(bh.Time , ux.Head.Time);
        ck_assert_int_eq(bh.BkSeq , ux.Head.BkSeq);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(hash, ux.Body.SrcTransaction, sizeof(cipher__SHA256)));
        ck_assert(t[i].index < ptx->Out.len);
        coin__TransactionOutput *poutput = (coin__TransactionOutput *)ptx->Out.data;
        ck_assert(isAddressEq(&ux.Body.Address, &poutput->Address));
        ck_assert_int_eq(ux.Body.Coins , poutput->Coins);
        ck_assert_int_eq(ux.Body.Hours , poutput->Hours);
    }
}
END_TEST

START_TEST(TestCreateUnspents)
{
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__Address address;
    GoUint32 result = makeKeysAndAddress(&pubkey, &seckey, &address);
    ck_assert_msg(result == SKY_OK, "makeKeysAndAddress failed");
    result = SKY_cipher_Address_Verify(&address, &pubkey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_Address_Verify failed");
    cipher__SHA256 hash;
    coin__Transaction *ptx;
    Transaction__Handle handle;
    ptx = makeEmptyTransaction(&handle);
    result = SKY_coin_Transaction_PushOutput(handle, &address, 11000000, 255);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushOutput failed");
    coin__BlockHeader bh;
    memset(&bh, 0, sizeof(coin__BlockHeader));
    bh.Time = time(0);
    bh.BkSeq = 1;
    unsigned char bufferUxs[1024];
    coin__UxArray uxs = {bufferUxs, 0, 1024};
    result = SKY_coin_CreateUnspents(&bh, handle, &uxs);
    ck_assert_msg(result == SKY_OK, "SKY_coin_CreateUnspents failed");
    registerMemCleanup(uxs.data);
    ck_assert(uxs.len == 1);
    ck_assert_int_eq(uxs.len, ptx->Out.len);
    coin__UxOut *pout = (coin__UxOut *)uxs.data;
    coin__TransactionOutput *ptxout = (coin__TransactionOutput *)ptx->Out.data;
    int i;
    for (i = 0; i < uxs.len; i++)
    {
        ck_assert_int_eq(bh.Time, pout->Head.Time);
        ck_assert_int_eq(bh.BkSeq, pout->Head.BkSeq);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(
            isU8Eq(hash, pout->Body.SrcTransaction, sizeof(cipher__SHA256)));
        ck_assert(isAddressEq(&pout->Body.Address, &ptxout->Address));
        ck_assert_int_eq(pout->Body.Coins, ptxout->Coins);
        ck_assert_int_eq(pout->Body.Hours, ptxout->Hours);
        pout++;
        ptxout++;
    }
}
END_TEST

Suite *coin_blocks(void) {
  Suite *s = suite_create("Load coin.block");
  TCase *tc;

  tc = tcase_create("coin.block");
  tcase_add_checked_fixture(tc, setup, teardown);
  tcase_add_test(tc, TestNewBlock); //ok
  tcase_add_test(tc, TestBlockHashHeader); // ok
  tcase_add_test(tc, TestBlockHashBody);   // ok
   tcase_add_test(tc, TestNewGenesisBlock); //ok
  tcase_add_test(tc, TestCreateUnspent);  // ok
  tcase_add_test(tc, TestCreateUnspents); // ok
  suite_add_tcase(s, tc);
  tcase_set_timeout(tc, 150);

  return s;
}
