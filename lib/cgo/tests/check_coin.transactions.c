
#include <signal.h>
#include <stdio.h>

#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytxn.h"
#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "check.h"

GoUint64 Million = 1000000;

START_TEST(TestTransactionVerify)
{
    printf("Load TestTransactionVerify\n");
    unsigned long long MaxUint64 =
        0xFFFFFFFFFFFFFFFF;
    unsigned int MaxUint16 = 0xFFFF;
    int result;

    coin__Transaction* ptx;
    Transaction__Handle handle;
    // Mismatch header hash
    ptx = makeTransaction(&handle);
    memset(ptx->InnerHash, 0, sizeof(cipher__SHA256));
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // No inputs
    ptx = makeTransaction(&handle);
    result = SKY_coin_Transaction_ResetInputs(handle, 0);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // No outputs
    ptx = makeTransaction(&handle);
    result = SKY_coin_Transaction_ResetOutputs(handle, 0);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Invalid number of Sigs
    ptx = makeTransaction(&handle);
    result = SKY_coin_Transaction_ResetSignatures(handle, 0);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);
    result = SKY_coin_Transaction_ResetSignatures(handle, 20);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Too many sigs & inputs
    ptx = makeTransaction(&handle);
    result = SKY_coin_Transaction_ResetSignatures(handle, MaxUint16);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_ResetInputs(handle, MaxUint16);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Duplicate inputs
    coin__UxOut ux;
    cipher__SecKey seckey;
    memset(&ux, 0, sizeof(coin__UxOut));
    memset(&seckey, 0, sizeof(cipher__SecKey));
    cipher__SHA256 sha256;
    makeUxOutWithSecret(&ux, &seckey);
    ptx = makeTransactionFromUxOut(&ux, &seckey, &handle);
    memcpy(&sha256, ptx->In.data, sizeof(cipher__SHA256));
    GoUint16 r;
    result = SKY_coin_Transaction_PushInput(handle, &sha256);
    result = SKY_coin_Transaction_ResetSignatures(handle, 0);
    ck_assert(result == SKY_OK);
    GoSlice seckeys;
    seckeys.data = malloc(sizeof(cipher__SecKey) * 2);
    ck_assert(seckeys.data != NULL);
    registerMemCleanup(seckeys.data);
    seckeys.len = seckeys.cap = 2;
    memcpy(seckeys.data, &seckey, sizeof(cipher__SecKey));
    memcpy(((cipher__SecKey*)seckeys.data) + 1, &seckey, sizeof(cipher__SecKey));
    result = SKY_coin_Transaction_SignInputs(handle, seckeys);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
#if __GNUC__
#if __x86_64__
    ck_assert_msg(result == SKY_ERROR, "Fail in err %X", result);
#endif
#endif

    // Duplicate outputs
    ptx = makeTransaction(&handle);
    coin__TransactionOutput* pOutput = ptx->Out.data;
    cipher__Address addr;
    memcpy(&addr, &pOutput->Address, sizeof(cipher__Address));
    result = SKY_coin_Transaction_PushOutput(handle, &addr, pOutput->Coins,
        pOutput->Hours);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Invalid signature, empty
    ptx = makeTransaction(&handle);
    memset(ptx->Sigs.data, 0, sizeof(cipher__Sig));
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert_int_eq(result, SKY_ERROR);

    // Output coins are 0
    ptx = makeTransaction(&handle);
    pOutput = ptx->Out.data;
    pOutput->Coins = 0;
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Output coin overflow
    ptx = makeTransaction(&handle);
    pOutput = ptx->Out.data;
    pOutput->Coins = MaxUint64 - 3000000;
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_ERROR);

    // Output coins are not multiples of 1e6 (valid, decimal restriction is not
    // enforced here)
    ptx = makeTransaction(&handle);
    pOutput = ptx->Out.data;
    pOutput->Coins += 10;
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_ResetSignatures(handle, 0);
    ck_assert(result == SKY_OK);
    cipher__PubKey pubkey;
    result = SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
    ck_assert(result == SKY_OK);
    seckeys.data = &seckey;
    seckeys.len = 1;
    seckeys.cap = 1;
    result = SKY_coin_Transaction_SignInputs(handle, seckeys);
    ck_assert(result == SKY_OK);
    ck_assert(pOutput->Coins % 1000000 != 0);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_OK);

    // Valid
    ptx = makeTransaction(&handle);
    pOutput = ptx->Out.data;
    pOutput->Coins = 10000000;
    pOutput++;
    pOutput->Coins = 1000000;
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_Verify(handle);
    ck_assert(result == SKY_OK);
}
END_TEST

START_TEST(TestTransactionPushInput)
{
    printf("Load TestTransactionPushInput\n");
    unsigned long long MaxUint64 = 0xFFFFFFFFFFFFFFFF;
    unsigned int MaxUint16 = 0xFFFF;
    int result;
    Transaction__Handle handle;
    coin__Transaction* ptx;
    coin__UxOut ux;
    ptx = makeEmptyTransaction(&handle);
    makeUxOut(&ux);
    cipher__SHA256 hash;
    result = SKY_coin_UxOut_Hash(&ux, &hash);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_PushInput(handle, &hash);
    ck_assert(result == SKY_OK);
    ck_assert_msg(ptx->In.len == 1, "Fail len is %d", ptx->In.len);
    cipher__SHA256* pIn = ptx->In.data;
    ck_assert(isU8Eq(hash, *pIn, sizeof(cipher__SHA256)));

    int len = ptx->In.len;
    void* data = malloc(len * sizeof(cipher__SHA256));
    ck_assert(data != NULL);
    registerMemCleanup(data);
    memcpy(data, ptx->In.data, len * sizeof(cipher__SHA256));
    result = SKY_coin_Transaction_ResetInputs(handle, MaxUint16 + len);
    ck_assert(result == SKY_OK);
    memcpy(ptx->In.data, data, len * sizeof(cipher__Sig));
    freeRegisteredMemCleanup(data);
    makeUxOut(&ux);
    result = SKY_coin_UxOut_Hash(&ux, &hash);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_PushInput(handle, &hash);
    ck_assert_int_eq(result, SKY_ERROR);
}
END_TEST

