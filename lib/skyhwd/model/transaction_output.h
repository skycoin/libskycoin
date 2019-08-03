/*
 * transaction_output.h
 *
 * 
 */

#ifndef _transaction_output_H_
#define _transaction_output_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct transaction_output_t {
    int address_index; //numeric
    char *address; // string
    char *coins; // string
    char *hours; // string

} transaction_output_t;

transaction_output_t *transaction_output_create(
    int address_index,
    char *address,
    char *coins,
    char *hours
);

void transaction_output_free(transaction_output_t *transaction_output);

transaction_output_t *transaction_output_parseFromJSON(cJSON *transaction_outputJSON);

cJSON *transaction_output_convertToJSON(transaction_output_t *transaction_output);

#endif /* _transaction_output_H_ */

