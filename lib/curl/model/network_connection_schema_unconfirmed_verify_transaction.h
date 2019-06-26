/*
 * network_connection_schema_unconfirmed_verify_transaction.h
 *
 * Represent unconfirmed transactions
 */

#ifndef _network_connection_schema_unconfirmed_verify_transaction_H_
#define _network_connection_schema_unconfirmed_verify_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct network_connection_schema_unconfirmed_verify_transaction_t {
    int burn_factor; //numeric
    int max_decimals; //numeric
    int max_transaction_size; //numeric

} network_connection_schema_unconfirmed_verify_transaction_t;

network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_create(
    int burn_factor,
    int max_decimals,
    int max_transaction_size
);

void network_connection_schema_unconfirmed_verify_transaction_free(network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction);

network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_parseFromJSON(cJSON *network_connection_schema_unconfirmed_verify_transactionJSON);

cJSON *network_connection_schema_unconfirmed_verify_transaction_convertToJSON(network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction);

#endif /* _network_connection_schema_unconfirmed_verify_transaction_H_ */

