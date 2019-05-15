#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_output.h"



transaction_output_t *transaction_output_create(
    int address_index,
    char *address,
    char *coins,
    char *hours
    ) {
	transaction_output_t *transaction_output_local_var = malloc(sizeof(transaction_output_t));
    if (!transaction_output_local_var) {
        return NULL;
    }
	transaction_output_local_var->address_index = address_index;
	transaction_output_local_var->address = address;
	transaction_output_local_var->coins = coins;
	transaction_output_local_var->hours = hours;

	return transaction_output_local_var;
}


void transaction_output_free(transaction_output_t *transaction_output) {
    listEntry_t *listEntry;
    free(transaction_output->address);
    free(transaction_output->coins);
    free(transaction_output->hours);
	free(transaction_output);
}

cJSON *transaction_output_convertToJSON(transaction_output_t *transaction_output) {
	cJSON *item = cJSON_CreateObject();

	// transaction_output->address_index
    if (!transaction_output->address_index) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "address_index", transaction_output->address_index) == NULL) {
    goto fail; //Numeric
    }


	// transaction_output->address
    if (!transaction_output->address) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "address", transaction_output->address) == NULL) {
    goto fail; //String
    }


	// transaction_output->coins
    if (!transaction_output->coins) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "coins", transaction_output->coins) == NULL) {
    goto fail; //String
    }


	// transaction_output->hours
    if (!transaction_output->hours) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "hours", transaction_output->hours) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_output_t *transaction_output_parseFromJSON(cJSON *transaction_outputJSON){

    transaction_output_t *transaction_output_local_var = NULL;

    // transaction_output->address_index
    cJSON *address_index = cJSON_GetObjectItemCaseSensitive(transaction_outputJSON, "address_index");
    if (!address_index) {
        goto end;
    }

    
    if(!cJSON_IsNumber(address_index))
    {
    goto end; //Numeric
    }

    // transaction_output->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(transaction_outputJSON, "address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // transaction_output->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(transaction_outputJSON, "coins");
    if (!coins) {
        goto end;
    }

    
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }

    // transaction_output->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(transaction_outputJSON, "hours");
    if (!hours) {
        goto end;
    }

    
    if(!cJSON_IsString(hours))
    {
    goto end; //String
    }


    transaction_output_local_var = transaction_output_create (
        address_index->valuedouble,
        strdup(address->valuestring),
        strdup(coins->valuestring),
        strdup(hours->valuestring)
        );

    return transaction_output_local_var;
end:
    return NULL;

}
