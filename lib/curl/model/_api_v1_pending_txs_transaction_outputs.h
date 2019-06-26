/*
 * _api_v1_pending_txs_transaction_outputs.h
 *
 * 
 */

#ifndef __api_v1_pending_txs_transaction_outputs_H_
#define __api_v1_pending_txs_transaction_outputs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_pending_txs_transaction_outputs_t {
    char *uxid; // string
    char *dst; // string
    char *coins; // string
    long hours; //numeric

} _api_v1_pending_txs_transaction_outputs_t;

_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_create(
    char *uxid,
    char *dst,
    char *coins,
    long hours
);

void _api_v1_pending_txs_transaction_outputs_free(_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs);

_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_parseFromJSON(cJSON *_api_v1_pending_txs_transaction_outputsJSON);

cJSON *_api_v1_pending_txs_transaction_outputs_convertToJSON(_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs);

#endif /* __api_v1_pending_txs_transaction_outputs_H_ */

