#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passphrase_request.h"



passphrase_request_t *passphrase_request_create(
    char *passphrase
    ) {
	passphrase_request_t *passphrase_request_local_var = malloc(sizeof(passphrase_request_t));
    if (!passphrase_request_local_var) {
        return NULL;
    }
	passphrase_request_local_var->passphrase = passphrase;

	return passphrase_request_local_var;
}


void passphrase_request_free(passphrase_request_t *passphrase_request) {
    listEntry_t *listEntry;
    free(passphrase_request->passphrase);
	free(passphrase_request);
}

cJSON *passphrase_request_convertToJSON(passphrase_request_t *passphrase_request) {
	cJSON *item = cJSON_CreateObject();

	// passphrase_request->passphrase
    if (!passphrase_request->passphrase) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "passphrase", passphrase_request->passphrase) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

passphrase_request_t *passphrase_request_parseFromJSON(cJSON *passphrase_requestJSON){

    passphrase_request_t *passphrase_request_local_var = NULL;

    // passphrase_request->passphrase
    cJSON *passphrase = cJSON_GetObjectItemCaseSensitive(passphrase_requestJSON, "passphrase");
    if (!passphrase) {
        goto end;
    }

    
    if(!cJSON_IsString(passphrase))
    {
    goto end; //String
    }


    passphrase_request_local_var = passphrase_request_create (
        strdup(passphrase->valuestring)
        );

    return passphrase_request_local_var;
end:
    return NULL;

}
