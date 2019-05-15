#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_3_unconfirmed_verify_transaction.h"



inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_create(
    int burn_factor,
    int max_transaction_size,
    int max_decimals
    ) {
	inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_local_var = malloc(sizeof(inline_response_200_3_unconfirmed_verify_transaction_t));
    if (!inline_response_200_3_unconfirmed_verify_transaction_local_var) {
        return NULL;
    }
	inline_response_200_3_unconfirmed_verify_transaction_local_var->burn_factor = burn_factor;
	inline_response_200_3_unconfirmed_verify_transaction_local_var->max_transaction_size = max_transaction_size;
	inline_response_200_3_unconfirmed_verify_transaction_local_var->max_decimals = max_decimals;

	return inline_response_200_3_unconfirmed_verify_transaction_local_var;
}


void inline_response_200_3_unconfirmed_verify_transaction_free(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction) {
    listEntry_t *listEntry;
	free(inline_response_200_3_unconfirmed_verify_transaction);
}

cJSON *inline_response_200_3_unconfirmed_verify_transaction_convertToJSON(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_3_unconfirmed_verify_transaction->burn_factor
    if(inline_response_200_3_unconfirmed_verify_transaction->burn_factor) { 
    if(cJSON_AddNumberToObject(item, "burn_factor", inline_response_200_3_unconfirmed_verify_transaction->burn_factor) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size
    if(inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size) { 
    if(cJSON_AddNumberToObject(item, "max_transaction_size", inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3_unconfirmed_verify_transaction->max_decimals
    if(inline_response_200_3_unconfirmed_verify_transaction->max_decimals) { 
    if(cJSON_AddNumberToObject(item, "max_decimals", inline_response_200_3_unconfirmed_verify_transaction->max_decimals) == NULL) {
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

inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_parseFromJSON(cJSON *inline_response_200_3_unconfirmed_verify_transactionJSON){

    inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_local_var = NULL;

    // inline_response_200_3_unconfirmed_verify_transaction->burn_factor
    cJSON *burn_factor = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "burn_factor");
    if (burn_factor) { 
    if(!cJSON_IsNumber(burn_factor))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3_unconfirmed_verify_transaction->max_transaction_size
    cJSON *max_transaction_size = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "max_transaction_size");
    if (max_transaction_size) { 
    if(!cJSON_IsNumber(max_transaction_size))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3_unconfirmed_verify_transaction->max_decimals
    cJSON *max_decimals = cJSON_GetObjectItemCaseSensitive(inline_response_200_3_unconfirmed_verify_transactionJSON, "max_decimals");
    if (max_decimals) { 
    if(!cJSON_IsNumber(max_decimals))
    {
    goto end; //Numeric
    }
    }


    inline_response_200_3_unconfirmed_verify_transaction_local_var = inline_response_200_3_unconfirmed_verify_transaction_create (
        burn_factor ? burn_factor->valuedouble : 0,
        max_transaction_size ? max_transaction_size->valuedouble : 0,
        max_decimals ? max_decimals->valuedouble : 0
        );

    return inline_response_200_3_unconfirmed_verify_transaction_local_var;
end:
    return NULL;

}
