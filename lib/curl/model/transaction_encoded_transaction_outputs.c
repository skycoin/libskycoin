#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_encoded_transaction_outputs.h"



transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_create(
    char *uxid,
    char *dst,
    char *coins,
    long hours
    ) {
	transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_local_var = malloc(sizeof(transaction_encoded_transaction_outputs_t));
    if (!transaction_encoded_transaction_outputs_local_var) {
        return NULL;
    }
	transaction_encoded_transaction_outputs_local_var->uxid = uxid;
	transaction_encoded_transaction_outputs_local_var->dst = dst;
	transaction_encoded_transaction_outputs_local_var->coins = coins;
	transaction_encoded_transaction_outputs_local_var->hours = hours;

	return transaction_encoded_transaction_outputs_local_var;
}


void transaction_encoded_transaction_outputs_free(transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs) {
    listEntry_t *listEntry;
    free(transaction_encoded_transaction_outputs->uxid);
    free(transaction_encoded_transaction_outputs->dst);
    free(transaction_encoded_transaction_outputs->coins);
	free(transaction_encoded_transaction_outputs);
}

cJSON *transaction_encoded_transaction_outputs_convertToJSON(transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs) {
	cJSON *item = cJSON_CreateObject();

	// transaction_encoded_transaction_outputs->uxid
    if(transaction_encoded_transaction_outputs->uxid) { 
    if(cJSON_AddStringToObject(item, "uxid", transaction_encoded_transaction_outputs->uxid) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded_transaction_outputs->dst
    if(transaction_encoded_transaction_outputs->dst) { 
    if(cJSON_AddStringToObject(item, "dst", transaction_encoded_transaction_outputs->dst) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded_transaction_outputs->coins
    if(transaction_encoded_transaction_outputs->coins) { 
    if(cJSON_AddStringToObject(item, "coins", transaction_encoded_transaction_outputs->coins) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded_transaction_outputs->hours
    if(transaction_encoded_transaction_outputs->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", transaction_encoded_transaction_outputs->hours) == NULL) {
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

transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_parseFromJSON(cJSON *transaction_encoded_transaction_outputsJSON){

    transaction_encoded_transaction_outputs_t *transaction_encoded_transaction_outputs_local_var = NULL;

    // transaction_encoded_transaction_outputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transaction_outputsJSON, "uxid");
    if (uxid) { 
    if(!cJSON_IsString(uxid))
    {
    goto end; //String
    }
    }

    // transaction_encoded_transaction_outputs->dst
    cJSON *dst = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transaction_outputsJSON, "dst");
    if (dst) { 
    if(!cJSON_IsString(dst))
    {
    goto end; //String
    }
    }

    // transaction_encoded_transaction_outputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transaction_outputsJSON, "coins");
    if (coins) { 
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }
    }

    // transaction_encoded_transaction_outputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transaction_outputsJSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }


    transaction_encoded_transaction_outputs_local_var = transaction_encoded_transaction_outputs_create (
        uxid ? strdup(uxid->valuestring) : NULL,
        dst ? strdup(dst->valuestring) : NULL,
        coins ? strdup(coins->valuestring) : NULL,
        hours ? hours->valuedouble : 0
        );

    return transaction_encoded_transaction_outputs_local_var;
end:
    return NULL;

}
