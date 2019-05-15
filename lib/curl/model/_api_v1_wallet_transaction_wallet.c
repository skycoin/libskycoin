#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_wallet_transaction_wallet.h"



_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_create(
    list_t *unspents,
    list_t *addresses,
    char *password,
    char *id
    ) {
	_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_local_var = malloc(sizeof(_api_v1_wallet_transaction_wallet_t));
    if (!_api_v1_wallet_transaction_wallet_local_var) {
        return NULL;
    }
	_api_v1_wallet_transaction_wallet_local_var->unspents = unspents;
	_api_v1_wallet_transaction_wallet_local_var->addresses = addresses;
	_api_v1_wallet_transaction_wallet_local_var->password = password;
	_api_v1_wallet_transaction_wallet_local_var->id = id;

	return _api_v1_wallet_transaction_wallet_local_var;
}


void _api_v1_wallet_transaction_wallet_free(_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, _api_v1_wallet_transaction_wallet->unspents) {
		free(listEntry->data);
	}
	list_free(_api_v1_wallet_transaction_wallet->unspents);
	list_ForEach(listEntry, _api_v1_wallet_transaction_wallet->addresses) {
		free(listEntry->data);
	}
	list_free(_api_v1_wallet_transaction_wallet->addresses);
    free(_api_v1_wallet_transaction_wallet->password);
    free(_api_v1_wallet_transaction_wallet->id);
	free(_api_v1_wallet_transaction_wallet);
}

cJSON *_api_v1_wallet_transaction_wallet_convertToJSON(_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_wallet_transaction_wallet->unspents
    if(_api_v1_wallet_transaction_wallet->unspents) { 
	cJSON *unspents = cJSON_AddArrayToObject(item, "unspents");
	if(unspents == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *unspentsListEntry;
    list_ForEach(unspentsListEntry, _api_v1_wallet_transaction_wallet->unspents) {
    if(cJSON_AddStringToObject(unspents, "", (char*)unspentsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// _api_v1_wallet_transaction_wallet->addresses
    if(_api_v1_wallet_transaction_wallet->addresses) { 
	cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
	if(addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, _api_v1_wallet_transaction_wallet->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// _api_v1_wallet_transaction_wallet->password
    if(_api_v1_wallet_transaction_wallet->password) { 
    if(cJSON_AddStringToObject(item, "password", _api_v1_wallet_transaction_wallet->password) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallet_transaction_wallet->id
    if(_api_v1_wallet_transaction_wallet->id) { 
    if(cJSON_AddStringToObject(item, "id", _api_v1_wallet_transaction_wallet->id) == NULL) {
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

_api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_parseFromJSON(cJSON *_api_v1_wallet_transaction_walletJSON){

    _api_v1_wallet_transaction_wallet_t *_api_v1_wallet_transaction_wallet_local_var = NULL;

    // _api_v1_wallet_transaction_wallet->unspents
    cJSON *unspents = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_walletJSON, "unspents");
    list_t *unspentsList;
    if (unspents) { 
    cJSON *unspents_local;
    if(!cJSON_IsArray(unspents)) {
        goto end;//primitive container
    }
    unspentsList = list_create();

    cJSON_ArrayForEach(unspents_local, unspents)
    {
        if(!cJSON_IsString(unspents_local))
        {
            goto end;
        }
        list_addElement(unspentsList , strdup(unspents_local->valuestring));
    }
    }

    // _api_v1_wallet_transaction_wallet->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_walletJSON, "addresses");
    list_t *addressesList;
    if (addresses) { 
    cJSON *addresses_local;
    if(!cJSON_IsArray(addresses)) {
        goto end;//primitive container
    }
    addressesList = list_create();

    cJSON_ArrayForEach(addresses_local, addresses)
    {
        if(!cJSON_IsString(addresses_local))
        {
            goto end;
        }
        list_addElement(addressesList , strdup(addresses_local->valuestring));
    }
    }

    // _api_v1_wallet_transaction_wallet->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_walletJSON, "password");
    if (password) { 
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }
    }

    // _api_v1_wallet_transaction_wallet->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_walletJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }
    }


    _api_v1_wallet_transaction_wallet_local_var = _api_v1_wallet_transaction_wallet_create (
        unspents ? unspentsList : NULL,
        addresses ? addressesList : NULL,
        password ? strdup(password->valuestring) : NULL,
        id ? strdup(id->valuestring) : NULL
        );

    return _api_v1_wallet_transaction_wallet_local_var;
end:
    return NULL;

}
