/*
 * transaction.h
 *
 * 
 */

#ifndef _transaction_H_
#define _transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_status.h"
#include "transaction_txn.h"



typedef struct transaction_t {
    transaction_status_t *status; //model
    transaction_txn_t *txn; //model
    long time; //numeric

} transaction_t;

transaction_t *transaction_create(
    transaction_status_t *status,
    transaction_txn_t *txn,
    long time
);

void transaction_free(transaction_t *transaction);

transaction_t *transaction_parseFromJSON(cJSON *transactionJSON);

cJSON *transaction_convertToJSON(transaction_t *transaction);

#endif /* _transaction_H_ */

