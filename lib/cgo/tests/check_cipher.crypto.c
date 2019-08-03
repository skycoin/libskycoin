#include <stdio.h>
#include <stdlib.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

START_TEST(TestNewPubKey)
{
    unsigned char buff[101];
    GoSlice slice;
    cipher__PubKey pk, pk2;
    cipher__SecKey sk;

    slice.data = buff;
    slice.cap = 101;

    randBytes(&slice, 31);
    slice.len = 31;
    unsigned int errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "31 random bytes");

    randBytes(&slice, 32);
    errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "32 random bytes");

    randBytes(&slice, 34);
    errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "34 random bytes");

    slice.len = 0;
    errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "0 random bytes");

    randBytes(&slice, 100);
    errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "100 random bytes");

    randBytes(&slice, 33);
    errorcode = SKY_cipher_NewPubKey(slice, &pk);
    ck_assert_msg(errorcode != SKY_OK, "33 random bytes");

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    GoSlice buffer = {pk, sizeof(pk), sizeof(pk)};
    errorcode = SKY_cipher_NewPubKey(buffer, &pk2);
    ck_assert_msg(errorcode == SKY_OK);

    ck_assert(isPubKeyEq(&pk, &pk2));
}
END_TEST

START_TEST(TestPubKeyFromHex)
{
    cipher__PubKey p, p1;
    cipher__SecKey sk;
    GoString s;
    unsigned char buff[51];
    char sbuff[101];
    GoSlice slice = {(void*)buff, 0, 51};
    unsigned int errorcode;

    // Invalid hex
    s.n = 0;
    errorcode = SKY_cipher_PubKeyFromHex(s, &p1);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "TestPubKeyFromHex: Invalid hex. Empty string");

    s.p = "cascs";
    s.n = strlen(s.p);
    errorcode = SKY_cipher_PubKeyFromHex(s, &p1);
    ck_assert_msg(errorcode == SKY_ErrInvalidPubKey, "TestPubKeyFromHex: Invalid hex. Bad chars");

    // Invalid hex length
    SKY_cipher_GenerateKeyPair(&p, &sk);
    memcpy(slice.data, (void*)p, sizeof(p));
    slice.len = sizeof(p);
    bytesnhex(&p[0], sbuff, slice.len >> 1);
    s.p = sbuff;
    s.n = strlen(s.p);
    errorcode = SKY_cipher_PubKeyFromHex(s, &p1);
    ck_assert_msg(errorcode == SKY_ErrInvalidLengthPubKey, "TestPubKeyFromHex: Invalid hex length");

    // Valid
    bytesnhex(p, sbuff, sizeof(p));
    s.p = sbuff;
    s.n = sizeof(p) << 1;
    errorcode = SKY_cipher_PubKeyFromHex(s, &p1);
    ck_assert_msg(errorcode == SKY_OK, "TestPubKeyFromHex: Valid. No panic.");
    ck_assert(isPubKeyEq(&p, &p1));
}
END_TEST

START_TEST(TestPubKeyHex)
{
    cipher__PubKey p, p2;
    cipher__SecKey sk;
    GoString s3, s4;
    unsigned char buff[50];
    unsigned char buff_s3[50];
    GoSlice slice = {buff, 0, 50};
    unsigned int errorcode;

    GoUint32 err = SKY_cipher_GenerateKeyPair(&p, &sk);
    ck_assert(err == SKY_OK);
    GoString_ tmp_s3 = {buff_s3, 0};
    err = SKY_cipher_PubKey_Hex(&p, &tmp_s3);
    ck_assert(err == SKY_OK);
    s3.n = tmp_s3.n;
    s3.p = tmp_s3.p;
    registerMemCleanup((void*)s3.p);
    errorcode = SKY_cipher_PubKeyFromHex(s3, &p2);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isPubKeyEq(&p, &p2));

    unsigned char s4_buff[50];
    GoString_ tmp_s4 = {s4_buff, 0};
    err = SKY_cipher_PubKey_Hex(&p2, &tmp_s4);
    ck_assert(err == SKY_OK);
    s4.n = s4.n;
    s4.p = s4.p;
    registerMemCleanup((void*)s4.p);
    // // TODO: Translate into cr_assert(eq(type(GoString), s3, s4));
    ck_assert(isGoStringEq(s3, s4) == 0);
}
END_TEST

