#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_8_data.h"



inline_response_200_8_data_t *inline_response_200_8_data_create(
    transaction_t *transaction
    ) {
	inline_response_200_8_data_t *inline_response_200_8_data_local_var = malloc(sizeof(inline_response_200_8_data_t));
    if (!inline_response_200_8_data_local_var) {
        return NULL;
    }
	inline_response_200_8_data_local_var->transaction = transaction;

	return inline_response_200_8_data_local_var;
}


void inline_response_200_8_data_free(inline_response_200_8_data_t *inline_response_200_8_data) {
    listEntry_t *listEntry;
    transaction_free(inline_response_200_8_data->transaction);
	free(inline_response_200_8_data);
}

cJSON *inline_response_200_8_data_convertToJSON(inline_response_200_8_data_t *inline_response_200_8_data) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_8_data->transaction
    if(inline_response_200_8_data->transaction) { 
    cJSON *transaction_local_JSON = transaction_convertToJSON(inline_response_200_8_data->transaction);
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

inline_response_200_8_data_t *inline_response_200_8_data_parseFromJSON(cJSON *inline_response_200_8_dataJSON){

    inline_response_200_8_data_t *inline_response_200_8_data_local_var = NULL;

    // inline_response_200_8_data->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(inline_response_200_8_dataJSON, "transaction");
    transaction_t *transaction_local_nonprim = NULL;
    if (transaction) { 
    transaction_local_nonprim = transaction_parseFromJSON(transaction); //nonprimitive
    }


    inline_response_200_8_data_local_var = inline_response_200_8_data_create (
        transaction ? transaction_local_nonprim : NULL
        );

    return inline_response_200_8_data_local_var;
end:
    return NULL;

}