START_TEST(TestTransactionPushOutput)
{
    printf("Load TestTransactionPushOutput\n");
    GoUint32 result;
    Transaction__Handle handle;
    coin__Transaction* ptx;
    ptx = makeEmptyTransaction(&handle);

    cipher__Address addr;
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 100, 150);
    ck_assert(result == SKY_OK);
    ck_assert(ptx->Out.len == 1);
    coin__TransactionOutput* pOutput = ptx->Out.data;
    coin__TransactionOutput output;
    memcpy(&output.Address, &addr, sizeof(cipher__Address));
    output.Coins = 100;
    output.Hours = 150;
    ck_assert(isTransactionOutputEq(&output, pOutput));
    for (int i = 1; i < 20; i++) {
        makeAddress(&addr);
        result = SKY_coin_Transaction_PushOutput(handle, &addr, i * 100, i * 50);
        ck_assert(result == SKY_OK);
        ck_assert(ptx->Out.len == i + 1);
        pOutput = ptx->Out.data;
        pOutput += i;
        memcpy(&output.Address, &addr, sizeof(cipher__Address));
        output.Coins = i * 100;
        output.Hours = i * 50;
        ck_assert(isTransactionOutputEq(&output, pOutput));
    }
}
END_TEST

START_TEST(TestTransactionHash)
{
    printf("Load TestTransactionHash\n");
    GoUint32 result;
    Transaction__Handle handle;
    coin__Transaction* ptx;
    ptx = makeEmptyTransaction(&handle);

    cipher__SHA256 nullHash, hash1, hash2;
    memset(&nullHash, 0, sizeof(cipher__SHA256));
    result = SKY_coin_Transaction_Hash(handle, &hash1);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(isU8Eq(nullHash, hash1, sizeof(cipher__SHA256)), 0);
    result = SKY_coin_Transaction_HashInner(handle, &hash2);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(isU8Eq(hash2, hash1, sizeof(cipher__SHA256)), 0);
}
END_TEST

START_TEST(TestTransactionUpdateHeader)
{
    printf("Load TestTransactionUpdateHeader\n");
    GoUint32 result;
    Transaction__Handle handle;
    coin__Transaction* ptx;
    ptx = makeTransaction(&handle);
    cipher__SHA256 hash;
    cipher__SHA256 nullHash = "";
    cipher__SHA256 hashInner;
    memcpy(&hash, &ptx->InnerHash, sizeof(cipher__SHA256));
    memset(&ptx->InnerHash, 0, sizeof(cipher__SHA256));
    result = SKY_coin_Transaction_UpdateHeader(handle);
    ck_assert_int_eq(isU8Eq(ptx->InnerHash, nullHash, sizeof(cipher__SHA256)), 0);
    ck_assert(isU8Eq(ptx->InnerHash, hash, sizeof(cipher__SHA256)));
    result = SKY_coin_Transaction_HashInner(handle, &hashInner);
    ck_assert(result == SKY_OK);
    ck_assert(isU8Eq(hashInner, ptx->InnerHash, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestTransactionsSize)
{
    printf("Load TestTransactionsSize\n");
    GoUint32 result;
    Transactions__Handle txns;
    result = makeTransactions(10, &txns);
    ck_assert(result == SKY_OK);
    GoInt size = 0;
    for (size_t i = 0; i < 10; i++) {
        Transaction__Handle handle = 0;
        result = SKY_coin_Transactions_GetAt(txns, i, &handle);
        registerHandleClose(handle);
        ck_assert(result == SKY_OK);
        coin__UxArray p1 = {NULL, 0, 0};
        result = SKY_coin_Transaction_Serialize(handle, &p1);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Serialize");
        size += p1.len;
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Size");
    }
    GoUint32 sizeTransactions;
    result = SKY_coin_Transactions_Size(txns, &sizeTransactions);
    ck_assert(size != 0);
    ck_assert(sizeTransactions == size);
}
END_TEST

// START_TEST(TestTransactionVerifyInput)
// {
//     printf("Load TestTransactionVerifyInput\n");
//     GoUint32 result;
//     Transaction__Handle handle;
//     coin__Transaction* ptx;
//     ptx = makeTransaction(&handle);
//     result = SKY_coin_Transaction_VerifyInput(handle, NULL);
//     ck_assert(result == SKY_ERROR);
//     coin__UxArray ux;
//     memset(&ux, 0, sizeof(coin__UxArray));
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);
//     memset(&ux, 0, sizeof(coin__UxArray));
//     ux.data = malloc(3 * sizeof(coin__UxOut));
//     ck_assert(ux.data != NULL);
//     registerMemCleanup(ux.data);
//     ux.len = 3;
//     ux.cap = 3;
//     memset(ux.data, 0, 3 * sizeof(coin__UxOut));
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     coin__UxOut uxOut;
//     cipher__SecKey seckey;
//     cipher__Sig sig;
//     cipher__SHA256 hash;

//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     result = SKY_coin_Transaction_ResetSignatures(handle, 0);
//     ck_assert(result == SKY_OK);
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     memset(&sig, 0, sizeof(cipher__Sig));
//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     result = SKY_coin_Transaction_ResetSignatures(handle, 1);
//     ck_assert(result == SKY_OK);
//     memcpy(ptx->Sigs.data, &sig, sizeof(cipher__Sig));
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     // Invalid Tx Inner Hash
//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     memset(ptx->InnerHash, 0, sizeof(cipher__SHA256));
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     // Ux hash mismatch
//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     memset(&uxOut, 0, sizeof(coin__UxOut));
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     // Invalid signature
//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     result = SKY_coin_Transaction_ResetSignatures(handle, 1);
//     ck_assert(result == SKY_OK);
//     memset(ptx->Sigs.data, 0, sizeof(cipher__Sig));
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_ERROR);