START_TEST(TestPubKeyVerify)
{
    cipher__PubKey p;
    unsigned char buff[50];
    GoSlice slice = {buff, 0, 50};
    unsigned int errorcode;
    int failed = 1;

    int i = 0;
    for (; i < 10; i++) {
        randBytes(&slice, 33);
        memcpy((void*)&p, slice.data, 33);
        failed = 1 || (errorcode = SKY_cipher_PubKey_Verify(&p));
    }
    ck_assert(failed);
}
END_TEST

START_TEST(TestPubKeyVerifyNil)
{
    cipher__PubKey p = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0};
    unsigned int errorcode;

    errorcode = SKY_cipher_PubKey_Verify(&p);
    ck_assert(errorcode == SKY_ErrInvalidPubKey);
}
END_TEST

START_TEST(TestPubKeyVerifyDefault1)
{
    cipher__PubKey p;
    cipher__SecKey s;

    SKY_cipher_GenerateKeyPair(&p, &s);
    GoUint32 errorcode = SKY_cipher_PubKey_Verify(&p);
    ck_assert(errorcode == SKY_OK);
}
END_TEST

START_TEST(TestPubKeyVerifyDefault2)
{
    cipher__PubKey p;
    cipher__SecKey s;
    int i;

    for (i = 0; i < 1024; ++i) {
        SKY_cipher_GenerateKeyPair(&p, &s);
        GoUint32 errorcode = SKY_cipher_PubKey_Verify(&p);
        ck_assert(errorcode == SKY_OK);
    }
}
END_TEST

START_TEST(TestPubKeyRipemd160)
{
    cipher__PubKey p;
    cipher__SecKey s;
    cipher__Ripemd160 h;

    SKY_cipher_GenerateKeyPair(&p, &s);
    SKY_cipher_PubKeyRipemd160(&p, &h);
    // TODO: Translate code snippet
    //
    // x := sha256.Sum256(p[:])
    // x = sha256.Sum256(x[:])
    // rh := ripemd160.New()
    // rh.Write(x[:])
    // y := rh.Sum(nil)
    // assert.True(t, bytes.Equal(h[:], y))
    //
    //
}
END_TEST

START_TEST(TestPubKeyToAddress)
{
    cipher__PubKey p;
    cipher__SecKey s;
    cipher__Address addr;
    cipher__Ripemd160 h;
    GoUint32 errorcode;

    SKY_cipher_GenerateKeyPair(&p, &s);
    SKY_cipher_AddressFromPubKey(&p, &addr);
    errorcode = SKY_cipher_Address_Verify(&addr, &p);
    ck_assert(errorcode == SKY_OK);
}
END_TEST

START_TEST(TestPubKeyToAddress2)
{
    cipher__PubKey p;
    cipher__SecKey s;
    cipher__Address addr;
    GoString_ addrStr;
    int i;
    GoUint32 errorcode;

    for (i = 0; i < 1024; i++) {
        SKY_cipher_GenerateKeyPair(&p, &s);
        SKY_cipher_AddressFromPubKey(&p, &addr);
        //func (self Address) Verify(key PubKey) error
        errorcode = SKY_cipher_Address_Verify(&addr, &p);
        ck_assert(errorcode == SKY_OK);
        SKY_cipher_Address_String(&addr, &addrStr);
        unsigned char buff[50];
        GoString addrStr_tmp = {buff, 0};
        addrStr_tmp.p = addrStr.p;
        addrStr_tmp.n = addrStr.n;
        registerMemCleanup((void*)addrStr.p);
        errorcode = SKY_cipher_DecodeBase58Address(addrStr_tmp, &addr);
        //func DecodeBase58Address(addr string) (Address, error)
        ck_assert(errorcode == SKY_OK);
    }
}
END_TEST

