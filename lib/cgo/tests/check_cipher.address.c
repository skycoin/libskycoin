#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SKYCOIN_ADDRESS_VALID "2GgFvqoyk9RjwVzj8tqfcXVXB4orBwoc9qv"

// TestSuite(cipher_address, .init = setup, .fini = teardown);
//
// buffer big enough to hold all kind of data needed by test cases
unsigned char buff[1024];
//
START_TEST(TestDecodeBase58Address)
{
    GoString strAddr = {SKYCOIN_ADDRESS_VALID, 35};
    cipher__Address addr;
    GoUint32 err = SKY_cipher_DecodeBase58Address(strAddr, &addr);
    ck_assert_int_eq(err, SKY_OK);

    char tempStr[50];
    int errorcode;

    // preceding whitespace is invalid
    strcpy(tempStr, " ");
    strcat(tempStr, SKYCOIN_ADDRESS_VALID);
    strAddr.p = tempStr;
    strAddr.n = strlen(tempStr);
    errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
    ck_assert_msg(errorcode == SKY_ERROR, "preceding whitespace is invalid");

    // preceding zeroes are invalid
    strcpy(tempStr, "000");
    strcat(tempStr, SKYCOIN_ADDRESS_VALID);
    strAddr.p = tempStr;
    strAddr.n = strlen(tempStr);
    errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
    ck_assert_msg(errorcode == SKY_ERROR, "leading zeroes prefix are invalid");

    // trailing whitespace is invalid
    strcpy(tempStr, SKYCOIN_ADDRESS_VALID);
    strcat(tempStr, " ");
    strAddr.p = tempStr;
    strAddr.n = strlen(tempStr);
    errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
    ck_assert_msg(errorcode == SKY_ERROR, "trailing whitespace is invalid");

    // trailing zeroes are invalid
    strcpy(tempStr, SKYCOIN_ADDRESS_VALID);
    strcat(tempStr, "000");
    strAddr.p = tempStr;
    strAddr.n = strlen(tempStr);
    errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
    ck_assert_msg(errorcode == SKY_ERROR, "trailing zeroes suffix are invalid");

    cipher__PubKey p;
    cipher__SecKey s;
    errorcode = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert(errorcode == SKY_OK);
    cipher__Address a;
    errorcode = SKY_cipher_AddressFromPubKey(&p, &a);
    ck_assert(errorcode == SKY_OK);
    GoSlice b;
    coin__UxArray Cub;
    Cub.data = buff;
    Cub.len = 0;
    Cub.cap = sizeof(buff);
    errorcode = SKY_cipher_Address_Bytes(&addr, &Cub);
    ck_assert_msg(errorcode == SKY_OK, "Fail SKY_cipher_Address_Bytes");
    b.cap = Cub.cap;
    b.data = Cub.data;
    b.len = Cub.len;

    int len_b = b.len;
    char bufferHead[1024];
    GoString_ h = {bufferHead, 0};
    b.len = (GoInt)(len_b / 2);
    errorcode = SKY_base58_Hex2Base58(b, &h);
    ck_assert(errorcode == SKY_OK);
    char bufferHeadTmp[1024];
    GoString tmph = {bufferHeadTmp, 0};
    tmph.n = h.n;
    tmph.p = h.p;
    errorcode = SKY_cipher_DecodeBase58Address(tmph, &addr);
    ck_assert_msg(errorcode == SKY_ErrAddressInvalidLength, "Fail %X", errorcode);
    b.len = len_b;
    errorcode = SKY_base58_Hex2Base58(b, &h);
    ck_assert(errorcode == SKY_OK);
    tmph.n = h.n;
    tmph.p = h.p;
    errorcode = SKY_cipher_DecodeBase58Address(tmph, &addr);
    ck_assert_msg(errorcode == SKY_OK, "Fail %X", errorcode);
}
END_TEST

