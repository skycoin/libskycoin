#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_object.h"



inline_object_t *inline_object_create(
    char *change_address,
    _api_v1_wallet_transaction_hours_selection_t *hours_selection,
    int ignore_unconfirmed,
    list_t *to,
    _api_v1_wallet_transaction_wallet_t *wallet
    ) {
	inline_object_t *inline_object_local_var = malloc(sizeof(inline_object_t));
    if (!inline_object_local_var) {
        return NULL;
    }
	inline_object_local_var->change_address = change_address;
	inline_object_local_var->hours_selection = hours_selection;
	inline_object_local_var->ignore_unconfirmed = ignore_unconfirmed;
	inline_object_local_var->to = to;
	inline_object_local_var->wallet = wallet;

	return inline_object_local_var;
}


void inline_object_free(inline_object_t *inline_object) {
    listEntry_t *listEntry;
    free(inline_object->change_address);
    _api_v1_wallet_transaction_hours_selection_free(inline_object->hours_selection);
	list_ForEach(listEntry, inline_object->to) {
		_api_v1_wallet_transaction_to_free(listEntry->data);
	}
	list_free(inline_object->to);
    _api_v1_wallet_transaction_wallet_free(inline_object->wallet);
	free(inline_object);
}

cJSON *inline_object_convertToJSON(inline_object_t *inline_object) {
	cJSON *item = cJSON_CreateObject();

	// inline_object->change_address
    if(inline_object->change_address) { 
    if(cJSON_AddStringToObject(item, "change_address", inline_object->change_address) == NULL) {
    goto fail; //String
    }
     } 


	// inline_object->hours_selection
    if(inline_object->hours_selection) { 
    cJSON *hours_selection_local_JSON = _api_v1_wallet_transaction_hours_selection_convertToJSON(inline_object->hours_selection);
    if(hours_selection_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hours_selection", hours_selection_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// inline_object->ignore_unconfirmed
    if(inline_object->ignore_unconfirmed) { 
    if(cJSON_AddBoolToObject(item, "ignore_unconfirmed", inline_object->ignore_unconfirmed) == NULL) {
    goto fail; //Bool
    }
     } 


	// inline_object->to
    if(inline_object->to) { 
    cJSON *to = cJSON_AddArrayToObject(item, "to");
    if(to == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *toListEntry;
    if (inline_object->to) {
    list_ForEach(toListEntry, inline_object->to) {
    cJSON *itemLocal = _api_v1_wallet_transaction_to_convertToJSON(toListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(to, itemLocal);
    }
    }
     } 


	// inline_object->wallet
    if(inline_object->wallet) { 
    cJSON *wallet_local_JSON = _api_v1_wallet_transaction_wallet_convertToJSON(inline_object->wallet);
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

inline_object_t *inline_object_parseFromJSON(cJSON *inline_objectJSON){

    inline_object_t *inline_object_local_var = NULL;

    // inline_object->change_address
    cJSON *change_address = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "change_address");
    if (change_address) { 
    if(!cJSON_IsString(change_address))
    {
    goto end; //String
    }
    }

    // inline_object->hours_selection
    cJSON *hours_selection = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "hours_selection");
    _api_v1_wallet_transaction_hours_selection_t *hours_selection_local_nonprim = NULL;
    if (hours_selection) { 
    hours_selection_local_nonprim = _api_v1_wallet_transaction_hours_selection_parseFromJSON(hours_selection); //nonprimitive
    }

    // inline_object->ignore_unconfirmed
    cJSON *ignore_unconfirmed = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "ignore_unconfirmed");
    if (ignore_unconfirmed) { 
    if(!cJSON_IsBool(ignore_unconfirmed))
    {
    goto end; //Bool
    }
    }

    // inline_object->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "to");
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
        _api_v1_wallet_transaction_to_t *toItem = _api_v1_wallet_transaction_to_parseFromJSON(to_local_nonprimitive);

        list_addElement(toList, toItem);
    }
    }

    // inline_object->wallet
    cJSON *wallet = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "wallet");
    _api_v1_wallet_transaction_wallet_t *wallet_local_nonprim = NULL;
    if (wallet) { 
    wallet_local_nonprim = _api_v1_wallet_transaction_wallet_parseFromJSON(wallet); //nonprimitive
    }


    inline_object_local_var = inline_object_create (
        change_address ? strdup(change_address->valuestring) : NULL,
        hours_selection ? hours_selection_local_nonprim : NULL,
        ignore_unconfirmed ? ignore_unconfirmed->valueint : 0,
        to ? toList : NULL,
        wallet ? wallet_local_nonprim : NULL
        );

    return inline_object_local_var;
end:
    return NULL;

}