//     // Valid
//     result = makeUxOutWithSecret(&uxOut, &seckey);
//     ck_assert(result == SKY_OK);
//     ptx = makeTransactionFromUxOut(&uxOut, &seckey, &handle);
//     ck_assert(result == SKY_OK);
//     ux.data = &uxOut;
//     ux.len = 1;
//     ux.cap = 1;
//     result = SKY_coin_Transaction_VerifyInput(handle, &ux);
//     ck_assert(result == SKY_OK);
// }
// END_TEST

START_TEST(TestTransactionSignInputs)
{
    printf("Load TestTransactionSignInputs\n");
    GoUint32 result;
    coin__Transaction* ptx;
    Transaction__Handle handle;
    coin__UxOut ux, ux2;
    cipher__SecKey seckey, seckey2;
    cipher__SHA256 hash, hash2;
    cipher__Address addr, addr2;
    cipher__PubKey pubkey;
    GoUint16 r;
    GoSlice keys;

    // Error if txns already signed
    ptx = makeEmptyTransaction(&handle);
    result = SKY_coin_Transaction_ResetSignatures(handle, 1);
    ck_assert(result == SKY_OK);

    memset(&seckey, 0, sizeof(cipher__SecKey));
    keys.data = &seckey;
    keys.len = 1;
    keys.cap = 1;
    result = SKY_coin_Transaction_SignInputs(handle, keys);
    ck_assert(result == SKY_ERROR);

    // Panics if not enough keys
    ptx = makeEmptyTransaction(&handle);
    memset(&seckey, 0, sizeof(cipher__SecKey));
    memset(&seckey2, 0, sizeof(cipher__SecKey));
    result = makeUxOutWithSecret(&ux, &seckey);
    ck_assert(result == SKY_OK);
    result = SKY_coin_UxOut_Hash(&ux, &hash);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_PushInput(handle, &hash);
    ck_assert(result == SKY_OK);
    result = makeUxOutWithSecret(&ux2, &seckey2);
    ck_assert(result == SKY_OK);
    result = SKY_coin_UxOut_Hash(&ux2, &hash2);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_PushInput(handle, &hash2);
    ck_assert(result == SKY_OK);
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 40, 80);
    ck_assert(result == SKY_OK);
    ck_assert(ptx->Sigs.len == 0);
    keys.data = &seckey;
    keys.len = 1;
    keys.cap = 1;
    result = SKY_coin_Transaction_SignInputs(handle, keys);
    ck_assert(result == SKY_ERROR);
    ck_assert(ptx->Sigs.len == 0);

    // Valid signing
    result = SKY_coin_Transaction_HashInner(handle, &hash);
    ck_assert(result == SKY_OK);
    keys.data = malloc(2 * sizeof(cipher__SecKey));
    ck_assert(keys.data != NULL);
    registerMemCleanup(keys.data);
    keys.len = keys.cap = 2;
    memcpy(keys.data, &seckey, sizeof(cipher__SecKey));
    memcpy(((cipher__SecKey*)keys.data) + 1, &seckey2, sizeof(cipher__SecKey));
    result = SKY_coin_Transaction_SignInputs(handle, keys);
    ck_assert(result == SKY_OK);
    ck_assert(ptx->Sigs.len == 2);
    result = SKY_coin_Transaction_HashInner(handle, &hash2);
    ck_assert(result == SKY_OK);
    ck_assert(isU8Eq(hash2, hash, sizeof(cipher__SHA256)) == 0);

    result = SKY_cipher_PubKeyFromSecKey(&seckey, &pubkey);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_AddressFromPubKey(&pubkey, &addr);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_PubKeyFromSecKey(&seckey2, &pubkey);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_AddressFromPubKey(&pubkey, &addr2);
    ck_assert(result == SKY_OK);

    cipher__SHA256 addHash, addHash2;
    result =
        SKY_cipher_AddSHA256(&hash, (cipher__SHA256*)ptx->In.data, &addHash);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_AddSHA256(&hash, ((cipher__SHA256*)ptx->In.data) + 1,
        &addHash2);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_VerifyAddressSignedHash(
        &addr, (cipher__Sig*)ptx->Sigs.data, &addHash);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_VerifyAddressSignedHash(
        &addr2, ((cipher__Sig*)ptx->Sigs.data) + 1, &addHash2);
    ck_assert(result == SKY_OK);
    result = SKY_cipher_VerifyAddressSignedHash(
        &addr, ((cipher__Sig*)ptx->Sigs.data) + 1, &hash);
    ck_assert(result == SKY_ERROR);
    result = SKY_cipher_VerifyAddressSignedHash(
        &addr2, (cipher__Sig*)ptx->Sigs.data, &hash);
    ck_assert(result == SKY_ERROR);
}
END_TEST

