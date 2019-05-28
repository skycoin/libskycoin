#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_v2_params_unspent.h"



transaction_v2_params_unspent_t *transaction_v2_params_unspent_create(
    transaction_v2_params_unspent_hours_selection_t *hours_selection,
    list_t *unspents,
    char *change_address,
    list_t *to
    ) {
	transaction_v2_params_unspent_t *transaction_v2_params_unspent_local_var = malloc(sizeof(transaction_v2_params_unspent_t));
    if (!transaction_v2_params_unspent_local_var) {
        return NULL;
    }
	transaction_v2_params_unspent_local_var->hours_selection = hours_selection;
	transaction_v2_params_unspent_local_var->unspents = unspents;
	transaction_v2_params_unspent_local_var->change_address = change_address;
	transaction_v2_params_unspent_local_var->to = to;

	return transaction_v2_params_unspent_local_var;
}


void transaction_v2_params_unspent_free(transaction_v2_params_unspent_t *transaction_v2_params_unspent) {
    listEntry_t *listEntry;
    transaction_v2_params_unspent_hours_selection_free(transaction_v2_params_unspent->hours_selection);
	list_ForEach(listEntry, transaction_v2_params_unspent->unspents) {
		free(listEntry->data);
	}
	list_free(transaction_v2_params_unspent->unspents);
    free(transaction_v2_params_unspent->change_address);
	list_ForEach(listEntry, transaction_v2_params_unspent->to) {
		transaction_v2_params_unspent_to_free(listEntry->data);
	}
	list_free(transaction_v2_params_unspent->to);
	free(transaction_v2_params_unspent);
}

cJSON *transaction_v2_params_unspent_convertToJSON(transaction_v2_params_unspent_t *transaction_v2_params_unspent) {
	cJSON *item = cJSON_CreateObject();

	// transaction_v2_params_unspent->hours_selection
    if(transaction_v2_params_unspent->hours_selection) { 
    cJSON *hours_selection_local_JSON = transaction_v2_params_unspent_hours_selection_convertToJSON(transaction_v2_params_unspent->hours_selection);
    if(hours_selection_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hours_selection", hours_selection_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction_v2_params_unspent->unspents
    if(transaction_v2_params_unspent->unspents) { 
	cJSON *unspents = cJSON_AddArrayToObject(item, "unspents");
	if(unspents == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *unspentsListEntry;
    list_ForEach(unspentsListEntry, transaction_v2_params_unspent->unspents) {
    if(cJSON_AddStringToObject(unspents, "", (char*)unspentsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_v2_params_unspent->change_address
    if(transaction_v2_params_unspent->change_address) { 
    if(cJSON_AddStringToObject(item, "change_address", transaction_v2_params_unspent->change_address) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_v2_params_unspent->to
    if(transaction_v2_params_unspent->to) { 
    cJSON *to = cJSON_AddArrayToObject(item, "to");
    if(to == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *toListEntry;
    if (transaction_v2_params_unspent->to) {
    list_ForEach(toListEntry, transaction_v2_params_unspent->to) {
    cJSON *itemLocal = transaction_v2_params_unspent_to_convertToJSON(toListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(to, itemLocal);
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

transaction_v2_params_unspent_t *transaction_v2_params_unspent_parseFromJSON(cJSON *transaction_v2_params_unspentJSON){

    transaction_v2_params_unspent_t *transaction_v2_params_unspent_local_var = NULL;

    // transaction_v2_params_unspent->hours_selection
    cJSON *hours_selection = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspentJSON, "hours_selection");
    transaction_v2_params_unspent_hours_selection_t *hours_selection_local_nonprim = NULL;
    if (hours_selection) { 
    hours_selection_local_nonprim = transaction_v2_params_unspent_hours_selection_parseFromJSON(hours_selection); //nonprimitive
    }

    // transaction_v2_params_unspent->unspents
    cJSON *unspents = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspentJSON, "unspents");
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

    // transaction_v2_params_unspent->change_address
    cJSON *change_address = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspentJSON, "change_address");
    if (change_address) { 
    if(!cJSON_IsString(change_address))
    {
    goto end; //String
    }
    }

    // transaction_v2_params_unspent->to
    cJSON *to = cJSON_GetObjectItemCaseSensitive(transaction_v2_params_unspentJSON, "to");
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
        transaction_v2_params_unspent_to_t *toItem = transaction_v2_params_unspent_to_parseFromJSON(to_local_nonprimitive);

        list_addElement(toList, toItem);
    }
    }


    transaction_v2_params_unspent_local_var = transaction_v2_params_unspent_create (
        hours_selection ? hours_selection_local_nonprim : NULL,
        unspents ? unspentsList : NULL,
        change_address ? strdup(change_address->valuestring) : NULL,
        to ? toList : NULL
        );

    return transaction_v2_params_unspent_local_var;
end:
    return NULL;

}
