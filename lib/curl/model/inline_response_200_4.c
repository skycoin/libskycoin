#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_4.h"



inline_response_200_4_t *inline_response_200_4_create(
    char *announced,
    int is_valid,
    char *checked,
    char *received,
    _api_v1_pending_txs_transaction_t *transaction
    ) {
	inline_response_200_4_t *inline_response_200_4_local_var = malloc(sizeof(inline_response_200_4_t));
    if (!inline_response_200_4_local_var) {
        return NULL;
    }
	inline_response_200_4_local_var->announced = announced;
	inline_response_200_4_local_var->is_valid = is_valid;
	inline_response_200_4_local_var->checked = checked;
	inline_response_200_4_local_var->received = received;
	inline_response_200_4_local_var->transaction = transaction;

	return inline_response_200_4_local_var;
}


void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4) {
    listEntry_t *listEntry;
    free(inline_response_200_4->announced);
    free(inline_response_200_4->checked);
    free(inline_response_200_4->received);
    _api_v1_pending_txs_transaction_free(inline_response_200_4->transaction);
	free(inline_response_200_4);
}

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_4->announced
    if(inline_response_200_4->announced) { 
    if(cJSON_AddStringToObject(item, "announced", inline_response_200_4->announced) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_4->is_valid
    if(inline_response_200_4->is_valid) { 
    if(cJSON_AddBoolToObject(item, "is_valid", inline_response_200_4->is_valid) == NULL) {
    goto fail; //Bool
    }
     } 


	// inline_response_200_4->checked
    if(inline_response_200_4->checked) { 
    if(cJSON_AddStringToObject(item, "checked", inline_response_200_4->checked) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_4->received
    if(inline_response_200_4->received) { 
    if(cJSON_AddStringToObject(item, "received", inline_response_200_4->received) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_4->transaction
    if(inline_response_200_4->transaction) { 
    cJSON *transaction_local_JSON = _api_v1_pending_txs_transaction_convertToJSON(inline_response_200_4->transaction);
    if(transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "transaction", transaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_4_t *inline_response_200_4_parseFromJSON(cJSON *inline_response_200_4JSON){

    inline_response_200_4_t *inline_response_200_4_local_var = NULL;

    // inline_response_200_4->announced
    cJSON *announced = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "announced");
    if (announced) { 
    if(!cJSON_IsString(announced))
    {
    goto end; //String
    }
    }

    // inline_response_200_4->is_valid
    cJSON *is_valid = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "is_valid");
    if (is_valid) { 
    if(!cJSON_IsBool(is_valid))
    {
    goto end; //Bool
    }
    }

    // inline_response_200_4->checked
    cJSON *checked = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "checked");
    if (checked) { 
    if(!cJSON_IsString(checked))
    {
    goto end; //String
    }
    }

    // inline_response_200_4->received
    cJSON *received = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "received");
    if (received) { 
    if(!cJSON_IsString(received))
    {
    goto end; //String
    }
    }

    // inline_response_200_4->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "transaction");
    _api_v1_pending_txs_transaction_t *transaction_local_nonprim = NULL;
    if (transaction) { 
    transaction_local_nonprim = _api_v1_pending_txs_transaction_parseFromJSON(transaction); //nonprimitive
    }


    inline_response_200_4_local_var = inline_response_200_4_create (
        announced ? strdup(announced->valuestring) : NULL,
        is_valid ? is_valid->valueint : 0,
        checked ? strdup(checked->valuestring) : NULL,
        received ? strdup(received->valuestring) : NULL,
        transaction ? transaction_local_nonprim : NULL
        );

    return inline_response_200_4_local_var;
end:
    return NULL;

}
