#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "http_error_response_error.h"



http_error_response_error_t *http_error_response_error_create(
    int code,
    char *message
    ) {
	http_error_response_error_t *http_error_response_error_local_var = malloc(sizeof(http_error_response_error_t));
    if (!http_error_response_error_local_var) {
        return NULL;
    }
	http_error_response_error_local_var->code = code;
	http_error_response_error_local_var->message = message;

	return http_error_response_error_local_var;
}


void http_error_response_error_free(http_error_response_error_t *http_error_response_error) {
    listEntry_t *listEntry;
    free(http_error_response_error->message);
	free(http_error_response_error);
}

cJSON *http_error_response_error_convertToJSON(http_error_response_error_t *http_error_response_error) {
	cJSON *item = cJSON_CreateObject();

	// http_error_response_error->code
    if(http_error_response_error->code) { 
    if(cJSON_AddNumberToObject(item, "code", http_error_response_error->code) == NULL) {
    goto fail; //Numeric
    }
     } 


	// http_error_response_error->message
    if(http_error_response_error->message) { 
    if(cJSON_AddStringToObject(item, "message", http_error_response_error->message) == NULL) {
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

http_error_response_error_t *http_error_response_error_parseFromJSON(cJSON *http_error_response_errorJSON){

    http_error_response_error_t *http_error_response_error_local_var = NULL;

    // http_error_response_error->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(http_error_response_errorJSON, "code");
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // http_error_response_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(http_error_response_errorJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }


    http_error_response_error_local_var = http_error_response_error_create (
        code ? code->valuedouble : 0,
        message ? strdup(message->valuestring) : NULL
        );

    return http_error_response_error_local_var;
end:
    return NULL;

}
