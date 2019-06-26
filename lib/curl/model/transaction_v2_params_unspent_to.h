/*
 * transaction_v2_params_unspent_to.h
 *
 * 
 */

#ifndef _transaction_v2_params_unspent_to_H_
#define _transaction_v2_params_unspent_to_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_v2_params_unspent_to_t {
    char *address; // string
    char *coins; // string

} transaction_v2_params_unspent_to_t;

transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_create(
    char *address,
    char *coins
);

void transaction_v2_params_unspent_to_free(transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to);

transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_parseFromJSON(cJSON *transaction_v2_params_unspent_toJSON);

cJSON *transaction_v2_params_unspent_to_convertToJSON(transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to);

#endif /* _transaction_v2_params_unspent_to_H_ */

