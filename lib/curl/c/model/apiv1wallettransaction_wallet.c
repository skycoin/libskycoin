#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1wallettransaction_wallet.h"
#include "list.h"


apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet_create(
    list_t *unspents,
    list_t *addresses,
    char *password,
    char *id
    ) {
	apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet = malloc(sizeof(apiv1wallettransaction_wallet_t));
	apiv1wallettransaction_wallet->unspents = unspents;
	apiv1wallettransaction_wallet->addresses = addresses;
	apiv1wallettransaction_wallet->password = password;
	apiv1wallettransaction_wallet->id = id;

	return apiv1wallettransaction_wallet;
}


void apiv1wallettransaction_wallet_free(apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, apiv1wallettransaction_wallet->unspents) {
		free(listEntry->data);
	}
	list_free(apiv1wallettransaction_wallet->unspents);
	list_ForEach(listEntry, apiv1wallettransaction_wallet->addresses) {
		free(listEntry->data);
	}
	list_free(apiv1wallettransaction_wallet->addresses);
    free(apiv1wallettransaction_wallet->password);
    free(apiv1wallettransaction_wallet->id);

	free(apiv1wallettransaction_wallet);
}

cJSON *apiv1wallettransaction_wallet_convertToJSON(apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet) {
	cJSON *item = cJSON_CreateObject();
	// apiv1wallettransaction_wallet->unspents
	cJSON *unspents = cJSON_AddArrayToObject(item, "unspents");
	if(unspents == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *unspentsListEntry;
    list_ForEach(unspentsListEntry, apiv1wallettransaction_wallet->unspents) {
        if(cJSON_AddStringToObject(unspents, "", (char*)unspentsListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1wallettransaction_wallet->addresses
	cJSON *addresses = cJSON_AddArrayToObject(item, "addresses");
	if(addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *addressesListEntry;
    list_ForEach(addressesListEntry, apiv1wallettransaction_wallet->addresses) {
        if(cJSON_AddStringToObject(addresses, "", (char*)addressesListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1wallettransaction_wallet->password
    if(cJSON_AddStringToObject(item, "password", apiv1wallettransaction_wallet->password) == NULL) {
    goto fail; //String
    }

	// apiv1wallettransaction_wallet->id
    if(cJSON_AddStringToObject(item, "id", apiv1wallettransaction_wallet->id) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet_parseFromJSON(char *jsonString){

    apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet = NULL;
    cJSON *apiv1wallettransaction_walletJSON = cJSON_Parse(jsonString);
    if(apiv1wallettransaction_walletJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1wallettransaction_wallet->unspents
    cJSON *unspents;
    cJSON *unspentsJSON = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_walletJSON, "unspents");
    if(!cJSON_IsArray(unspentsJSON)) {
        goto end;//primitive container
    }
    list_t *unspentsList = list_create();

    cJSON_ArrayForEach(unspents, unspentsJSON)
    {
        if(!cJSON_IsString(unspents))
        {
            goto end;
        }
        list_addElement(unspentsList , strdup(unspents->valuestring));

    }

    // apiv1wallettransaction_wallet->addresses
    cJSON *addresses;
    cJSON *addressesJSON = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_walletJSON, "addresses");
    if(!cJSON_IsArray(addressesJSON)) {
        goto end;//primitive container
    }
    list_t *addressesList = list_create();

    cJSON_ArrayForEach(addresses, addressesJSON)
    {
        if(!cJSON_IsString(addresses))
        {
            goto end;
        }
        list_addElement(addressesList , strdup(addresses->valuestring));

    }

    // apiv1wallettransaction_wallet->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_walletJSON, "password");
    if(!cJSON_IsString(password) || (password->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallettransaction_wallet->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_walletJSON, "id");
    if(!cJSON_IsString(id) || (id->valuestring == NULL)){
    goto end; //String
    }


    apiv1wallettransaction_wallet = apiv1wallettransaction_wallet_create (
        unspentsList,
        addressesList,
        strdup(password->valuestring),
        strdup(id->valuestring)
        );
 cJSON_Delete(apiv1wallettransaction_walletJSON);
    return apiv1wallettransaction_wallet;
end:
    cJSON_Delete(apiv1wallettransaction_walletJSON);
    return NULL;

}

