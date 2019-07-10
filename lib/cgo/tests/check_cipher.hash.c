#include <stdio.h>
#include <stdlib.h>

#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

void freshSumRipemd160(GoSlice bytes, cipher__Ripemd160* rp160)
{
    SKY_cipher_HashRipemd160(bytes, rp160);
}

void freshSumSHA256(GoSlice bytes, cipher__SHA256* sha256)
{
    SKY_cipher_SumSHA256(bytes, sha256);
}

START_TEST(TestHashRipemd160)
{
    cipher__Ripemd160 tmp;
    cipher__Ripemd160 r;
    cipher__Ripemd160 r2;
    unsigned char buff[257];
    GoSlice slice = {buff, 0, 257};

    randBytes(&slice, 128);
    SKY_cipher_HashRipemd160(slice, &tmp);
    randBytes(&slice, 160);
    SKY_cipher_HashRipemd160(slice, &r);
    ck_assert_int_eq(isU8Eq(tmp, r, sizeof(cipher__Ripemd160)), 0);

    unsigned char buff1[257];
    GoSlice b = {buff1, 0, 257};
    randBytes(&b, 256);
    SKY_cipher_HashRipemd160(b, &r2);
    ck_assert_int_eq(isU8Eq(tmp, r2, sizeof(cipher__Ripemd160)), 0);
    freshSumRipemd160(b, &tmp);
    ck_assert(isU8Eq(tmp, r2, sizeof(cipher__Ripemd160)));
}
END_TEST

START_TEST(TestRipemd160Set)
{
    cipher__Ripemd160 h;
    unsigned char buff[101];
    GoSlice slice = {buff, 0, 101};
    int error;

    memset(h, 0, sizeof(cipher__Ripemd160));
    randBytes(&slice, 21);

    error = SKY_cipher_Ripemd160_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthRipemd160);

    randBytes(&slice, 100);
    error = SKY_cipher_Ripemd160_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthRipemd160);

    randBytes(&slice, 19);
    error = SKY_cipher_Ripemd160_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthRipemd160);

    randBytes(&slice, 0);
    error = SKY_cipher_Ripemd160_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthRipemd160);

    randBytes(&slice, 20);
    error = SKY_cipher_Ripemd160_Set(&h, slice);
    ck_assert(error == SKY_OK);
    ck_assert(isU8Eq(h, buff, 20));
}
END_TEST

START_TEST(TestSHA256Set)
{
    cipher__SHA256 h;
    unsigned char buff[101];
    GoSlice slice = {buff, 0, 101};
    int error;

    randBytes(&slice, 33);
    error = SKY_cipher_SHA256_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthSHA256);

    randBytes(&slice, 100);
    error = SKY_cipher_SHA256_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthSHA256);

    randBytes(&slice, 31);
    error = SKY_cipher_SHA256_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthSHA256);

    randBytes(&slice, 0);
    error = SKY_cipher_SHA256_Set(&h, slice);
    ck_assert(error == SKY_ErrInvalidLengthSHA256);

    randBytes(&slice, 32);
    error = SKY_cipher_SHA256_Set(&h, slice);
    ck_assert(error == SKY_OK);
    ck_assert(isU8Eq(h, slice.data, 32));
}
END_TEST

START_TEST(TestSHA256Hex)
{
    cipher__SHA256 h;
    unsigned char buff[101];
    GoSlice slice = {buff, 0, 101};
    int error;

    memset(&h, 0, sizeof(h));
    randBytes(&slice, 32);
    SKY_cipher_SHA256_Set(&h, slice);
    GoString_ s;

    SKY_cipher_SHA256_Hex(&h, &s);
    registerMemCleanup((void*)s.p);

    cipher__SHA256 h2;
    GoString tmpS = {s.p, s.n};
    error = SKY_cipher_SHA256FromHex(tmpS, &h2);
    ck_assert(error == SKY_OK);
    ck_assert(isU8Eq(h, h2, 32));

    GoString_ s2;
    SKY_cipher_SHA256_Hex(&h2, &s2);
    registerMemCleanup((void*)s2.p);
    ck_assert_str_eq(s.p, s2.p);
}
END_TEST

