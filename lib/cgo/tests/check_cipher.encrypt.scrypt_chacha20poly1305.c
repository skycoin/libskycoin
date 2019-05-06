#include <stdio.h>
#include <stdlib.h>

#include "base64.h"
#include "libskycoin.h"
#include "skyassert.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include <check.h>

#define PLAINTEXT "plaintext"
#define PASSWORD "password"
#define PASSWORD2 "pwd"
#define WRONG_PASSWORD "wrong password"
#define ENCRYPTED "dQB7Im4iOjUyNDI4OCwiciI6OCwicCI6MSwia2V5TGVuIjozMiwic2FsdCI6ImpiejUrSFNjTFFLWkI5T0tYblNNRmt2WDBPY3JxVGZ0ZFpDNm9KUFpaeHc9Iiwibm9uY2UiOiJLTlhOQmRQa1ZUWHZYNHdoIn3PQFmOot0ETxTuv//skTG7Q57UVamGCgG5"
#define BUFFER_SIZE 1024
#define SCRYPTCHACHA20METALENGTHSIZE 2


void parseJsonMetaData(char* metadata, int* n, int* r, int* p, int* keyLen)
{
    *n = *r = *p = *keyLen = 0;
    int length = strlen(metadata);
    int openingQuote = -1;
    const char* keys[] = {"n", "r", "p", "keyLen"};
    int keysCount = 4;
    int keyIndex = -1;
    int startNumber = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (metadata[i] == '\"') {
            startNumber = -1;
            if (openingQuote >= 0) {
                keyIndex = -1;
                metadata[i] = 0;
                int k;
                for (k = 0; k < keysCount; k++) {
                    if (strcmp(metadata + openingQuote + 1, keys[k]) == 0) {
                        keyIndex = k;
                    }
                }
                openingQuote = -1;
            } else {
                openingQuote = i;
            }
        } else if (metadata[i] >= '0' && metadata[i] <= '9') {
            if (startNumber < 0)
                startNumber = i;
        } else if (metadata[i] == ',') {
            if (startNumber >= 0) {
                metadata[i] = 0;
                int number = atoi(metadata + startNumber);
                startNumber = -1;
                if (keyIndex == 0)
                    *n = number;
                else if (keyIndex == 1)
                    *r = number;
                else if (keyIndex == 2)
                    *p = number;
                else if (keyIndex == 3)
                    *keyLen = number;
            }
        } else {
            startNumber = -1;
        }
    }
}

