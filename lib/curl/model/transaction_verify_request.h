/*
 * transaction_verify_request.h
 *
 *
 */

#ifndef _transaction_verify_request_H_
#define _transaction_verify_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_verify_request_t {
    int unsigned_; //boolean
    char *encoded_transaction; // string

} transaction_verify_request_t;

transaction_verify_request_t *transaction_verify_request_create(
    int unsigned_,
    char *encoded_transaction
);

void transaction_verify_request_free(transaction_verify_request_t *transaction_verify_request);

transaction_verify_request_t *transaction_verify_request_parseFromJSON(cJSON *transaction_verify_requestJSON);

cJSON *transaction_verify_request_convertToJSON(transaction_verify_request_t *transaction_verify_request);

#endif /* _transaction_verify_request_H_ */

