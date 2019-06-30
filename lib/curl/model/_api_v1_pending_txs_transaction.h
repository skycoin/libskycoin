/*
 * _api_v1_pending_txs_transaction.h
 *
 * BlockTransactionVerbose has readable transaction data for transactions inside a block. It differs from Transaction in that it includes metadata for transaction inputs and the calculated coinhour fee spent by the block
 */

#ifndef __api_v1_pending_txs_transaction_H_
#define __api_v1_pending_txs_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_explorer_address_outputs.h"



typedef struct _api_v1_pending_txs_transaction_t {
    list_t *outputs; //nonprimitive container
    char *inner_hash; // string
    list_t *inputs; //primitive container
    list_t *sigs; //primitive container
    int length; //numeric
    char *txid; // string
    int type; //numeric
    int timestamp; //numeric

} _api_v1_pending_txs_transaction_t;

_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    list_t *sigs,
    int length,
    char *txid,
    int type,
    int timestamp
);

void _api_v1_pending_txs_transaction_free(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction);

_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_parseFromJSON(cJSON *_api_v1_pending_txs_transactionJSON);

cJSON *_api_v1_pending_txs_transaction_convertToJSON(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction);

#endif /* __api_v1_pending_txs_transaction_H_ */

