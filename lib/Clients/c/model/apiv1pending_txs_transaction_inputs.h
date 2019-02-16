/*
 * apiv1pending_txs_transaction_inputs.h
 *
 * 
 */

#ifndef _apiv1pending_txs_transaction_inputs_H_
#define _apiv1pending_txs_transaction_inputs_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1pending_txs_transaction_inputs_t {
        long hours; //numeric
        long calculated_hours; //numeric
        char *dst; //no enum string
        char *coins; //no enum string
        char *uxid; //no enum string

} apiv1pending_txs_transaction_inputs_t;

apiv1pending_txs_transaction_inputs_t *apiv1pending_txs_transaction_inputs_create(
        long hours,
        long calculated_hours,
        char *dst,
        char *coins,
        char *uxid
);

void apiv1pending_txs_transaction_inputs_free(apiv1pending_txs_transaction_inputs_t *apiv1pending_txs_transaction_inputs);

apiv1pending_txs_transaction_inputs_t *apiv1pending_txs_transaction_inputs_parseFromJSON(char *jsonString);

cJSON *apiv1pending_txs_transaction_inputs_convertToJSON(apiv1pending_txs_transaction_inputs_t *apiv1pending_txs_transaction_inputs);

#endif /* _apiv1pending_txs_transaction_inputs_H_ */

