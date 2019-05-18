#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_wallets_entries.h"



_api_v1_wallets_entries_t *_api_v1_wallets_entries_create(
    char *public_key,
    char *address
    ) {
	_api_v1_wallets_entries_t *_api_v1_wallets_entries_local_var = malloc(sizeof(_api_v1_wallets_entries_t));
    if (!_api_v1_wallets_entries_local_var) {
        return NULL;
    }
	_api_v1_wallets_entries_local_var->public_key = public_key;
	_api_v1_wallets_entries_local_var->address = address;

	return _api_v1_wallets_entries_local_var;
}


void _api_v1_wallets_entries_free(_api_v1_wallets_entries_t *_api_v1_wallets_entries) {
    listEntry_t *listEntry;
    free(_api_v1_wallets_entries->public_key);
    free(_api_v1_wallets_entries->address);
	free(_api_v1_wallets_entries);
}

cJSON *_api_v1_wallets_entries_convertToJSON(_api_v1_wallets_entries_t *_api_v1_wallets_entries) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_wallets_entries->public_key
    if(_api_v1_wallets_entries->public_key) { 
    if(cJSON_AddStringToObject(item, "public_key", _api_v1_wallets_entries->public_key) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_entries->address
    if(_api_v1_wallets_entries->address) { 
    if(cJSON_AddStringToObject(item, "address", _api_v1_wallets_entries->address) == NULL) {
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

_api_v1_wallets_entries_t *_api_v1_wallets_entries_parseFromJSON(cJSON *_api_v1_wallets_entriesJSON){

    _api_v1_wallets_entries_t *_api_v1_wallets_entries_local_var = NULL;

    // _api_v1_wallets_entries->public_key
    cJSON *public_key = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_entriesJSON, "public_key");
    if (public_key) { 
    if(!cJSON_IsString(public_key))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_entries->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_entriesJSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }


    _api_v1_wallets_entries_local_var = _api_v1_wallets_entries_create (
        public_key ? strdup(public_key->valuestring) : NULL,
        address ? strdup(address->valuestring) : NULL
        );

    return _api_v1_wallets_entries_local_var;
end:
    return NULL;

}