START_TEST(TestTransactionHashInner)
{
    printf("Load TestTransactionHashInner\n");
    GoUint32 result;
    Transaction__Handle handle1 = 0, handle2 = 0;
    coin__Transaction* ptx = NULL;
    coin__Transaction* ptx2 = NULL;
    ptx = makeTransaction(&handle1);
    cipher__SHA256 hash, nullHash = "";
    result = SKY_coin_Transaction_HashInner(handle1, &hash);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(isU8Eq(nullHash, hash, sizeof(cipher__SHA256)), 0);

    // If tx.In is changed, hash should change
    ptx2 = copyTransaction(handle1, &handle2);
    ck_assert_mem_ne(ptx, ptx2, sizeof(coin__Transaction));
    ck_assert(ptx2->In.len > 0);
    coin__UxOut uxOut;
    makeUxOut(&uxOut);
    cipher__SHA256* pHash = ptx2->In.data;
    result = SKY_coin_UxOut_Hash(&uxOut, pHash);
    ck_assert(result == SKY_OK);
    ck_assert_mem_ne(ptx, ptx2, sizeof(coin__Transaction));
    cipher__SHA256 hash1, hash2;
    result = SKY_coin_Transaction_HashInner(handle1, &hash1);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_HashInner(handle2, &hash2);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)), 0);

    // If tx.Out is changed, hash should change
    handle2 = 0;
    ptx2 = copyTransaction(handle1, &handle2);
    ck_assert(ptx != ptx2);
    ck_assert_mem_ne(ptx, ptx2, sizeof(coin__Transaction));
    coin__TransactionOutput* output = ptx2->Out.data;
    cipher__Address addr;
    memset(&addr, 0, sizeof(cipher__Address));
    makeAddress(&addr);
    registerMemCleanup(&addr);
    memcpy(&output->Address, &addr, sizeof(cipher__Address));

    ck_assert_mem_ne(ptx, ptx2, sizeof(coin__Transaction));
    ck_assert(isAddressEq(&addr, &output->Address));
    result = SKY_coin_Transaction_HashInner(handle1, &hash1);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_HashInner(handle2, &hash2);
    ck_assert(result == SKY_OK);
    ck_assert_int_eq(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)), 0);

    // If tx.Head is changed, hash should not change
    ptx2 = copyTransaction(handle1, &handle2);
    int len = ptx2->Sigs.len;
    cipher__Sig* newSigs = malloc((len + 1) * sizeof(cipher__Sig));
    ck_assert(newSigs != NULL);
    registerMemCleanup(newSigs);
    memcpy(newSigs, ptx2->Sigs.data, len * sizeof(cipher__Sig));
    result = SKY_coin_Transaction_ResetSignatures(handle2, len + 1);
    ck_assert(result == SKY_OK);
    memcpy(ptx2->Sigs.data, newSigs, len * sizeof(cipher__Sig));
    newSigs += len;
    memset(newSigs, 0, sizeof(cipher__Sig));
    result = SKY_coin_Transaction_HashInner(handle1, &hash1);
    ck_assert(result == SKY_OK);
    result = SKY_coin_Transaction_HashInner(handle2, &hash2);
    ck_assert(result == SKY_OK);
    ck_assert(isU8Eq(hash1, hash2, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestTransactionSerialization)
{
    printf("Load TestTransactionSerialization\n");
    GoUint32 result;
    Transaction__Handle handle = 0;
    coin__Transaction* ptx = makeTransaction(&handle);
    unsigned char buffer[1024];
    coin__UxArray data = {buffer, 0, 1024};
    result = SKY_coin_Transaction_Serialize(handle, &data);
    ck_assert(result == SKY_OK);
    registerMemCleanup(data.data);
    coin__Transaction* ptx2 = NULL;
    Transaction__Handle handle2 = 0;
    GoSlice d = {data.data, data.len, data.cap};
    result = SKY_coin_TransactionDeserialize(d, &handle2);
    ck_assert(result == SKY_OK);
    result = SKY_coin_GetTransactionObject(handle2, &ptx2);
    ck_assert(result == SKY_OK);
    ck_assert(isTransactionEq(ptx, ptx2));
}
END_TEST

START_TEST(TestTransactionOutputHours)
{
    printf("Load TestTransactionOutputHours\n");
    coin__Transaction* ptx;
    Transaction__Handle handle;
    ptx = makeEmptyTransaction(&handle);
    cipher__Address addr;
    makeAddress(&addr);
    int result;
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 1000000, 100);
    ck_assert(result == SKY_OK);
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 1000000, 200);
    ck_assert(result == SKY_OK);
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 1000000, 500);
    ck_assert(result == SKY_OK);
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 1000000, 0);
    ck_assert(result == SKY_OK);
    GoUint64 hours;
    result = SKY_coin_Transaction_OutputHours(handle, &hours);
    ck_assert(result == SKY_OK);
    ck_assert(hours == 800);
    makeAddress(&addr);
    result = SKY_coin_Transaction_PushOutput(handle, &addr, 1000000,
        0xFFFFFFFFFFFFFFFF - 700);
    result = SKY_coin_Transaction_OutputHours(handle, &hours);
    ck_assert(result == SKY_ERROR);
}
END_TEST