START_TEST(TestSHA256KnownValue)
{
    typedef struct
    {
        char* input;
        char* output;
    } tmpstruct;

    tmpstruct vals[3];

    vals[0].input = "skycoin";
    vals[0].output =
        "5a42c0643bdb465d90bf673b99c14f5fa02db71513249d904573d2b8b63d353d";

    vals[1].input = "hello world";
    vals[1].output =
        "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9";

    vals[2].input = "hello world asd awd awd awdapodawpokawpod ";
    vals[2].output =
        "99d71f95cafe05ea2dddebc35b6083bd5af0e44850c9dc5139b4476c99950be4";
    int i;
    for (i = 0; i < 3; ++i) {
        GoSlice slice_input;
        GoSlice slice_output;

        slice_input.data = vals[i].input;
        slice_input.len = strlen(vals[i].input);
        slice_input.cap = strlen(vals[i].input) + 1;

        cipher__SHA256 sha;

        SKY_cipher_SumSHA256(slice_input, &sha);

        GoString_ tmp_output;

        SKY_cipher_SHA256_Hex(&sha, &tmp_output);
        registerMemCleanup((void*)tmp_output.p);

        ck_assert(strcmp(tmp_output.p, vals[i].output) == SKY_OK);
    }
}
END_TEST

START_TEST(TestSumSHA256)
{
    GoUint8 bbuff[257];
    GoUint8 cbuff[257];
    GoSlice b = {bbuff, 0, 257};
    cipher__SHA256 h1;
    randBytes(&b, 256);
    SKY_cipher_SumSHA256(b, &h1);
    cipher__SHA256 tmp = "";
    ck_assert_int_eq(isU8Eq(h1, tmp, 32), 0);
    GoSlice c = {cbuff, 0, 257};
    randBytes(&c, 256);
    cipher__SHA256 h2;
    SKY_cipher_SumSHA256(c, &h2);
    ck_assert_int_eq(isU8Eq(h1, tmp, 32), 0);
    cipher__SHA256 tmp_h2;
    freshSumSHA256(c, &tmp_h2);
    ck_assert(isU8Eq(h2, tmp_h2, 32));
}
END_TEST

START_TEST(TestSHA256FromHex)
{
    unsigned int error;
    cipher__SHA256 tmp;
    // Invalid hex hash
    GoString tmp_string = {"cawcd", 5};
    error = SKY_cipher_SHA256FromHex(tmp_string, &tmp);
    ck_assert(error == SKY_ERROR);
    // Truncated hex hash
    cipher__SHA256 h;
    unsigned char buff[130];
    char sbuff[300];
    GoSlice slice = {buff, 0, 130};
    randBytes(&slice, 128);
    SKY_cipher_SumSHA256(slice, &h);
    bytesnhex(h, sbuff, sizeof(h) >> 1);
    GoString s1 = {sbuff, strlen(sbuff)};
    error = SKY_cipher_SHA256FromHex(s1, &h);
    ck_assert(error == SKY_ErrInvalidHexLength);

    // Valid hex hash
    GoString_ s2;
    memset(&s2, 0, sizeof(GoString_));
    SKY_cipher_SHA256_Hex(&h, &s2);
    registerMemCleanup((void*)s2.p);
    cipher__SHA256 h2;
    GoString tmps2 = {s2.p, s2.n};
    error = SKY_cipher_SHA256FromHex(tmps2, &h2);
    ck_assert(error == SKY_OK);
    ck_assert(isU8Eq(h, h2, 32));
}
END_TEST

START_TEST(TestDoubleSHA256)
{
    unsigned char bbuff[130];
    GoSlice b = {bbuff, 0, 130};
    randBytes(&b, 128);
    cipher__SHA256 h;
    cipher__SHA256 tmp;
    SKY_cipher_DoubleSHA256(b, &h);
    ck_assert_int_eq(isU8Eq(tmp, h, 32), 0);
    freshSumSHA256(b, &tmp);
    ck_assert_int_eq(isU8Eq(tmp, h, 32), 0);
}
END_TEST

START_TEST(TestAddSHA256)
{
    unsigned char bbuff[130];
    GoSlice b = {bbuff, 0, 130};
    randBytes(&b, 128);
    cipher__SHA256 h;
    SKY_cipher_SumSHA256(b, &h);

    unsigned char cbuff[130];
    GoSlice c = {cbuff, 0, 130};
    randBytes(&c, 64);
    cipher__SHA256 i;
    SKY_cipher_SumSHA256(c, &i);

    cipher__SHA256 add;
    cipher__SHA256 tmp;

    SKY_cipher_AddSHA256(&h, &i, &add);
    ck_assert_int_eq(isU8Eq(add, tmp, 32), 0);
    ck_assert_int_eq(isU8Eq(add, h, 32), 0);
    ck_assert_int_eq(isU8Eq(add, i, 32), 0);
}
END_TEST