START_TEST(TestSecKeyFromHex)
{
    unsigned char buff[50];
    cipher__SecKey sk;
    GoString str = {buff, 0};
    // Invalid hex
    GoUint32 err = SKY_cipher_SecKeyFromHex(str, &sk);
    ck_assert_msg(err == SKY_ErrInvalidLengthSecKey);
    str.p = "cascs";
    str.n = strlen(str.p);
    err = SKY_cipher_SecKeyFromHex(str, &sk);
    ck_assert_msg(err == SKY_ErrInvalidSecKey);

    // Invalid hex length
    GoSlice b = {buff, 0, 50};
    randBytes(&b, 32);
    cipher__SecKey p;
    err = SKY_cipher_NewSecKey(b, &p);
    ck_assert(err == SKY_OK);
    int len_b = b.len;
    b.len = (int)(len_b / 2);
    //TODO: NOt implement
}
END_TEST

START_TEST(TestMustSecKeyFromHex)
{
    GoString str;
    cipher__SecKey sk, sk1;
    unsigned int buff[50];
    GoSlice b;
    char strBuff[101];
    GoString s;
    int errorcode;

    // Invalid hex
    s.p = "";
    s.n = strlen(s.p);
    errorcode = SKY_cipher_SecKeyFromHex(s, &sk);
    ck_assert(errorcode == SKY_ErrInvalidLengthSecKey);

    s.p = "cascs";
    s.n = strlen(s.p);
    errorcode = SKY_cipher_SecKeyFromHex(s, &sk);
    ck_assert(errorcode == SKY_ErrInvalidSecKey);

    // Invalid hex length
    b.data = buff;
    b.cap = 50;
    randBytes(&b, 32);
    errorcode = SKY_cipher_NewSecKey(b, &sk);
    ck_assert(errorcode == SKY_OK);
    bytesnhex(sk, strBuff, 16);
    s.p = strBuff;
    s.n = strlen(strBuff);
    errorcode = SKY_cipher_SecKeyFromHex(s, &sk1);
    ck_assert(errorcode == SKY_ErrInvalidLengthSecKey);

    // Valid
    bytesnhex(sk, strBuff, 32);
    s.p = strBuff;
    s.n = strlen(strBuff);
    errorcode = SKY_cipher_SecKeyFromHex(s, &sk1);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isSecKeyEq(&sk, &sk1));
}
END_TEST

START_TEST(TestSecKeyHex)
{
    cipher__SecKey sk, sk2;
    unsigned char buff[101];
    char strBuff[50];
    GoSlice b;
    GoString str, h;
    int errorcode;

    b.data = buff;
    b.cap = 50;
    h.p = strBuff;
    h.n = 0;

    randBytes(&b, 32);
    SKY_cipher_NewSecKey(b, &sk);
    SKY_cipher_SecKey_Hex(&sk, (GoString_*)&str);
    registerMemCleanup((void*)str.p);

    // Copy early to ensure memory is released
    strncpy((char*)h.p, str.p, str.n);
    h.n = str.n;

    errorcode = SKY_cipher_SecKeyFromHex(h, &sk2);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isSecKeyEq(&sk, &sk2));
}
END_TEST

START_TEST(TestSecKeyVerify)
{
    cipher__SecKey sk;
    cipher__PubKey pk;
    int errorcode;

    // Empty secret key should not be valid
    memset(sk, 0, 32);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_ErrInvalidSecKey);

    // Generated sec key should be valid
    SKY_cipher_GenerateKeyPair(&pk, &sk);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_OK);

    // Random bytes are usually valid
}
END_TEST

