#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_default.h"


inline_response_default_t *inline_response_default_create(
    int code,
    char *message
    ) {
	inline_response_default_t *inline_response_default = malloc(sizeof(inline_response_default_t));
	inline_response_default->code = code;
	inline_response_default->message = message;

	return inline_response_default;
}


void inline_response_default_free(inline_response_default_t *inline_response_default) {
    listEntry_t *listEntry;
    free(inline_response_default->message);

	free(inline_response_default);
}

cJSON *inline_response_default_convertToJSON(inline_response_default_t *inline_response_default) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_default->code
    if(cJSON_AddNumberToObject(item, "code", inline_response_default->code) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_default->message
    if(cJSON_AddStringToObject(item, "message", inline_response_default->message) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_default_t *inline_response_default_parseFromJSON(char *jsonString){

    inline_response_default_t *inline_response_default = NULL;
    cJSON *inline_response_defaultJSON = cJSON_Parse(jsonString);
    if(inline_response_defaultJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_default->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(inline_response_defaultJSON, "code");
    if(!cJSON_IsNumber(code))
    {
    goto end; //Numeric
    }

    // inline_response_default->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(inline_response_defaultJSON, "message");
    if(!cJSON_IsString(message) || (message->valuestring == NULL)){
    goto end; //String
    }


    inline_response_default = inline_response_default_create (
        code->valuedouble,
        strdup(message->valuestring)
        );
 cJSON_Delete(inline_response_defaultJSON);
    return inline_response_default;
end:
    cJSON_Delete(inline_response_defaultJSON);
    return NULL;

}