START_TEST(TestAddressFromBytes)
{
    cipher__Address addr, addr2;
    cipher__SecKey sk;
    cipher__PubKey pk;
    GoSlice bytes;
    GoSlice_ tempBytes;

    GoUint32 err = SKY_cipher_GenerateKeyPair(&pk, &sk);
    ck_assert(err == SKY_OK);
    SKY_cipher_AddressFromPubKey(&pk, &addr);

    tempBytes.data = buff;
    tempBytes.len = 0;
    tempBytes.cap = sizeof(buff);

    SKY_cipher_Address_Bytes(&addr, &tempBytes);
    ck_assert_msg(tempBytes.len > 0, "address bytes written");
    copyGoSlice_toGoSlice(&bytes, &tempBytes, tempBytes.len);
    err = SKY_cipher_AddressFromBytes(bytes, &addr2);
    ck_assert_msg(err == SKY_OK, "convert bytes to SKY address");

    ck_assert_msg(isAddressEq(&addr, &addr2), "Not equal Address");

    int bytes_len = bytes.len;

    bytes.len = bytes.len - 2;
    ck_assert_msg(SKY_cipher_AddressFromBytes(bytes, &addr2) ==
                      SKY_ErrAddressInvalidLength,
        "no SKY address due to short bytes length");

    bytes.len = bytes_len;
    ((char*)bytes.data)[bytes.len - 1] = '2';
    err = SKY_cipher_AddressFromBytes(bytes, &addr2);
    ck_assert_msg(err == SKY_ErrAddressInvalidChecksum,
        "no SKY address due to corrupted bytes %X", err);

    addr.Version = 2;
    SKY_cipher_Address_Bytes(&addr, &tempBytes);
    copyGoSlice_toGoSlice(&bytes, &tempBytes, tempBytes.len);
    err = SKY_cipher_AddressFromBytes(bytes, &addr2);
    ck_assert_msg(err == SKY_ErrAddressInvalidVersion, "Invalid version");
}
END_TEST

START_TEST(TestAddressRoundtrip)
{
    cipher__PubKey p;
    cipher__SecKey s;
    GoUint32_ error;
    error = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_int_eq(error, SKY_OK);
    cipher__Address a;
    error = SKY_cipher_AddressFromPubKey(&p, &a);
    ck_assert_int_eq(error, SKY_OK);
    unsigned char buffera_bytes[1024];
    coin__UxArray a_bytes = {buffera_bytes, 0, 1024};
    error = SKY_cipher_Address_Bytes(&a, &a_bytes);
    ck_assert_int_eq(error, SKY_OK);
    cipher__Address a2;
    GoSlice TMP_a_bytes = {a_bytes.data, a_bytes.len, a_bytes.cap};
    error = SKY_cipher_AddressFromBytes(TMP_a_bytes, &a2);
    ck_assert_int_eq(error, SKY_OK);
    ck_assert(isAddressEq(&a, &a2));
    GoString_ str_a;
    GoString_ str_a2;
    error = SKY_cipher_Address_String(&a, &str_a);
    error = SKY_cipher_Address_String(&a2, &str_a2);
    ck_assert(isGoString_Eq(str_a2, str_a));
}
END_TEST

START_TEST(TestAddressVerify)
{
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    cipher__PubKey pubkey2;
    cipher__SecKey seckey2;
    cipher__Address addr;

    SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
    SKY_cipher_AddressFromPubKey(&pubkey, &addr);

    // Valid pubkey+address
    ck_assert_msg(SKY_cipher_Address_Verify(&addr, &pubkey) == SKY_OK,
        "Valid pubkey + address");

    SKY_cipher_GenerateKeyPair(&pubkey, &seckey2);
    // Invalid pubkey
    ck_assert_msg(SKY_cipher_Address_Verify(&addr, &pubkey) ==
                      SKY_ErrAddressInvalidPubKey,
        " Invalid pubkey");

    // Bad version
    addr.Version = 0x01;
    ck_assert_msg(SKY_cipher_Address_Verify(&addr, &pubkey) ==
                      SKY_ErrAddressInvalidVersion,
        "  Bad version");
}
END_TEST

