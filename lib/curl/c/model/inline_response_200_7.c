#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_7.h"
#include "apiv1wallets_entries.h"
#include "apiv1wallets_meta.h"
#include "list.h"


inline_response_200_7_t *inline_response_200_7_create(
    list_t *entries,
    apiv1wallets_meta_t *meta
    ) {
	inline_response_200_7_t *inline_response_200_7 = malloc(sizeof(inline_response_200_7_t));
	inline_response_200_7->entries = entries;
	inline_response_200_7->meta = meta;

	return inline_response_200_7;
}


void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7) {
    listEntry_t *listEntry;
		list_ForEach(listEntry, inline_response_200_7->entries) {
		apiv1wallets_entries_free(listEntry->data);
	}
	list_free(inline_response_200_7->entries);
	apiv1wallets_meta_free(inline_response_200_7->meta);

	free(inline_response_200_7);
}

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_7->entries
    cJSON *entries = cJSON_AddArrayToObject(item, "entries");
	if(entries == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *entriesListEntry;
	list_ForEach(entriesListEntry, inline_response_200_7->entries) {
		cJSON *item = apiv1wallets_entries_convertToJSON(entriesListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(entries, item);
	}

	// inline_response_200_7->meta
	cJSON *meta = apiv1wallets_meta_convertToJSON(inline_response_200_7->meta);
	if(meta == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "meta", meta);
	if(item->child == NULL) {
		goto fail;
	}

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_7_t *inline_response_200_7_parseFromJSON(char *jsonString){

    inline_response_200_7_t *inline_response_200_7 = NULL;
    cJSON *inline_response_200_7JSON = cJSON_Parse(jsonString);
    if(inline_response_200_7JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_7->entries
    cJSON *entries;
    cJSON *entriesJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_7JSON,"entries");
    if(!cJSON_IsArray(entriesJSON)){
        goto end; //nonprimitive container
    }

    list_t *entriesList = list_create();

    cJSON_ArrayForEach(entries,entriesJSON )
    {
        if(!cJSON_IsObject(entries)){
            goto end;
        }
		char *JSONData = cJSON_Print(entries);
        apiv1wallets_entries_t *entriesItem = apiv1wallets_entries_parseFromJSON(JSONData);

        list_addElement(entriesList, entriesItem);
        free(JSONData);
    }

    // inline_response_200_7->meta
    apiv1wallets_meta_t *meta;
    cJSON *metaJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_7JSON, "meta");
    if(inline_response_200_7JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *metaJSONData = cJSON_Print(metaJSON);
    meta = apiv1wallets_meta_parseFromJSON(metaJSONData);


    inline_response_200_7 = inline_response_200_7_create (
        entriesList,
        meta
        );
        free(metaJSONData);
 cJSON_Delete(inline_response_200_7JSON);
    return inline_response_200_7;
end:
    cJSON_Delete(inline_response_200_7JSON);
    return NULL;

}

