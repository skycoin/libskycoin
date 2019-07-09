#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_7.h"



inline_response_200_7_t *inline_response_200_7_create(
    char *address
    ) {
	inline_response_200_7_t *inline_response_200_7_local_var = malloc(sizeof(inline_response_200_7_t));
    if (!inline_response_200_7_local_var) {
        return NULL;
    }
	inline_response_200_7_local_var->address = address;

	return inline_response_200_7_local_var;
}


void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7) {
    listEntry_t *listEntry;
    free(inline_response_200_7->address);
	free(inline_response_200_7);
}

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_7->address
    if(inline_response_200_7->address) { 
    if(cJSON_AddStringToObject(item, "address", inline_response_200_7->address) == NULL) {
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

inline_response_200_7_t *inline_response_200_7_parseFromJSON(cJSON *inline_response_200_7JSON){

    inline_response_200_7_t *inline_response_200_7_local_var = NULL;

    // inline_response_200_7->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_response_200_7JSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }


    inline_response_200_7_local_var = inline_response_200_7_create (
        address ? strdup(address->valuestring) : NULL
        );

    return inline_response_200_7_local_var;
end:
    return NULL;

}
