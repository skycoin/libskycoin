
#include <stdio.h>
#include <string.h>

// #include <criterion/criterion.h>
// #include <criterion/new/assert.h>
#include <check.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytxn.h"
#include "time.h"

// TestSuite(coin_coin, .init = setup, .fini = teardown);

START_TEST(TestAddress1)
{
    char* address_hex = "02fa939957e9fc52140e180264e621c2576a1bfe781f88792fb315ca3d1786afb8";
    char address[128];
    int result;
    int length = hexnstr(address_hex, (unsigned char*)address, 128);
    ck_assert_msg(length > 0, "Error decoding hex string");
    GoSlice slice = {address, length, 128};
    cipher__PubKey pubkey;
    result = SKY_cipher_NewPubKey(slice, &pubkey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_NewPubKey failed");
    cipher__Address c_address;
    result = SKY_cipher_AddressFromPubKey(&pubkey, &c_address);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
}
END_TEST

START_TEST(TestAddress2)
{
    char* address_hex = "5a42c0643bdb465d90bf673b99c14f5fa02db71513249d904573d2b8b63d353d";
    char address[128];
    int result;
    int length = hexnstr(address_hex, (unsigned char*)address, 128);
    ck_assert_msg(length > 0, "Error decoding hex string");
    GoSlice slice = {address, length, 128};
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    result = SKY_cipher_NewSecKey(slice, &seckey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_NewSecKey failed");
    result = SKY_cipher_PubKeyFromSecKey(&seckey, &pubkey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_PubKeyFromSecKey failed");
    cipher__Address c_address;
    result = SKY_cipher_AddressFromPubKey(&pubkey, &c_address);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
}
END_TEST

START_TEST(TestCrypto1)
{
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    int result;
    int i;
    for (i = 0; i < 10; i++) {
        result = SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
        ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");
        result = SKY_cipher_CheckSecKey(&seckey);
        ck_assert_msg(result == SKY_OK, "CRYPTOGRAPHIC INTEGRITY CHECK FAILED");
    }
}
END_TEST

START_TEST(TestCrypto2)
{
    char* address_hex = "5a42c0643bdb465d90bf673b99c14f5fa02db71513249d904573d2b8b63d353d";
    char address[128];
    int result;
    int length = hexnstr(address_hex, (unsigned char*)address, 128);
    ck_assert_msg(length == 32, "Error decoding hex string");

    GoSlice slice = {address, length, 128};
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    result = SKY_cipher_NewSecKey(slice, &seckey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_NewSecKey failed");
    result = SKY_cipher_PubKeyFromSecKey(&seckey, &pubkey);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_PubKeyFromSecKey failed");
    cipher__Address c_address;
    result = SKY_cipher_AddressFromPubKey(&pubkey, &c_address);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");

    char* text = "test message";
    int len = strlen(text);
    GoSlice textslice = {text, len, len};
    cipher__SHA256 hash;
    result = SKY_cipher_SumSHA256(textslice, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_SumSHA256 failed");
    result = SKY_cipher_CheckSecKeyHash(&seckey, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_CheckSecKeyHash failed");
}
END_TEST
Suite* coin_coin(void)
{
    Suite* s = suite_create("Load coin.coin");
    TCase* tc;

    tc = tcase_create("coin.coin");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestAddress1);
    tcase_add_test(tc, TestAddress2);
    tcase_add_test(tc, TestCrypto1);
    tcase_add_test(tc, TestCrypto2);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}