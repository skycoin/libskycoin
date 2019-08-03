
#include <stdio.h>
#include <string.h>

//#include <criterion/criterion.h>
//#include <criterion/new/assert.h>
#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytypes.h"
#include <check.h>

#define SKYCOIN_ADDRESS_VALID "2GgFvqoyk9RjwVzj8tqfcXVXB4orBwoc9qv"

START_TEST(TestBitcoinAddress)
{
    cipher__SecKey seckey;
    cipher__PubKey pubkey;
    cipher__BitcoinAddress btcAddr;
    GoString secKeys[3] = {
        {"1111111111111111111111111111111111111111111111111111111111111111", 64},
        {"dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd", 64},
        {"47f7616ea6f9b923076625b4488115de1ef1187f760e65f89eb6f4f7ff04b012", 64}};
    GoString pubKeys[3] = {
        {"034f355bdcb7cc0af728ef3cceb9615d90684bb5b2ca5f859ab0f0b704075871aa", 66},
        {"02ed83704c95d829046f1ac27806211132102c34e9ac7ffa1b71110658e5b9d1bd", 66},
        {"032596957532fc37e40486b910802ff45eeaa924548c0e1c080ef804e523ec3ed3", 66}};
    GoString addrs[3] = {
        {"1Q1pE5vPGEEMqRcVRMbtBK842Y6Pzo6nK9", 34},
        {"1NKRhS7iYUGTaAfaR5z8BueAJesqaTyc4a", 34},
        {"19ck9VKC6KjGxR9LJg4DNMRc45qFrJguvV", 34}};
    unsigned int error;

    GoString* secKeyStr = secKeys;
    GoString* pubKeyStr = pubKeys;
    GoString* addrStr = addrs;
    int i;
    for (i = 0; i < 3; ++i, ++secKeyStr, ++pubKeyStr, ++addrStr) {
        GoUint8 buff[1024];
        error = SKY_cipher_SecKeyFromHex(*secKeyStr, &seckey);
        ck_assert_msg(error == SKY_OK, "Create SecKey from Hex"); // (seckeyFailMsg));
        error = SKY_cipher_PubKeyFromHex(*pubKeyStr, &pubkey);
        ck_assert_msg(error == SKY_OK, "Create PubKey from Hex");

        GoString_ str = {NULL, 0};
        SKY_cipher_BitcoinAddressFromPubKey(&pubkey, &btcAddr);
        SKY_cipher_BitcoinAddress_String(&btcAddr, &str);
        registerMemCleanup((void*)str.p);
        GoString tmpStr = {str.p, str.n};
        ck_assert_str_eq(str.p, addrStr->p);

        error = SKY_cipher_BitcoinAddressFromSecKey(&seckey, &btcAddr);
        ck_assert(error == SKY_OK);
        GoString_ tmpstr = {buff, 0};
        SKY_cipher_BitcoinAddress_String(&btcAddr, &tmpstr);
        ck_assert_str_eq(tmpStr.p, addrStr->p);
    }
}
END_TEST

