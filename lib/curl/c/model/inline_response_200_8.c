#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_8.h"


inline_response_200_8_t *inline_response_200_8_create(
    char *address
    ) {
	inline_response_200_8_t *inline_response_200_8 = malloc(sizeof(inline_response_200_8_t));
	inline_response_200_8->address = address;

	return inline_response_200_8;
}


void inline_response_200_8_free(inline_response_200_8_t *inline_response_200_8) {
    listEntry_t *listEntry;
    free(inline_response_200_8->address);

	free(inline_response_200_8);
}

cJSON *inline_response_200_8_convertToJSON(inline_response_200_8_t *inline_response_200_8) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_8->address
    if(cJSON_AddStringToObject(item, "address", inline_response_200_8->address) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_8_t *inline_response_200_8_parseFromJSON(char *jsonString){

    inline_response_200_8_t *inline_response_200_8 = NULL;
    cJSON *inline_response_200_8JSON = cJSON_Parse(jsonString);
    if(inline_response_200_8JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_8->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_response_200_8JSON, "address");
    if(!cJSON_IsString(address) || (address->valuestring == NULL)){
    goto end; //String
    }


    inline_response_200_8 = inline_response_200_8_create (
        strdup(address->valuestring)
        );
 cJSON_Delete(inline_response_200_8JSON);
    return inline_response_200_8;
end:
    cJSON_Delete(inline_response_200_8JSON);
    return NULL;

}

