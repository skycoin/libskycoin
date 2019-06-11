#include <stdio.h>
#include <string.h>

// #include <criterion/criterion.h>
// #include <criterion/new/assert.h>
#include <check.h>

#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytxn.h"

// TestSuite(coin_outputs, .init = setup, .fini = teardown);

START_TEST(TestUxBodyHash)
{
    GoUint32 result;
    coin__UxBody uxbody;
    result = makeUxBody(&uxbody);
    ck_assert_msg(result == SKY_OK, "makeUxBody failed");
    cipher__SHA256 hash;
    memset(&hash, 0, sizeof(cipher__SHA256));
    result = SKY_coin_UxBody_Hash(&uxbody, &hash);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxBody_Hash failed");
    cipher__SHA256 nullHash = "";
    ck_assert(!isU8Eq(nullHash, hash, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestUxOutHash)
{
    int result;
    coin__UxBody uxbody;
    result = makeUxBody(&uxbody);
    ck_assert_msg(result == SKY_OK, "makeUxBody failed");

    coin__UxOut uxout;
    memset(&uxout, 0, sizeof(coin__UxOut));
    memcpy(&uxout.Body, &uxbody, sizeof(coin__UxBody));

    cipher__SHA256 hashBody, hashOut;
    result = SKY_coin_UxBody_Hash(&uxbody, &hashBody);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxBody_Hash failed");
    result = SKY_coin_UxOut_Hash(&uxout, &hashOut);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
    ck_assert(isU8Eq(hashBody, hashOut, sizeof(cipher__SHA256)));

    //Head should not affect hash
    uxout.Head.Time = 0;
    uxout.Head.BkSeq = 1;
    result = SKY_coin_UxOut_Hash(&uxout, &hashOut);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
    ck_assert(isU8Eq(hashBody, hashOut, sizeof(cipher__SHA256)));
}
END_TEST

START_TEST(TestUxOutSnapshotHash)
{
    GoUint32 result;
    coin__UxOut uxout, uxout2;
    result = makeUxOut(&uxout);
    ck_assert_msg(result == SKY_OK, "makeUxOut failed");
    cipher__SHA256 hash1, hash2;
    result = SKY_coin_UxOut_SnapshotHash(&uxout, &hash1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    uxout2.Head.Time = 20;
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(!isU8Eq(hash1, hash2, sizeof(cipher__SHA256)), "SKY_coin_UxOut_SnapshotHash failed");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    uxout2.Head.BkSeq = 4;
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");
    ck_assert_msg((!isU8Eq(hash1, hash2, sizeof(cipher__SHA256))), "Snapshot hash must be different");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    makeRandHash(&uxout2.Body.SrcTransaction);
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");
    ck_assert_msg((!isU8Eq(hash1, hash2, sizeof(cipher__SHA256))), "Snapshot hash must be different");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    makeAddress(&uxout2.Body.Address);
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");
    ck_assert_msg((!isU8Eq(hash1, hash2, sizeof(cipher__SHA256))), "Snapshot hash must be different");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    uxout2.Body.Coins = uxout.Body.Coins * 2;
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");
    ck_assert_msg((!isU8Eq(hash1, hash2, sizeof(cipher__SHA256))), "Snapshot hash must be different");

    memcpy(&uxout2, &uxout, sizeof(coin__UxOut));
    uxout2.Body.Hours = uxout.Body.Hours * 2;
    result = SKY_coin_UxOut_SnapshotHash(&uxout2, &hash2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_SnapshotHash failed");
    ck_assert_msg((!isU8Eq(hash1, hash2, sizeof(cipher__SHA256))), "Snapshot hash must be different");
}
END_TEST

START_TEST(TestUxOutCoinHours)
{
    GoUint64 _genCoins = 1000000000;
    GoUint64 _genCoinHours = 1000 * 1000;

    int result;
    coin__UxOut ux;
    result = makeUxOut(&ux);
    ck_assert_msg(result == SKY_OK, "makeUxOut failed");

    GoUint64 now, hours;

    //Less than an hour passed
    now = ux.Head.Time + 100;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours);

    //An hour passed
    now = ux.Head.Time + 3600;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + ux.Body.Coins / 1000000);

    //6 hours passed
    now = ux.Head.Time + 3600 * 6;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + (ux.Body.Coins / 1000000) * 6);

    //Time is backwards (treated as no hours passed)
    now = ux.Head.Time / 2;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours);

    //1 hour has passed, output has 1.5 coins, should gain 1 coinhour
    ux.Body.Coins = 1500000;
    now = ux.Head.Time + 3600;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + 1);

    //2 hours have passed, output has 1.5 coins, should gain 3 coin hours
    ux.Body.Coins = 1500000;
    now = ux.Head.Time + 3600 * 2;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + 3);

    //1 second has passed, output has 3600 coins, should gain 1 coin hour
    ux.Body.Coins = 3600000000;
    now = ux.Head.Time + 1;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + 1);

    //1000000 hours minus 1 second have passed, output has 1 droplet, should gain 0 coin hour
    ux.Body.Coins = 1;
    now = ux.Head.Time + (GoUint64)(1000000) * (GoUint64)(3600) - 1;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours);

    //1000000 hours have passed, output has 1 droplet, should gain 1 coin hour
    ux.Body.Coins = 1;
    now = ux.Head.Time + (GoUint64)(1000000) * (GoUint64)(3600);
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + 1);

    // No hours passed, using initial coin hours
    ux.Body.Coins = _genCoins;
    ux.Body.Hours = _genCoinHours;
    now = ux.Head.Time;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours);

    // One hour passed, using initial coin hours
    now = ux.Head.Time + 3600;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == ux.Body.Hours + _genCoins / 1000000);

    // No hours passed and no hours to begin with0
    ux.Body.Hours = 0;
    now = ux.Head.Time;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(hours == 0);

    // Centuries have passed, time-based calculation overflows uint64
    // when calculating the whole coin seconds
    ux.Body.Coins = 2000000;
    now = 0xFFFFFFFFFFFFFFFF;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_ERROR, "SKY_coin_UxOut_CoinHours should fail");

    // Centuries have passed, time-based calculation overflows uint64
    // when calculating the droplet seconds
    ux.Body.Coins = 1500000;
    now = 0xFFFFFFFFFFFFFFFF;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_ERROR, "SKY_coin_UxOut_CoinHours should fail");

    // Output would overflow if given more hours, has reached its limit
    ux.Body.Coins = 3600000000;
    now = 0xFFFFFFFFFFFFFFFE;
    result = SKY_coin_UxOut_CoinHours(&ux, now, &hours);
    ck_assert_msg(result == SKY_ERROR, "SKY_coin_UxOut_CoinHours should fail");
}
END_TEST

