#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_v2_params_unspent_hours_selection.h"



transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_create(
    char *type,
    char *mode,
    char *share_factor
    ) {
	transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_local_var = malloc(sizeof(transaction_v2_params_unspent_hours_selection_t));
    if (!transaction_v2_params_unspent_hours_selection_local_var) {
        return NULL;
    }
	transaction_v2_params_unspent_hours_selection_local_var->type = type;
	transaction_v2_params_unspent_hours_selection_local_var->mode = mode;
	transaction_v2_params_unspent_hours_selection_local_var->share_factor = share_factor;

	return transaction_v2_params_unspent_hours_selection_local_var;
}


void transaction_v2_params_unspent_hours_selection_free(transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection) {
    listEntry_t *listEntry;
    free(transaction_v2_params_unspent_hours_selection->type);
    free(transaction_v2_params_unspent_hours_selection->mode);
    free(transaction_v2_params_unspent_hours_selection->share_factor);
	free(transaction_v2_params_unspent_hours_selection);
}

cJSON *transaction_v2_params_unspent_hours_selection_convertToJSON(transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection) {
	cJSON *item = cJSON_CreateObject();

	// transaction_v2_params_unspent_hours_selection->type
    if(transaction_v2_params_unspent_hours_selection->type) { 
    if(cJSON_AddStringToObject(item, "type", transaction_v2_params_unspent_hours_selection->type) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_v2_params_unspent_hours_selection->mode
    if(transaction_v2_params_unspent_hours_selection->mode) { 
    if(cJSON_AddStringToObject(item, "mode", transaction_v2_params_unspent_hours_selection->mode) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_v2_params_unspent_hours_selection->share_factor
    if(transaction_v2_params_unspent_hours_selection->share_factor) { 
    if(cJSON_AddStringToObject(item, "share_factor", transaction_v2_params_unspent_hours_selection->share_factor) == NULL) {
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

transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_parseFromJSON(cJSON *transaction_v2_params_unspent_hours_selectionJSON){

    transaction_v2_params_unspent_hours_selection_t *transaction_v2_params_unspent_hours_selection_local_var = NULL;

    // transaction_v2_params_unspent_hours_selection->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspent_hours_selectionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // transaction_v2_params_unspent_hours_selection->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspent_hours_selectionJSON, "mode");
    if (mode) { 
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }
    }

    // transaction_v2_params_unspent_hours_selection->share_factor
    cJSON *share_factor = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspent_hours_selectionJSON, "share_factor");
    if (share_factor) { 
    if(!cJSON_IsString(share_factor))
    {
    goto end; //String
    }
    }


    transaction_v2_params_unspent_hours_selection_local_var = transaction_v2_params_unspent_hours_selection_create (
        type ? strdup(type->valuestring) : NULL,
        mode ? strdup(mode->valuestring) : NULL,
        share_factor ? strdup(share_factor->valuestring) : NULL
        );

    return transaction_v2_params_unspent_hours_selection_local_var;
end:
    return NULL;

}