START_TEST(TestTransactionsHashes)
{
    printf("Load TestTransactionsHashes\n");
    GoUint32 result;
    GoSlice_ hashes = {NULL, 0, 0};
    Transactions__Handle hTxns;
    result = makeTransactions(4, &hTxns);
    ck_assert(result == SKY_OK);

    result = SKY_coin_Transactions_Hashes(hTxns, &hashes);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Hashes failed");
    registerMemCleanup(hashes.data);
    ck_assert(hashes.len == 4);
    cipher__SHA256* ph = hashes.data;
    cipher__SHA256 hash;
    for (int i = 0; i < 4; i++) {
        Transaction__Handle handle;
        result = SKY_coin_Transactions_GetAt(hTxns, i, &handle);
        ck_assert(result == SKY_OK);
        result = SKY_coin_Transaction_Hash(handle, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Hash failed");
        ck_assert(isU8Eq(*ph, hash, sizeof(cipher__SHA256)));
        ph++;
    }
}
END_TEST

START_TEST(TestTransactionsTruncateBytesTo)
{
    printf("Load TestTransactionsTruncateBytesTo\n");
    GoUint32 result;
    Transactions__Handle h1, h2;
    result = makeTransactions(10, &h1);
    ck_assert(result == SKY_OK);
    GoInt length;
    result = SKY_coin_Transactions_Length(h1, &length);
    ck_assert(result == SKY_OK);
    int trunc = 0;
    GoUint32 size;
    for (int i = 0; i < length / 2; i++) {
        Transaction__Handle handle;
        result = SKY_coin_Transactions_GetAt(h1, i, &handle);
        registerHandleClose(handle);
        ck_assert(result == SKY_OK);
        result = SKY_coin_Transaction_Size(handle, &size);
        trunc += size;
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transaction_Size failed");
    }
    result = SKY_coin_Transactions_TruncateBytesTo(h1, trunc, &h2);
    ck_assert_msg(result == SKY_OK,
        "SKY_coin_Transactions_TruncateBytesTo failed");
    registerHandleClose(h2);

    GoInt length2;
    result = SKY_coin_Transactions_Length(h2, &length2);
    ck_assert(result == SKY_OK);
    ck_assert(length2 == length / 2);
    result = SKY_coin_Transactions_Size(h2, &size);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Size failed");
    ck_assert(trunc == size);

    trunc++;
    result = SKY_coin_Transactions_TruncateBytesTo(h1, trunc, &h2);
    ck_assert_msg(result == SKY_OK,
        "SKY_coin_Transactions_TruncateBytesTo failed");
    registerHandleClose(h2);

    // Stepping into next boundary has same cutoff, must exceed
    result = SKY_coin_Transactions_Length(h2, &length2);
    ck_assert(result == SKY_OK);
    ck_assert(length2 == length / 2);
    result = SKY_coin_Transactions_Size(h2, &size);
    ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Size failed");
    ck_assert(trunc - 1 == size);
}
END_TEST

typedef struct {
    GoUint64 coins;
    GoUint64 hours;
} test_ux;

typedef struct {
    test_ux* inUxs;
    test_ux* outUxs;
    int sizeIn;
    int sizeOut;
    GoUint64 headTime;
    int failure;
} test_case;

int makeTestCaseArrays(test_ux* elems, int size, coin__UxArray* pArray)
{
    if (size <= 0) {
        pArray->len = 0;
        pArray->cap = 0;
        pArray->data = NULL;
        return SKY_OK;
    }
    int elems_size = sizeof(coin__UxOut);
    void* data;
    data = malloc(size * elems_size);
    if (data == NULL)
        return SKY_ERROR;
    registerMemCleanup(data);
    memset(data, 0, size * elems_size);
    pArray->data = data;
    pArray->len = size;
    pArray->cap = size;
    coin__UxOut* p = data;
    for (int i = 0; i < size; i++) {
        p->Body.Coins = elems[i].coins;
        p->Body.Hours = elems[i].hours;
        p++;
    }
    return SKY_OK;
}

START_TEST(TestVerifyTransactionCoinsSpending)
{
    printf("Load TestVerifyTransactionCoinsSpending\n");
    unsigned long long MaxUint64 = 0xFFFFFFFFFFFFFFFF;
    unsigned int MaxUint16 = 0xFFFF;
    // Input coins overflow
    test_ux in1[] = {{MaxUint64 - Million + 1, 10}, {Million, 0}};

    // Output coins overflow
    test_ux in2[] = {{10 * Million, 10}};
    test_ux out2[] = {{MaxUint64 - 10 * Million + 1, 0}, {20 * Million, 1}};

    // Insufficient coins
    test_ux in3[] = {{10 * Million, 10}, {15 * Million, 10}};
    test_ux out3[] = {{20 * Million, 1}, {10 * Million, 1}};

    // Destroyed coins
    test_ux in4[] = {{10 * Million, 10}, {15 * Million, 10}};
    test_ux out4[] = {{5 * Million, 1}, {10 * Million, 1}};

    // Valid
    test_ux in5[] = {{10 * Million, 10}, {15 * Million, 10}};
    test_ux out5[] = {{10 * Million, 11}, {10 * Million, 1}, {5 * Million, 0}};

    test_case tests[] = {
        {in1, NULL, 2, 0, 0, 1}, // Input coins overflow
        {in2, out2, 1, 2, 0, 1}, // Output coins overflow
        {in3, out3, 2, 2, 0, 1}, // Destroyed coins
        {in4, out4, 1, 1, Million,
            1},                 // Invalid (coin hours overflow when adding earned hours, which is
                                // treated as 0, and now enough coin hours)
        {in5, out5, 2, 3, 0, 0} // Valid
    };

    coin__UxArray inArray;
    coin__UxArray outArray;
    int result;
    int count = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < count; i++) {
        result = makeTestCaseArrays(tests[i].inUxs, tests[i].sizeIn, &inArray);
        ck_assert(result == SKY_OK);
        result = makeTestCaseArrays(tests[i].outUxs, tests[i].sizeOut, &outArray);
        ck_assert(result == SKY_OK);
        result = SKY_coin_VerifyTransactionCoinsSpending(&inArray, &outArray);
        if (tests[i].failure)
            ck_assert_msg(result == SKY_ERROR,
                "VerifyTransactionCoinsSpending succeeded %d", i + 1);
        else
            ck_assert_msg(result == SKY_OK,
                "VerifyTransactionCoinsSpending failed %d", i + 1);
    }
}
END_TEST

