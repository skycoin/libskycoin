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
    cipher__SHA256 bodyhash = "";
    BlockBody__Handle block = 0;
    Transactions__Handle transactions = 0;
    transactions = makeTestTransactions();

    result = SKY_coin_NewEmptyBlock(transactions, &block);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewEmptyBlock failed");
    registerHandleClose(block);
    BlockHeader__Handle pBlockHeader = 0;
    result = SKY_coin_Block_GetBlockHeader(block, &pBlockHeader);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");

    SKY_coin_BlockHeader_SetTime(pBlockHeader, 100);
    SKY_coin_BlockHeader_SetBkSeq(pBlockHeader, 0);
    SKY_coin_BlockHeader_SetVersion(pBlockHeader, 0x02);
    SKY_coin_BlockHeader_SetFee(pBlockHeader, 10);

    BlockBody__Handle body = 0;
    result = SKY_coin_GetBlockBody(block, &body);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Get_Block_Body failed");
    result = SKY_coin_BlockBody_Hash(body, &bodyhash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockBody_Hash failed");
    FeeCalculator zf = {zeroFeeCalculator, NULL};
    result = SKY_coin_NewBlock(block, 100 + 200, uxHash, transactions, &zf, newBlock);
    ck_assert_int_eq(result, SKY_OK);
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
    BlockHeader__Handle pPrevBlockHeader = 0;
    result = SKY_coin_Block_GetBlockHeader(prevBlock, &pPrevBlockHeader);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");

    SKY_coin_BlockHeader_SetTime(pPrevBlockHeader, 100);
    SKY_coin_BlockHeader_SetBkSeq(pPrevBlockHeader, 98);

    GoUint8 buffer_slice[1024];
    GoSlice slice = {buffer_slice, 0, 1024};
    cipher__SHA256 hash = "";

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
    BlockHeader__Handle pnewBlockHeader = 0;
    result = SKY_coin_Block_GetBlockHeader(newBlock, &pnewBlockHeader);
    GoUint64 pHeadFee;
    GoUint64 pHeadTime;
    GoUint64 pHeadBkSeq;
    SKY_coin_BlockHeader_Fee(pnewBlockHeader, &pHeadFee);
    SKY_coin_BlockHeader_Time(pnewBlockHeader, &pHeadTime);
    SKY_coin_BlockHeader_BkSeq(pnewBlockHeader, &pHeadBkSeq);
    GoInt pTransLength;
    result = SKY_coin_Transactions_Length(transactions, &pTransLength);
    ck_assert_int_eq(pHeadFee, (fee * pTransLength));
    ck_assert_int_eq(pHeadTime, currentTime);
    pPrevBlockHeader = 0;
    result = SKY_coin_Block_GetBlockHeader(prevBlock, &pPrevBlockHeader);
    GoUint64 pPrevBkSeq;
    SKY_coin_BlockHeader_BkSeq(pPrevBlockHeader, &pPrevBkSeq);
    ck_assert_int_eq(pHeadBkSeq, pPrevBkSeq + 1);
    cipher__SHA256 pnewuxHash = " ";
    SKY_coin_BlockHeader_UxHash(pnewBlockHeader, &pnewuxHash);
    ck_assert(isU8Eq(pnewuxHash, hash, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestBlockHashHeader)
{
    printf("Load TestBlockHashHeader\n");
    GoUint32_ result;
    GoUint8 buffer_slice[1024];
    GoSlice slice = {buffer_slice, 0, 1024};
    cipher__SHA256 hash = "";
    randBytes(&slice, 128);
    result = SKY_cipher_SumSHA256(slice, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    Block__Handle block = 0;
    coin__Block* pBlock = NULL;
    result = makeNewBlock(&hash, &block);
    ck_assert_msg(result == SKY_OK, "makeNewBlock failed");

    cipher__SHA256 hash1 = "";
    cipher__SHA256 hash2 = "";
    result = SKY_coin_Block_HashHeader(block, &hash1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_HashHeader failed");
    BlockHeader__Handle blockheader = 0;
    coin__BlockHeader* pblockheader = NULL;
    result = SKY_coin_Block_GetBlockHeader(block, &blockheader);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_GetBlockHeader failed");
    result = SKY_coin_BlockHeader_Hash(blockheader, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Hash failed");
    ck_assert(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
    strcpy(hash2, "");
    ck_assert_int_eq(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)), 0);
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

    cipher__SHA256 hash1 = "";
    cipher__SHA256 hash2 = "";
    result = SKY_coin_Block_HashBody(block, &hash1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Block_HashBody failed");
    BlockBody__Handle blockbody = 0;
    result = SKY_coin_GetBlockBody(block, &blockbody);
    ck_assert_msg(result == SKY_OK, "SKY_coin_GetBlockBody failed");
    result = SKY_coin_BlockBody_Hash(blockbody, &hash2);
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

    GoUint32_ result = makeKeysAndAddress(&pubkey, &seckey, &address);
    ck_assert_msg(result == SKY_OK, "makeKeysAndAddress failed");
    result = SKY_coin_NewGenesisBlock(&address, genCoins, genTime, &block);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewGenesisBlock failed");

    cipher__SHA256 nullHash = "";
    BlockHeader__Handle blockheader = 0;
    coin__BlockHeader* pblockheader = NULL;
    result = SKY_coin_Block_GetBlockHeader(block, &blockheader);
    cipher__SHA256 pBlockPrevHash = "";
    result = SKY_coin_BlockHeader_PrevHash(blockheader, &pBlockPrevHash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_PrevHash failed");
    ck_assert(isU8Eq(nullHash, pBlockPrevHash, sizeof(cipher__SHA256)));

    GoUint64 pBlockTime;
    GoUint64 pBlockBkSeq;
    GoUint32 pBlockVersion;
    GoUint64 pBlockFee;
    result = SKY_coin_BlockHeader_Time(blockheader, &pBlockTime);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_Time failed");
    ck_assert(genTime == pBlockTime);
    result = SKY_coin_BlockHeader_BkSeq(blockheader, &pBlockBkSeq);
    ck_assert_msg(result == SKY_OK, "SKY_coin_BlockHeader_BkSeq failed");
    ck_assert(0 == pBlockBkSeq);
    result = SKY_coin_BlockHeader_Version(blockheader, &pBlockVersion);
    ck_assert(result == SKY_OK);
    ck_assert(0 == pBlockVersion);
    result = SKY_coin_BlockHeader_Fee(blockheader, &pBlockFee);
    ck_assert(result == SKY_OK);
    ck_assert(0 == pBlockFee);
    cipher__SHA256 pBlockUxHash = " ";
    result = SKY_coin_BlockHeader_UxHash(blockheader, &pBlockUxHash);
    ck_assert(result == SKY_OK);
    ck_assert(isU8Eq(nullHash, pBlockUxHash, sizeof(cipher__SHA256)));

    BlockBody__Handle blockbody = 0;
    result = SKY_coin_GetBlockBody(block, &blockbody);
    ck_assert(result == SKY_OK);
    Transactions__Handle trans = 0;
    result = SKY_coin_BlockBody_Transactions(blockbody, &trans);
    ck_assert(result == SKY_OK);
    GoInt transLength;
    result = SKY_coin_Transactions_Length(trans, &transLength);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(1, transLength);
    Transaction__Handle tran = 0;
    result = SKY_coin_Transactions_GetAt(trans, 0, &tran);
    ck_assert(result == SKY_OK);
    GoInt inLen;
    SKY_coin_Transaction_GetInputsCount(tran, &inLen);
    ck_assert_int_eq(0, inLen);
    GoInt sigLen;
    SKY_coin_Transaction_GetSignaturesCount(tran, &sigLen);
    ck_assert_int_eq(0, sigLen);
    GoInt outLen;
    SKY_coin_Transaction_GetOutputsCount(tran, &outLen);
    ck_assert_int_eq(1, outLen);
    coin__TransactionOutput poutput;
    SKY_coin_Transaction_GetOutputAt(tran, 0, &poutput);
    ck_assert(isAddressEq(&address, &poutput.Address));
    ck_assert(genCoins == poutput.Coins);
    ck_assert(genCoins == poutput.Hours);
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
    makeEmptyTransaction(&handle);
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
        strcpy(hash, " ");
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(hash, ux.Body.SrcTransaction, sizeof(cipher__SHA256)));
        GoInt ptxLen;
        SKY_coin_Transaction_GetOutputsCount(handle, &ptxLen);
        ck_assert_int_lt(t[i].index, ptxLen);
        coin__TransactionOutput poutput;
        SKY_coin_Transaction_GetOutputAt(handle, 0, &poutput);
        ck_assert(isAddressEq(&ux.Body.Address, &poutput.Address));
        ck_assert(ux.Body.Coins == poutput.Coins);
        ck_assert(ux.Body.Hours == poutput.Hours);
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
    makeEmptyTransaction(&handle);
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
    GoInt ptxLen;
    SKY_coin_Transaction_GetOutputsCount(handle, &ptxLen);
    ck_assert_int_eq(uxs.len, ptxLen);
    coin__UxOut* pout = (coin__UxOut*)uxs.data;
    for (int i = 0; i < uxs.len; i++) {
        coin__TransactionOutput ptxout;
        SKY_coin_Transaction_GetOutputAt(handle, i, &ptxout);
        ck_assert(bh.Time == pout->Head.Time);
        ck_assert(bh.BkSeq == pout->Head.BkSeq);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(hash, pout->Body.SrcTransaction, sizeof(cipher__SHA256)));
        ck_assert(isAddressEq(&pout->Body.Address, &ptxout.Address));
        ck_assert(pout->Body.Coins == ptxout.Coins);
        ck_assert(pout->Body.Hours == ptxout.Hours);
        pout++;
    }
}
END_TEST

Suite* coin_blocks(void)
{
    Suite* s = suite_create("Load coin.block");
    TCase* tc;

    tc = tcase_create("coin.block");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestNewBlock); //ok
    tcase_add_test(tc, TestBlockHashHeader);
    tcase_add_test(tc, TestBlockHashBody);
    tcase_add_test(tc, TestNewGenesisBlock); //ok
    tcase_add_test(tc, TestCreateUnspent);   //ok
    tcase_add_test(tc, TestCreateUnspents);  //ok
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}