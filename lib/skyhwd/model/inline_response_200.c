#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200.h"



inline_response_200_t *inline_response_200_create(
    int data
    ) {
	inline_response_200_t *inline_response_200_local_var = malloc(sizeof(inline_response_200_t));
    if (!inline_response_200_local_var) {
        return NULL;
    }
	inline_response_200_local_var->data = data;

	return inline_response_200_local_var;
}


void inline_response_200_free(inline_response_200_t *inline_response_200) {
    listEntry_t *listEntry;
	free(inline_response_200);
}

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200->data
    if(inline_response_200->data) { 
    if(cJSON_AddBoolToObject(item, "data", inline_response_200->data) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_t *inline_response_200_parseFromJSON(cJSON *inline_response_200JSON){

    inline_response_200_t *inline_response_200_local_var = NULL;

    // inline_response_200->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "data");
    if (data) { 
    if(!cJSON_IsBool(data))
    {
    goto end; //Bool
    }
    }


    inline_response_200_local_var = inline_response_200_create (
        data ? data->valueint : 0
        );

    return inline_response_200_local_var;
end:
    return NULL;

}