START_TEST(TestVerifyTransactionHoursSpending)
{
    printf("Load TestVerifyTransactionHoursSpending\n");
    GoUint64 Million = 1000000;
    unsigned long long MaxUint64 = 0xFFFFFFFFFFFFFFFF;
    unsigned int MaxUint16 = 0xFFFF;
    // Input hours overflow
    test_ux in1[] = {{3 * Million, MaxUint64 - Million + 1}, {Million, Million}};

    // Insufficient coin hours
    test_ux in2[] = {{10 * Million, 10}, {15 * Million, 10}};

    test_ux out2[] = {{15 * Million, 10}, {10 * Million, 11}};

    // coin hours time calculation overflow
    test_ux in3[] = {{10 * Million, 10}, {15 * Million, 10}};

    test_ux out3[] = {{10 * Million, 11}, {10 * Million, 1}, {5 * Million, 0}};

    // Invalid (coin hours overflow when adding earned hours, which is treated as
    // 0, and now enough coin hours)
    test_ux in4[] = {{10 * Million, MaxUint64}};

    test_ux out4[] = {{10 * Million, 1}};

    // Valid (coin hours overflow when adding earned hours, which is treated as 0,
    // but not sending any hours)
    test_ux in5[] = {{10 * Million, MaxUint64}};

    test_ux out5[] = {{10 * Million, 0}};

    // Valid (base inputs have insufficient coin hours, but have sufficient after
    // adjusting coinhours by headTime)
    test_ux in6[] = {{10 * Million, 10}, {15 * Million, 10}};

    test_ux out6[] = {{15 * Million, 10}, {10 * Million, 11}};

    // valid
    test_ux in7[] = {{10 * Million, 10}, {15 * Million, 10}};

    test_ux out7[] = {{10 * Million, 11}, {10 * Million, 1}, {5 * Million, 0}};

    test_case tests[] = {
        {in1, NULL, 2, 0, 0, 1},         // Input hours overflow
        {in2, out2, 2, 2, 0, 1},         // Insufficient coin hours
        {in3, out3, 2, 3, MaxUint64, 1}, // coin hours time calculation overflow
        {in4, out4, 1, 1, Million,
            1}, // Invalid (coin hours overflow when adding earned hours, which is
                // treated as 0, and now enough coin hours)
        {in5, out5, 1, 1, 0,
            0}, // Valid (coin hours overflow when adding earned hours, which is
                // treated as 0, but not sending any hours)
        {in6, out6, 2, 2, 1492707255,
            0},                  // Valid (base inputs have insufficient coin hours, but have
                                 // sufficient after adjusting coinhours by headTime)
        {in7, out7, 2, 3, 0, 0}, // Valid
    };
    coin__UxArray inArray;
    coin__UxArray outArray;
    int result;
    int count = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < count; i++) {
        result = makeTestCaseArrays(tests[i].inUxs, tests[i].sizeIn, &inArray);
        ck_assert(result == SKY_OK);
        result = makeTestCaseArrays(tests[i].outUxs, tests[i].sizeOut, &outArray);
        ck_assert(result == SKY_OK);
        result = SKY_coin_VerifyTransactionHoursSpending(tests[i].headTime,
            &inArray, &outArray);
        if (tests[i].failure)
            ck_assert_msg(result == SKY_ERROR,
                "SKY_coin_VerifyTransactionHoursSpending succeeded %d",
                i + 1);
        else
            ck_assert_msg(result == SKY_OK,
                "SKY_coin_VerifyTransactionHoursSpending failed %d", i + 1);
    }
}
END_TEST

GoUint32_ fix1FeeCalculator(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    *pFee = 1;
    return SKY_OK;
}

GoUint32_ badFeeCalculator(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    return SKY_ERROR;
}

GoUint32_ overflowFeeCalculator(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    *pFee = 0xFFFFFFFFFFFFFFFF;
    return SKY_OK;
}

