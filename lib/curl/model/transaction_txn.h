/*
 * transaction_txn.h
 *
 * TransactionVerbose has readable transaction data. It adds TransactionStatus to a BlockTransactionVerbose
 */

#ifndef _transaction_txn_H_
#define _transaction_txn_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct transaction_txn_t {
    char *inner_hash; // string
    list_t *inputs; //primitive container
    int length; //numeric
    list_t *outputs; //nonprimitive container
    list_t *sigs; //primitive container
    long timestamp; //numeric
    char *txid; // string
    int type; //numeric

} transaction_txn_t;

transaction_txn_t *transaction_txn_create(
    char *inner_hash,
    list_t *inputs,
    int length,
    list_t *outputs,
    list_t *sigs,
    long timestamp,
    char *txid,
    int type
);

void transaction_txn_free(transaction_txn_t *transaction_txn);

transaction_txn_t *transaction_txn_parseFromJSON(cJSON *transaction_txnJSON);

cJSON *transaction_txn_convertToJSON(transaction_txn_t *transaction_txn);

#endif /* _transaction_txn_H_ */

