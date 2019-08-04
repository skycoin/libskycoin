/*
 * transaction_input.h
 *
 * 
 */

#ifndef _transaction_input_H_
#define _transaction_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_input_t {
    int index; //numeric
    char *hash; // string

} transaction_input_t;

transaction_input_t *transaction_input_create(
    int index,
    char *hash
);

void transaction_input_free(transaction_input_t *transaction_input);

transaction_input_t *transaction_input_parseFromJSON(cJSON *transaction_inputJSON);

cJSON *transaction_input_convertToJSON(transaction_input_t *transaction_input);

#endif /* _transaction_input_H_ */