START_TEST(TestECDHonce)
{
    cipher__PubKey pub1, pub2;
    cipher__SecKey sec1, sec2;
    unsigned char buff1[50], buff2[50];
    GoSlice_ buf1, buf2;

    buf1.data = buff1;
    buf1.len = 0;
    buf1.cap = 50;
    buf2.data = buff2;
    buf2.len = 0;
    buf2.cap = 50;

    SKY_cipher_GenerateKeyPair(&pub1, &sec1);
    SKY_cipher_GenerateKeyPair(&pub2, &sec2);

    SKY_cipher_ECDH(&pub2, &sec1, &buf1);
    SKY_cipher_ECDH(&pub1, &sec2, &buf2);

    // ECDH shared secrets are 32 bytes SHA256 hashes in the end
    ck_assert(isSecKeyEq(&sec1, &sec2) == 0);
    // ck_assert(eq(u8[32], buff1, buff2));
}
END_TEST

START_TEST(TestECDHloop)
{
    int i;
    cipher__PubKey pub1, pub2;
    cipher__SecKey sec1, sec2;
    unsigned char buff1[50], buff2[50];
    GoSlice_ buf1, buf2;

    buf1.data = buff1;
    buf1.len = 0;
    buf1.cap = 50;
    buf2.data = buff2;
    buf2.len = 0;
    buf2.cap = 50;

    for (i = 0; i < 128; i++) {
        SKY_cipher_GenerateKeyPair(&pub1, &sec1);
        SKY_cipher_GenerateKeyPair(&pub2, &sec2);
        SKY_cipher_ECDH(&pub2, &sec1, &buf1);
        SKY_cipher_ECDH(&pub1, &sec2, &buf2);
        ck_assert_msg(isSecKeyEq(&sec1, &sec2) == 0, "Fail in %d", i);
    }
}
END_TEST

START_TEST(TestNewSig)
{
    unsigned char buff[101];
    GoSlice b;
    cipher__Sig s;
    int errorcode;

    b.data = buff;
    b.len = 0;
    b.cap = 101;

    randBytes(&b, 64);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    randBytes(&b, 66);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    randBytes(&b, 67);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    randBytes(&b, 0);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    randBytes(&b, 100);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    randBytes(&b, 65);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(buff, s, 65));
}
END_TEST

START_TEST(TestMustSigFromHex)
{
    unsigned char buff[101];
    char strBuff[257];
    GoSlice b = {buff, 0, 101};
    GoString str;
    cipher__Sig s, s2;
    int errorcode;

    // Invalid hex
    str.p = "";
    str.n = strlen(str.p);
    errorcode = SKY_cipher_SigFromHex(str, &s2);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    str.p = "cascs";
    str.n = strlen(str.p);
    errorcode = SKY_cipher_SigFromHex(str, &s2);
    ck_assert(errorcode == SKY_ErrInvalidSig);

    // Invalid hex length
    randBytes(&b, 65);
    errorcode = SKY_cipher_NewSig(b, &s);
    ck_assert(errorcode == SKY_OK);
    str.p = strBuff;
    str.n = 0;
    bytesnhex(s, (char*)str.p, 32);
    str.n = strlen(str.p);
    errorcode = SKY_cipher_SigFromHex(str, &s2);
    ck_assert(errorcode == SKY_ErrInvalidLengthSig);

    // Valid
    bytesnhex(s, (char*)str.p, 65);
    str.n = strlen(str.p);
    errorcode = SKY_cipher_SigFromHex(str, &s2);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(s2, s, 65));
}
END_TEST