START_TEST(TestXorSHA256)
{
    unsigned char bbuff[129], cbuff[129];
    GoSlice b = {bbuff, 0, 129};
    GoSlice c = {cbuff, 0, 129};
    cipher__SHA256 h, i;

    randBytes(&b, 128);
    SKY_cipher_SumSHA256(b, &h);
    randBytes(&c, 128);
    SKY_cipher_SumSHA256(c, &i);

    cipher__SHA256 tmp_xor1;
    cipher__SHA256 tmp_xor2;
    cipher__SHA256 tmp;

    SKY_cipher_SHA256_Xor(&h, &i, &tmp_xor1);
    SKY_cipher_SHA256_Xor(&i, &h, &tmp_xor2);
    ck_assert_int_eq(isU8Eq(tmp_xor1, h, 32), 0);
    ck_assert_int_eq(isU8Eq(tmp_xor1, i, 32), 0);
    ck_assert_int_eq(isU8Eq(tmp_xor1, tmp, 32), 0);
    ck_assert(isU8Eq(tmp_xor1, tmp_xor2, 32));
}
END_TEST

START_TEST(TestMerkle)
{
    unsigned char buff[129];
    cipher__SHA256 hashlist[5];
    GoSlice b = {buff, 0, 129}, hashes = {hashlist, 0, 5};
    cipher__SHA256 h, zero, out, out1, out2, out3, out4;
    int i;

    memset(zero, 0, sizeof(zero));

    for (i = 0; i < 5; i++) {
        randBytes(&b, 128);
        SKY_cipher_SumSHA256(b, &hashlist[i]);
    }

    // Single hash input returns hash
    hashes.len = 1;
    SKY_cipher_Merkle(&hashes, &h);
    ck_assert(isU8Eq(hashlist[0], h, 32));

    // 2 hashes should be Addcipher__SHA256 of them
    hashes.len = 2;
    SKY_cipher_AddSHA256(&hashlist[0], &hashlist[1], &out);
    SKY_cipher_Merkle(&hashes, &h);
    ck_assert(isU8Eq(out, h, 32));

    // 3 hashes should be Add(Add())
    hashes.len = 3;
    SKY_cipher_AddSHA256(&hashlist[0], &hashlist[1], &out1);
    SKY_cipher_AddSHA256(&hashlist[2], &zero, &out2);
    SKY_cipher_AddSHA256(&out1, &out2, &out);
    SKY_cipher_Merkle(&hashes, &h);
    ck_assert(isU8Eq(out, h, 32));

    // 4 hashes should be Add(Add())
    hashes.len = 4;
    SKY_cipher_AddSHA256(&hashlist[0], &hashlist[1], &out1);
    SKY_cipher_AddSHA256(&hashlist[2], &hashlist[3], &out2);
    SKY_cipher_AddSHA256(&out1, &out2, &out);
    SKY_cipher_Merkle(&hashes, &h);
    ck_assert(isU8Eq(out, h, 32));

    // 5 hashes
    hashes.len = 5;
    SKY_cipher_AddSHA256(&hashlist[0], &hashlist[1], &out1);
    SKY_cipher_AddSHA256(&hashlist[2], &hashlist[3], &out2);
    SKY_cipher_AddSHA256(&out1, &out2, &out3);
    SKY_cipher_AddSHA256(&hashlist[4], &zero, &out1);
    SKY_cipher_AddSHA256(&zero, &zero, &out2);
    SKY_cipher_AddSHA256(&out1, &out2, &out4);
    SKY_cipher_AddSHA256(&out3, &out4, &out);
    SKY_cipher_Merkle(&hashes, &h);
    ck_assert(isU8Eq(out, h, 32));
}
END_TEST

START_TEST(TestSHA256Null)
{
    cipher__SHA256 x;
    memset(&x, 0, sizeof(cipher__SHA256));
    GoUint32 result;
    GoUint8 isNull;
    ck_assert(SKY_cipher_SHA256_Null(&x, &isNull) == SKY_OK);
    ck_assert(isNull);
    char buff[130];
    GoSlice b = {buff, 0, 129};
    randBytes(&b, 128);
    ck_assert(SKY_cipher_SumSHA256(b, &x) == SKY_OK);
    ck_assert(SKY_cipher_SHA256_Null(&x, &isNull) == SKY_OK);
    ck_assert(isNull == 0);
}
END_TEST

Suite* cipher_hash(void)
{
    Suite* s = suite_create("Load cipher.hash");
    TCase* tc;

    tc = tcase_create("cipher.hash");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestHashRipemd160);
    tcase_add_test(tc, TestRipemd160Set);
    tcase_add_test(tc, TestSHA256Set);
    tcase_add_test(tc, TestSHA256Hex);
    tcase_add_test(tc, TestSHA256KnownValue);
    tcase_add_test(tc, TestSumSHA256);
    tcase_add_test(tc, TestSHA256FromHex);
    tcase_add_test(tc, TestDoubleSHA256);
    tcase_add_test(tc, TestAddSHA256);
    tcase_add_test(tc, TestXorSHA256);
    tcase_add_test(tc, TestMerkle);
    tcase_add_test(tc, TestSHA256Null);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}
