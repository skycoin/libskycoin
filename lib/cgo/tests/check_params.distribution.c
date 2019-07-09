#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>


START_TEST(TestDistributionAddressArrays)
{
    coin__UxArray all = {NULL, 0, 0};
    coin__UxArray unlocked = {NULL, 0, 0};
    coin__UxArray locked = {NULL, 0, 0};

    SKY_params_GetDistributionAddresses(&all);
    ck_assert(all.len == 100);

    // At the time of this writing, there should be 25 addresses in the
    // unlocked pool and 75 in the locked pool.
    SKY_params_GetUnlockedDistributionAddresses(&unlocked);
    ck_assert(unlocked.len == 25);
    SKY_params_GetLockedDistributionAddresses(&locked);
    ck_assert(locked.len == 75);

    int i, j, k;
    GoString *iStr, *jStr, *kStr;
    int notfound;

    for (i = 0, iStr = (GoString*)all.data; i < all.len; ++i, ++iStr) {
        // Check no duplicate address in distribution addresses
        for (j = i + 1, jStr = iStr + 1; j < all.len; ++j, ++jStr) {
            ck_assert_str_ne((char*)iStr->p, (char*)jStr->p);
        }
    }

    for (i = 0, iStr = (GoString*)unlocked.data; i < unlocked.len; ++i, ++iStr) {
        // Check no duplicate address in unlocked addresses
        for (j = i + 1, jStr = iStr + 1; j < unlocked.len; ++j, ++jStr) {
            ck_assert_str_ne((char*)iStr->p, (char*)jStr->p);
        }

        // Check unlocked address in set of all addresses
        for (k = 0, notfound = 1, kStr = (GoString*)all.data; notfound && (k < all.len); ++k, ++kStr) {
            notfound = strcmp(iStr->p, kStr->p);
        }
        ck_assert(notfound == 0);
    }

    for (i = 0, iStr = (GoString*)locked.data; i < locked.len; ++i, ++iStr) {
        // Check no duplicate address in locked addresses
        for (j = i + 1, jStr = iStr + 1; j < locked.len; ++j, ++jStr) {
            ck_assert_str_ne((char*)iStr->p, (char*)jStr->p);
        }

        // Check locked address in set of all addresses
        for (k = 0, notfound = 1, kStr = (GoString*)all.data; notfound && k < all.len; ++k, ++kStr) {
            notfound = strcmp(iStr->p, kStr->p);
        }
        ck_assert(notfound == 0);

        // Check locked address not in set of unlocked addresses
        for (k = 0, notfound = 1, kStr = (GoString*)unlocked.data; notfound && k < unlocked.len; ++k, ++kStr) {
            // ck_assert_str_ne((char *)iStr->p, (char *)jStr->p);
        }
    }
}
END_TEST

Suite* param_distribution(void)
{
    Suite* s = suite_create("Load param.Distribution");
    TCase* tc;

    tc = tcase_create("params.distribution");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestDistributionAddressArrays);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);
    return s;
}