START_TEST(TestSigHex)
{
    unsigned char buff[66];
    GoSlice b = {buff, 0, 66};
    char strBuff[150],
        strBuff2[150];
    GoString str = {NULL, 0},
             str2 = {NULL, 0};
    cipher__Sig s, s2;
    int errorcode;

    randBytes(&b, 65);
    errorcode = SKY_cipher_NewSig(b, &s);

    ck_assert(errorcode == SKY_OK);
    char buffer[100];
    GoString_ tmp_str = {buffer, 0};
    SKY_cipher_Sig_Hex(&s, &tmp_str);
    str.p = tmp_str.p;
    str.n = tmp_str.n;
    registerMemCleanup((void*)str.p);
    errorcode = SKY_cipher_SigFromHex(str, &s2);

    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(s, s2, 65));

    char buffer2[100];
    GoString_ tmp_str2 = {buffer, 0};
    SKY_cipher_Sig_Hex(&s2, &tmp_str);
    str2.p = tmp_str.p;
    str2.n = tmp_str.n;
    registerMemCleanup((void*)str2.p);
    // ck_assert(isGoStringEq(str, str2));
    ck_assert_str_eq(str.p, str2.p);
}
END_TEST

// FIXME: Split in multiple test cases so as to catch panic at the right place
START_TEST(TestVerifyAddressSignedHash)
{
    cipher__PubKey pk, pk2;
    cipher__SecKey sk, sk2;
    cipher__Address addr, addr2;
    unsigned char buff[257];
    GoSlice b = {buff, 0, 257};
    cipher__SHA256 h, h2;
    cipher__Sig sig, sig2;
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    errorcode = SKY_cipher_PubKey_Verify(&pk);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_OK);

    SKY_cipher_AddressFromPubKey(&pk, &addr);
    errorcode = SKY_cipher_Address_Verify(&addr, &pk);
    ck_assert(errorcode == SKY_OK);
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    SKY_cipher_SignHash(&h, &sk, &sig);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
    ck_assert(errorcode == SKY_OK);

    // Empty sig should be invalid
    memset(&sig, 0, sizeof(sig));
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
    ck_assert(errorcode == SKY_ErrInvalidSigPubKeyRecovery);

    // Random sigs should not pass
    int i;
    for (i = 0; i < 100; i++) {
        randBytes(&b, 65);
        SKY_cipher_NewSig(b, &sig);
        errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
        ck_assert(errorcode != SKY_OK); // One of many error codes
    }

    // Sig for one hash does not work for another hash
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h2);
    SKY_cipher_SignHash(&h2, &sk, &sig2);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig2, &h2);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig2, &h);
    ck_assert(errorcode == SKY_ErrInvalidAddressForSig);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h2);
    ck_assert(errorcode != SKY_OK); // One of many error codes

    // Different secret keys should not create same sig
    SKY_cipher_GenerateKeyPair(&pk2, &sk2);
    SKY_cipher_AddressFromPubKey(&pk2, &addr2);
    memset(&h, 0, sizeof(h));
    SKY_cipher_SignHash(&h, &sk, &sig);
    SKY_cipher_SignHash(&h, &sk2, &sig2);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr2, &sig2, &h);
    ck_assert(errorcode == SKY_OK);
    ck_assert_int_eq(isU8Eq(sig, sig2, 65), 0);

    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    SKY_cipher_SignHash(&h, &sk, &sig);
    SKY_cipher_SignHash(&h, &sk2, &sig2);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr2, &sig2, &h);
    ck_assert(errorcode == SKY_OK);
    ck_assert_int_eq(isU8Eq(sig, sig2, 65), 0);

    // Bad address should be invalid
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig2, &h);
    ck_assert(errorcode == SKY_ErrInvalidAddressForSig);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr2, &sig, &h);
    ck_assert(errorcode == SKY_ErrInvalidAddressForSig);
}
END_TEST

