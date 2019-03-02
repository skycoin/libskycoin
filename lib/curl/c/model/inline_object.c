#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_object.h"
#include "apiv1wallettransaction_hours_selection.h"
#include "apiv1wallettransaction_to.h"
#include "apiv1wallettransaction_wallet.h"
#include "list.h"


inline_object_t *inline_object_create(
    char *change_address,
    apiv1wallettransaction_hours_selection_t *hours_selection,
    bool ignore_unconfirmed,
    list_t *to,
    apiv1wallettransaction_wallet_t *wallet
    ) {
	inline_object_t *inline_object = malloc(sizeof(inline_object_t));
	inline_object->change_address = change_address;
	inline_object->hours_selection = hours_selection;
	inline_object->ignore_unconfirmed = ignore_unconfirmed;
	inline_object->to = to;
	inline_object->wallet = wallet;

	return inline_object;
}


void inline_object_free(inline_object_t *inline_object) {
    listEntry_t *listEntry;
    free(inline_object->change_address);
	apiv1wallettransaction_hours_selection_free(inline_object->hours_selection);
		list_ForEach(listEntry, inline_object->to) {
		apiv1wallettransaction_to_free(listEntry->data);
	}
	list_free(inline_object->to);
	apiv1wallettransaction_wallet_free(inline_object->wallet);

	free(inline_object);
}

cJSON *inline_object_convertToJSON(inline_object_t *inline_object) {
	cJSON *item = cJSON_CreateObject();
	// inline_object->change_address
    if(cJSON_AddStringToObject(item, "change_address", inline_object->change_address) == NULL) {
    goto fail; //String
    }

	// inline_object->hours_selection
	cJSON *hours_selection = apiv1wallettransaction_hours_selection_convertToJSON(inline_object->hours_selection);
	if(hours_selection == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "hours_selection", hours_selection);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_object->ignore_unconfirmed
    if(cJSON_AddBoolToObject(item, "ignore_unconfirmed", inline_object->ignore_unconfirmed) == NULL) {
    goto fail; //Numeric
    }

	// inline_object->to
    cJSON *to = cJSON_AddArrayToObject(item, "to");
	if(to == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *toListEntry;
	list_ForEach(toListEntry, inline_object->to) {
		cJSON *item = apiv1wallettransaction_to_convertToJSON(toListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(to, item);
	}

	// inline_object->wallet
	cJSON *wallet = apiv1wallettransaction_wallet_convertToJSON(inline_object->wallet);
	if(wallet == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "wallet", wallet);
	if(item->child == NULL) {
		goto fail;
	}

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_object_t *inline_object_parseFromJSON(char *jsonString){

    inline_object_t *inline_object = NULL;
    cJSON *inline_objectJSON = cJSON_Parse(jsonString);
    if(inline_objectJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_object->change_address
    cJSON *change_address = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "change_address");
    if(!cJSON_IsString(change_address) || (change_address->valuestring == NULL)){
    goto end; //String
    }

    // inline_object->hours_selection
    apiv1wallettransaction_hours_selection_t *hours_selection;
    cJSON *hours_selectionJSON = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "hours_selection");
    if(inline_objectJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *hours_selectionJSONData = cJSON_Print(hours_selectionJSON);
    hours_selection = apiv1wallettransaction_hours_selection_parseFromJSON(hours_selectionJSONData);

    // inline_object->ignore_unconfirmed
    cJSON *ignore_unconfirmed = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "ignore_unconfirmed");
    if(!cJSON_IsBool(ignore_unconfirmed))
    {
    goto end; //Numeric
    }

    // inline_object->to
    cJSON *to;
    cJSON *toJSON = cJSON_GetObjectItemCaseSensitive(inline_objectJSON,"to");
    if(!cJSON_IsArray(toJSON)){
        goto end; //nonprimitive container
    }

    list_t *toList = list_create();

    cJSON_ArrayForEach(to,toJSON )
    {
        if(!cJSON_IsObject(to)){
            goto end;
        }
		char *JSONData = cJSON_Print(to);
        apiv1wallettransaction_to_t *toItem = apiv1wallettransaction_to_parseFromJSON(JSONData);

        list_addElement(toList, toItem);
        free(JSONData);
    }

    // inline_object->wallet
    apiv1wallettransaction_wallet_t *wallet;
    cJSON *walletJSON = cJSON_GetObjectItemCaseSensitive(inline_objectJSON, "wallet");
    if(inline_objectJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *walletJSONData = cJSON_Print(walletJSON);
    wallet = apiv1wallettransaction_wallet_parseFromJSON(walletJSONData);


    inline_object = inline_object_create (
        strdup(change_address->valuestring),
        hours_selection,
        ignore_unconfirmed->valueint,
        toList,
        wallet
        );
        free(hours_selectionJSONData);
        free(walletJSONData);
 cJSON_Delete(inline_objectJSON);
    return inline_object;
end:
    cJSON_Delete(inline_objectJSON);
    return NULL;

}