START_TEST(TestDecodeBase58BitcoinAddress)
{
    cipher__PubKey p;
    cipher__SecKey s;
    cipher__BitcoinAddress a;
    GoUint32 err;
    err = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_int_eq(err, SKY_OK);
    SKY_cipher_BitcoinAddressFromPubKey(&p, &a);
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p);
    ck_assert_int_eq(err, SKY_OK);

    cipher__BitcoinAddress a2;
    GoString str = {"", 0};
    err = SKY_cipher_DecodeBase58BitcoinAddress(str, &a2);
    ck_assert_int_ne(err, SKY_OK);

    str.p = "cascs";
    str.n = 5;
    err = SKY_cipher_DecodeBase58BitcoinAddress(str, &a2);
    ck_assert_int_ne(err, SKY_OK);

    GoUint8 buffer_b[1024];
    GoUint8 buffer_b_temp[1024];
    GoSlice b = {buffer_b, 0, 1024};
    GoUint8 buffer_h_temp[1024];
    GoString_ h_tmp = {buffer_h_temp, 0};
    coin__UxArray b_temp = {buffer_b_temp, 0, 1024};
    SKY_cipher_BitcoinAddress_Bytes(&a, &b_temp);
    copycoin_UxArraytoGoSlice(&b, &b_temp, b_temp.len);
    GoInt_ len_b = b.len;
    b.len = (GoInt_)(len_b / 2);
    GoUint8_ buffer_h[1024];
    GoString h = {buffer_h, 0};
    err = SKY_base58_Hex2Base58(b, &h_tmp);
    ck_assert_int_eq(err, SKY_OK);
    h.n = h_tmp.n;
    h.p = h_tmp.p;
    err = SKY_cipher_DecodeBase58BitcoinAddress(h, &a2);
    ck_assert_int_ne(err, SKY_OK);

    memset(&b_temp, 0, sizeof(coin__UxArray));
    SKY_cipher_BitcoinAddress_Bytes(&a, &b_temp);
    err = copycoin_UxArraytoGoSlice(&b, &b_temp, b_temp.len);
    ck_assert_int_eq(err, SKY_OK);
    err = SKY_base58_Hex2Base58(b, &h_tmp);
    ck_assert_int_eq(err, SKY_OK);
    h.n = h_tmp.n;
    h.p = h_tmp.p;
    err = SKY_cipher_DecodeBase58BitcoinAddress(h, &a2);
    ck_assert_int_eq(err, SKY_OK);
    ck_assert(isBitcoinAddressEq(&a, &a2));

    GoUint8_ buffer_as[1024];
    GoString_ as = {buffer_as, 0};
    memset(&a2, 0, sizeof(cipher__BitcoinAddress));
    SKY_cipher_BitcoinAddress_String(&a, &as);
    GoString as_temp;
    as_temp.p = as.p;
    as_temp.n = as.n;
    err = SKY_cipher_DecodeBase58BitcoinAddress(as_temp, &a2);
    ck_assert_int_eq(err, SKY_OK);
    ck_assert(isBitcoinAddressEq(&a, &a2));

    // preceding whitespace is invalid
    GoUint8_ buffer_as2[1024];
    GoString as2 = {buffer_as2, 0};
    char tempStr[50];
    strcpy(tempStr, " ");
    strcat(tempStr, as.p);
    as2.p = tempStr;
    as2.n = strlen(tempStr);
    cipher__BitcoinAddress a3;
    err = SKY_cipher_DecodeBase58BitcoinAddress(as2, &a3);
    ck_assert_int_ne(err, SKY_OK);

    // preceding zeroes are invalid
    strcpy(tempStr, "000");
    strcat(tempStr, as.p);
    as2.p = tempStr;
    as2.n = strlen(tempStr);
    err = SKY_cipher_DecodeBase58BitcoinAddress(as2, &a3);
    ck_assert_int_ne(err, SKY_OK);

    // trailing whitespace is invalid
    strcpy(tempStr, as.p);
    strcat(tempStr, " ");
    as2.p = tempStr;
    as2.n = strlen(tempStr);
    err = SKY_cipher_DecodeBase58BitcoinAddress(as2, &a3);
    ck_assert_int_ne(err, SKY_OK);

    // trailing zeroes are invalid
    strcpy(tempStr, as.p);
    strcat(tempStr, "000");
    as2.p = tempStr;
    as2.n = strlen(tempStr);
    err = SKY_cipher_DecodeBase58BitcoinAddress(as2, &a3);
    ck_assert_int_ne(err, SKY_OK);

    GoString nulls = {"1111111111111111111111111", 25};
    err = SKY_cipher_DecodeBase58BitcoinAddress(nulls, &a3);
    ck_assert_int_eq(err, SKY_ErrAddressInvalidChecksum);
}
END_TEST

