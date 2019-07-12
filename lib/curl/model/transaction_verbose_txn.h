/*
 * transaction_verbose_txn.h
 *
 * TransactionVerbose has readable transaction data. It adds TransactionStatus to a BlockTransactionVerbose
 */

#ifndef _transaction_verbose_txn_H_
#define _transaction_verbose_txn_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"
#include "transaction_status.h"
#include "transaction_verbose_txn_inputs.h"



typedef struct transaction_verbose_txn_t {
    transaction_status_t *status; //model
    long fee; //numeric
    char *inner_hash; // string
    list_t *inputs; //nonprimitive container
    int length; //numeric
    list_t *outputs; //nonprimitive container
    list_t *sigs; //primitive container
    long timestamp; //numeric
    char *txid; // string
    int type; //numeric

} transaction_verbose_txn_t;

transaction_verbose_txn_t *transaction_verbose_txn_create(
    transaction_status_t *status,
    long fee,
    char *inner_hash,
    list_t *inputs,
    int length,
    list_t *outputs,
    list_t *sigs,
    long timestamp,
    char *txid,
    int type
);

void transaction_verbose_txn_free(transaction_verbose_txn_t *transaction_verbose_txn);

transaction_verbose_txn_t *transaction_verbose_txn_parseFromJSON(cJSON *transaction_verbose_txnJSON);

cJSON *transaction_verbose_txn_convertToJSON(transaction_verbose_txn_t *transaction_verbose_txn);

#endif /* _transaction_verbose_txn_H_ */

