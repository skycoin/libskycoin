/*
 * transaction_v2_params_address.h
 *
 * 
 */

#ifndef _transaction_v2_params_address_H_
#define _transaction_v2_params_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_v2_params_address_hours_selection.h"



typedef struct transaction_v2_params_address_t {
    transaction_v2_params_address_hours_selection_t *hours_selection; //model

} transaction_v2_params_address_t;

transaction_v2_params_address_t *transaction_v2_params_address_create(
    transaction_v2_params_address_hours_selection_t *hours_selection
);

void transaction_v2_params_address_free(transaction_v2_params_address_t *transaction_v2_params_address);

transaction_v2_params_address_t *transaction_v2_params_address_parseFromJSON(cJSON *transaction_v2_params_addressJSON);

cJSON *transaction_v2_params_address_convertToJSON(transaction_v2_params_address_t *transaction_v2_params_address);

#endif /* _transaction_v2_params_address_H_ */