START_TEST(TestUxArrayCoins)
{
    coin__UxArray uxs;
    int result = makeUxArray(&uxs, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    GoUint64 coins;
    result = SKY_coin_UxArray_Coins(&uxs, &coins);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Coins failed");
    ck_assert(coins == 4000000);
    coin__UxOut* p = (coin__UxOut*)uxs.data;
    p += 2;
    p->Body.Coins = 0xFFFFFFFFFFFFFFFF - 1000000;
    result = SKY_coin_UxArray_Coins(&uxs, &coins);
    ck_assert_msg(result == SKY_ERROR, "SKY_coin_UxArray_Coins should fail with overflow");
}
END_TEST

START_TEST(TestUxArrayCoinHours)
{
    coin__UxArray uxs;
    int result = makeUxArray(&uxs, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    coin__UxOut* p = (coin__UxOut*)uxs.data;
    GoUint64 n;

    result = SKY_coin_UxArray_CoinHours(&uxs, p->Head.Time, &n);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(n == 400);

    result = SKY_coin_UxArray_CoinHours(&uxs, p->Head.Time + 3600, &n);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(n == 404);

    result = SKY_coin_UxArray_CoinHours(&uxs, p->Head.Time + 3600 + 4600, &n);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_CoinHours failed");
    ck_assert(n == 408);

    p[2].Body.Hours = 0xFFFFFFFFFFFFFFFF - 100;
    result = SKY_coin_UxArray_CoinHours(&uxs, p->Head.Time, &n);
    ck_assert_msg(result == SKY_ERROR, "SKY_coin_UxOut_CoinHours should have fail with overflow");

    result = SKY_coin_UxArray_CoinHours(&uxs, p->Head.Time * (GoUint64)1000000000000, &n);
    ck_assert_msg(result == SKY_ErrAddEarnedCoinHoursAdditionOverflow, "SKY_coin_UxOut_CoinHours should have fail with overflow");
}
END_TEST

START_TEST(TestUxArrayHashArray)
{
    coin__UxArray uxs;
    int result = makeUxArray(&uxs, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    coin__UxOut* p = (coin__UxOut*)uxs.data;

    GoSlice_ hashes = {NULL, 0, 0};
    result = SKY_coin_UxArray_Hashes(&uxs, &hashes);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Hashes failed");
    registerMemCleanup(hashes.data);
    ck_assert(hashes.len == uxs.len);
    coin__UxOut* pux = (coin__UxOut*)uxs.data;
    cipher__SHA256* ph = (cipher__SHA256*)hashes.data;
    cipher__SHA256 hash;
    int i;
    for (i = 0; i < hashes.len; i++) {
        result = SKY_coin_UxOut_Hash(pux, &hash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
        ck_assert(isU8Eq(hash, *ph, sizeof(cipher__SHA256)));
        pux++;
        ph++;
    }
}
END_TEST

START_TEST(TestUxArrayHasDupes)
{
    coin__UxArray uxs;
    int result = makeUxArray(&uxs, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    GoUint8 hasDupes;
    result = SKY_coin_UxArray_HasDupes(&uxs, &hasDupes);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_HasDupes failed");
    ck_assert(hasDupes == 0);
    coin__UxOut* p = (coin__UxOut*)uxs.data;
    p++;
    memcpy(uxs.data, p, sizeof(coin__UxOut));
    result = SKY_coin_UxArray_HasDupes(&uxs, &hasDupes);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_HasDupes failed");
    ck_assert(hasDupes != 0);
}
END_TEST

START_TEST(TestUxArraySub)
{
    int result, equal;
    coin__UxArray uxa, uxb, uxc, uxd;
    coin__UxArray t1, t2, t3, t4;

    int arraySize = sizeof(coin__UxArray);
    memset(&uxa, 0, arraySize);
    memset(&uxb, 0, arraySize);
    memset(&uxc, 0, arraySize);
    memset(&uxd, 0, arraySize);
    memset(&t1, 0, arraySize);
    memset(&t2, 0, arraySize);
    memset(&t3, 0, arraySize);
    memset(&t4, 0, arraySize);

    result = makeUxArray(&uxa, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    result = makeUxArray(&uxb, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");

    int elems_size = sizeof(coin__UxOut);
    cutSlice(&uxa, 0, 1, elems_size, &t1);
    ck_assert_msg(result == SKY_OK, "cutSlice failed");
    result = concatSlices(&t1, &uxb, elems_size, &t2);
    ck_assert_msg(result == SKY_OK, "concatSlices failed");
    result = cutSlice(&uxa, 1, 2, elems_size, &t3);
    ck_assert_msg(result == SKY_OK, "cutSlice failed");
    result = concatSlices(&t2, &t3, elems_size, &uxc);
    ck_assert_msg(result == SKY_OK, "concatSlices failed");
    //   //TODO: Fix comparision
    memset(&uxd, 0, arraySize);
    result = SKY_coin_UxArray_Sub(&uxc, &uxa, &uxd);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Sub failed");
    ck_assert(isUxArrayEq(&uxd, &uxb));

    memset(&uxd, 0, arraySize);
    result = SKY_coin_UxArray_Sub(&uxc, &uxb, &uxd);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Sub failed");
    ck_assert_msg(uxd.len == 2, "uxd length must be 2 and it is: %s", uxd.len);
    cutSlice(&uxa, 0, 2, elems_size, &t1);
    ck_assert(isUxArrayEq(&uxd, &t1));

    // No intersection
    memset(&t1, 0, arraySize);
    memset(&t2, 0, arraySize);
    result = SKY_coin_UxArray_Sub(&uxa, &uxb, &t1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Sub failed");
    result = SKY_coin_UxArray_Sub(&uxb, &uxa, &t2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Sub failed");
    ck_assert(isUxArrayEq(&uxa, &t1));
    ck_assert(isUxArrayEq(&uxb, &t2));
}
END_TEST

int isUxArraySorted(coin__UxArray* uxa)
{
    int n = uxa->len;
    coin__UxOut* prev = uxa->data;
    coin__UxOut* current = prev;
    current++;
    cipher__SHA256 hash1, hash2;
    cipher__SHA256* prevHash = NULL;
    cipher__SHA256* currentHash = NULL;

    int result;
    int i;
    for (i = 1; i < n; i++) {
        if (prevHash == NULL) {
            result = SKY_coin_UxOut_Hash(prev, &hash1);
            ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
            prevHash = &hash1;
        }
        if (currentHash == NULL)
            currentHash = &hash2;
        result = SKY_coin_UxOut_Hash(current, currentHash);
        ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
        if (memcmp(prevHash, currentHash, sizeof(cipher__SHA256)) > 0)
            return 0; //Array is not sorted
        if (i % 2 != 0) {
            prevHash = &hash2;
            currentHash = &hash1;
        } else {
            prevHash = &hash1;
            currentHash = &hash2;
        }
        prev++;
        current++;
    }
    return 1;
}

START_TEST(TestUxArraySorting)
{
    int result;
    coin__UxArray uxa;
    result = makeUxArray(&uxa, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    int isSorted = isUxArraySorted(&uxa);
    if (isSorted) { //If already sorted then break the order
        coin__UxOut temp;
        coin__UxOut* p = uxa.data;
        memcpy(&temp, p, sizeof(coin__UxOut));
        memcpy(p, p + 1, sizeof(coin__UxOut));
        memcpy(p + 1, &temp, sizeof(coin__UxOut));
    }
    isSorted = isUxArraySorted(&uxa);
    ck_assert(isSorted == 0);
    result = SKY_coin_UxArray_Sort(&uxa);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Sort failed");
    isSorted = isUxArraySorted(&uxa);
    ck_assert(isSorted == 1);
}
END_TEST

START_TEST(TestUxArrayLen)
{
    int result;
    coin__UxArray uxa;
    result = makeUxArray(&uxa, 4);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    GoInt len;
    result = SKY_coin_UxArray_Len(&uxa, &len);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Len failed");
    ck_assert(len == uxa.len);
    ck_assert(len == 4);
}
END_TEST

START_TEST(TestUxArrayLess)
{
    int result;
    coin__UxArray uxa;
    result = makeUxArray(&uxa, 2);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    cipher__SHA256 hashes[2];
    coin__UxOut* p = uxa.data;
    result = SKY_coin_UxOut_Hash(p, &hashes[0]);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
    p++;
    result = SKY_coin_UxOut_Hash(p, &hashes[1]);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxOut_Hash failed");
    GoUint8 lessResult1, lessResult2;
    int memcmpResult;
    result = SKY_coin_UxArray_Less(&uxa, 0, 1, &lessResult1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Less failed");
    result = SKY_coin_UxArray_Less(&uxa, 1, 0, &lessResult2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Less failed");
    memcmpResult = memcmp(&hashes[0], &hashes[1], sizeof(cipher__SHA256));
    int r;
    r = (lessResult1 == 1) == (memcmpResult < 0);
    ck_assert(r != 0);
    r = (lessResult2 == 1) == (memcmpResult > 0);
    ck_assert(r != 0);
}
END_TEST

START_TEST(TestUxArraySwap)
{
    int result;
    coin__UxArray uxa;
    result = makeUxArray(&uxa, 2);
    ck_assert_msg(result == SKY_OK, "makeUxArray failed");
    coin__UxOut uxx, uxy;
    coin__UxOut* p = uxa.data;
    memcpy(&uxx, p, sizeof(coin__UxOut));
    memcpy(&uxy, p + 1, sizeof(coin__UxOut));

    result = SKY_coin_UxArray_Swap(&uxa, 0, 1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Swap failed");
    ck_assert(isUxOutEq(&uxy, p));
    ck_assert(isUxOutEq(&uxx, (p + 1)));

    result = SKY_coin_UxArray_Swap(&uxa, 0, 1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Swap failed");
    ck_assert(isUxOutEq(&uxy, (p + 1)));
    ck_assert(isUxOutEq(&uxx, p));

    result = SKY_coin_UxArray_Swap(&uxa, 1, 0);
    ck_assert_msg(result == SKY_OK, "SKY_coin_UxArray_Swap failed");
    ck_assert(isUxOutEq(&uxy, p));
    ck_assert(isUxOutEq(&uxx, (p + 1)));
}
END_TEST

START_TEST(TestAddressUxOutsKeys)
{
    int result;
    int test_count = 3;
    coin__UxOut uxs[test_count];
    int i;
    for (i = 0; i < 3; i++) {
        makeUxOut(&uxs[i]);
    }

    coin__UxArray uxa = {uxs, test_count, test_count};
    AddressUxOuts_Handle uxOutsHandle;
    result = SKY_coin_NewAddressUxOuts(&uxa, &uxOutsHandle);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    GoSlice_ keys = {NULL, 0, 0};
    result = SKY_coin_AddressUxOuts_Keys(uxOutsHandle, &keys);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Keys failed");
    registerMemCleanup(keys.data);
    ck_assert(keys.len == test_count);
    cipher__Address* pKey = keys.data;
    for (int i = 0; i < test_count; i++) {
        //Check if every key matches uxout
        int found = 0;
        int j;
        for (j = 0; j < test_count; j++) {
            if (memcmp(pKey, &uxs[j].Body.Address, sizeof(cipher__Address)) == 0) {
                found = 1;
            }
        }
        found = 0;
        if (i < test_count - 1) {
            cipher__Address* pKey2 = pKey;
            for (j = i + 1; j < test_count; j++) {
                pKey2++;
                if (memcmp(pKey, pKey2, sizeof(cipher__Address)) == 0) {
                    found = 1;
                }
            }
        }
        ck_assert_msg(found == 0, "Duplicate keys received from SKY_coin_AddressUxOuts_Keys");
        pKey++;
    }
}
END_TEST

START_TEST(TestAddressUxOutsSub)
{
    int result;
    coin__UxArray uxa, empty;
    makeUxArray(&uxa, 4);
    coin__UxOut* pData = uxa.data;
    memset(&empty, 0, sizeof(coin__UxArray));
    AddressUxOuts_Handle h1, h2, h3;
    result = SKY_coin_NewAddressUxOuts(&empty, &h1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h1);
    result = SKY_coin_NewAddressUxOuts(&empty, &h2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h2);
    memcpy(&(pData + 1)->Body.Address, &pData->Body.Address, sizeof(cipher__Address));

    coin__UxArray ux2 = {pData, 2, 2};
    result = SKY_coin_AddressUxOuts_Set(h1, &pData->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux3 = {pData + 2, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h1, &(pData + 2)->Body.Address, &ux3);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux4 = {pData + 3, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h1, &(pData + 3)->Body.Address, &ux4);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");

    coin__UxArray ux5 = {pData, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h2, &pData->Body.Address, &ux5);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux6 = {pData + 2, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h2, &(pData + 2)->Body.Address, &ux6);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");

    result = SKY_coin_AddressUxOuts_Sub(h1, h2, &h3);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Sub failed");
    registerHandleClose(h3);

    GoInt length;
    result = SKY_coin_AddressUxOuts_Length(h3, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    // One address should have been removed, because no elements
    ck_assert_msg(length == 2, "Invalid length %d", length);
    GoUint8_ hasKey;
    result = SKY_coin_AddressUxOuts_HasKey(h3, &(pData + 2)->Body.Address, &hasKey);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_HasKey failed");
    ck_assert(hasKey == 0);

    memset(&ux3, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &(pData + 3)->Body.Address, &ux3);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux3.data);
    ck_assert(ux3.len == 1);
    coin__UxOut* pData2 = ux3.data;
    ck_assert(isUxOutEq(pData2, (pData + 3)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &pData->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 1);
    pData2 = ux2.data;
    ck_assert(isUxOutEq(pData2, (pData + 1)));

    // Originals should be unmodified
    result = SKY_coin_AddressUxOuts_Length(h1, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 3, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &pData->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 2, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &(pData + 2)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &(pData + 3)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);

    result = SKY_coin_AddressUxOuts_Length(h2, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 2, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h2, &pData->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h2, &(pData + 2)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
}
END_TEST

START_TEST(TestAddressUxOutsAdd)
{
    int result;
    coin__UxArray uxa, empty;
    makeUxArray(&uxa, 4);
    coin__UxOut* pData = uxa.data;
    memset(&empty, 0, sizeof(coin__UxArray));
    AddressUxOuts_Handle h1, h2, h3;
    result = SKY_coin_NewAddressUxOuts(&empty, &h1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h1);
    result = SKY_coin_NewAddressUxOuts(&empty, &h2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h2);
    memcpy(&(pData + 1)->Body.Address, &pData->Body.Address, sizeof(cipher__Address));

    coin__UxArray ux2 = {pData, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h1, &pData->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux3 = {pData + 2, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h1, &(pData + 2)->Body.Address, &ux3);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux4 = {pData + 3, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h1, &(pData + 3)->Body.Address, &ux4);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");

    coin__UxArray ux5 = {pData + 1, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h2, &pData->Body.Address, &ux5);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    coin__UxArray ux6 = {pData + 2, 1, 1};
    result = SKY_coin_AddressUxOuts_Set(h2, &(pData + 2)->Body.Address, &ux6);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");

    result = SKY_coin_AddressUxOuts_Add(h1, h2, &h3);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Add failed");
    registerHandleClose(h3);

    GoInt length;
    result = SKY_coin_AddressUxOuts_Length(h3, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    // One address should have been removed, because no elements
    ck_assert_msg(length == 3, "Invalid length %d", length);

    result = SKY_coin_AddressUxOuts_GetOutputLength(h3, &pData->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 2, "Invalid length %d", length);

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &pData->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 2);
    coin__UxOut* pData2 = ux2.data;
    ck_assert(isUxOutEq(pData2, pData));
    ck_assert(isUxOutEq((pData2 + 1), (pData + 1)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &(pData + 2)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 1);
    pData2 = ux2.data;
    ck_assert(isUxOutEq(pData2, (pData + 2)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &(pData + 3)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 1);
    pData2 = ux2.data;
    ck_assert(isUxOutEq(pData2, (pData + 3)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h3, &(pData + 1)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 2);
    pData2 = ux2.data;
    ck_assert(isUxOutEq(pData2, pData));
    ck_assert(isUxOutEq((pData2 + 1), (pData + 1)));

    // Originals should be unmodified
    result = SKY_coin_AddressUxOuts_Length(h1, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 3, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &pData->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &(pData + 2)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h1, &(pData + 3)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_Length(h2, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 2, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h2, &pData->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
    result = SKY_coin_AddressUxOuts_GetOutputLength(h2, &(pData + 2)->Body.Address, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert_msg(length == 1, "Invalid length %d", length);
}
END_TEST

START_TEST(TestAddressUxOutsFlatten)
{
    int result;
    coin__UxArray uxa, emptyArray;
    makeUxArray(&uxa, 3);
    coin__UxOut* pData = uxa.data;
    memcpy(&(pData + 2)->Body.Address, &(pData + 1)->Body.Address, sizeof(cipher__Address));
    memset(&emptyArray, 0, sizeof(coin__UxArray));
    AddressUxOuts_Handle h;
    result = SKY_coin_NewAddressUxOuts(&emptyArray, &h);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h);
    cipher__Address emptyAddr;
    makeAddress(&emptyAddr);
    coin__UxArray ux1 = {pData, 1, 1};
    coin__UxArray ux2 = {pData + 1, 2, 2};
    result = SKY_coin_AddressUxOuts_Set(h, &emptyAddr, &emptyArray);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    result = SKY_coin_AddressUxOuts_Set(h, &pData->Body.Address, &ux1);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");
    result = SKY_coin_AddressUxOuts_Set(h, &(pData + 1)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOut_Set failed");

    coin__UxArray flatArray;
    memset(&flatArray, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Flatten(h, &flatArray);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Flatten failed");
    registerMemCleanup(flatArray.data);
    ck_assert(flatArray.len == 3);
    // emptyAddr should not be in the array
    coin__UxOut* pData2 = flatArray.data;
    int i;
    for (i = 0; i < flatArray.len; pData2++, i++) {
        int cmp = memcmp(&emptyAddr, &pData2->Body.Address, sizeof(cipher__Address));
        ck_assert(cmp != 0);
    }
    pData2 = flatArray.data;
    int cmp = memcmp(&pData->Body.Address, &pData2->Body.Address, sizeof(cipher__Address));
    if (cmp == 0) {
        ck_assert(isUxOutEq(pData2, pData));
        ck_assert(isUxOutEq((pData2 + 1), (pData + 1)));
        ck_assert(isUxOutEq((pData2 + 2), (pData + 2)));
        ck_assert(isAddressEq(&pData2->Body.Address, &pData->Body.Address));
        ck_assert(isAddressEq(&(pData2 + 1)->Body.Address, &(pData + 1)->Body.Address));
        ck_assert(isAddressEq(&(pData2 + 2)->Body.Address, &(pData + 2)->Body.Address));
    } else {
        ck_assert(isUxOutEq(pData2, (pData + 1)));
        ck_assert(isUxOutEq((pData2 + 1), (pData + 2)));
        ck_assert(isUxOutEq((pData2 + 2), (pData)));
        ck_assert(isAddressEq(&pData2->Body.Address, &(pData + 1)->Body.Address));
        ck_assert(isAddressEq(&(pData2 + 1)->Body.Address, &(pData + 2)->Body.Address));
        ck_assert(isAddressEq(&(pData2 + 2)->Body.Address, &(pData)->Body.Address));
    }
}
END_TEST

START_TEST(TestNewAddressUxOuts)
{
    int result;
    coin__UxArray uxa, ux2;
    makeUxArray(&uxa, 6);
    coin__UxOut* pData = uxa.data;
    memcpy(&(pData + 1)->Body.Address, &(pData)->Body.Address, sizeof(cipher__Address));
    memcpy(&(pData + 3)->Body.Address, &(pData + 2)->Body.Address, sizeof(cipher__Address));
    memcpy(&(pData + 4)->Body.Address, &(pData + 2)->Body.Address, sizeof(cipher__Address));
    AddressUxOuts_Handle h;
    result = SKY_coin_NewAddressUxOuts(&uxa, &h);
    ck_assert_msg(result == SKY_OK, "SKY_coin_NewAddressUxOuts failed");
    registerHandleClose(h);

    GoInt length;
    result = SKY_coin_AddressUxOuts_Length(h, &length);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Length failed");
    ck_assert(length == 3);

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h, &(pData)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 2);
    coin__UxOut* pData2 = ux2.data;
    ck_assert(isUxOutEq((pData2), (pData)));
    ck_assert(isUxOutEq((pData2 + 1), (pData + 1)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h, &(pData + 3)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 3);
    pData2 = ux2.data;
    ck_assert(isUxOutEq((pData2), (pData + 2)));
    ck_assert(isUxOutEq((pData2 + 1), (pData + 3)));
    ck_assert(isUxOutEq((pData2 + 2), (pData + 4)));

    memset(&ux2, 0, sizeof(coin__UxArray));
    result = SKY_coin_AddressUxOuts_Get(h, &(pData + 5)->Body.Address, &ux2);
    ck_assert_msg(result == SKY_OK, "SKY_coin_AddressUxOuts_Get failed");
    registerMemCleanup(ux2.data);
    ck_assert(ux2.len == 1);
    pData2 = ux2.data;
    ck_assert(isUxOutEq((pData2), (pData + 5)));
}
END_TEST
Suite* coin_output(void)
{
    Suite* s = suite_create("Load coin.output");
    TCase* tc;

    tc = tcase_create("coin.output");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestUxBodyHash);
    tcase_add_test(tc, TestUxOutHash);
    tcase_add_test(tc, TestUxOutSnapshotHash);
    tcase_add_test(tc, TestUxOutCoinHours);
    tcase_add_test(tc, TestUxArrayCoins);
    tcase_add_test(tc, TestUxArrayCoinHours);
    tcase_add_test(tc, TestUxArrayHashArray);
    tcase_add_test(tc, TestUxArrayHasDupes);
    tcase_add_test(tc, TestUxArraySub);
    tcase_add_test(tc, TestUxArraySorting);
    tcase_add_test(tc, TestUxArrayLen);
    tcase_add_test(tc, TestUxArrayLess);
    tcase_add_test(tc, TestUxArraySwap);
    tcase_add_test(tc, TestAddressUxOutsKeys);
    tcase_add_test(tc, TestAddressUxOutsSub);
    tcase_add_test(tc, TestAddressUxOutsAdd);
    tcase_add_test(tc, TestAddressUxOutsFlatten);
    tcase_add_test(tc, TestNewAddressUxOuts);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}
