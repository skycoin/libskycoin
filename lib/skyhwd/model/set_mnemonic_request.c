#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_mnemonic_request.h"



set_mnemonic_request_t *set_mnemonic_request_create(
    char *mnemonic
    ) {
	set_mnemonic_request_t *set_mnemonic_request_local_var = malloc(sizeof(set_mnemonic_request_t));
    if (!set_mnemonic_request_local_var) {
        return NULL;
    }
	set_mnemonic_request_local_var->mnemonic = mnemonic;

	return set_mnemonic_request_local_var;
}


void set_mnemonic_request_free(set_mnemonic_request_t *set_mnemonic_request) {
    listEntry_t *listEntry;
    free(set_mnemonic_request->mnemonic);
	free(set_mnemonic_request);
}

cJSON *set_mnemonic_request_convertToJSON(set_mnemonic_request_t *set_mnemonic_request) {
	cJSON *item = cJSON_CreateObject();

	// set_mnemonic_request->mnemonic
    if (!set_mnemonic_request->mnemonic) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "mnemonic", set_mnemonic_request->mnemonic) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

set_mnemonic_request_t *set_mnemonic_request_parseFromJSON(cJSON *set_mnemonic_requestJSON){

    set_mnemonic_request_t *set_mnemonic_request_local_var = NULL;

    // set_mnemonic_request->mnemonic
    cJSON *mnemonic = cJSON_GetObjectItemCaseSensitive(set_mnemonic_requestJSON, "mnemonic");
    if (!mnemonic) {
        goto end;
    }

    
    if(!cJSON_IsString(mnemonic))
    {
    goto end; //String
    }


    set_mnemonic_request_local_var = set_mnemonic_request_create (
        strdup(mnemonic->valuestring)
        );

    return set_mnemonic_request_local_var;
end:
    return NULL;

}