START_TEST(TestSignHash)
{
    cipher__PubKey pk, pk2;
    cipher__SecKey sk;
    cipher__Address addr;
    unsigned char buff[257];
    GoSlice b = {buff, 0, 257};
    cipher__SHA256 h;
    cipher__Sig sig, sig2;
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    SKY_cipher_AddressFromPubKey(&pk, &addr);

    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    errorcode = SKY_cipher_SignHash(&h, &sk, &sig);
    ck_assert(errorcode == SKY_OK);
    memset((void*)&sig2, 0, 65);
    ck_assert_int_eq(isU8Eq(sig, sig2, 65), 0);
    errorcode = SKY_cipher_VerifyAddressSignedHash(&addr, &sig, &h);
    ck_assert(errorcode == SKY_OK);

    errorcode = SKY_cipher_PubKeyFromSig(&sig, &h, &pk2);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(pk, pk2, 33));

    cipher__SecKey empty_sk;
    cipher__Sig temp_sig;
    memset((void*)&empty_sk, 0, 32);
    errorcode = SKY_cipher_SignHash(&h, &empty_sk, &temp_sig);
    ck_assert(errorcode == SKY_ErrInvalidSecKey);
}
END_TEST

START_TEST(TestPubKeyFromSecKey)
{
    cipher__PubKey pk, pk2;
    cipher__SecKey sk;
    unsigned char buff[101];
    GoSlice b = {buff, 0, 101};
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    errorcode = SKY_cipher_PubKeyFromSecKey(&sk, &pk2);
    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(pk, pk2, 33));

    memset(&sk, 0, sizeof(sk));
    errorcode = SKY_cipher_PubKeyFromSecKey(&sk, &pk);
    ck_assert(errorcode == SKY_ErrPubKeyFromNullSecKey);

    randBytes(&b, 99);
    errorcode = SKY_cipher_NewSecKey(b, &sk);
    ck_assert(errorcode == SKY_ErrInvalidLengthSecKey);

    randBytes(&b, 31);
    errorcode = SKY_cipher_NewSecKey(b, &sk);
    ck_assert(errorcode == SKY_ErrInvalidLengthSecKey);
}
END_TEST

START_TEST(TestPubKeyFromSig)
{
    cipher__PubKey pk, pk2;
    cipher__SecKey sk;
    cipher__SHA256 h;
    cipher__Sig sig;
    unsigned char buff[257];
    GoSlice b = {buff, 0, 257};
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);

    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    SKY_cipher_SignHash(&h, &sk, &sig);
    errorcode = SKY_cipher_PubKeyFromSig(&sig, &h, &pk2);

    ck_assert(errorcode == SKY_OK);
    ck_assert(isU8Eq(pk, pk2, 33));

    memset(&sig, 0, sizeof(sig));
    errorcode = SKY_cipher_PubKeyFromSig(&sig, &h, &pk2);
    ck_assert(errorcode == SKY_ErrInvalidSigPubKeyRecovery);
}
END_TEST

START_TEST(TestVerifyPubKeySignedHash)
{
    cipher__PubKey pk, pk2;
    cipher__SecKey sk, sk2;
    cipher__SHA256 h, h2;
    cipher__Sig sig, sig2;
    unsigned char buff[257];
    GoSlice b = {buff, 0, 257};
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h2);
    SKY_cipher_SignHash(&h, &sk, &sig);
    errorcode = SKY_cipher_VerifyPubKeySignedHash(&pk, &sig, &h);
    ck_assert(errorcode == SKY_OK);

    memset(&sig2, 0, sizeof(sig2));
    errorcode = SKY_cipher_VerifyPubKeySignedHash(&pk, &sig2, &h);
    ck_assert(errorcode == SKY_ErrInvalidSigPubKeyRecovery);

    errorcode = SKY_cipher_VerifyPubKeySignedHash(&pk, &sig, &h2);
    ck_assert(errorcode == SKY_ErrPubKeyRecoverMismatch);

    SKY_cipher_GenerateKeyPair(&pk2, &sk2);
    errorcode = SKY_cipher_VerifyPubKeySignedHash(&pk2, &sig, &h);
    ck_assert(errorcode == SKY_ErrPubKeyRecoverMismatch);

    memset(&pk2, 0, sizeof(pk2));
    errorcode = SKY_cipher_VerifyPubKeySignedHash(&pk2, &sig, &h);
    ck_assert(errorcode == SKY_ErrPubKeyRecoverMismatch);
}
END_TEST


