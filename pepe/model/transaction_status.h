/*
 * transaction_status.h
 *
 * 
 */

#ifndef _transaction_status_H_
#define _transaction_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_status_t {
    long block_seq; //numeric
    int confirmed; //boolean
    long height; //numeric
    int unconfirmed; //boolean

} transaction_status_t;

transaction_status_t *transaction_status_create(
    long block_seq,
    int confirmed,
    long height,
    int unconfirmed
);

void transaction_status_free(transaction_status_t *transaction_status);

transaction_status_t *transaction_status_parseFromJSON(cJSON *transaction_statusJSON);

cJSON *transaction_status_convertToJSON(transaction_status_t *transaction_status);

#endif /* _transaction_status_H_ */

