#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_verbose_txn_inputs.h"



transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_create(
    char *uxid,
    char *owner,
    char *coins,
    long hours,
    long calculated_hours
    ) {
	transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_local_var = malloc(sizeof(transaction_verbose_txn_inputs_t));
    if (!transaction_verbose_txn_inputs_local_var) {
        return NULL;
    }
	transaction_verbose_txn_inputs_local_var->uxid = uxid;
	transaction_verbose_txn_inputs_local_var->owner = owner;
	transaction_verbose_txn_inputs_local_var->coins = coins;
	transaction_verbose_txn_inputs_local_var->hours = hours;
	transaction_verbose_txn_inputs_local_var->calculated_hours = calculated_hours;

	return transaction_verbose_txn_inputs_local_var;
}


void transaction_verbose_txn_inputs_free(transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs) {
    listEntry_t *listEntry;
    free(transaction_verbose_txn_inputs->uxid);
    free(transaction_verbose_txn_inputs->owner);
    free(transaction_verbose_txn_inputs->coins);
	free(transaction_verbose_txn_inputs);
}

cJSON *transaction_verbose_txn_inputs_convertToJSON(transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs) {
	cJSON *item = cJSON_CreateObject();

	// transaction_verbose_txn_inputs->uxid
    if(transaction_verbose_txn_inputs->uxid) { 
    if(cJSON_AddStringToObject(item, "uxid", transaction_verbose_txn_inputs->uxid) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_verbose_txn_inputs->owner
    if(transaction_verbose_txn_inputs->owner) { 
    if(cJSON_AddStringToObject(item, "owner", transaction_verbose_txn_inputs->owner) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_verbose_txn_inputs->coins
    if(transaction_verbose_txn_inputs->coins) { 
    if(cJSON_AddStringToObject(item, "coins", transaction_verbose_txn_inputs->coins) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_verbose_txn_inputs->hours
    if(transaction_verbose_txn_inputs->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", transaction_verbose_txn_inputs->hours) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_verbose_txn_inputs->calculated_hours
    if(transaction_verbose_txn_inputs->calculated_hours) { 
    if(cJSON_AddNumberToObject(item, "calculated_hours", transaction_verbose_txn_inputs->calculated_hours) == NULL) {
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

transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_parseFromJSON(cJSON *transaction_verbose_txn_inputsJSON){

    transaction_verbose_txn_inputs_t *transaction_verbose_txn_inputs_local_var = NULL;

    // transaction_verbose_txn_inputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txn_inputsJSON, "uxid");
    if (uxid) { 
    if(!cJSON_IsString(uxid))
    {
    goto end; //String
    }
    }

    // transaction_verbose_txn_inputs->owner
    cJSON *owner = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txn_inputsJSON, "owner");
    if (owner) { 
    if(!cJSON_IsString(owner))
    {
    goto end; //String
    }
    }

    // transaction_verbose_txn_inputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txn_inputsJSON, "coins");
    if (coins) { 
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }
    }

    // transaction_verbose_txn_inputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txn_inputsJSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }

    // transaction_verbose_txn_inputs->calculated_hours
    cJSON *calculated_hours = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txn_inputsJSON, "calculated_hours");
    if (calculated_hours) { 
    if(!cJSON_IsNumber(calculated_hours))
    {
    goto end; //Numeric
    }
    }


    transaction_verbose_txn_inputs_local_var = transaction_verbose_txn_inputs_create (
        uxid ? strdup(uxid->valuestring) : NULL,
        owner ? strdup(owner->valuestring) : NULL,
        coins ? strdup(coins->valuestring) : NULL,
        hours ? hours->valuedouble : 0,
        calculated_hours ? calculated_hours->valuedouble : 0
        );

    return transaction_verbose_txn_inputs_local_var;
end:
    return NULL;

}
