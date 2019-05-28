/*
 * transaction_verbose.h
 *
 * 
 */

#ifndef _transaction_verbose_H_
#define _transaction_verbose_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction_status.h"
#include "transaction_verbose_txn.h"



typedef struct transaction_verbose_t {
    long time; //numeric
    transaction_status_t *status; //model
    transaction_verbose_txn_t *txn; //model

} transaction_verbose_t;

transaction_verbose_t *transaction_verbose_create(
    long time,
    transaction_status_t *status,
    transaction_verbose_txn_t *txn
);

void transaction_verbose_free(transaction_verbose_t *transaction_verbose);

transaction_verbose_t *transaction_verbose_parseFromJSON(cJSON *transaction_verboseJSON);

cJSON *transaction_verbose_convertToJSON(transaction_verbose_t *transaction_verbose);

#endif /* _transaction_verbose_H_ */

