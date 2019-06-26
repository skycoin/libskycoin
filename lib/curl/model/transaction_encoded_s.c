#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_encoded_s.h"



transaction_encoded_s_t *transaction_encoded_s_create(
    long time,
    transaction_status_t *status,
    char *encoded_transaction
    ) {
	transaction_encoded_s_t *transaction_encoded_s_local_var = malloc(sizeof(transaction_encoded_s_t));
    if (!transaction_encoded_s_local_var) {
        return NULL;
    }
	transaction_encoded_s_local_var->time = time;
	transaction_encoded_s_local_var->status = status;
	transaction_encoded_s_local_var->encoded_transaction = encoded_transaction;

	return transaction_encoded_s_local_var;
}


void transaction_encoded_s_free(transaction_encoded_s_t *transaction_encoded_s) {
    listEntry_t *listEntry;
    transaction_status_free(transaction_encoded_s->status);
    free(transaction_encoded_s->encoded_transaction);
	free(transaction_encoded_s);
}

cJSON *transaction_encoded_s_convertToJSON(transaction_encoded_s_t *transaction_encoded_s) {
	cJSON *item = cJSON_CreateObject();

	// transaction_encoded_s->time
    if(transaction_encoded_s->time) { 
    if(cJSON_AddNumberToObject(item, "time", transaction_encoded_s->time) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_encoded_s->status
    if(transaction_encoded_s->status) { 
    cJSON *status_local_JSON = transaction_status_convertToJSON(transaction_encoded_s->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction_encoded_s->encoded_transaction
    if(transaction_encoded_s->encoded_transaction) { 
    if(cJSON_AddStringToObject(item, "encoded_transaction", transaction_encoded_s->encoded_transaction) == NULL) {
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

transaction_encoded_s_t *transaction_encoded_s_parseFromJSON(cJSON *transaction_encoded_sJSON){

    transaction_encoded_s_t *transaction_encoded_s_local_var = NULL;

    // transaction_encoded_s->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(transaction_encoded_sJSON, "time");
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }

    // transaction_encoded_s->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(transaction_encoded_sJSON, "status");
    transaction_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = transaction_status_parseFromJSON(status); //nonprimitive
    }

    // transaction_encoded_s->encoded_transaction
    cJSON *encoded_transaction = cJSON_GetObjectItemCaseSensitive(transaction_encoded_sJSON, "encoded_transaction");
    if (encoded_transaction) { 
    if(!cJSON_IsString(encoded_transaction))
    {
    goto end; //String
    }
    }


    transaction_encoded_s_local_var = transaction_encoded_s_create (
        time ? time->valuedouble : 0,
        status ? status_local_nonprim : NULL,
        encoded_transaction ? strdup(encoded_transaction->valuestring) : NULL
        );

    return transaction_encoded_s_local_var;
end:
    return NULL;

}