START_TEST(TestScryptChacha20poly1305Encrypt)
{
    GoSlice nullData;
    GoSlice nullPassword;
    char str[BUFFER_SIZE];
    GoSlice text;
    GoSlice password;
    GoSlice password2;
    GoSlice wrong_password;
    GoSlice encrypted;

    memset(&text, 0, sizeof(GoSlice));
    memset(&password, 0, sizeof(GoSlice));
    memset(&password2, 0, sizeof(GoSlice));
    memset(&wrong_password, 0, sizeof(GoSlice));
    memset(&encrypted, 0, sizeof(GoSlice));
    memset(&nullData, 0, sizeof(GoSlice));
    memset(&nullPassword, 0, sizeof(GoSlice));
    memset(str, 0, BUFFER_SIZE);

    text.data = PLAINTEXT;
    text.len = strlen(PLAINTEXT);
    text.cap = text.len;
    password.data = PASSWORD;
    password.len = strlen(PASSWORD);
    password.cap = password.len;
    password2.data = PASSWORD2;
    password2.len = strlen(PASSWORD2);
    password2.cap = password2.len;
    wrong_password.data = WRONG_PASSWORD;
    wrong_password.len = strlen(WRONG_PASSWORD);
    wrong_password.cap = wrong_password.len;
    encrypted.data = ENCRYPTED;
    encrypted.len = strlen(ENCRYPTED);
    encrypted.cap = encrypted.len;

    GoUint32 errcode;
    unsigned int metalength;
    encrypt__ScryptChacha20poly1305 encrypt = {0, 1 << 0, 1 << 3, 1 << 5};
    registerMemCleanup(&encrypt);
    int i;
    for (i = 1; i <= 20; i++) {
        unsigned char buffer[BUFFER_SIZE];
        GoSlice_ result = {buffer, 0, BUFFER_SIZE};
        encrypt.N = 1 << i;
        errcode = SKY_encrypt_ScryptChacha20poly1305_Encrypt(&encrypt, text, password, &result);
        ck_assert_msg(errcode == SKY_OK, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed");
        registerMemCleanup((void*)result.data);
        ck_assert_msg(result.len > SCRYPTCHACHA20METALENGTHSIZE, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed, result data length too short");
        int decode_len = b64_decode((const unsigned char*)result.data,
            result.len, (unsigned char*)str);
        ck_assert_msg(decode_len >= SCRYPTCHACHA20METALENGTHSIZE, "base64_decode_string failed");
        ck_assert_msg(decode_len < BUFFER_SIZE, "base64_decode_string failed, buffer overflow");
        metalength = (unsigned int)str[0];
        int m;
        for (m = 1; m < SCRYPTCHACHA20METALENGTHSIZE; m++) {
            if (str[m] > 0) {
                metalength += (((unsigned int)str[m]) << (m * 8));
            }
        }
        ck_assert_msg(metalength + SCRYPTCHACHA20METALENGTHSIZE < decode_len, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed. Metadata length greater than result lentgh.");
        char* meta = str + SCRYPTCHACHA20METALENGTHSIZE;
        meta[metalength] = 0;
        int n, r, p, keyLen;
        parseJsonMetaData(meta, &n, &r, &p, &keyLen);

        ck_assert_msg(n == encrypt.N, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed. Metadata value N incorrect.");
        ck_assert_msg(r == encrypt.R, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed. Metadata value R incorrect.");
        ck_assert_msg(p == encrypt.P, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed. Metadata value P incorrect.");
        ck_assert_msg(keyLen == encrypt.KeyLen, "SKY_encrypt_ScryptChacha20poly1305_Encrypt failed. Metadata value KeyLen incorrect.");
    }
}
END_TEST

START_TEST(TestScryptChacha20poly1305Decrypt)
{
    coin__UxArray result;
    GoSlice nullData;
    GoSlice nullPassword;
    GoSlice_ text;
    GoSlice password;
    GoSlice password2;
    GoSlice wrong_password;
    GoSlice encrypted;

    memset(&text, 0, sizeof(GoSlice_));
    memset(&password, 0, sizeof(GoSlice));
    memset(&password2, 0, sizeof(GoSlice));
    memset(&wrong_password, 0, sizeof(GoSlice));
    memset(&encrypted, 0, sizeof(GoSlice));
    memset(&nullData, 0, sizeof(GoSlice));
    memset(&nullPassword, 0, sizeof(GoSlice));
    memset(&result, 0, sizeof(coin__UxArray));

    text.data = PLAINTEXT;
    text.len = strlen(PLAINTEXT);
    text.cap = text.len;
    password.data = PASSWORD;
    password.len = strlen(PASSWORD);
    password.cap = password.len;
    password2.data = PASSWORD2;
    password2.len = strlen(PASSWORD2);
    password2.cap = password2.len;
    wrong_password.data = WRONG_PASSWORD;
    wrong_password.len = strlen(WRONG_PASSWORD);
    wrong_password.cap = wrong_password.len;
    encrypted.data = ENCRYPTED;
    encrypted.len = strlen(ENCRYPTED);
    encrypted.cap = encrypted.len;

    GoUint32 errcode;
    encrypt__ScryptChacha20poly1305 encrypt = {0, 0, 0, 0};
    unsigned char buffer_result[BUFFER_SIZE];
    GoSlice_ tmp_result = {buffer_result, 0, BUFFER_SIZE};
    errcode = SKY_encrypt_ScryptChacha20poly1305_Decrypt(&encrypt, encrypted, password2, &result);
    ck_assert_msg(errcode == SKY_OK, "SKY_encrypt_ScryptChacha20poly1305_Decrypt failed");
    registerMemCleanup((void*)result.data);
    ck_assert(isGoSlice_Eq(&text, &result));
    result.cap = result.len = 0;
    errcode = SKY_encrypt_ScryptChacha20poly1305_Decrypt(&encrypt, encrypted, wrong_password, &tmp_result);
    ck_assert_msg(errcode == SKY_ERROR, "SKY_encrypt_ScryptChacha20poly1305_Decrypt decrypted with wrong password.");
    result.cap = result.len = 0;
    errcode = SKY_encrypt_ScryptChacha20poly1305_Decrypt(&encrypt, encrypted, nullPassword, &tmp_result);
    ck_assert_msg(errcode == SKY_ERROR, "SKY_encrypt_ScryptChacha20poly1305_Decrypt decrypted with null password.");
}
END_TEST

Suite* cipher_encrypt_scrypt_chacha20poly1305(void)
{
    Suite* s = suite_create("Load cipher.encrypt.scrypt.chacha20poly1305");
    TCase* tc;

    tc = tcase_create("cipher.encrypt.scrypt.chacha20poly1305");
    tcase_add_checked_fixture(tc, setup, teardown);
    tcase_add_test(tc, TestScryptChacha20poly1305Encrypt);
    tcase_add_test(tc, TestScryptChacha20poly1305Decrypt);
    suite_add_tcase(s, tc);
    tcase_set_timeout(tc, 150);

    return s;
}
