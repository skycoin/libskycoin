#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_3_unconfirmed_verify_transaction.h"


inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_create(
    int burn_factor,
    int max_transaction_size,
    int max_decimals
    ) {
	inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction = malloc(sizeof(inline_response_200_3_unconfirmed_verify_transaction_t));
	inline_response_200_3_unconfirmed_verify_transaction->burn_factor = burn_factor;
	inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size = max_transaction_size;
	inline_response_200_3_unconfirmed_verify_transaction->max_decimals = max_decimals;

	return inline_response_200_3_unconfirmed_verify_transaction;
}


void inline_response_200_3_unconfirmed_verify_transaction_free(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction) {
    listEntry_t *listEntry;

	free(inline_response_200_3_unconfirmed_verify_transaction);
}

cJSON *inline_response_200_3_unconfirmed_verify_transaction_convertToJSON(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_3_unconfirmed_verify_transaction->burn_factor
    if(cJSON_AddNumberToObject(item, "burn_factor", inline_response_200_3_unconfirmed_verify_transaction->burn_factor) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size
    if(cJSON_AddNumberToObject(item, "max_transaction_size", inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3_unconfirmed_verify_transaction->max_decimals
    if(cJSON_AddNumberToObject(item, "max_decimals", inline_response_200_3_unconfirmed_verify_transaction->max_decimals) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_parseFromJSON(char *jsonString){

    inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction = NULL;
    cJSON *inline_response_200_3_unconfirmed_verify_transactionJSON = cJSON_Parse(jsonString);
    if(inline_response_200_3_unconfirmed_verify_transactionJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_3_unconfirmed_verify_transaction->burn_factor
    cJSON *burn_factor = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "burn_factor");
    if(!cJSON_IsNumber(burn_factor))
    {
    goto end; //Numeric
    }

    // inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size
    cJSON *max_transaction_size = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "max_transaction_size");
    if(!cJSON_IsNumber(max_transaction_size))
    {
    goto end; //Numeric
    }

    // inline_response_200_3_unconfirmed_verify_transaction->max_decimals
    cJSON *max_decimals = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "max_decimals");
    if(!cJSON_IsNumber(max_decimals))
    {
    goto end; //Numeric
    }


    inline_response_200_3_unconfirmed_verify_transaction = inline_response_200_3_unconfirmed_verify_transaction_create (
        burn_factor->valuedouble,
        max_transaction_size->valuedouble,
        max_decimals->valuedouble
        );
 cJSON_Delete(inline_response_200_3_unconfirmed_verify_transactionJSON);
    return inline_response_200_3_unconfirmed_verify_transaction;
end:
    cJSON_Delete(inline_response_200_3_unconfirmed_verify_transactionJSON);
    return NULL;

}

