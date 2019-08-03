#ifndef TEST_MAIN_H
#define TEST_MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <check.h>
#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"
#include "skytypes.h"
#include "skyerrors.h"

Suite *cipher_bitcoin(void);
Suite *cipher_address(void);
Suite *cipher_testsuite(void);
Suite *cipher_crypto(void);
Suite *cipher_secp256k1(void);
Suite *cipher_encrypt_scrypt_chacha20poly1305(void);
Suite *cipher_hash(void);
Suite *coin_blocks(void);
Suite *coin_coin(void);
Suite *coin_math(void);
Suite *coin_output(void);
Suite *coin_transaction(void);
Suite *coin_transaction_fork(void);
Suite *param_distribution(void);
Suite *util_droplet(void);
Suite *util_fee(void);

#endif