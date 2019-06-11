/*
 * _api_v1_wallet_transaction_to.h
 *
 * 
 */

#ifndef __api_v1_wallet_transaction_to_H_
#define __api_v1_wallet_transaction_to_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_wallet_transaction_to_t {
    long hours; //numeric
    char *address; // string
    long coins; //numeric

} _api_v1_wallet_transaction_to_t;

_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_create(
    long hours,
    char *address,
    long coins
);

void _api_v1_wallet_transaction_to_free(_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to);

_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_parseFromJSON(cJSON *_api_v1_wallet_transaction_toJSON);

cJSON *_api_v1_wallet_transaction_to_convertToJSON(_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to);

#endif /* __api_v1_wallet_transaction_to_H_ */

