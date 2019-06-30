/*
 * _api_v1_wallet_transaction_hours_selection.h
 *
 * 
 */

#ifndef __api_v1_wallet_transaction_hours_selection_H_
#define __api_v1_wallet_transaction_hours_selection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_wallet_transaction_hours_selection_t {
    char *mode; // string
    char *share_factor; // string
    char *type; // string

} _api_v1_wallet_transaction_hours_selection_t;

_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_create(
    char *mode,
    char *share_factor,
    char *type
);

void _api_v1_wallet_transaction_hours_selection_free(_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection);

_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_parseFromJSON(cJSON *_api_v1_wallet_transaction_hours_selectionJSON);

cJSON *_api_v1_wallet_transaction_hours_selection_convertToJSON(_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection);

#endif /* __api_v1_wallet_transaction_hours_selection_H_ */