START_TEST(TestBitcoinAddressFromBytes)
{
    cipher__PubKey p;
    cipher__SecKey s;
    GoInt32 err;
    err = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_int_eq(err, SKY_OK);
    cipher__BitcoinAddress a;
    err = SKY_cipher_BitcoinAddressFromSecKey(&s, &a);
    ck_assert_int_eq(err, SKY_OK);
    // Valid pubkey+address
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p);
    ck_assert_int_eq(err, SKY_OK);

    memset(s, 0, sizeof(cipher__SecKey));
    err = SKY_cipher_BitcoinAddressFromSecKey(&s, &a);
    ck_assert_int_eq(err, SKY_ErrPubKeyFromNullSecKey);
}
END_TEST

START_TEST(TestBitcoinAddressNull)
{
    cipher__BitcoinAddress a;
    memset(&a, 0, sizeof(cipher__BitcoinAddress));
    GoUint8 err = SKY_cipher_BitcoinAddress_Null(&a);
    ck_assert_int_eq(err, 1);

    cipher__PubKey p;
    cipher__SecKey s;
    err = SKY_cipher_GenerateKeyPair(&p, &s);
    memset(&a, 0, sizeof(cipher__BitcoinAddress));
    SKY_cipher_BitcoinAddressFromPubKey(&p, &a);
    err = SKY_cipher_BitcoinAddress_Null(&a);
    ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(TestBitcoinAddressVerify)
{
    cipher__PubKey p;
    cipher__SecKey s;
    GoUint32 err;
    err = SKY_cipher_GenerateKeyPair(&p, &s);
    ck_assert_int_eq(err, SKY_OK);
    cipher__BitcoinAddress a;
    SKY_cipher_BitcoinAddressFromPubKey(&p, &a);
    // Valid pubkey+address
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p);
    ck_assert_int_eq(err, SKY_OK);
    // Invalid pubkey
    memset(&p, 0, sizeof(cipher__PubKey));
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p);
    ck_assert_int_eq(err, SKY_ErrAddressInvalidPubKey);
    cipher__PubKey p2;
    err = SKY_cipher_GenerateKeyPair(&p2, &s);
    ck_assert_int_eq(err, SKY_OK);
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p2);
    ck_assert_int_eq(err, SKY_ErrAddressInvalidPubKey);
    // Bad version
    a.Version = 0x01;
    err = SKY_cipher_BitcoinAddress_Verify(&a, &p);
    ck_assert_int_eq(err, SKY_ErrAddressInvalidVersion);
}
END_TEST

START_TEST(TestBitcoinWIFRoundTrip)
{
    cipher__SecKey seckey;
    cipher__PubKey pubkey;
    SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
    unsigned char wip1_buff[50];
    unsigned char wip2_buff[50];
    GoString wip1;
    GoString_ tmp_wip1 = {wip1_buff, 0};
    SKY_cipher_BitcoinWalletImportFormatFromSeckey(&seckey, &tmp_wip1);
    wip1.n = tmp_wip1.n;
    wip1.p = tmp_wip1.p;
    registerMemCleanup((void*)wip1.p);
    cipher__SecKey seckey2;
    GoUint32 err;
    err = SKY_cipher_SecKeyFromBitcoinWalletImportFormat(wip1, &seckey2);
    ck_assert(err == SKY_OK);
    GoString_ wip2;
    SKY_cipher_BitcoinWalletImportFormatFromSeckey(&seckey2, &wip2);
    ck_assert(isSecKeyEq(&seckey, &seckey2));

    GoString_ seckeyhex1;
    GoString_ seckeyhex2;
    SKY_cipher_SecKey_Hex(&seckey, &seckeyhex1);
    SKY_cipher_SecKey_Hex(&seckey2, &seckeyhex2);
    ck_assert_str_eq((seckeyhex1.p), (seckeyhex2.p));
    ck_assert_str_eq((tmp_wip1.p), (wip2.p));
}
END_TEST

