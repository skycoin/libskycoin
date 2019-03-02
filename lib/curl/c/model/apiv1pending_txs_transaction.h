/*
 * apiv1pending_txs_transaction.h
 *
 * BlockTransactionVerbose has readable transaction data for transactions inside a block. It differs from Transaction in that it includes metadata for transaction inputs and the calculated coinhour fee spent by the block
 */

#ifndef _apiv1pending_txs_transaction_H_
#define _apiv1pending_txs_transaction_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1exploreraddress_outputs.h"
#include "list.h"




typedef struct apiv1pending_txs_transaction_t {
        list_t *outputs; //nonprimitive container
        char *inner_hash; //no enum string
        list_t *inputs; //primitive container
        list_t *sigs; //primitive container
        int length; //numeric
        char *txid; //no enum string
        int type; //numeric
        int timestamp; //numeric

} apiv1pending_txs_transaction_t;

apiv1pending_txs_transaction_t *apiv1pending_txs_transaction_create(
        list_t *outputs,
        char *inner_hash,
        list_t *inputs,
        list_t *sigs,
        int length,
        char *txid,
        int type,
        int timestamp
);

void apiv1pending_txs_transaction_free(apiv1pending_txs_transaction_t *apiv1pending_txs_transaction);

apiv1pending_txs_transaction_t *apiv1pending_txs_transaction_parseFromJSON(char *jsonString);

cJSON *apiv1pending_txs_transaction_convertToJSON(apiv1pending_txs_transaction_t *apiv1pending_txs_transaction);

#endif /* _apiv1pending_txs_transaction_H_ */