START_TEST(TestTransactionsFees)
{
    printf("Load TestTransactionsFees\n");
    GoUint64 fee;
    GoUint32 result;
    Transactions__Handle transactionsHandle = 0;
    Transaction__Handle transactionHandle = 0;

    // Nil txns
    makeTransactions(0, &transactionsHandle);
    FeeCalculator f1 = {fix1FeeCalculator, NULL};
    result = SKY_coin_Transactions_Fees(transactionsHandle, &f1, &fee);
    ck_assert(result == SKY_OK);
    ck_assert(fee == 0);

    makeEmptyTransaction(&transactionHandle);
    result = SKY_coin_Transactions_Add(transactionsHandle, transactionHandle);
    ck_assert(result == SKY_OK);
    makeEmptyTransaction(&transactionHandle);
    result = SKY_coin_Transactions_Add(transactionsHandle, transactionHandle);
    ck_assert(result == SKY_OK);
    // 2 transactions, calc() always returns 1
    result = SKY_coin_Transactions_Fees(transactionsHandle, &f1, &fee);
    ck_assert(result == SKY_OK);
    ck_assert(fee == 2);

    // calc error
    FeeCalculator badFee = {badFeeCalculator, NULL};
    result = SKY_coin_Transactions_Fees(transactionsHandle, &badFee, &fee);
    ck_assert(result == SKY_ERROR);

    // summing of calculated fees overflows
    FeeCalculator overflow = {overflowFeeCalculator, NULL};
    result = SKY_coin_Transactions_Fees(transactionsHandle, &overflow, &fee);
    ck_assert(result == SKY_ERROR);
}
END_TEST

GoUint32_ feeCalculator1(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    coin__Transaction* pTx;
    int result = SKY_coin_GetTransactionObject(handle, &pTx);
    if (result == SKY_OK) {
        coin__TransactionOutput* pOutput = pTx->Out.data;
        *pFee = 100 * Million - pOutput->Hours;
    }
    return result;
}

GoUint32_ feeCalculator2(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    *pFee = 100 * Million;
    return SKY_OK;
}

void assertTransactionsHandleEqual(Transaction__Handle h1,
    Transaction__Handle h2,
    char* testName)
{
    coin__Transaction* pTx1 = NULL;
    coin__Transaction* pTx2 = NULL;
    GoUint32 result;
    result = SKY_coin_GetTransactionObject(h1, &pTx1);
    ck_assert(result == SKY_OK);
    result = SKY_coin_GetTransactionObject(h2, &pTx2);
    ck_assert(result == SKY_OK);
    ck_assert_msg(isTransactionEq(pTx1, pTx2),
        "Failed SortTransactions test \"%s\"", testName);
}