START_TEST(TestAddressString)
{
    cipher__PubKey pk;
    cipher__SecKey sk;
    cipher__Address addr, addr2, addr3;
    GoString str = {buff, 0};

    GoUint32 err = SKY_cipher_GenerateKeyPair(&pk, &sk);
    ck_assert(err == SKY_OK);
    err = SKY_cipher_AddressFromPubKey(&pk, &addr);
    ck_assert(err == SKY_OK);
    GoString_ tmpstr = {str.p, str.n};

    err = SKY_cipher_Address_String(&addr, &tmpstr);
    ck_assert(err == SKY_OK);
    str.n = tmpstr.n;
    str.p = tmpstr.p;
    ck_assert(SKY_cipher_DecodeBase58Address(str, &addr2) == SKY_OK);
    ck_assert(isAddressEq(&addr, &addr2));

    SKY_cipher_Address_String(&addr2, (GoString_*)&str);
    ck_assert(SKY_cipher_DecodeBase58Address(str, &addr3) == SKY_OK);
    ck_assert(isAddressEq(&addr, &addr2));
}
END_TEST

START_TEST(TestAddressBulk)
{
    unsigned char buff[50];
    GoSlice slice = {buff, 0, 50};
    int i;
    for (i = 0; i < 1024; ++i) {
        GoUint32 err;
        randBytes(&slice, 32);
        cipher__PubKey pubkey;
        cipher__SecKey seckey;
        err = SKY_cipher_GenerateDeterministicKeyPair(slice, &pubkey, &seckey);
        ck_assert(err == SKY_OK);
        cipher__Address addr;
        err = SKY_cipher_AddressFromPubKey(&pubkey, &addr);
        ck_assert(err == SKY_OK);
        err = SKY_cipher_Address_Verify(&addr, &pubkey);
        ck_assert(err == SKY_OK);

        GoString_ tempstrAddr;
        err = SKY_cipher_Address_String(&addr, &tempstrAddr);
        ck_assert(err == SKY_OK);
        registerMemCleanup((void*)tempstrAddr.p);
        cipher__Address addr2;
        GoString strAddr;
        strAddr.n = tempstrAddr.n;
        strAddr.p = tempstrAddr.p;
        err = SKY_cipher_DecodeBase58Address(strAddr, &addr2);
        ck_assert(err == SKY_OK);
        ck_assert(isAddressEq(&addr, &addr2));
    }
}
END_TEST

START_TEST(TestAddressNull)
{
    cipher__Address a;
    memset(&a, 0, sizeof(cipher__Address));
    GoUint32 result;
    GoUint8 isNull;
    result = SKY_cipher_Address_Null(&a, &isNull);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_Address_Null");
    ck_assert(isNull == 1);

    cipher__PubKey p;
    cipher__SecKey s;

    result = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");

    result = SKY_cipher_AddressFromPubKey(&p, &a);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
    result = SKY_cipher_Address_Null(&a, &isNull);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_Address_Null");
    ck_assert(isNull == 0);
}
END_TEST

START_TEST(TestAddressFromSecKey)
{
    GoUint32 result;
    cipher__PubKey p;
    cipher__SecKey s;
    result = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");
    cipher__Address a;
    result = SKY_cipher_AddressFromSecKey(&s, &a);
    ck_assert_int_eq(result, SKY_OK);
    result = SKY_cipher_Address_Verify(&a, &p);
    ck_assert_int_eq(result, SKY_OK);
    cipher__SecKey s2;
    result = SKY_cipher_AddressFromSecKey(&s, &a);
    ck_assert_int_eq(result, SKY_ERROR);
}
END_TEST

// define test suite and cases
Suite* cipher_address(void)
{
    Suite* s = suite_create("Load cipher.address");
    TCase* tc;

    tc = tcase_create("cipher.address");
    tcase_add_checked_fixture(tc, setup, teardown);
    // tcase_add_test(tc, TestDecodeBase58Address);
    // tcase_add_test(tc, TestAddressFromBytes);
    // tcase_add_test(tc, TestAddressRoundtrip);
    // tcase_add_test(tc, TestAddressVerify);
    // tcase_add_test(tc, TestAddressString);
    // tcase_add_test(tc, TestAddressBulk);
    // tcase_add_test(tc, TestAddressNull);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}