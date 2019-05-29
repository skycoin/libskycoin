#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_11.h"



inline_response_200_11_t *inline_response_200_11_create(
    object_t *data
    ) {
	inline_response_200_11_t *inline_response_200_11_local_var = malloc(sizeof(inline_response_200_11_t));
    if (!inline_response_200_11_local_var) {
        return NULL;
    }
	inline_response_200_11_local_var->data = data;

	return inline_response_200_11_local_var;
}


void inline_response_200_11_free(inline_response_200_11_t *inline_response_200_11) {
    listEntry_t *listEntry;
    object_free(inline_response_200_11->data);
	free(inline_response_200_11);
}

cJSON *inline_response_200_11_convertToJSON(inline_response_200_11_t *inline_response_200_11) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_11->data
    if(inline_response_200_11->data) { 
    cJSON *data_local_JSON = object_convertToJSON(inline_response_200_11->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_11_t *inline_response_200_11_parseFromJSON(cJSON *inline_response_200_11JSON){

    inline_response_200_11_t *inline_response_200_11_local_var = NULL;

    // inline_response_200_11->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(inline_response_200_11JSON, "data");
    object_t *data_local_nonprim = NULL;
    if (data) { 
    data_local_nonprim = object_parseFromJSON(data); //nonprimitive
    }


    inline_response_200_11_local_var = inline_response_200_11_create (
        data ? data_local_nonprim : NULL
        );

    return inline_response_200_11_local_var;
end:
    return NULL;

}
