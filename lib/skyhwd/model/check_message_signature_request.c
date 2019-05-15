#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "check_message_signature_request.h"



check_message_signature_request_t *check_message_signature_request_create(
    char *message,
    char *signature,
    char *address
    ) {
	check_message_signature_request_t *check_message_signature_request_local_var = malloc(sizeof(check_message_signature_request_t));
    if (!check_message_signature_request_local_var) {
        return NULL;
    }
	check_message_signature_request_local_var->message = message;
	check_message_signature_request_local_var->signature = signature;
	check_message_signature_request_local_var->address = address;

	return check_message_signature_request_local_var;
}


void check_message_signature_request_free(check_message_signature_request_t *check_message_signature_request) {
    listEntry_t *listEntry;
    free(check_message_signature_request->message);
    free(check_message_signature_request->signature);
    free(check_message_signature_request->address);
	free(check_message_signature_request);
}

cJSON *check_message_signature_request_convertToJSON(check_message_signature_request_t *check_message_signature_request) {
	cJSON *item = cJSON_CreateObject();

	// check_message_signature_request->message
    if (!check_message_signature_request->message) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "message", check_message_signature_request->message) == NULL) {
    goto fail; //String
    }


	// check_message_signature_request->signature
    if (!check_message_signature_request->signature) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "signature", check_message_signature_request->signature) == NULL) {
    goto fail; //String
    }


	// check_message_signature_request->address
    if (!check_message_signature_request->address) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "address", check_message_signature_request->address) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

check_message_signature_request_t *check_message_signature_request_parseFromJSON(cJSON *check_message_signature_requestJSON){

    check_message_signature_request_t *check_message_signature_request_local_var = NULL;

    // check_message_signature_request->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(check_message_signature_requestJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // check_message_signature_request->signature
    cJSON *signature = cJSON_GetObjectItemCaseSensitive(check_message_signature_requestJSON, "signature");
    if (!signature) {
        goto end;
    }

    
    if(!cJSON_IsString(signature))
    {
    goto end; //String
    }

    // check_message_signature_request->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(check_message_signature_requestJSON, "address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }


    check_message_signature_request_local_var = check_message_signature_request_create (
        strdup(message->valuestring),
        strdup(signature->valuestring),
        strdup(address->valuestring)
        );

    return check_message_signature_request_local_var;
end:
    return NULL;

}
