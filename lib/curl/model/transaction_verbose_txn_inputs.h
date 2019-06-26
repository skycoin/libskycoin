/*
 * transaction_verbose_txn_inputs.h
 *
 * 
 */

#ifndef _transaction_verbose_txn_inputs_H_
#define _transaction_verbose_txn_inputs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_verbose_txn_inputs_t {
    char *uxid; // string
    char *owner; // string
    char *coins; // string
    long hours; //numeric
    long calculated_hours; //numeric

} transaction_verbose_txn_inputs_t;

transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_create(
    char *uxid,
    char *owner,
    char *coins,
    long hours,
    long calculated_hours
);

void transaction_verbose_txn_inputs_free(transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs);

transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_parseFromJSON(cJSON *transaction_verbose_txn_inputsJSON);

cJSON *transaction_verbose_txn_inputs_convertToJSON(transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs);

#endif /* _transaction_verbose_txn_inputs_H_ */

