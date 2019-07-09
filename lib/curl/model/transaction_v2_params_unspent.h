/*
 * transaction_v2_params_unspent.h
 *
 * 
 */

#ifndef _transaction_v2_params_unspent_H_
#define _transaction_v2_params_unspent_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_v2_params_unspent_hours_selection.h"
#include "transaction_v2_params_unspent_to.h"



typedef struct transaction_v2_params_unspent_t {
    transaction_v2_params_unspent_hours_selection_t *hours_selection; //model
    list_t *unspents; //primitive container
    char *change_address; // string
    list_t *to; //nonprimitive container

} transaction_v2_params_unspent_t;

transaction_v2_params_unspent_t *transaction_v2_params_unspent_create(
    transaction_v2_params_unspent_hours_selection_t *hours_selection,
    list_t *unspents,
    char *change_address,
    list_t *to
);

void transaction_v2_params_unspent_free(transaction_v2_params_unspent_t *transaction_v2_params_unspent);

transaction_v2_params_unspent_t *transaction_v2_params_unspent_parseFromJSON(cJSON *transaction_v2_params_unspentJSON);

cJSON *transaction_v2_params_unspent_convertToJSON(transaction_v2_params_unspent_t *transaction_v2_params_unspent);

#endif /* _transaction_v2_params_unspent_H_ */

