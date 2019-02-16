/*
 * apiv1transactions_txn_status.h
 *
 * 
 */

#ifndef _apiv1transactions_txn_status_H_
#define _apiv1transactions_txn_status_H_

#include <string.h>
#include "cJSON.h"

typedef int bool;
#define true 1
#define false 0
typedef int bool;
#define true 1
#define false 0



typedef struct apiv1transactions_txn_status_t {
        bool unconfirmed; //boolean
        long block_seq; //numeric
        bool confirmed; //boolean
        long height; //numeric

} apiv1transactions_txn_status_t;

apiv1transactions_txn_status_t *apiv1transactions_txn_status_create(
        bool unconfirmed,
        long block_seq,
        bool confirmed,
        long height
);

void apiv1transactions_txn_status_free(apiv1transactions_txn_status_t *apiv1transactions_txn_status);

apiv1transactions_txn_status_t *apiv1transactions_txn_status_parseFromJSON(char *jsonString);

cJSON *apiv1transactions_txn_status_convertToJSON(apiv1transactions_txn_status_t *apiv1transactions_txn_status);

#endif /* _apiv1transactions_txn_status_H_ */

