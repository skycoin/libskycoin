/*
 * wallet_transaction_request.h
 *
 * 
 */

#ifndef _wallet_transaction_request_H_
#define _wallet_transaction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"
#include "wallet_transaction_request_hours_selection.h"
#include "wallet_transaction_request_wallet.h"



typedef struct wallet_transaction_request_t {
    char *change_address; // string
    wallet_transaction_request_hours_selection_t *hours_selection; //model
    int ignore_unconfirmed; //boolean
    list_t *to; //nonprimitive container
    wallet_transaction_request_wallet_t *wallet; //model

} wallet_transaction_request_t;

wallet_transaction_request_t *wallet_transaction_request_create(
    char *change_address,
    wallet_transaction_request_hours_selection_t *hours_selection,
    int ignore_unconfirmed,
    list_t *to,
    wallet_transaction_request_wallet_t *wallet
);

void wallet_transaction_request_free(wallet_transaction_request_t *wallet_transaction_request);

wallet_transaction_request_t *wallet_transaction_request_parseFromJSON(cJSON *wallet_transaction_requestJSON);

cJSON *wallet_transaction_request_convertToJSON(wallet_transaction_request_t *wallet_transaction_request);

#endif /* _wallet_transaction_request_H_ */

