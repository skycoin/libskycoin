#include <stdio.h>
#include <stdlib.h>

#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytxn.h"
#include "time.h"
#include <check.h>

Transactions__Handle makeTestTransactions()
{
    Transactions__Handle transactions = 0;
    Transaction__Handle transaction = 0;

    GoUint32 result = SKY_coin_Create_Transactions(&transactions);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transactions failed");
    registerHandleClose(transactions);
    result = SKY_coin_Create_Transaction(&transaction);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Create_Transaction failed");
    registerHandleClose(transaction);
    result = SKY_coin_Transactions_Add(transactions, transaction);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Add failed");
    return transactions;
}

GoUint32 makeNewBlock(cipher__SHA256* uxHash, Block__Handle* newBlock)
{
    GoUint32 result;
    cipher__SHA256 bodyhash;
    BlockBody__Handle block;
    Transactions__Handle transactions = makeTestTransactions();

    result = SKY_coin_NewEmptyBlock(transactions, &block);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewEmptyBlock failed");
    registerHandleClose(block);
    coin__Block* pBlock;
    result = SKY_coin_GetBlockObject(block, &pBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Get_Block_Object failed");

    pBlock->Head.Version = 0x02;
    pBlock->Head.Time = 100;
    pBlock->Head.BkSeq = 0;
    pBlock->Head.Fee = 10;
    BlockBody__Handle body = 0;
    result = SKY_coin_GetBlockBody(block, &body);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Get_Block_Body failed");
    result = SKY_coin_BlockBody_Hash(body, &bodyhash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockBody_Hash failed");
    FeeCalculator zf = {zeroFeeCalculator, NULL};
    result = SKY_coin_NewBlock(block, 100 + 200, uxHash, transactions, &zf, newBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewBlock failed");
    registerHandleClose(*newBlock);
    return result;
}

GoUint32_ fix121FeeCalculator(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    *pFee = 121;
    return SKY_OK;
}

START_TEST(TestNewBlock)
{
    printf("Load TestNewBlock\n");
    Block__Handle prevBlock = 0;
    Block__Handle newBlock = 0;
    coin__Block* pPrevBlock = NULL;
    coin__Block* pNewBlock = NULL;
    GoUint32 result = 0;

    Transactions__Handle transactions = makeTestTransactions();
    result = SKY_coin_NewEmptyBlock(transactions, &prevBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewEmptyBlock failed");
    registerHandleClose(prevBlock);
    coin__Block* pBlock;
    result = SKY_coin_GetBlockObject(prevBlock, &pPrevBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed");

    pPrevBlock->Head.Version = 0x02;
    pPrevBlock->Head.Time = 100;
    pPrevBlock->Head.BkSeq = 98;

    GoUint8 buffer_slice[1024];
    GoSlice slice = {buffer_slice, 0, 1024};
    cipher__SHA256 hash;

    randBytes(&slice, 128);
    registerMemCleanup(slice.data);
    result = SKY_cipher_SumSHA256(slice, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    FeeCalculator zf = {zeroFeeCalculator, NULL};
    result = SKY_coin_NewBlock(prevBlock, 133, &hash, 0, &zf, &newBlock);
    ck_assert_msg(result != SKY_OK, "SKY_coin_NewBlock has to fail with no transactions");
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
    coin__Transactions* pTransactions = NULL;
    SKY_coin_GetTransactionsObject(transactions, &pTransactions);
    ck_assert(isTransactionsEq(&pNewBlock->Body.Transactions, pTransactions));
    ck_assert(pNewBlock->Head.Fee == fee * (GoUint64)(pTransactions->len));
    ck_assert(pNewBlock->Head.Time == currentTime);
    ck_assert(pNewBlock->Head.BkSeq == (pPrevBlock->Head.BkSeq + 1));
    ck_assert(isU8Eq(pNewBlock->Head.UxHash, hash, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestBlockHashHeader)
{
    printf("Load TestBlockHashHeader\n");
    GoUint32_ result;
    Block__Handle block = 0;
    coin__Block* pBlock = NULL;
    GoUint8 buffer_slice[1024];
    GoSlice slice = {buffer_slice, 0, 1024};
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
    strcpy(hash2, "");
    ck_assert(!isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestBlockHashBody)
{
    printf("Load TestBlockHashBody\n");
    GoUint32_ result;
    Block__Handle block = 0;
    GoUint8 buffer_slice[1024];
    GoSlice slice = {buffer_slice, 0, 1024};
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
    printf("Load TestNewGenesisBlock\n");
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__Address address;
    GoUint64 genTime = 1000;
    GoUint64 genCoins = 1000 * 1000 * 1000;
    GoUint64 genCoinHours = 1000 * 1000;
    Block__Handle block = 0;
    coin__Block* pBlock = NULL;

    GoUint32_ result = makeKeysAndAddress(&pubkey, &seckey, &address);
    ck_assert_msg(result == SKY_OK, "makeKeysAndAddress failed");
    result = SKY_coin_NewGenesisBlock(&address, genCoins, genTime, &block);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewGenesisBlock failed");
    result = SKY_coin_GetBlockObject(block, &pBlock);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockObject failed");

    cipher__SHA256 nullHash;
    memset(&nullHash, 0, sizeof(cipher__SHA256));
    ck_assert(isU8Eq(nullHash, pBlock->Head.PrevHash, sizeof(cipher__SHA256)));
    ck_assert(genTime == pBlock->Head.Time);
    ck_assert(0 == pBlock->Head.BkSeq);
    ck_assert(0 == pBlock->Head.Version);
    ck_assert(0 == pBlock->Head.Fee);
    ck_assert(isU8Eq(nullHash, pBlock->Head.UxHash, sizeof(cipher__SHA256)));

    ck_assert(1 == pBlock->Body.Transactions.len);
    coin__Transaction* ptransaction = (coin__Transaction*)pBlock->Body.Transactions.data;
    ck_assert(0 == ptransaction->In.len);
    ck_assert(0 == ptransaction->Sigs.len);
    ck_assert(1 == ptransaction->Out.len);

    coin__TransactionOutput* poutput = (coin__TransactionOutput*)ptransaction->Out.data;
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
    printf("Load TestCreateUnspent\n");
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__Address address;
    GoUint32 result = makeKeysAndAddress(&pubkey, &seckey, &address);

    cipher__SHA256 hash;
    coin__Transaction* ptx;
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
    for (int i = 0; i < tests_count; i++) {
        memset(&ux, 0, sizeof(coin__UxOut));
        result = SKY_coin_CreateUnspent(&bh, handle, t[i].index, &ux);
        if (t[i].failure) {
            ck_assert_msg(result == SKY_ERROR, "SKY_coin_CreateUnspent should have failed");
            continue;
        } else {
            ck_assert_msg(result == SKY_OK, "SKY_coin_CreateUnspent failed");
        }
        ck_assert(bh.Time == ux.Head.Time);
        ck_assert(bh.BkSeq == ux.Head.BkSeq);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(hash, ux.Body.SrcTransaction, sizeof(cipher__SHA256)));
        ck_assert(t[i].index < ptx->Out.len);
        coin__TransactionOutput* poutput = (coin__TransactionOutput*)ptx->Out.data;
        ck_assert(isAddressEq(&ux.Body.Address, &poutput->Address));
        ck_assert(ux.Body.Coins == poutput->Coins);
        ck_assert(ux.Body.Hours == poutput->Hours);
    }
}
END_TEST

START_TEST(TestCreateUnspents)
{
    printf("Load TestCreateUnspents\n");
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__Address address;
    GoUint32_ result = makeKeysAndAddress(&pubkey, &seckey, &address);

    cipher__SHA256 hash;
    coin__Transaction* ptx;
    Transaction__Handle handle;
    ptx = makeEmptyTransaction(&handle);
    result = SKY_coin_Transaction_PushOutput(handle, &address, 11000000, 255);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_PushOutput failed");
    coin__BlockHeader bh;
    memset(&bh, 0, sizeof(coin__BlockHeader));
    bh.Time = time(0);
    bh.BkSeq = 1;

    coin__UxArray uxs = {NULL, 0, 0};
    result = SKY_coin_CreateUnspents(&bh, handle, &uxs);
    ck_assert_msg(result == SKY_OK, "SKY_coin_CreateUnspents failed");
    registerMemCleanup(uxs.data);
    ck_assert(uxs.len == 1);
    ck_assert_int_eq(uxs.len, ptx->Out.len);
    coin__UxOut* pout = (coin__UxOut*)uxs.data;
    coin__TransactionOutput* ptxout = (coin__TransactionOutput*)ptx->Out.data;
    for (int i = 0; i < uxs.len; i++) {
        ck_assert(bh.Time == pout->Head.Time);
        ck_assert(bh.BkSeq == pout->Head.BkSeq);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(hash, pout->Body.SrcTransaction, sizeof(cipher__SHA256)));
        ck_assert(isAddressEq(&pout->Body.Address, &ptxout->Address));
        ck_assert(pout->Body.Coins == ptxout->Coins);
        ck_assert(pout->Body.Hours == ptxout->Hours);
        pout++;
        ptxout++;
    }
}
END_TEST

Suite* coin_blocks(void)
{
    Suite* s = suite_create("Load coin.block");
    TCase* tc;

    tc = tcase_create("coin.block");
    tcase_add_checked_fixture(tc, setup, teardown);
    // tcase_add_test(tc, TestNewBlock);
    // tcase_add_test(tc, TestBlockHashHeader);
    // tcase_add_test(tc, TestBlockHashBody);
    // tcase_add_test(tc, TestNewGenesisBlock);
    // tcase_add_test(tc, TestCreateUnspent);
    tcase_add_test(tc, TestCreateUnspents);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}