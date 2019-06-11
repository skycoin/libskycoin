#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_explorer_address_inputs.h"



_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_create(
    char *owner,
    long hours,
    long calculated_hours,
    char *coins,
    char *uxid
    ) {
	_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_local_var = malloc(sizeof(_api_v1_explorer_address_inputs_t));
    if (!_api_v1_explorer_address_inputs_local_var) {
        return NULL;
    }
	_api_v1_explorer_address_inputs_local_var->owner = owner;
	_api_v1_explorer_address_inputs_local_var->hours = hours;
	_api_v1_explorer_address_inputs_local_var->calculated_hours = calculated_hours;
	_api_v1_explorer_address_inputs_local_var->coins = coins;
	_api_v1_explorer_address_inputs_local_var->uxid = uxid;

	return _api_v1_explorer_address_inputs_local_var;
}


void _api_v1_explorer_address_inputs_free(_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs) {
    listEntry_t *listEntry;
    free(_api_v1_explorer_address_inputs->owner);
    free(_api_v1_explorer_address_inputs->coins);
    free(_api_v1_explorer_address_inputs->uxid);
	free(_api_v1_explorer_address_inputs);
}

cJSON *_api_v1_explorer_address_inputs_convertToJSON(_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_explorer_address_inputs->owner
    if(_api_v1_explorer_address_inputs->owner) { 
    if(cJSON_AddStringToObject(item, "owner", _api_v1_explorer_address_inputs->owner) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_explorer_address_inputs->hours
    if(_api_v1_explorer_address_inputs->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", _api_v1_explorer_address_inputs->hours) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_explorer_address_inputs->calculated_hours
    if(_api_v1_explorer_address_inputs->calculated_hours) { 
    if(cJSON_AddNumberToObject(item, "calculated_hours", _api_v1_explorer_address_inputs->calculated_hours) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_explorer_address_inputs->coins
    if(_api_v1_explorer_address_inputs->coins) { 
    if(cJSON_AddStringToObject(item, "coins", _api_v1_explorer_address_inputs->coins) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_explorer_address_inputs->uxid
    if(_api_v1_explorer_address_inputs->uxid) { 
    if(cJSON_AddStringToObject(item, "uxid", _api_v1_explorer_address_inputs->uxid) == NULL) {
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

_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_parseFromJSON(cJSON *_api_v1_explorer_address_inputsJSON){

    _api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_local_var = NULL;

    // _api_v1_explorer_address_inputs->owner
    cJSON *owner = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_inputsJSON, "owner");
    if (owner) { 
    if(!cJSON_IsString(owner))
    {
    goto end; //String
    }
    }

    // _api_v1_explorer_address_inputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_inputsJSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_explorer_address_inputs->calculated_hours
    cJSON *calculated_hours = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_inputsJSON, "calculated_hours");
    if (calculated_hours) { 
    if(!cJSON_IsNumber(calculated_hours))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_explorer_address_inputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_inputsJSON, "coins");
    if (coins) { 
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }
    }

    // _api_v1_explorer_address_inputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(_api_v1_explorer_address_inputsJSON, "uxid");
    if (uxid) { 
    if(!cJSON_IsString(uxid))
    {
    goto end; //String
    }
    }


    _api_v1_explorer_address_inputs_local_var = _api_v1_explorer_address_inputs_create (
        owner ? strdup(owner->valuestring) : NULL,
        hours ? hours->valuedouble : 0,
        calculated_hours ? calculated_hours->valuedouble : 0,
        coins ? strdup(coins->valuestring) : NULL,
        uxid ? strdup(uxid->valuestring) : NULL
        );

    return _api_v1_explorer_address_inputs_local_var;
end:
    return NULL;

}
