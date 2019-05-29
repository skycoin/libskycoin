#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_10.h"



inline_response_200_10_t *inline_response_200_10_create(
    inline_response_200_10_data_t *data
    ) {
	inline_response_200_10_t *inline_response_200_10_local_var = malloc(sizeof(inline_response_200_10_t));
    if (!inline_response_200_10_local_var) {
        return NULL;
    }
	inline_response_200_10_local_var->data = data;

	return inline_response_200_10_local_var;
}


void inline_response_200_10_free(inline_response_200_10_t *inline_response_200_10) {
    listEntry_t *listEntry;
    inline_response_200_10_data_free(inline_response_200_10->data);
	free(inline_response_200_10);
}

cJSON *inline_response_200_10_convertToJSON(inline_response_200_10_t *inline_response_200_10) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_10->data
    if(inline_response_200_10->data) { 
    cJSON *data_local_JSON = inline_response_200_10_data_convertToJSON(inline_response_200_10->data);
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

inline_response_200_10_t *inline_response_200_10_parseFromJSON(cJSON *inline_response_200_10JSON){

    inline_response_200_10_t *inline_response_200_10_local_var = NULL;

    // inline_response_200_10->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(inline_response_200_10JSON, "data");
    inline_response_200_10_data_t *data_local_nonprim = NULL;
    if (data) { 
    data_local_nonprim = inline_response_200_10_data_parseFromJSON(data); //nonprimitive
    }


    inline_response_200_10_local_var = inline_response_200_10_create (
        data ? data_local_nonprim : NULL
        );

    return inline_response_200_10_local_var;
end:
    return NULL;

}
