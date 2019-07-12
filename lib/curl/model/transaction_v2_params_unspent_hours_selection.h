/*
 * transaction_v2_params_unspent_hours_selection.h
 *
 * 
 */

#ifndef _transaction_v2_params_unspent_hours_selection_H_
#define _transaction_v2_params_unspent_hours_selection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_v2_params_unspent_hours_selection_t {
    char *type; // string
    char *mode; // string
    char *share_factor; // string

} transaction_v2_params_unspent_hours_selection_t;

transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_create(
    char *type,
    char *mode,
    char *share_factor
);

void transaction_v2_params_unspent_hours_selection_free(transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection);

transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_parseFromJSON(cJSON *transaction_v2_params_unspent_hours_selectionJSON);

cJSON *transaction_v2_params_unspent_hours_selection_convertToJSON(transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection);

#endif /* _transaction_v2_params_unspent_hours_selection_H_ */

