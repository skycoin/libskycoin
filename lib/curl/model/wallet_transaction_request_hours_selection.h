/*
 * wallet_transaction_request_hours_selection.h
 *
 * 
 */

#ifndef _wallet_transaction_request_hours_selection_H_
#define _wallet_transaction_request_hours_selection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct wallet_transaction_request_hours_selection_t {
    char *mode; // string
    char *share_factor; // string
    char *type; // string

} wallet_transaction_request_hours_selection_t;

wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_create(
    char *mode,
    char *share_factor,
    char *type
);

void wallet_transaction_request_hours_selection_free(wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection);

wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_parseFromJSON(cJSON *wallet_transaction_request_hours_selectionJSON);

cJSON *wallet_transaction_request_hours_selection_convertToJSON(wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection);

#endif /* _wallet_transaction_request_hours_selection_H_ */

