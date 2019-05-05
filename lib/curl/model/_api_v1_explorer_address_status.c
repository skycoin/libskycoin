#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_explorer_address_status.h"



_api_v1_explorer_address_status_t *_api_v1_explorer_address_status_create(
    int unconfirmed,
    long block_seq,
    long label,
    int confirmed
    ) {
	_api_v1_explorer_address_status_t *_api_v1_explorer_address_status_local_var = malloc(sizeof(_api_v1_explorer_address_status_t));
    if (!_api_v1_explorer_address_status_local_var) {
        return NULL;
    }
	_api_v1_explorer_address_status_local_var->unconfirmed = unconfirmed;
	_api_v1_explorer_address_status_local_var->block_seq = block_seq;
	_api_v1_explorer_address_status_local_var->label = label;
	_api_v1_explorer_address_status_local_var->confirmed = confirmed;

	return _api_v1_explorer_address_status_local_var;
}


void _api_v1_explorer_address_status_free(_api_v1_explorer_address_status_t *_api_v1_explorer_address_status) {
    listEntry_t *listEntry;
	free(_api_v1_explorer_address_status);
}

cJSON *_api_v1_explorer_address_status_convertToJSON(_api_v1_explorer_address_status_t *_api_v1_explorer_address_status) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_explorer_address_status->unconfirmed
    if(_api_v1_explorer_address_status->unconfirmed) { 
    if(cJSON_AddBoolToObject(item, "unconfirmed", _api_v1_explorer_address_status->unconfirmed) == NULL) {
    goto fail; //Bool
    }
     } 


	// _api_v1_explorer_address_status->block_seq
    if(_api_v1_explorer_address_status->block_seq) { 
    if(cJSON_AddNumberToObject(item, "block_seq", _api_v1_explorer_address_status->block_seq) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_explorer_address_status->label
    if(_api_v1_explorer_address_status->label) { 
    if(cJSON_AddNumberToObject(item, "label", _api_v1_explorer_address_status->label) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_explorer_address_status->confirmed
    if(_api_v1_explorer_address_status->confirmed) { 
    if(cJSON_AddBoolToObject(item, "confirmed", _api_v1_explorer_address_status->confirmed) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

_api_v1_explorer_address_status_t *_api_v1_explorer_address_status_parseFromJSON(cJSON *_api_v1_explorer_address_statusJSON){

    _api_v1_explorer_address_status_t *_api_v1_explorer_address_status_local_var = NULL;

    // _api_v1_explorer_address_status->unconfirmed
    cJSON *unconfirmed = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_statusJSON, "unconfirmed");
    if (unconfirmed) { 
    if(!cJSON_IsBool(unconfirmed))
    {
    goto end; //Bool
    }
    }

    // _api_v1_explorer_address_status->block_seq
    cJSON *block_seq = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_statusJSON, "block_seq");
    if (block_seq) { 
    if(!cJSON_IsNumber(block_seq))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_explorer_address_status->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_statusJSON, "label");
    if (label) { 
    if(!cJSON_IsNumber(label))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_explorer_address_status->confirmed
    cJSON *confirmed = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_statusJSON, "confirmed");
    if (confirmed) { 
    if(!cJSON_IsBool(confirmed))
    {
    goto end; //Bool
    }
    }


    _api_v1_explorer_address_status_local_var = _api_v1_explorer_address_status_create (
        unconfirmed ? unconfirmed->valueint : 0,
        block_seq ? block_seq->valuedouble : 0,
        label ? label->valuedouble : 0,
        confirmed ? confirmed->valueint : 0
        );

    return _api_v1_explorer_address_status_local_var;
end:
    return NULL;

}
