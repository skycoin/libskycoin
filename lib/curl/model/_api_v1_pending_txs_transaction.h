/*
 * _api_v1_pending_txs_transaction.h
 *
 * 
 */

#ifndef __api_v1_pending_txs_transaction_H_
#define __api_v1_pending_txs_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_pending_txs_transaction_outputs.h"



typedef struct _api_v1_pending_txs_transaction_t {
    long length; //numeric
    long type; //numeric
    char *txid; // string
    char *inner_hash; // string
    list_t *sigs; //primitive container
    list_t *inputs; //primitive container
    list_t *outputs; //nonprimitive container

} _api_v1_pending_txs_transaction_t;

_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_create(
    long length,
    long type,
    char *txid,
    char *inner_hash,
    list_t *sigs,
    list_t *inputs,
    list_t *outputs
);

void _api_v1_pending_txs_transaction_free(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction);

_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_parseFromJSON(cJSON *_api_v1_pending_txs_transactionJSON);

cJSON *_api_v1_pending_txs_transaction_convertToJSON(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction);

#endif /* __api_v1_pending_txs_transaction_H_ */

