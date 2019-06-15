#include <stdio.h>
#include <stdlib.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

START_TEST(Test_Abnormal_Keys2)
{
   
}
END_TEST

Suite* cipher_secp256k1(void)
{
    Suite* s = suite_create("Load cipher.secp256k1");
    TCase* tc;

    tc = tcase_create("cipher.secp256k1");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, Test_Abnormal_Keys2);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}