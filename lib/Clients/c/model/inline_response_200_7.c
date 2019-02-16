#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_7.h"


inline_response_200_7_t *inline_response_200_7_create(
    char *address
    ) {
	inline_response_200_7_t *inline_response_200_7 = malloc(sizeof(inline_response_200_7_t));
	inline_response_200_7->address = address;

	return inline_response_200_7;
}


void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7) {
    listEntry_t *listEntry;
    free(inline_response_200_7->address);

	free(inline_response_200_7);
}

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_7->address
    if(cJSON_AddStringToObject(item, "address", inline_response_200_7->address) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_7_t *inline_response_200_7_parseFromJSON(char *jsonString){

    inline_response_200_7_t *inline_response_200_7 = NULL;
    cJSON *inline_response_200_7JSON = cJSON_Parse(jsonString);
    if(inline_response_200_7JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_7->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_response_200_7JSON, "address");
    if(!cJSON_IsString(address) || (address->valuestring == NULL)){
    goto end; //String
    }


    inline_response_200_7 = inline_response_200_7_create (
        strdup(address->valuestring)
        );
 cJSON_Delete(inline_response_200_7JSON);
    return inline_response_200_7;
end:
    cJSON_Delete(inline_response_200_7JSON);
    return NULL;

}

