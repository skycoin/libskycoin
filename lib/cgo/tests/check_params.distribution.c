#include <stdio.h>
#include <stdlib.h>

#include <check.h>
#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"

// TestSuite(params_distribution, .init = setup, .fini = teardown);

START_TEST(TestDistributionAddressArrays)
{
    GoSlice all = {NULL, 0, 0};
    GoSlice unlocked = {NULL, 0, 0};
    GoSlice locked = {NULL, 0, 0};

    SKY_params_GetDistributionAddresses((GoSlice_ *)&all);
    ck_assert(all.len == 100);

    // At the time of this writing, there should be 25 addresses in the
    // unlocked pool and 75 in the locked pool.
    SKY_params_GetUnlockedDistributionAddresses((GoSlice_ *)&unlocked);
    ck_assert(unlocked.len == 25);
    SKY_params_GetLockedDistributionAddresses((GoSlice_ *)&locked);
    ck_assert(locked.len == 75);

    int i, j, k;
    GoString *iStr, *jStr, *kStr;
    int notfound;

    for (i = 0, iStr = (GoString *)all.data; i < all.len; ++i, ++iStr)
    {
        // Check no duplicate address in distribution addresses
        for (j = i + 1, jStr = iStr + 1; j < all.len; ++j, ++jStr)
        {
            ck_assert(isGoStringEq(*iStr, *jStr) == 1);
        }
    }

    for (i = 0, iStr = (GoString *)unlocked.data; i < unlocked.len; ++i, ++iStr)
    {
        // Check no duplicate address in unlocked addresses
        for (j = i + 1, jStr = iStr + 1; j < unlocked.len; ++j, ++jStr)
        {
            ck_assert(isGoStringEq(*iStr, *jStr) == 1);
        }

        // Check unlocked address in set of all addresses
        for (k = 0, notfound = 1, kStr = (GoString *)all.data; notfound && (k < all.len); ++k, ++kStr)
        {
            notfound = isGoStringEq(*iStr, *kStr);
        }
        ck_assert(notfound == 0);
    }

    for (i = 0, iStr = (GoString *)locked.data; i < locked.len; ++i, ++iStr)
    {
        // Check no duplicate address in locked addresses
        for (j = i + 1, jStr = iStr + 1; j < locked.len; ++j, ++jStr)
        {
            ck_assert(isGoStringEq(*iStr, *jStr) == 1);
        }

        // Check locked address in set of all addresses
        for (k = 0, notfound = 1, kStr = (GoString *)all.data; notfound && k < all.len; ++k, ++kStr)
        {
            notfound = isGoStringEq(*iStr, *kStr);
        }
        ck_assert(notfound == 0);

        // Check locked address not in set of unlocked addresses
        for (k = 0, notfound = 1, kStr = (GoString *)unlocked.data; notfound && k < unlocked.len; ++k, ++kStr)
        {
            ck_assert(isGoStringEq(*iStr, *kStr) == 1);
        }
    }
}
END_TEST

Suite *param_distribution(void)
{
    Suite *s = suite_create("Load param.Distribution");
    TCase *tc;

    tc = tcase_create("params.distribution");
    tcase_add_test(tc, TestDistributionAddressArrays);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);
    return s;
}