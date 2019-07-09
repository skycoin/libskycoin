#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_v2_params_address_hours_selection.h"



transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection_create(
    char *type
    ) {
	transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection_local_var = malloc(sizeof(transaction_v2_params_address_hours_selection_t));
    if (!transaction_v2_params_address_hours_selection_local_var) {
        return NULL;
    }
	transaction_v2_params_address_hours_selection_local_var->type = type;

	return transaction_v2_params_address_hours_selection_local_var;
}


void transaction_v2_params_address_hours_selection_free(transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection) {
    listEntry_t *listEntry;
    free(transaction_v2_params_address_hours_selection->type);
	free(transaction_v2_params_address_hours_selection);
}

cJSON *transaction_v2_params_address_hours_selection_convertToJSON(transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection) {
	cJSON *item = cJSON_CreateObject();

	// transaction_v2_params_address_hours_selection->type
    if(transaction_v2_params_address_hours_selection->type) { 
    if(cJSON_AddStringToObject(item, "type", transaction_v2_params_address_hours_selection->type) == NULL) {
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

transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection_parseFromJSON(cJSON *transaction_v2_params_address_hours_selectionJSON){

    transaction_v2_params_address_hours_selection_t *transaction_v2_params_address_hours_selection_local_var = NULL;

    // transaction_v2_params_address_hours_selection->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_address_hours_selectionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    transaction_v2_params_address_hours_selection_local_var = transaction_v2_params_address_hours_selection_create (
        type ? strdup(type->valuestring) : NULL
        );

    return transaction_v2_params_address_hours_selection_local_var;
end:
    return NULL;

}