START_TEST(TestBitcoinWIF)
{
    //wallet input format string
    GoString wip[3];
    wip[0].p = "KwntMbt59tTsj8xqpqYqRRWufyjGunvhSyeMo3NTYpFYzZbXJ5Hp";
    wip[1].p = "L4ezQvyC6QoBhxB4GVs9fAPhUKtbaXYUn8YTqoeXwbevQq4U92vN";
    wip[2].p = "KydbzBtk6uc7M6dXwEgTEH2sphZxSPbmDSz6kUUHi4eUpSQuhEbq";
    wip[0].n = 52;
    wip[1].n = 52;
    wip[2].n = 52;
    //   // //the expected pubkey to generate
    GoString_ pub[3];
    pub[0].p = "034f355bdcb7cc0af728ef3cceb9615d90684bb5b2ca5f859ab0f0b704075871aa";
    pub[1].p = "02ed83704c95d829046f1ac27806211132102c34e9ac7ffa1b71110658e5b9d1bd";
    pub[2].p = "032596957532fc37e40486b910802ff45eeaa924548c0e1c080ef804e523ec3ed3";
    pub[0].n = 66;
    pub[1].n = 66;
    pub[2].n = 66;
    // //the expected addrss to generate
    GoString addr[3];
    addr[0].p = "1Q1pE5vPGEEMqRcVRMbtBK842Y6Pzo6nK9";
    addr[1].p = "1NKRhS7iYUGTaAfaR5z8BueAJesqaTyc4a";
    addr[2].p = "19ck9VKC6KjGxR9LJg4DNMRc45qFrJguvV";
    addr[0].n = 34;
    addr[1].n = 34;
    addr[2].n = 34;
    int i;
    for (i = 0; i < 3; i++) {
        cipher__SecKey seckey;
        unsigned int err;
        err = SKY_cipher_SecKeyFromBitcoinWalletImportFormat(wip[i], &seckey);
        ck_assert(err == SKY_OK);
        cipher__PubKey pubkey;
        err = SKY_cipher_PubKeyFromSecKey(&seckey, &pubkey);
        ck_assert(err == SKY_OK);
        unsigned char* pubkeyhextmp;
        GoString_ string;
        err = SKY_cipher_PubKey_Hex(&pubkey, &string);
        ck_assert(err == SKY_OK);
        ck_assert_str_eq(string.p, pub[i].p);
        cipher__BitcoinAddress bitcoinAddr;
        GoString bitcoinAddrStr;
        SKY_cipher_BitcoinAddressFromPubKey(&pubkey, &bitcoinAddr);
        unsigned char buff_bitcoinAddrStr[50];
        GoString_ tmp_bitcoinAddrStr = {buff_bitcoinAddrStr, 0};
        SKY_cipher_BitcoinAddress_String(&bitcoinAddr, &tmp_bitcoinAddrStr);
        bitcoinAddrStr.p = tmp_bitcoinAddrStr.p;
        bitcoinAddrStr.n = tmp_bitcoinAddrStr.n;
        registerMemCleanup((void*)bitcoinAddrStr.p);
        ck_assert_msg(addr[i].p, bitcoinAddrStr.p);
    }
}
END_TEST


// define test suite and cases
Suite* cipher_bitcoin(void)
{
    Suite* s = suite_create("Load cipher.bitcoin");
    TCase* tc;

    tc = tcase_create("cipher.bitcoin");
    tcase_add_test(tc, TestBitcoinAddress);
    tcase_add_test(tc, TestDecodeBase58BitcoinAddress);
    tcase_add_test(tc, TestBitcoinAddressFromBytes);
    tcase_add_test(tc, TestBitcoinAddressNull);
    tcase_add_test(tc, TestBitcoinAddressVerify);
    tcase_add_test(tc, TestBitcoinWIFRoundTrip);
    tcase_add_test(tc, TestBitcoinWIF);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}
