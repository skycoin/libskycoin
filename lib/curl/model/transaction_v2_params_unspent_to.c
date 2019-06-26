#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_v2_params_unspent_to.h"



transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_create(
    char *address,
    char *coins
    ) {
	transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_local_var = malloc(sizeof(transaction_v2_params_unspent_to_t));
    if (!transaction_v2_params_unspent_to_local_var) {
        return NULL;
    }
	transaction_v2_params_unspent_to_local_var->address = address;
	transaction_v2_params_unspent_to_local_var->coins = coins;

	return transaction_v2_params_unspent_to_local_var;
}


void transaction_v2_params_unspent_to_free(transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to) {
    listEntry_t *listEntry;
    free(transaction_v2_params_unspent_to->address);
    free(transaction_v2_params_unspent_to->coins);
	free(transaction_v2_params_unspent_to);
}

cJSON *transaction_v2_params_unspent_to_convertToJSON(transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to) {
	cJSON *item = cJSON_CreateObject();

	// transaction_v2_params_unspent_to->address
    if(transaction_v2_params_unspent_to->address) { 
    if(cJSON_AddStringToObject(item, "address", transaction_v2_params_unspent_to->address) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_v2_params_unspent_to->coins
    if(transaction_v2_params_unspent_to->coins) { 
    if(cJSON_AddStringToObject(item, "coins", transaction_v2_params_unspent_to->coins) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_parseFromJSON(cJSON *transaction_v2_params_unspent_toJSON){

    transaction_v2_params_unspent_to_t *transaction_v2_params_unspent_to_local_var = NULL;

    // transaction_v2_params_unspent_to->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspent_toJSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }

    // transaction_v2_params_unspent_to->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspent_toJSON, "coins");
    if (coins) { 
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }
    }


    transaction_v2_params_unspent_to_local_var = transaction_v2_params_unspent_to_create (
        address ? strdup(address->valuestring) : NULL,
        coins ? strdup(coins->valuestring) : NULL
        );

    return transaction_v2_params_unspent_to_local_var;
end:
    return NULL;

}
