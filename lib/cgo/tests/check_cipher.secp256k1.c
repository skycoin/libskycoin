#include <stdio.h>
#include <stdlib.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

GoString _testSeckey[] = {
    {"08efb79385c9a8b0d1c6f5f6511be0c6f6c2902963d874a3a4bacc18802528d3", 64},
    {"78298d9ecdc0640c9ae6883201a53f4518055442642024d23c45858f45d0c3e6", 64},
    {"04e04fe65bfa6ded50a12769a3bd83d7351b2dbff08c9bac14662b23a3294b9e", 64},
    {"2f5141f1b75747996c5de77c911dae062d16ae48799052c04ead20ccd5afa113", 64},
};

START_TEST(Test_Abnormal_Keys2)
{
    for (size_t i = 0; i < 4; i++) {
        GoUint8_ buffer_seckey[1024];
        coin__UxArray seckey1 = {buffer_seckey, 0, 1024};
        GoUint32_ err;
        err = SKY_base58_String2Hex(_testSeckey[i], &seckey1);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoUint8_ buffer_pubkey[1024];
        GoSlice seckey_slice = {seckey1.data, seckey1.len, seckey1.cap};
        coin__UxArray pubkey1 = {buffer_pubkey, 0, 1024};
        err = SKY_secp256k1_PubkeyFromSeckey(seckey_slice, &pubkey1);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoSlice pubkey_slice = {pubkey1.data, pubkey1.len, pubkey1.cap};
        err = SKY_secp256k1_VerifyPubkey(pubkey_slice);
        ck_assert_msg(err == 1, "generates key that fails validation in ite #%d", i);
    }
}
END_TEST

START_TEST(Test_Abnormal_Keys3)
{
    for (size_t i = 0; i < 4; i++) {
        GoUint8_ buffer_seckey[1024];
        coin__UxArray seckey1 = {buffer_seckey, 0, 1024};
        GoUint32 err;
        err = SKY_base58_String2Hex(_testSeckey[i], &seckey1);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoUint8_ buffer_pubkey[1024];
        GoSlice seckey_slice = {seckey1.data, seckey1.len, seckey1.cap};
        coin__UxArray pubkey1 = {buffer_pubkey, 0, 1024};
        err = SKY_secp256k1_PubkeyFromSeckey(seckey_slice, &pubkey1);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoSlice pubkey1_slice = {pubkey1.data, pubkey1.len, pubkey1.cap};
        GoInt n = rand() % 4;

        GoUint8_ buffer_seckey2[1024];
        coin__UxArray seckey2 = {buffer_seckey, 0, 1024};
        err = SKY_base58_String2Hex(_testSeckey[n], &seckey2);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoUint8_ buffer_pubkey2[1024];
        GoSlice seckey2_slice = {seckey2.data, seckey2.len, seckey2.cap};
        coin__UxArray pubkey2 = {buffer_pubkey2, 0, 1024};
        err = SKY_secp256k1_PubkeyFromSeckey(seckey2_slice, &pubkey2);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        GoSlice pubkey2_slice = {pubkey2.data, pubkey2.len, pubkey2.cap};
        GoUint8 buffer_puba[1024];
        coin__UxArray puba = {buffer_puba, 0, 1024};
        GoUint8 buffer_pubb[1024];
        coin__UxArray pubb = {buffer_pubb, 0, 1024};
        err = SKY_secp256k1_ECDH(pubkey1_slice, seckey2_slice, &puba);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
        err = SKY_secp256k1_ECDH(pubkey2_slice, seckey_slice, &pubb);
        ck_assert_msg(err == SKY_OK, "Fail in iteration %d, err %x != %x", i, err, SKY_OK);
    }
}
END_TEST
Suite*
cipher_secp256k1(void)
{
    Suite* s = suite_create("Load cipher.secp256k1");
    TCase* tc;

    tc = tcase_create("cipher.secp256k1");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, Test_Abnormal_Keys2);
    tcase_add_test(tc, Test_Abnormal_Keys3);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}