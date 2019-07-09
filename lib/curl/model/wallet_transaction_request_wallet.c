#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wallet_transaction_request_wallet.h"



wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_create(
    list_t *addresses,
    char *id,
    char *password,
    list_t *unspents
    ) {
	wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_local_var = malloc(sizeof(wallet_transaction_request_wallet_t));
    if (!wallet_transaction_request_wallet_local_var) {
        return NULL;
    }
	wallet_transaction_request_wallet_local_var->addresses = addresses;
	wallet_transaction_request_wallet_local_var->id = id;
	wallet_transaction_request_wallet_local_var->password = password;
	wallet_transaction_request_wallet_local_var->unspents = unspents;

	return wallet_transaction_request_wallet_local_var;
}


void wallet_transaction_request_wallet_free(wallet_transaction_request_wallet_t *wallet_transaction_request_wallet) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, wallet_transaction_request_wallet->addresses) {
		free(listEntry->data);
	}
	list_free(wallet_transaction_request_wallet->addresses);
    free(wallet_transaction_request_wallet->id);
    free(wallet_transaction_request_wallet->password);
	list_ForEach(listEntry, wallet_transaction_request_wallet->unspents) {
		free(listEntry->data);
	}
	list_free(wallet_transaction_request_wallet->unspents);
	free(wallet_transaction_request_wallet);
}

cJSON *wallet_transaction_request_wallet_convertToJSON(wallet_transaction_request_wallet_t *wallet_transaction_request_wallet) {
	cJSON *item = cJSON_CreateObject();

	// wallet_transaction_request_wallet->addresses
    if(wallet_transaction_request_wallet->addresses) { 
	cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
	if(addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, wallet_transaction_request_wallet->addresses) {
    if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// wallet_transaction_request_wallet->id
    if(wallet_transaction_request_wallet->id) { 
    if(cJSON_AddStringToObject(item, "id", wallet_transaction_request_wallet->id) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_request_wallet->password
    if(wallet_transaction_request_wallet->password) { 
    if(cJSON_AddStringToObject(item, "password", wallet_transaction_request_wallet->password) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_request_wallet->unspents
    if(wallet_transaction_request_wallet->unspents) { 
	cJSON *unspents = cJSON_AddArrayToObject(item, "unspents");
	if(unspents == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *unspentsListEntry;
    list_ForEach(unspentsListEntry, wallet_transaction_request_wallet->unspents) {
    if(cJSON_AddStringToObject(unspents, "", (char*)unspentsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_parseFromJSON(cJSON *wallet_transaction_request_walletJSON){

    wallet_transaction_request_wallet_t *wallet_transaction_request_wallet_local_var = NULL;

    // wallet_transaction_request_wallet->addresses
    cJSON *addresses = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_walletJSON, "addresses");
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

    // wallet_transaction_request_wallet->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_walletJSON, "id");
    if (id) { 
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }
    }

    // wallet_transaction_request_wallet->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_walletJSON, "password");
    if (password) { 
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }
    }

    // wallet_transaction_request_wallet->unspents
    cJSON *unspents = cJSON_GetObjectItemCaseSensitive(wallet_transaction_request_walletJSON, "unspents");
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


    wallet_transaction_request_wallet_local_var = wallet_transaction_request_wallet_create (
        addresses ? addressesList : NULL,
        id ? strdup(id->valuestring) : NULL,
        password ? strdup(password->valuestring) : NULL,
        unspents ? unspentsList : NULL
        );

    return wallet_transaction_request_wallet_local_var;
end:
    return NULL;

}
