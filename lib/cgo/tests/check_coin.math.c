#include <stdio.h>
#include <string.h>

// #include <criterion/criterion.h>
// #include <criterion/new/assert.h>
#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

// TestSuite(coin_math, .init = setup, .fini = teardown);

START_TEST(TestAddUint64)
{
    int result;
    GoUint64 r;
    result = SKY_coin_AddUint64(10, 11, &r);
    ck_assert(result == SKY_OK);
    ck_assert(r == 21);
    GoUint64 maxUint64 = 0xFFFFFFFFFFFFFFFF;
    GoUint64 one = 1;
    result = SKY_coin_AddUint64(maxUint64, one, &r);
    ck_assert(result == SKY_ErrUint64AddOverflow);
}
END_TEST

typedef struct
{
    GoUint64 a;
    GoInt64 b;
    int failure;
} math_tests;

START_TEST(TestUint64ToInt64)
{
    int result;
    GoInt64 r;
    GoUint64 maxUint64 = 0xFFFFFFFFFFFFFFFF;
    GoInt64 maxInt64 = 0x7FFFFFFFFFFFFFFF;

    math_tests tests[] = {
        {0, 0, 0},
        {1, 1, 0},
        {maxInt64, maxInt64, 0},
        {maxUint64, 0, 1},
        //This is reset to zero in C, and it doesn't fail
        //{maxUint64 + 1, 0, 1},
    };
    int tests_count = sizeof(tests) / sizeof(math_tests);
    int i;
    for (i = 0; i < tests_count; i++) {
        result = SKY_coin_Uint64ToInt64(tests[i].a, &r);
        if (tests[i].failure) {
            ck_assert_msg(result == SKY_ErrUint64OverflowsInt64, "Failed test # %d", i + 1);
        } else {
            ck_assert_msg(result == SKY_OK, "Failed test # %d", i + 1);
            ck_assert(tests[i].b == r);
        }
    }
}
END_TEST

Suite* coin_math(void)
{
    Suite* s = suite_create("Load coin.math");
    TCase* tc;

    tc = tcase_create("coin.math");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestAddUint64);
    tcase_add_test(tc, TestUint64ToInt64);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}