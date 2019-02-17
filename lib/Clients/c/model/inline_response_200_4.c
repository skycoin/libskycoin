#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_4.h"
#include "apiv1pending_txs_transaction.h"


inline_response_200_4_t *inline_response_200_4_create(
    char *announced,
    bool is_valid,
    char *checked,
    char *received,
    apiv1pending_txs_transaction_t *transaction
    ) {
	inline_response_200_4_t *inline_response_200_4 = malloc(sizeof(inline_response_200_4_t));
	inline_response_200_4->announced = announced;
	inline_response_200_4->is_valid = is_valid;
	inline_response_200_4->checked = checked;
	inline_response_200_4->received = received;
	inline_response_200_4->transaction = transaction;

	return inline_response_200_4;
}


void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4) {
    listEntry_t *listEntry;
    free(inline_response_200_4->announced);
    free(inline_response_200_4->checked);
    free(inline_response_200_4->received);
	apiv1pending_txs_transaction_free(inline_response_200_4->transaction);

	free(inline_response_200_4);
}

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_4->announced
    if(cJSON_AddStringToObject(item, "announced", inline_response_200_4->announced) == NULL) {
    goto fail; //String
    }

	// inline_response_200_4->is_valid
    if(cJSON_AddBoolToObject(item, "is_valid", inline_response_200_4->is_valid) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_4->checked
    if(cJSON_AddStringToObject(item, "checked", inline_response_200_4->checked) == NULL) {
    goto fail; //String
    }

	// inline_response_200_4->received
    if(cJSON_AddStringToObject(item, "received", inline_response_200_4->received) == NULL) {
    goto fail; //String
    }

	// inline_response_200_4->transaction
	cJSON *transaction = apiv1pending_txs_transaction_convertToJSON(inline_response_200_4->transaction);
	if(transaction == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "transaction", transaction);
	if(item->child == NULL) {
		goto fail;
	}

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_4_t *inline_response_200_4_parseFromJSON(char *jsonString){

    inline_response_200_4_t *inline_response_200_4 = NULL;
    cJSON *inline_response_200_4JSON = cJSON_Parse(jsonString);
    if(inline_response_200_4JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_4->announced
    cJSON *announced = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "announced");
    if(!cJSON_IsString(announced) || (announced->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_4->is_valid
    cJSON *is_valid = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "is_valid");
    if(!cJSON_IsBool(is_valid))
    {
    goto end; //Numeric
    }

    // inline_response_200_4->checked
    cJSON *checked = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "checked");
    if(!cJSON_IsString(checked) || (checked->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_4->received
    cJSON *received = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "received");
    if(!cJSON_IsString(received) || (received->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_4->transaction
    apiv1pending_txs_transaction_t *transaction;
    cJSON *transactionJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "transaction");
    if(inline_response_200_4JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *transactionJSONData = cJSON_Print(transactionJSON);
    transaction = apiv1pending_txs_transaction_parseFromJSON(transactionJSONData);


    inline_response_200_4 = inline_response_200_4_create (
        strdup(announced->valuestring),
        is_valid->valueint,
        strdup(checked->valuestring),
        strdup(received->valuestring),
        transaction
        );
        free(transactionJSONData);
 cJSON_Delete(inline_response_200_4JSON);
    return inline_response_200_4;
end:
    cJSON_Delete(inline_response_200_4JSON);
    return NULL;

}

