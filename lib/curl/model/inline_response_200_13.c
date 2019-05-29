#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_13.h"



inline_response_200_13_t *inline_response_200_13_create(
    _api_v1_pending_txs_verbose_transaction_t *transaction,
    char *received,
    char *checked,
    char *announced,
    int is_valid
    ) {
	inline_response_200_13_t *inline_response_200_13_local_var = malloc(sizeof(inline_response_200_13_t));
    if (!inline_response_200_13_local_var) {
        return NULL;
    }
	inline_response_200_13_local_var->transaction = transaction;
	inline_response_200_13_local_var->received = received;
	inline_response_200_13_local_var->checked = checked;
	inline_response_200_13_local_var->announced = announced;
	inline_response_200_13_local_var->is_valid = is_valid;

	return inline_response_200_13_local_var;
}


void inline_response_200_13_free(inline_response_200_13_t *inline_response_200_13) {
    listEntry_t *listEntry;
    _api_v1_pending_txs_verbose_transaction_free(inline_response_200_13->transaction);
    free(inline_response_200_13->received);
    free(inline_response_200_13->checked);
    free(inline_response_200_13->announced);
	free(inline_response_200_13);
}

cJSON *inline_response_200_13_convertToJSON(inline_response_200_13_t *inline_response_200_13) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_13->transaction
    if(inline_response_200_13->transaction) { 
    cJSON *transaction_local_JSON = _api_v1_pending_txs_verbose_transaction_convertToJSON(inline_response_200_13->transaction);
    if(transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "transaction", transaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// inline_response_200_13->received
    if(inline_response_200_13->received) { 
    if(cJSON_AddStringToObject(item, "received", inline_response_200_13->received) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_13->checked
    if(inline_response_200_13->checked) { 
    if(cJSON_AddStringToObject(item, "checked", inline_response_200_13->checked) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_13->announced
    if(inline_response_200_13->announced) { 
    if(cJSON_AddStringToObject(item, "announced", inline_response_200_13->announced) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_13->is_valid
    if(inline_response_200_13->is_valid) { 
    if(cJSON_AddBoolToObject(item, "is_valid", inline_response_200_13->is_valid) == NULL) {
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

inline_response_200_13_t *inline_response_200_13_parseFromJSON(cJSON *inline_response_200_13JSON){

    inline_response_200_13_t *inline_response_200_13_local_var = NULL;

    // inline_response_200_13->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(inline_response_200_13JSON, "transaction");
    _api_v1_pending_txs_verbose_transaction_t *transaction_local_nonprim = NULL;
    if (transaction) { 
    transaction_local_nonprim = _api_v1_pending_txs_verbose_transaction_parseFromJSON(transaction); //nonprimitive
    }

    // inline_response_200_13->received
    cJSON *received = cJSON_GetObjectItemCaseSensitive(inline_response_200_13JSON, "received");
    if (received) { 
    if(!cJSON_IsString(received))
    {
    goto end; //String
    }
    }

    // inline_response_200_13->checked
    cJSON *checked = cJSON_GetObjectItemCaseSensitive(inline_response_200_13JSON, "checked");
    if (checked) { 
    if(!cJSON_IsString(checked))
    {
    goto end; //String
    }
    }

    // inline_response_200_13->announced
    cJSON *announced = cJSON_GetObjectItemCaseSensitive(inline_response_200_13JSON, "announced");
    if (announced) { 
    if(!cJSON_IsString(announced))
    {
    goto end; //String
    }
    }

    // inline_response_200_13->is_valid
    cJSON *is_valid = cJSON_GetObjectItemCaseSensitive(inline_response_200_13JSON, "is_valid");
    if (is_valid) { 
    if(!cJSON_IsBool(is_valid))
    {
    goto end; //Bool
    }
    }


    inline_response_200_13_local_var = inline_response_200_13_create (
        transaction ? transaction_local_nonprim : NULL,
        received ? strdup(received->valuestring) : NULL,
        checked ? strdup(checked->valuestring) : NULL,
        announced ? strdup(announced->valuestring) : NULL,
        is_valid ? is_valid->valueint : 0
        );

    return inline_response_200_13_local_var;
end:
    return NULL;

}
