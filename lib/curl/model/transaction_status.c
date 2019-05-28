#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_status.h"



transaction_status_t *transaction_status_create(
    long block_seq,
    int confirmed,
    long height,
    int unconfirmed
    ) {
	transaction_status_t *transaction_status_local_var = malloc(sizeof(transaction_status_t));
    if (!transaction_status_local_var) {
        return NULL;
    }
	transaction_status_local_var->block_seq = block_seq;
	transaction_status_local_var->confirmed = confirmed;
	transaction_status_local_var->height = height;
	transaction_status_local_var->unconfirmed = unconfirmed;

	return transaction_status_local_var;
}


void transaction_status_free(transaction_status_t *transaction_status) {
    listEntry_t *listEntry;
	free(transaction_status);
}

cJSON *transaction_status_convertToJSON(transaction_status_t *transaction_status) {
	cJSON *item = cJSON_CreateObject();

	// transaction_status->block_seq
    if(transaction_status->block_seq) { 
    if(cJSON_AddNumberToObject(item, "block_seq", transaction_status->block_seq) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_status->confirmed
    if(transaction_status->confirmed) { 
    if(cJSON_AddBoolToObject(item, "confirmed", transaction_status->confirmed) == NULL) {
    goto fail; //Bool
    }
     } 


	// transaction_status->height
    if(transaction_status->height) { 
    if(cJSON_AddNumberToObject(item, "height", transaction_status->height) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_status->unconfirmed
    if(transaction_status->unconfirmed) { 
    if(cJSON_AddBoolToObject(item, "unconfirmed", transaction_status->unconfirmed) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_status_t *transaction_status_parseFromJSON(cJSON *transaction_statusJSON){

    transaction_status_t *transaction_status_local_var = NULL;

    // transaction_status->block_seq
    cJSON *block_seq = cJSON_GetObjectItemCaseSensitive(transaction_statusJSON, "block_seq");
    if (block_seq) { 
    if(!cJSON_IsNumber(block_seq))
    {
    goto end; //Numeric
    }
    }

    // transaction_status->confirmed
    cJSON *confirmed = cJSON_GetObjectItemCaseSensitive(transaction_statusJSON, "confirmed");
    if (confirmed) { 
    if(!cJSON_IsBool(confirmed))
    {
    goto end; //Bool
    }
    }

    // transaction_status->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(transaction_statusJSON, "height");
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // transaction_status->unconfirmed
    cJSON *unconfirmed = cJSON_GetObjectItemCaseSensitive(transaction_statusJSON, "unconfirmed");
    if (unconfirmed) { 
    if(!cJSON_IsBool(unconfirmed))
    {
    goto end; //Bool
    }
    }


    transaction_status_local_var = transaction_status_create (
        block_seq ? block_seq->valuedouble : 0,
        confirmed ? confirmed->valueint : 0,
        height ? height->valuedouble : 0,
        unconfirmed ? unconfirmed->valueint : 0
        );

    return transaction_status_local_var;
end:
    return NULL;

}
