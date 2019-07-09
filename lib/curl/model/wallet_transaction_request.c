#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wallet_transaction_request.h"



wallet_transaction_request_t *wallet_transaction_request_create(
    char *change_address,
    wallet_transaction_request_hours_selection_t *hours_selection,
    int ignore_unconfirmed,
    list_t *to,
    wallet_transaction_request_wallet_t *wallet
    ) {
	wallet_transaction_request_t *wallet_transaction_request_local_var = malloc(sizeof(wallet_transaction_request_t));
    if (!wallet_transaction_request_local_var) {
        return NULL;
    }
	wallet_transaction_request_local_var->change_address = change_address;
	wallet_transaction_request_local_var->hours_selection = hours_selection;
	wallet_transaction_request_local_var->ignore_unconfirmed = ignore_unconfirmed;
	wallet_transaction_request_local_var->to = to;
	wallet_transaction_request_local_var->wallet = wallet;

	return wallet_transaction_request_local_var;
}


void wallet_transaction_request_free(wallet_transaction_request_t *wallet_transaction_request) {
    listEntry_t *listEntry;
    free(wallet_transaction_request->change_address);
    wallet_transaction_request_hours_selection_free(wallet_transaction_request->hours_selection);
	list_ForEach(listEntry, wallet_transaction_request->to) {
		object_free(listEntry->data);
	}
	list_free(wallet_transaction_request->to);
    wallet_transaction_request_wallet_free(wallet_transaction_request->wallet);
	free(wallet_transaction_request);
}

cJSON *wallet_transaction_request_convertToJSON(wallet_transaction_request_t *wallet_transaction_request) {
	cJSON *item = cJSON_CreateObject();

	// wallet_transaction_request->change_address
    if(wallet_transaction_request->change_address) { 
    if(cJSON_AddStringToObject(item, "change_address", wallet_transaction_request->change_address) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_request->hours_selection
    if(wallet_transaction_request->hours_selection) { 
    cJSON *hours_selection_local_JSON = wallet_transaction_request_hours_selection_convertToJSON(wallet_transaction_request->hours_selection);
    if(hours_selection_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hours_selection", hours_selection_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// wallet_transaction_request->ignore_unconfirmed
    if(wallet_transaction_request->ignore_unconfirmed) { 
    if(cJSON_AddBoolToObject(item, "ignore_unconfirmed", wallet_transaction_request->ignore_unconfirmed) == NULL) {
    goto fail; //Bool
    }
     } 


	// wallet_transaction_request->to
    if(wallet_transaction_request->to) { 
    cJSON *to = cJSON_AddArrayToObject(item, "to");
    if(to == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *toListEntry;
    if (wallet_transaction_request->to) {
    list_ForEach(toListEntry, wallet_transaction_request->to) {
    cJSON *itemLocal = object_convertToJSON(toListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(to, itemLocal);
    }
    }
     } 


	// wallet_transaction_request->wallet
    if(wallet_transaction_request->wallet) { 
    cJSON *wallet_local_JSON = wallet_transaction_request_wallet_convertToJSON(wallet_transaction_request->wallet);
    if(wallet_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "wallet", wallet_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

wallet_transaction_request_t *wallet_transaction_request_parseFromJSON(cJSON *wallet_transaction_requestJSON){

    wallet_transaction_request_t *wallet_transaction_request_local_var = NULL;

    // wallet_transaction_request->change_address
    cJSON *change_address = cJSON_GetObjectItemCaseSensitive(wallet_transaction_requestJSON, "change_address");
    if (change_address) { 
    if(!cJSON_IsString(change_address))
    {
    goto end; //String
    }
    }

    // wallet_transaction_request->hours_selection
    cJSON *hours_selection = cJSON_GetObjectItemCaseSensitive(wallet_transaction_requestJSON, "hours_selection");
    wallet_transaction_request_hours_selection_t *hours_selection_local_nonprim = NULL;
    if (hours_selection) { 
    hours_selection_local_nonprim = wallet_transaction_request_hours_selection_parseFromJSON(hours_selection); //nonprimitive
    }

    // wallet_transaction_request->ignore_unconfirmed
    cJSON *ignore_unconfirmed = cJSON_GetObjectItemCaseSensitive(wallet_transaction_requestJSON, "ignore_unconfirmed");
    if (ignore_unconfirmed) { 
    if(!cJSON_IsBool(ignore_unconfirmed))
    {
    goto end; //Bool
    }
    }

    // wallet_transaction_request->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(wallet_transaction_requestJSON, "to");
    list_t *toList;
    if (to) { 
    cJSON *to_local_nonprimitive;
    if(!cJSON_IsArray(to)){
        goto end; //nonprimitive container
    }

    toList = list_create();

    cJSON_ArrayForEach(to_local_nonprimitive,to )
    {
        if(!cJSON_IsObject(to_local_nonprimitive)){
            goto end;
        }
        object_t *toItem = object_parseFromJSON(to_local_nonprimitive);

        list_addElement(toList, toItem);
    }
    }

    // wallet_transaction_request->wallet
    cJSON *wallet = cJSON_GetObjectItemCaseSensitive(wallet_transaction_requestJSON, "wallet");
    wallet_transaction_request_wallet_t *wallet_local_nonprim = NULL;
    if (wallet) { 
    wallet_local_nonprim = wallet_transaction_request_wallet_parseFromJSON(wallet); //nonprimitive
    }


    wallet_transaction_request_local_var = wallet_transaction_request_create (
        change_address ? strdup(change_address->valuestring) : NULL,
        hours_selection ? hours_selection_local_nonprim : NULL,
        ignore_unconfirmed ? ignore_unconfirmed->valueint : 0,
        to ? toList : NULL,
        wallet ? wallet_local_nonprim : NULL
        );

    return wallet_transaction_request_local_var;
end:
    return NULL;

}
