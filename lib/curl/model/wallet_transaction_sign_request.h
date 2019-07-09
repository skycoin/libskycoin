/*
 * wallet_transaction_sign_request.h
 *
 * 
 */

#ifndef _wallet_transaction_sign_request_H_
#define _wallet_transaction_sign_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct wallet_transaction_sign_request_t {
    char *wallet_id; // string
    char *password; // string
    char *encoded_transaction; // string
    list_t *sign_indexes; //primitive container

} wallet_transaction_sign_request_t;

wallet_transaction_sign_request_t *wallet_transaction_sign_request_create(
    char *wallet_id,
    char *password,
    char *encoded_transaction,
    list_t *sign_indexes
);

void wallet_transaction_sign_request_free(wallet_transaction_sign_request_t *wallet_transaction_sign_request);

wallet_transaction_sign_request_t *wallet_transaction_sign_request_parseFromJSON(cJSON *wallet_transaction_sign_requestJSON);

cJSON *wallet_transaction_sign_request_convertToJSON(wallet_transaction_sign_request_t *wallet_transaction_sign_request);

#endif /* _wallet_transaction_sign_request_H_ */

