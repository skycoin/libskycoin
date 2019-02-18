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

#endif