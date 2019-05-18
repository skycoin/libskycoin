#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_default.h"



inline_response_default_t *inline_response_default_create(
    int code,
    char *message
    ) {
	inline_response_default_t *inline_response_default_local_var = malloc(sizeof(inline_response_default_t));
    if (!inline_response_default_local_var) {
        return NULL;
    }
	inline_response_default_local_var->code = code;
	inline_response_default_local_var->message = message;

	return inline_response_default_local_var;
}


void inline_response_default_free(inline_response_default_t *inline_response_default) {
    listEntry_t *listEntry;
    free(inline_response_default->message);
	free(inline_response_default);
}

cJSON *inline_response_default_convertToJSON(inline_response_default_t *inline_response_default) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_default->code
    if(inline_response_default->code) { 
    if(cJSON_AddNumberToObject(item, "code", inline_response_default->code) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_default->message
    if(inline_response_default->message) { 
    if(cJSON_AddStringToObject(item, "message", inline_response_default->message) == NULL) {
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

inline_response_default_t *inline_response_default_parseFromJSON(cJSON *inline_response_defaultJSON){

    inline_response_default_t *inline_response_default_local_var = NULL;

    // inline_response_default->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(inline_response_defaultJSON, "code");
    if (code) { 
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }
    }

    // inline_response_default->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(inline_response_defaultJSON, "message");
    if (message) { 
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }
    }


    inline_response_default_local_var = inline_response_default_create (
        code ? code->valuedouble : 0,
        message ? strdup(message->valuestring) : NULL
        );

    return inline_response_default_local_var;
end:
    return NULL;

}
