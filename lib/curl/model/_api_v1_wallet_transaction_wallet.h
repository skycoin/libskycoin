/*
 * _api_v1_wallet_transaction_wallet.h
 *
 * 
 */

#ifndef __api_v1_wallet_transaction_wallet_H_
#define __api_v1_wallet_transaction_wallet_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_wallet_transaction_wallet_t {
    list_t *unspents; //primitive container
    list_t *addresses; //primitive container
    char *password; // string
    char *id; // string

} _api_v1_wallet_transaction_wallet_t;

_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_create(
    list_t *unspents,
    list_t *addresses,
    char *password,
    char *id
);

void _api_v1_wallet_transaction_wallet_free(_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet);

_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_parseFromJSON(cJSON *_api_v1_wallet_transaction_walletJSON);

cJSON *_api_v1_wallet_transaction_wallet_convertToJSON(_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet);

#endif /* __api_v1_wallet_transaction_wallet_H_ */

