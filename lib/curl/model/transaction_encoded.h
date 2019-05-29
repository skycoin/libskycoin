/*
 * transaction_encoded.h
 *
 * 
 */

#ifndef _transaction_encoded_H_
#define _transaction_encoded_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_pending_txs_transaction.h"



typedef struct transaction_encoded_t {
    _api_v1_pending_txs_transaction_t *transaction; //model
    char *received; // string
    char *checked; // string
    char *announced; // string
    int is_valid; //boolean

} transaction_encoded_t;

transaction_encoded_t *transaction_encoded_create(
    _api_v1_pending_txs_transaction_t *transaction,
    char *received,
    char *checked,
    char *announced,
    int is_valid
);

void transaction_encoded_free(transaction_encoded_t *transaction_encoded);

transaction_encoded_t *transaction_encoded_parseFromJSON(cJSON *transaction_encodedJSON);

cJSON *transaction_encoded_convertToJSON(transaction_encoded_t *transaction_encoded);

#endif /* _transaction_encoded_H_ */

