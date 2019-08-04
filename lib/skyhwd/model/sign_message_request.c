#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sign_message_request.h"



sign_message_request_t *sign_message_request_create(
    int address_n,
    char *message
    ) {
	sign_message_request_t *sign_message_request_local_var = malloc(sizeof(sign_message_request_t));
    if (!sign_message_request_local_var) {
        return NULL;
    }
	sign_message_request_local_var->address_n = address_n;
	sign_message_request_local_var->message = message;

	return sign_message_request_local_var;
}


void sign_message_request_free(sign_message_request_t *sign_message_request) {
    listEntry_t *listEntry;
    free(sign_message_request->message);
	free(sign_message_request);
}

cJSON *sign_message_request_convertToJSON(sign_message_request_t *sign_message_request) {
	cJSON *item = cJSON_CreateObject();

	// sign_message_request->address_n
    if (!sign_message_request->address_n) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "address_n", sign_message_request->address_n) == NULL) {
    goto fail; //Numeric
    }


	// sign_message_request->message
    if (!sign_message_request->message) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "message", sign_message_request->message) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

sign_message_request_t *sign_message_request_parseFromJSON(cJSON *sign_message_requestJSON){

    sign_message_request_t *sign_message_request_local_var = NULL;

    // sign_message_request->address_n
    cJSON *address_n = cJSON_GetObjectItemCaseSensitive(sign_message_requestJSON, "address_n");
    if (!address_n) {
        goto end;
    }

    
    if(!cJSON_IsNumber(address_n))
    {
    goto end; //Numeric
    }

    // sign_message_request->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(sign_message_requestJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    sign_message_request_local_var = sign_message_request_create (
        address_n->valuedouble,
        strdup(message->valuestring)
        );

    return sign_message_request_local_var;
end:
    return NULL;

}
