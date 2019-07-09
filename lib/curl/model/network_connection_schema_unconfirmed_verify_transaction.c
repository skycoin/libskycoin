#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_schema_unconfirmed_verify_transaction.h"



network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_create(
    int burn_factor,
    int max_decimals,
    int max_transaction_size
    ) {
	network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_local_var = malloc(sizeof(network_connection_schema_unconfirmed_verify_transaction_t));
    if (!network_connection_schema_unconfirmed_verify_transaction_local_var) {
        return NULL;
    }
	network_connection_schema_unconfirmed_verify_transaction_local_var->burn_factor = burn_factor;
	network_connection_schema_unconfirmed_verify_transaction_local_var->max_decimals = max_decimals;
	network_connection_schema_unconfirmed_verify_transaction_local_var->max_transaction_size = max_transaction_size;

	return network_connection_schema_unconfirmed_verify_transaction_local_var;
}


void network_connection_schema_unconfirmed_verify_transaction_free(network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction) {
    listEntry_t *listEntry;
	free(network_connection_schema_unconfirmed_verify_transaction);
}

cJSON *network_connection_schema_unconfirmed_verify_transaction_convertToJSON(network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction) {
	cJSON *item = cJSON_CreateObject();

	// network_connection_schema_unconfirmed_verify_transaction->burn_factor
    if(network_connection_schema_unconfirmed_verify_transaction->burn_factor) { 
    if(cJSON_AddNumberToObject(item, "burn_factor", network_connection_schema_unconfirmed_verify_transaction->burn_factor) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema_unconfirmed_verify_transaction->max_decimals
    if(network_connection_schema_unconfirmed_verify_transaction->max_decimals) { 
    if(cJSON_AddNumberToObject(item, "max_decimals", network_connection_schema_unconfirmed_verify_transaction->max_decimals) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema_unconfirmed_verify_transaction->max_transaction_size
    if(network_connection_schema_unconfirmed_verify_transaction->max_transaction_size) { 
    if(cJSON_AddNumberToObject(item, "max_transaction_size", network_connection_schema_unconfirmed_verify_transaction->max_transaction_size) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_parseFromJSON(cJSON *network_connection_schema_unconfirmed_verify_transactionJSON){

    network_connection_schema_unconfirmed_verify_transaction_t *network_connection_schema_unconfirmed_verify_transaction_local_var = NULL;

    // network_connection_schema_unconfirmed_verify_transaction->burn_factor
    cJSON *burn_factor = cJSON_GetObjectItemCaseSensitive(network_connection_schema_unconfirmed_verify_transactionJSON, "burn_factor");
    if (burn_factor) { 
    if(!cJSON_IsNumber(burn_factor))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema_unconfirmed_verify_transaction->max_decimals
    cJSON *max_decimals = cJSON_GetObjectItemCaseSensitive(network_connection_schema_unconfirmed_verify_transactionJSON, "max_decimals");
    if (max_decimals) { 
    if(!cJSON_IsNumber(max_decimals))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema_unconfirmed_verify_transaction->max_transaction_size
    cJSON *max_transaction_size = cJSON_GetObjectItemCaseSensitive(network_connection_schema_unconfirmed_verify_transactionJSON, "max_transaction_size");
    if (max_transaction_size) { 
    if(!cJSON_IsNumber(max_transaction_size))
    {
    goto end; //Numeric
    }
    }


    network_connection_schema_unconfirmed_verify_transaction_local_var = network_connection_schema_unconfirmed_verify_transaction_create (
        burn_factor ? burn_factor->valuedouble : 0,
        max_decimals ? max_decimals->valuedouble : 0,
        max_transaction_size ? max_transaction_size->valuedouble : 0
        );

    return network_connection_schema_unconfirmed_verify_transaction_local_var;
end:
    return NULL;

}
