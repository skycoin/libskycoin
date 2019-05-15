/*
 * transaction_sign_request.h
 *
 * 
 */

#ifndef _transaction_sign_request_H_
#define _transaction_sign_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_input.h"
#include "transaction_output.h"



typedef struct transaction_sign_request_t {
    list_t *transaction_inputs; //nonprimitive container
    list_t *transaction_outputs; //nonprimitive container

} transaction_sign_request_t;

transaction_sign_request_t *transaction_sign_request_create(
    list_t *transaction_inputs,
    list_t *transaction_outputs
);

void transaction_sign_request_free(transaction_sign_request_t *transaction_sign_request);

transaction_sign_request_t *transaction_sign_request_parseFromJSON(cJSON *transaction_sign_requestJSON);

cJSON *transaction_sign_request_convertToJSON(transaction_sign_request_t *transaction_sign_request);

#endif /* _transaction_sign_request_H_ */

