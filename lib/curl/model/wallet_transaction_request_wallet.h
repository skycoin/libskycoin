/*
 * wallet_transaction_request_wallet.h
 *
 * 
 */

#ifndef _wallet_transaction_request_wallet_H_
#define _wallet_transaction_request_wallet_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct wallet_transaction_request_wallet_t {
    list_t *addresses; //primitive container
    char *id; // string
    char *password; // string
    list_t *unspents; //primitive container

} wallet_transaction_request_wallet_t;

wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_create(
    list_t *addresses,
    char *id,
    char *password,
    list_t *unspents
);

void wallet_transaction_request_wallet_free(wallet_transaction_request_wallet_t *wallet_transaction_request_wallet);

wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_parseFromJSON(cJSON *wallet_transaction_request_walletJSON);

cJSON *wallet_transaction_request_wallet_convertToJSON(wallet_transaction_request_wallet_t *wallet_transaction_request_wallet);

#endif /* _wallet_transaction_request_wallet_H_ */

