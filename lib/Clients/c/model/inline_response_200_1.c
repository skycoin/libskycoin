#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_1.h"


inline_response_200_1_t *inline_response_200_1_create(
    char *csrf_token
    ) {
	inline_response_200_1_t *inline_response_200_1 = malloc(sizeof(inline_response_200_1_t));
	inline_response_200_1->csrf_token = csrf_token;

	return inline_response_200_1;
}


void inline_response_200_1_free(inline_response_200_1_t *inline_response_200_1) {
    listEntry_t *listEntry;
    free(inline_response_200_1->csrf_token);

	free(inline_response_200_1);
}

cJSON *inline_response_200_1_convertToJSON(inline_response_200_1_t *inline_response_200_1) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_1->csrf_token
    if(cJSON_AddStringToObject(item, "csrf_token", inline_response_200_1->csrf_token) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_1_t *inline_response_200_1_parseFromJSON(char *jsonString){

    inline_response_200_1_t *inline_response_200_1 = NULL;
    cJSON *inline_response_200_1JSON = cJSON_Parse(jsonString);
    if(inline_response_200_1JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_1->csrf_token
    cJSON *csrf_token = cJSON_GetObjectItemCaseSensitive(inline_response_200_1JSON, "csrf_token");
    if(!cJSON_IsString(csrf_token) || (csrf_token->valuestring == NULL)){
    goto end; //String
    }


    inline_response_200_1 = inline_response_200_1_create (
        strdup(csrf_token->valuestring)
        );
 cJSON_Delete(inline_response_200_1JSON);
    return inline_response_200_1;
end:
    cJSON_Delete(inline_response_200_1JSON);
    return NULL;

}

