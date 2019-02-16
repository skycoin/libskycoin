/*
 * apiv1transactions_txn.h
 *
 * TransactionVerbose has readable transaction data. It adds TransactionStatus to a BlockTransactionVerbose
 */

#ifndef _apiv1transactions_txn_H_
#define _apiv1transactions_txn_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1pending_txs_transaction_inputs.h"
#include "apiv1transactions_txn_status.h"
#include "list.h"




typedef struct apiv1transactions_txn_t {
        list_t *outputs; //nonprimitive container
        char *inner_hash; //no enum string
        list_t *inputs; //nonprimitive container
        int fee; //numeric
        list_t *sigs; //primitive container
        int length; //numeric
        int type; //numeric
        char *hash; //no enum string
        apiv1transactions_txn_status_t *status; //nonprimitive
        long timestamp; //numeric

} apiv1transactions_txn_t;

apiv1transactions_txn_t *apiv1transactions_txn_create(
        list_t *outputs,
        char *inner_hash,
        list_t *inputs,
        int fee,
        list_t *sigs,
        int length,
        int type,
        char *hash,
        apiv1transactions_txn_status_t *status,
        long timestamp
);

void apiv1transactions_txn_free(apiv1transactions_txn_t *apiv1transactions_txn);

apiv1transactions_txn_t *apiv1transactions_txn_parseFromJSON(char *jsonString);

cJSON *apiv1transactions_txn_convertToJSON(apiv1transactions_txn_t *apiv1transactions_txn);

#endif /* _apiv1transactions_txn_H_ */

