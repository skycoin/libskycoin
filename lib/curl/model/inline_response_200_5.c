#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_5.h"



inline_response_200_5_t *inline_response_200_5_create(
    list_t *entries,
    _api_v1_wallets_meta_t *meta
    ) {
	inline_response_200_5_t *inline_response_200_5_local_var = malloc(sizeof(inline_response_200_5_t));
    if (!inline_response_200_5_local_var) {
        return NULL;
    }
	inline_response_200_5_local_var->entries = entries;
	inline_response_200_5_local_var->meta = meta;

	return inline_response_200_5_local_var;
}


void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_5->entries) {
		_api_v1_wallets_entries_free(listEntry->data);
	}
	list_free(inline_response_200_5->entries);
    _api_v1_wallets_meta_free(inline_response_200_5->meta);
	free(inline_response_200_5);
}

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_5->entries
    if(inline_response_200_5->entries) { 
    cJSON *entries = cJSON_AddArrayToObject(item, "entries");
    if(entries == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entriesListEntry;
    if (inline_response_200_5->entries) {
    list_ForEach(entriesListEntry, inline_response_200_5->entries) {
    cJSON *itemLocal = _api_v1_wallets_entries_convertToJSON(entriesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entries, itemLocal);
    }
    }
     } 


	// inline_response_200_5->meta
    if(inline_response_200_5->meta) { 
    cJSON *meta_local_JSON = _api_v1_wallets_meta_convertToJSON(inline_response_200_5->meta);
    if(meta_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "meta", meta_local_JSON);
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

inline_response_200_5_t *inline_response_200_5_parseFromJSON(cJSON *inline_response_200_5JSON){

    inline_response_200_5_t *inline_response_200_5_local_var = NULL;

    // inline_response_200_5->entries
    cJSON *entries = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "entries");
    list_t *entriesList;
    if (entries) { 
    cJSON *entries_local_nonprimitive;
    if(!cJSON_IsArray(entries)){
        goto end; //nonprimitive container
    }

    entriesList = list_create();

    cJSON_ArrayForEach(entries_local_nonprimitive,entries )
    {
        if(!cJSON_IsObject(entries_local_nonprimitive)){
            goto end;
        }
        _api_v1_wallets_entries_t *entriesItem = _api_v1_wallets_entries_parseFromJSON(entries_local_nonprimitive);

        list_addElement(entriesList, entriesItem);
    }
    }

    // inline_response_200_5->meta
    cJSON *meta = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "meta");
    _api_v1_wallets_meta_t *meta_local_nonprim = NULL;
    if (meta) { 
    meta_local_nonprim = _api_v1_wallets_meta_parseFromJSON(meta); //nonprimitive
    }


    inline_response_200_5_local_var = inline_response_200_5_create (
        entries ? entriesList : NULL,
        meta ? meta_local_nonprim : NULL
        );

    return inline_response_200_5_local_var;
end:
    return NULL;

}
