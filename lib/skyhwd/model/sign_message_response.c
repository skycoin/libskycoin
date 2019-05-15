#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sign_message_response.h"



sign_message_response_t *sign_message_response_create(
    char *data
    ) {
	sign_message_response_t *sign_message_response_local_var = malloc(sizeof(sign_message_response_t));
    if (!sign_message_response_local_var) {
        return NULL;
    }
	sign_message_response_local_var->data = data;

	return sign_message_response_local_var;
}


void sign_message_response_free(sign_message_response_t *sign_message_response) {
    listEntry_t *listEntry;
    free(sign_message_response->data);
	free(sign_message_response);
}

cJSON *sign_message_response_convertToJSON(sign_message_response_t *sign_message_response) {
	cJSON *item = cJSON_CreateObject();

	// sign_message_response->data
    if(sign_message_response->data) { 
    if(cJSON_AddStringToObject(item, "data", sign_message_response->data) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

sign_message_response_t *sign_message_response_parseFromJSON(cJSON *sign_message_responseJSON){

    sign_message_response_t *sign_message_response_local_var = NULL;

    // sign_message_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(sign_message_responseJSON, "data");
    if (data) { 
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }
    }


    sign_message_response_local_var = sign_message_response_create (
        data ? strdup(data->valuestring) : NULL
        );

    return sign_message_response_local_var;
end:
    return NULL;

}
