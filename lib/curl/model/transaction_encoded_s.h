/*
 * transaction_encoded_s.h
 *
 * 
 */

#ifndef _transaction_encoded_s_H_
#define _transaction_encoded_s_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_status.h"



typedef struct transaction_encoded_s_t {
    long time; //numeric
    transaction_status_t *status; //model
    char *encoded_transaction; // string

} transaction_encoded_s_t;

transaction_encoded_s_t *transaction_encoded_s_create(
    long time,
    transaction_status_t *status,
    char *encoded_transaction
);

void transaction_encoded_s_free(transaction_encoded_s_t *transaction_encoded_s);

transaction_encoded_s_t *transaction_encoded_s_parseFromJSON(cJSON *transaction_encoded_sJSON);

cJSON *transaction_encoded_s_convertToJSON(transaction_encoded_s_t *transaction_encoded_s);

#endif /* _transaction_encoded_s_H_ */

