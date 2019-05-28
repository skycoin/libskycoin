/*
 * transaction_encoded_transaction.h
 *
 * 
 */

#ifndef _transaction_encoded_transaction_H_
#define _transaction_encoded_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_encoded_transaction_outputs.h"



typedef struct transaction_encoded_transaction_t {
    long length; //numeric
    long type; //numeric
    char *txid; // string
    char *inner_hash; // string
    list_t *sigs; //primitive container
    list_t *inputs; //primitive container
    list_t *outputs; //nonprimitive container

} transaction_encoded_transaction_t;

transaction_encoded_transaction_t *transaction_encoded_transaction_create(
    long length,
    long type,
    char *txid,
    char *inner_hash,
    list_t *sigs,
    list_t *inputs,
    list_t *outputs
);

void transaction_encoded_transaction_free(transaction_encoded_transaction_t *transaction_encoded_transaction);

transaction_encoded_transaction_t *transaction_encoded_transaction_parseFromJSON(cJSON *transaction_encoded_transactionJSON);

cJSON *transaction_encoded_transaction_convertToJSON(transaction_encoded_transaction_t *transaction_encoded_transaction);

#endif /* _transaction_encoded_transaction_H_ */

