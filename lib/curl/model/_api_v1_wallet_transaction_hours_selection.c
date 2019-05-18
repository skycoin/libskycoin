#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_wallet_transaction_hours_selection.h"



_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_create(
    char *mode,
    char *share_factor,
    char *type
    ) {
	_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_local_var = malloc(sizeof(_api_v1_wallet_transaction_hours_selection_t));
    if (!_api_v1_wallet_transaction_hours_selection_local_var) {
        return NULL;
    }
	_api_v1_wallet_transaction_hours_selection_local_var->mode = mode;
	_api_v1_wallet_transaction_hours_selection_local_var->share_factor = share_factor;
	_api_v1_wallet_transaction_hours_selection_local_var->type = type;

	return _api_v1_wallet_transaction_hours_selection_local_var;
}


void _api_v1_wallet_transaction_hours_selection_free(_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection) {
    listEntry_t *listEntry;
    free(_api_v1_wallet_transaction_hours_selection->mode);
    free(_api_v1_wallet_transaction_hours_selection->share_factor);
    free(_api_v1_wallet_transaction_hours_selection->type);
	free(_api_v1_wallet_transaction_hours_selection);
}

cJSON *_api_v1_wallet_transaction_hours_selection_convertToJSON(_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_wallet_transaction_hours_selection->mode
    if(_api_v1_wallet_transaction_hours_selection->mode) { 
    if(cJSON_AddStringToObject(item, "mode", _api_v1_wallet_transaction_hours_selection->mode) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallet_transaction_hours_selection->share_factor
    if(_api_v1_wallet_transaction_hours_selection->share_factor) { 
    if(cJSON_AddStringToObject(item, "share_factor", _api_v1_wallet_transaction_hours_selection->share_factor) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallet_transaction_hours_selection->type
    if(_api_v1_wallet_transaction_hours_selection->type) { 
    if(cJSON_AddStringToObject(item, "type", _api_v1_wallet_transaction_hours_selection->type) == NULL) {
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

_api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_parseFromJSON(cJSON *_api_v1_wallet_transaction_hours_selectionJSON){

    _api_v1_wallet_transaction_hours_selection_t *_api_v1_wallet_transaction_hours_selection_local_var = NULL;

    // _api_v1_wallet_transaction_hours_selection->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_hours_selectionJSON, "mode");
    if (mode) { 
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }
    }

    // _api_v1_wallet_transaction_hours_selection->share_factor
    cJSON *share_factor = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_hours_selectionJSON, "share_factor");
    if (share_factor) { 
    if(!cJSON_IsString(share_factor))
    {
    goto end; //String
    }
    }

    // _api_v1_wallet_transaction_hours_selection->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_hours_selectionJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    _api_v1_wallet_transaction_hours_selection_local_var = _api_v1_wallet_transaction_hours_selection_create (
        mode ? strdup(mode->valuestring) : NULL,
        share_factor ? strdup(share_factor->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return _api_v1_wallet_transaction_hours_selection_local_var;
end:
    return NULL;

}
