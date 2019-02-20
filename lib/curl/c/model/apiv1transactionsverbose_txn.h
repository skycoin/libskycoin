/*
 * apiv1transactionsverbose_txn.h
 *
 * TransactionVerbose has readable transaction data. It adds TransactionStatus to a BlockTransactionVerbose
 */

#ifndef _apiv1transactionsverbose_txn_H_
#define _apiv1transactionsverbose_txn_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1pending_txsverbose_transaction_inputs.h"
#include "apiv1transactionsverbose_txn_status.h"
#include "list.h"




typedef struct apiv1transactionsverbose_txn_t {
        list_t *outputs; //nonprimitive container
        char *inner_hash; //no enum string
        list_t *inputs; //nonprimitive container
        int fee; //numeric
        list_t *sigs; //primitive container
        int length; //numeric
        int type; //numeric
        char *hash; //no enum string
        apiv1transactionsverbose_txn_status_t *status; //nonprimitive
        long timestamp; //numeric

} apiv1transactionsverbose_txn_t;

apiv1transactionsverbose_txn_t *apiv1transactionsverbose_txn_create(
        list_t *outputs,
        char *inner_hash,
        list_t *inputs,
        int fee,
        list_t *sigs,
        int length,
        int type,
        char *hash,
        apiv1transactionsverbose_txn_status_t *status,
        long timestamp
);

void apiv1transactionsverbose_txn_free(apiv1transactionsverbose_txn_t *apiv1transactionsverbose_txn);

apiv1transactionsverbose_txn_t *apiv1transactionsverbose_txn_parseFromJSON(char *jsonString);

cJSON *apiv1transactionsverbose_txn_convertToJSON(apiv1transactionsverbose_txn_t *apiv1transactionsverbose_txn);

#endif /* _apiv1transactionsverbose_txn_H_ */

