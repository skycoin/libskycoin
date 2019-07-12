#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wallet_transaction_request_hours_selection.h"



wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_create(
    char *mode,
    char *share_factor,
    char *type
    ) {
	wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_local_var = malloc(sizeof(wallet_transaction_request_hours_selection_t));
    if (!wallet_transaction_request_hours_selection_local_var) {
        return NULL;
    }
	wallet_transaction_request_hours_selection_local_var->mode = mode;
	wallet_transaction_request_hours_selection_local_var->share_factor = share_factor;
	wallet_transaction_request_hours_selection_local_var->type = type;

	return wallet_transaction_request_hours_selection_local_var;
}


void wallet_transaction_request_hours_selection_free(wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection) {
    listEntry_t *listEntry;
    free(wallet_transaction_request_hours_selection->mode);
    free(wallet_transaction_request_hours_selection->share_factor);
    free(wallet_transaction_request_hours_selection->type);
	free(wallet_transaction_request_hours_selection);
}

cJSON *wallet_transaction_request_hours_selection_convertToJSON(wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection) {
	cJSON *item = cJSON_CreateObject();

	// wallet_transaction_request_hours_selection->mode
    if(wallet_transaction_request_hours_selection->mode) { 
    if(cJSON_AddStringToObject(item, "mode", wallet_transaction_request_hours_selection->mode) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_request_hours_selection->share_factor
    if(wallet_transaction_request_hours_selection->share_factor) { 
    if(cJSON_AddStringToObject(item, "share_factor", wallet_transaction_request_hours_selection->share_factor) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_request_hours_selection->type
    if(wallet_transaction_request_hours_selection->type) { 
    if(cJSON_AddStringToObject(item, "type", wallet_transaction_request_hours_selection->type) == NULL) {
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

wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_parseFromJSON(cJSON *wallet_transaction_request_hours_selectionJSON){

    wallet_transaction_request_hours_selection_t *wallet_transaction_request_hours_selection_local_var = NULL;

    // wallet_transaction_request_hours_selection->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_hours_selectionJSON, "mode");
    if (mode) { 
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }
    }

    // wallet_transaction_request_hours_selection->share_factor
    cJSON *share_factor = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_hours_selectionJSON, "share_factor");
    if (share_factor) { 
    if(!cJSON_IsString(share_factor))
    {
    goto end; //String
    }
    }

    // wallet_transaction_request_hours_selection->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_hours_selectionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    wallet_transaction_request_hours_selection_local_var = wallet_transaction_request_hours_selection_create (
        mode ? strdup(mode->valuestring) : NULL,
        share_factor ? strdup(share_factor->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return wallet_transaction_request_hours_selection_local_var;
end:
    return NULL;

}
