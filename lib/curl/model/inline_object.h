/*
 * inline_object.h
 *
 * 
 */

#ifndef _inline_object_H_
#define _inline_object_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_wallet_transaction_hours_selection.h"
#include "_api_v1_wallet_transaction_to.h"
#include "_api_v1_wallet_transaction_wallet.h"



typedef struct inline_object_t {
    char *change_address; // string
    _api_v1_wallet_transaction_hours_selection_t *hours_selection; //model
    int ignore_unconfirmed; //boolean
    list_t *to; //nonprimitive container
    _api_v1_wallet_transaction_wallet_t *wallet; //model

} inline_object_t;

inline_object_t *inline_object_create(
    char *change_address,
    _api_v1_wallet_transaction_hours_selection_t *hours_selection,
    int ignore_unconfirmed,
    list_t *to,
    _api_v1_wallet_transaction_wallet_t *wallet
);

void inline_object_free(inline_object_t *inline_object);

inline_object_t *inline_object_parseFromJSON(cJSON *inline_objectJSON);

cJSON *inline_object_convertToJSON(inline_object_t *inline_object);

#endif /* _inline_object_H_ */

