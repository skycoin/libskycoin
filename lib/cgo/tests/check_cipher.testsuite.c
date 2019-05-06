
#include <check.h>
#include <fts.h>
#include <stdio.h>

#include "cipher.testsuite.testsuite.go.h"

// TODO: File path utils. Move elsewhere.

// Determine if a file name matches pattern for golden dataset
// i.e. matches 'seed-\d+.golden' regex
int isGoldenFile(const char* filename)
{
    if (strncmp(filename, "seed-", 5) != 0)
        return 1;
    char* ptr = (char*)filename + 5;
    if (*ptr < '0' || *ptr > '9')
        return 1;
    while (*++ptr >= '0' && *ptr <= '9') {
    }
    return strcmp(ptr, ".golden") == 0;
}

START_TEST(TestManyAddresses)
{
    SeedTestDataJSON dataJSON;
    SeedTestData data;
    GoUint32 err;

    json_value* json = loadGoldenFile(MANY_ADDRESSES_FILENAME);
    ck_assert_msg(json != NULL, "Error loading file %s", MANY_ADDRESSES_FILENAME);
    registerJsonFree(json);
    SeedTestDataJSON* dataset = jsonToSeedTestData(json, &dataJSON);
    ck_assert_msg(dataset != NULL, "Loaded JSON golden dataset must not be NULL");
    registerSeedTestDataJSONCleanup(&dataJSON);
    err = SeedTestDataFromJSON(&dataJSON, &data);
    registerSeedTestDataCleanup(&data);
    ck_assert_msg(err == SKY_OK, "Deserializing seed test data from JSON ... %d", err);
    ValidateSeedData(&data, NULL);
}
END_TEST

GoUint32 traverseGoldenFiles(const char* path, InputTestData* inputData)
{
    char* _path[2];
    _path[0] = (char*)path;
    _path[1] = NULL;
    size_t i = 0;
    FTS* tree = fts_open(_path, FTS_NOCHDIR, NULL);

    if (!tree)
        return 1;
    FTSENT* node;
    while ((node = fts_read(tree))) {
        if ((node->fts_info & FTS_F) && isGoldenFile(node->fts_name)) {
            char fn[FILENAME_MAX];
            fprintf(stderr, "Golden data set %s\n", node->fts_path);
            SeedTestDataJSON seedDataJSON;
            SeedTestData seedData;

            json_value* json = loadGoldenFile(node->fts_name);
            ck_assert_msg(json != NULL, "Error loading file %s", node->fts_name);
            SeedTestDataJSON* dataset = jsonToSeedTestData(json, &seedDataJSON);
            ck_assert_msg(dataset != NULL, "Loaded JSON seed golden dataset must not be NULL");
            GoUint32 err = SeedTestDataFromJSON(&seedDataJSON, &seedData);
            ck_assert_msg(err == SKY_OK, "Deserializing seed test data from JSON ... %d", err);
            ValidateSeedData(&seedData, inputData);
        }
    }
    return 0;
}

START_TEST(TestSeedSignatures)
{
    InputTestDataJSON inputDataJSON;
    InputTestData inputData;
    GoUint32 err;

    json_value* json = loadGoldenFile(INPUT_HASHES_FILENAME);
    ck_assert_msg(json != NULL, "Error loading file %s", INPUT_HASHES_FILENAME);
    InputTestDataJSON* dataset = jsonToInputTestData(json, &inputDataJSON);
    ck_assert_msg(dataset != NULL, "Loaded JSON input golden dataset must not be NULL");
    err = InputTestDataFromJSON(&inputDataJSON, &inputData);
    ck_assert_msg(err == SKY_OK, "Deserializing seed test data from JSON ... %d", err);
    err = traverseGoldenFiles(TEST_DATA_DIR, &inputData);
    ck_assert(err == 0);
}
END_TEST

Suite* cipher_testsuite(void)
{
    Suite* s = suite_create("Load cipher.suite");
    TCase* tc;

    tc = tcase_create("cipher.testsuite");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestManyAddresses);
    // tcase_add_test(tc, TestSeedSignatures);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}