void testTransactionSorting(Transactions__Handle hTrans, int* original_indexes, int original_indexes_count, int* expected_indexes, int expected_indexes_count, FeeCalculator* feeCalc, char* testName)
{
    GoUint32 result;
    Transactions__Handle transactionsHandle = 0;
    Transactions__Handle sortedTxnsHandle = 0;
    Transaction__Handle handle = 0;
    result = makeTransactions(0, &transactionsHandle);
    ck_assert_msg(result == SKY_OK, "makeTransactions failed");
    GoInt i;
    for (i = 0; i < original_indexes_count; i++) {
        result = SKY_coin_Transactions_GetAt(hTrans, original_indexes[i], &handle);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transactions_GetAt failed iter %d", i);
        registerHandleClose(handle);
        result = SKY_coin_Transactions_Add(transactionsHandle, handle);
        ck_assert_msg(result == SKY_OK, "SKY_coin_Transactions_Add failed iter %d",
            i);
    }
    result = SKY_coin_SortTransactions(transactionsHandle, feeCalc, &sortedTxnsHandle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_SortTransactions");
    registerHandleClose(sortedTxnsHandle);
    Transaction__Handle h1 = 0, h2 = 0;
    for (i = 0; i < expected_indexes_count; i++) {
        GoInt length;
        result = SKY_coin_Transactions_Length(sortedTxnsHandle, &length);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transactions_GetAt failed iter %d", i);
        if (i >= length) {
            break;
        }
        result = SKY_coin_Transactions_GetAt(sortedTxnsHandle, i, &h1);
        ck_assert_msg(
            result == SKY_OK,
            "SKY_coin_Transactions_GetAt in sortedTxnsHandle failed iter %d is err is %X", i, result);
        registerHandleClose(h1);
        result = SKY_coin_Transactions_GetAt(hTrans, expected_indexes[i], &h2);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transactions_GetAt failed iter %d", i);
        registerHandleClose(h2);
        assertTransactionsHandleEqual(h1, h2, testName);
    }
}

GoUint32_ feeCalculator3(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    cipher__SHA256* thirdHash = (cipher__SHA256*)context;
    cipher__SHA256 hash;
    unsigned long long MaxUint64 = 0xFFFFFFFFFFFFFFFF;
    unsigned int MaxUint16 = 0xFFFF;
    int result = SKY_coin_Transaction_Hash(handle, &hash);
    if (result == SKY_OK && (memcmp(&hash, thirdHash, sizeof(cipher__SHA256)))) {
        *pFee = MaxUint64 / 2;
    } else {
        coin__Transaction* pTx;
        result = SKY_coin_GetTransactionObject(handle, &pTx);
        if (result == SKY_OK) {
            coin__TransactionOutput* pOutput = pTx->Out.data;
            *pFee = 100 * Million - pOutput->Hours;
        }
    }
    return result;
}

GoUint32_ feeCalculator4(Transaction__Handle handle, GoUint64_* pFee, void* context)
{
    cipher__SHA256 hash;
    cipher__SHA256* thirdHash = (cipher__SHA256*)context;

    int result = SKY_coin_Transaction_Hash(handle, &hash);
    if (result == SKY_OK && (memcmp(&hash, thirdHash, sizeof(cipher__SHA256)))) {
        *pFee = 0;
        result = SKY_ERROR;
    } else {
        coin__Transaction* pTx;
        result = SKY_coin_GetTransactionObject(handle, &pTx);
        if (result == SKY_OK) {
            coin__TransactionOutput* pOutput = pTx->Out.data;
            *pFee = 100 * Million - pOutput->Hours;
        }
    }
    return result;
}

START_TEST(TestSortTransactions)
{
    int n = 6;
    int i;
    GoUint32 result;

    Transactions__Handle transactionsHandle = 0;
    Transactions__Handle transactionsHandle2 = 0;
    Transactions__Handle hashSortedTxnsHandle = 0;
    Transactions__Handle sortedTxnsHandle = 0;
    Transaction__Handle transactionHandle = 0;
    cipher__Address addr;
    result = makeTransactions(0, &transactionsHandle);
    ck_assert_msg(result == SKY_OK, "makeTransactions failed in ite %d", i);
    cipher__SHA256 thirdHash = "";
    for (i = 0; i < n; i++) {
        makeEmptyTransaction(&transactionHandle);
        makeAddress(&addr);
        result = SKY_coin_Transaction_PushOutput(transactionHandle, &addr, 1000000,
            i * 1000);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transaction_PushOutput failed in ite %d", i);
        result = SKY_coin_Transaction_UpdateHeader(transactionHandle);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transaction_UpdateHeader failed in ite %d", i);
        result = SKY_coin_Transactions_Add(transactionsHandle, transactionHandle);
        ck_assert_msg(result == SKY_OK,
            "SKY_coin_Transactions_Add failed in ite %d", i);
        if (i == 2) {
            result = SKY_coin_Transaction_Hash(transactionHandle, &thirdHash);
            ck_assert_msg(result == SKY_OK,
                "SKY_coin_Transaction_Hash failed in ite %d", i);
        }
    }
    sortTransactions(transactionsHandle, &hashSortedTxnsHandle);

    int index1[] = {0, 1};
    int expec1[] = {0, 1};
    FeeCalculator fc1 = {feeCalculator1, NULL};
    testTransactionSorting(transactionsHandle, index1, 2, expec1, 2, &fc1,
        "Already sorted");

    int index2[] = {1, 0};
    int expec2[] = {0, 1};
    testTransactionSorting(transactionsHandle, index2, 2, expec2, 2, &fc1,
        "reverse sorted");

    FeeCalculator fc2 = {feeCalculator2, NULL};
    testTransactionSorting(hashSortedTxnsHandle, index2, 2, expec2, 2, &fc2,
        "hash tiebreaker");

    int index3[] = {1, 2, 0};
    int expec3[] = {2, 0, 1};
    FeeCalculator f3 = {feeCalculator3, &thirdHash};
    testTransactionSorting(transactionsHandle, index3, 3, expec3, 3, &f3,
        "invalid fee multiplication is capped");

    int index4[] = {1, 2, 0};
    int expec4[] = {0, 1};
    FeeCalculator f4 = {feeCalculator4, &thirdHash};
    testTransactionSorting(transactionsHandle, index4, 3, expec4, 2, &f4,
        "failed fee calc is filtered");
}
END_TEST

Suite* coin_transaction(void)
{
    Suite* s = suite_create("Load Coin.Transactions");
    TCase* tc;

    tc = tcase_create("coin.transaction");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestTransactionVerify);              //ok
    tcase_add_test(tc, TestTransactionPushOutput);          //ok
    tcase_add_test(tc, TestTransactionHash);                //ok
    tcase_add_test(tc, TestTransactionUpdateHeader);        //ok
    tcase_add_test(tc, TestTransactionsSize);               //ok
    tcase_add_test(tc, TestTransactionHashInner);           //ok
    tcase_add_test(tc, TestTransactionSerialization);       //ok
    tcase_add_test(tc, TestTransactionOutputHours);         //ok
    tcase_add_test(tc, TestTransactionsHashes);             //ok
    tcase_add_test(tc, TestTransactionsTruncateBytesTo);    //ok
    tcase_add_test(tc, TestVerifyTransactionCoinsSpending); //ok
    tcase_add_test(tc, TestVerifyTransactionHoursSpending); //ok
    tcase_add_test(tc, TestSortTransactions);               //ok
    tcase_add_test(tc, TestTransactionsFees);               // ok
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, INFINITY);
    return s;
}

Suite* coin_transaction_fork(void)
{
    Suite* s = suite_create("Load Coin.Transactions FORK");
    TCase* tc;

    tc = tcase_create("coin.transaction_fork");
    tcase_add_checked_fixture(tc, setup, teardown);
#if __linux__
    tcase_add_test_raise_signal(tc, TestTransactionPushInput, SKY_ABORT);
    tcase_add_test_raise_signal(tc, TestTransactionSignInputs, SKY_ABORT);
#elif __APPLE__
    tcase_add_exit_test(tc, TestTransactionPushInput, SKY_ABORT);
    tcase_add_exit_test(tc, TestTransactionSignInputs, SKY_ABORT);
#endif
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);
    return s;
}