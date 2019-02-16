#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1wallets_entries.h"


apiv1wallets_entries_t *apiv1wallets_entries_create(
    char *public_key,
    char *address
    ) {
	apiv1wallets_entries_t *apiv1wallets_entries = malloc(sizeof(apiv1wallets_entries_t));
	apiv1wallets_entries->public_key = public_key;
	apiv1wallets_entries->address = address;

	return apiv1wallets_entries;
}


void apiv1wallets_entries_free(apiv1wallets_entries_t *apiv1wallets_entries) {
    listEntry_t *listEntry;
    free(apiv1wallets_entries->public_key);
    free(apiv1wallets_entries->address);

	free(apiv1wallets_entries);
}

cJSON *apiv1wallets_entries_convertToJSON(apiv1wallets_entries_t *apiv1wallets_entries) {
	cJSON *item = cJSON_CreateObject();
	// apiv1wallets_entries->public_key
    if(cJSON_AddStringToObject(item, "public_key", apiv1wallets_entries->public_key) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_entries->address
    if(cJSON_AddStringToObject(item, "address", apiv1wallets_entries->address) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1wallets_entries_t *apiv1wallets_entries_parseFromJSON(char *jsonString){

    apiv1wallets_entries_t *apiv1wallets_entries = NULL;
    cJSON *apiv1wallets_entriesJSON = cJSON_Parse(jsonString);
    if(apiv1wallets_entriesJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1wallets_entries->public_key
    cJSON *public_key = cJSON_GetObjectItemCaseSensitive(apiv1wallets_entriesJSON, "public_key");
    if(!cJSON_IsString(public_key) || (public_key->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_entries->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(apiv1wallets_entriesJSON, "address");
    if(!cJSON_IsString(address) || (address->valuestring == NULL)){
    goto end; //String
    }


    apiv1wallets_entries = apiv1wallets_entries_create (
        strdup(public_key->valuestring),
        strdup(address->valuestring)
        );
 cJSON_Delete(apiv1wallets_entriesJSON);
    return apiv1wallets_entries;
end:
    cJSON_Delete(apiv1wallets_entriesJSON);
    return NULL;

}

