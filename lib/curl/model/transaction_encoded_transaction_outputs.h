/*
 * transaction_encoded_transaction_outputs.h
 *
 * 
 */

#ifndef _transaction_encoded_transaction_outputs_H_
#define _transaction_encoded_transaction_outputs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_encoded_transaction_outputs_t {
    char *uxid; // string
    char *dst; // string
    char *coins; // string
    long hours; //numeric

} transaction_encoded_transaction_outputs_t;

transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_create(
    char *uxid,
    char *dst,
    char *coins,
    long hours
);

void transaction_encoded_transaction_outputs_free(transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs);

transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_parseFromJSON(cJSON *transaction_encoded_transaction_outputsJSON);

cJSON *transaction_encoded_transaction_outputs_convertToJSON(transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs);

#endif /* _transaction_encoded_transaction_outputs_H_ */