START_TEST(TestGenerateKeyPair)
{
    cipher__PubKey pk;
    cipher__SecKey sk;
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    errorcode = SKY_cipher_PubKey_Verify(&pk);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_OK);
}
END_TEST

START_TEST(TestGenerateDeterministicKeyPair)
{
    cipher__PubKey pk;
    cipher__SecKey sk;
    unsigned char buff[33];
    GoSlice seed = {buff, 0, 33};
    int errorcode;

    // TODO -- deterministic key pairs are useless as is because we can't
    // generate pair n+1, only pair 0
    randBytes(&seed, 32);
    SKY_cipher_GenerateDeterministicKeyPair(seed, &pk, &sk);
    errorcode = SKY_cipher_PubKey_Verify(&pk);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_OK);

    SKY_cipher_GenerateDeterministicKeyPair(seed, &pk, &sk);
    errorcode = SKY_cipher_PubKey_Verify(&pk);
    ck_assert(errorcode == SKY_OK);
    errorcode = SKY_cipher_SecKey_Verify(&sk);
    ck_assert(errorcode == SKY_OK);
}
END_TEST

START_TEST(TestSecKeTest)
{
    cipher__PubKey pk;
    cipher__SecKey sk;
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    errorcode = SKY_cipher_CheckSecKey(&sk);
    ck_assert(errorcode == SKY_OK);

    memset(&sk, 0, sizeof(sk));
    errorcode = SKY_cipher_CheckSecKey(&sk);
    ck_assert(errorcode == SKY_ErrInvalidSecKyVerification);
}
END_TEST

START_TEST(TestSecKeyHashTest)
{
    cipher__PubKey pk;
    cipher__SecKey sk;
    cipher__SHA256 h;
    unsigned char buff[257];
    GoSlice b = {buff, 0, 257};
    int errorcode;

    SKY_cipher_GenerateKeyPair(&pk, &sk);
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h);
    errorcode = SKY_cipher_CheckSecKeyHash(&sk, &h);
    ck_assert(errorcode == SKY_OK);

    memset(&sk, 0, sizeof(sk));
    errorcode = SKY_cipher_CheckSecKeyHash(&sk, &h);
    ck_assert(errorcode == SKY_ErrInvalidSecKyVerification);
}
END_TEST

Suite* cipher_crypto(void)
{
    Suite* s = suite_create("Load cipher.crypto");
    TCase* tc;

    tc = tcase_create("cipher.crypto");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestNewPubKey);
    tcase_add_test(tc, TestPubKeyFromHex);
    tcase_add_test(tc, TestPubKeyHex);
    tcase_add_test(tc, TestPubKeyVerify);
    tcase_add_test(tc, TestPubKeyVerifyNil);
    tcase_add_test(tc, TestPubKeyVerifyDefault1);
    tcase_add_test(tc, TestPubKeyRipemd160);
    tcase_add_test(tc, TestPubKeyToAddress2);
    tcase_add_test(tc, TestSecKeyFromHex);
    tcase_add_test(tc, TestMustSecKeyFromHex);
    tcase_add_test(tc, TestSecKeyVerify);
    tcase_add_test(tc, TestECDHonce);
    tcase_add_test(tc, TestECDHloop);
    tcase_add_test(tc, TestNewSig);
    tcase_add_test(tc, TestMustSigFromHex);
    tcase_add_test(tc, TestSigHex);
    tcase_add_test(tc, TestVerifyAddressSignedHash);
    tcase_add_test(tc, TestPubKeyFromSecKey);
    tcase_add_test(tc, TestPubKeyFromSig);
    tcase_add_test(tc, TestVerifyPubKeySignedHash);
    tcase_add_test(tc, TestGenerateDeterministicKeyPair);
    tcase_add_test(tc, TestSecKeTest);
    tcase_add_test(tc, TestSecKeyHashTest);
    tcase_add_test(tc, TestGenerateKeyPair);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}