#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_encoded.h"



transaction_encoded_t *transaction_encoded_create(
    _api_v1_pending_txs_transaction_t *transaction,
    char *received,
    char *checked,
    char *announced,
    int is_valid
    ) {
	transaction_encoded_t *transaction_encoded_local_var = malloc(sizeof(transaction_encoded_t));
    if (!transaction_encoded_local_var) {
        return NULL;
    }
	transaction_encoded_local_var->transaction = transaction;
	transaction_encoded_local_var->received = received;
	transaction_encoded_local_var->checked = checked;
	transaction_encoded_local_var->announced = announced;
	transaction_encoded_local_var->is_valid = is_valid;

	return transaction_encoded_local_var;
}


void transaction_encoded_free(transaction_encoded_t *transaction_encoded) {
    listEntry_t *listEntry;
    _api_v1_pending_txs_transaction_free(transaction_encoded->transaction);
    free(transaction_encoded->received);
    free(transaction_encoded->checked);
    free(transaction_encoded->announced);
	free(transaction_encoded);
}

cJSON *transaction_encoded_convertToJSON(transaction_encoded_t *transaction_encoded) {
	cJSON *item = cJSON_CreateObject();

	// transaction_encoded->transaction
    if(transaction_encoded->transaction) { 
    cJSON *transaction_local_JSON = _api_v1_pending_txs_transaction_convertToJSON(transaction_encoded->transaction);
    if(transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "transaction", transaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction_encoded->received
    if(transaction_encoded->received) { 
    if(cJSON_AddStringToObject(item, "received", transaction_encoded->received) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded->checked
    if(transaction_encoded->checked) { 
    if(cJSON_AddStringToObject(item, "checked", transaction_encoded->checked) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded->announced
    if(transaction_encoded->announced) { 
    if(cJSON_AddStringToObject(item, "announced", transaction_encoded->announced) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded->is_valid
    if(transaction_encoded->is_valid) { 
    if(cJSON_AddBoolToObject(item, "is_valid", transaction_encoded->is_valid) == NULL) {
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

transaction_encoded_t *transaction_encoded_parseFromJSON(cJSON *transaction_encodedJSON){

    transaction_encoded_t *transaction_encoded_local_var = NULL;

    // transaction_encoded->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(transaction_encodedJSON, "transaction");
    _api_v1_pending_txs_transaction_t *transaction_local_nonprim = NULL;
    if (transaction) { 
    transaction_local_nonprim = _api_v1_pending_txs_transaction_parseFromJSON(transaction); //nonprimitive
    }

    // transaction_encoded->received
    cJSON *received = cJSON_GetObjectItemCaseSensitive(transaction_encodedJSON, "received");
    if (received) { 
    if(!cJSON_IsString(received))
    {
    goto end; //String
    }
    }

    // transaction_encoded->checked
    cJSON *checked = cJSON_GetObjectItemCaseSensitive(transaction_encodedJSON, "checked");
    if (checked) { 
    if(!cJSON_IsString(checked))
    {
    goto end; //String
    }
    }

    // transaction_encoded->announced
    cJSON *announced = cJSON_GetObjectItemCaseSensitive(transaction_encodedJSON, "announced");
    if (announced) { 
    if(!cJSON_IsString(announced))
    {
    goto end; //String
    }
    }

    // transaction_encoded->is_valid
    cJSON *is_valid = cJSON_GetObjectItemCaseSensitive(transaction_encodedJSON, "is_valid");
    if (is_valid) { 
    if(!cJSON_IsBool(is_valid))
    {
    goto end; //Bool
    }
    }


    transaction_encoded_local_var = transaction_encoded_create (
        transaction ? transaction_local_nonprim : NULL,
        received ? strdup(received->valuestring) : NULL,
        checked ? strdup(checked->valuestring) : NULL,
        announced ? strdup(announced->valuestring) : NULL,
        is_valid ? is_valid->valueint : 0
        );

    return transaction_encoded_local_var;
end:
    return NULL;

}
