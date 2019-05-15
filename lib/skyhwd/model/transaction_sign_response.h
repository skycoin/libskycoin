/*
 * transaction_sign_response.h
 *
 * 
 */

#ifndef _transaction_sign_response_H_
#define _transaction_sign_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_sign_response_t {
    list_t *data; //primitive container

} transaction_sign_response_t;

transaction_sign_response_t *transaction_sign_response_create(
    list_t *data
);

void transaction_sign_response_free(transaction_sign_response_t *transaction_sign_response);

transaction_sign_response_t *transaction_sign_response_parseFromJSON(cJSON *transaction_sign_responseJSON);

cJSON *transaction_sign_response_convertToJSON(transaction_sign_response_t *transaction_sign_response);

#endif /* _transaction_sign_response_H_ */

