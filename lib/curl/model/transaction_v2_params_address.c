#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_v2_params_address.h"



transaction_v2_params_address_t *transaction_v2_params_address_create(
    transaction_v2_params_address_hours_selection_t *hours_selection
    ) {
	transaction_v2_params_address_t *transaction_v2_params_address_local_var = malloc(sizeof(transaction_v2_params_address_t));
    if (!transaction_v2_params_address_local_var) {
        return NULL;
    }
	transaction_v2_params_address_local_var->hours_selection = hours_selection;

	return transaction_v2_params_address_local_var;
}


void transaction_v2_params_address_free(transaction_v2_params_address_t *transaction_v2_params_address) {
    listEntry_t *listEntry;
    transaction_v2_params_address_hours_selection_free(transaction_v2_params_address->hours_selection);
	free(transaction_v2_params_address);
}

cJSON *transaction_v2_params_address_convertToJSON(transaction_v2_params_address_t *transaction_v2_params_address) {
	cJSON *item = cJSON_CreateObject();

	// transaction_v2_params_address->hours_selection
    if(transaction_v2_params_address->hours_selection) { 
    cJSON *hours_selection_local_JSON = transaction_v2_params_address_hours_selection_convertToJSON(transaction_v2_params_address->hours_selection);
    if(hours_selection_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hours_selection", hours_selection_local_JSON);
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

transaction_v2_params_address_t *transaction_v2_params_address_parseFromJSON(cJSON *transaction_v2_params_addressJSON){

    transaction_v2_params_address_t *transaction_v2_params_address_local_var = NULL;

    // transaction_v2_params_address->hours_selection
    cJSON *hours_selection = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_addressJSON, "hours_selection");
    transaction_v2_params_address_hours_selection_t *hours_selection_local_nonprim = NULL;
    if (hours_selection) { 
    hours_selection_local_nonprim = transaction_v2_params_address_hours_selection_parseFromJSON(hours_selection); //nonprimitive
    }


    transaction_v2_params_address_local_var = transaction_v2_params_address_create (
        hours_selection ? hours_selection_local_nonprim : NULL
        );

    return transaction_v2_params_address_local_var;
end:
    return NULL;

}
