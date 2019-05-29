#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200.h"



inline_response_200_t *inline_response_200_create(
    long count
    ) {
	inline_response_200_t *inline_response_200_local_var = malloc(sizeof(inline_response_200_t));
    if (!inline_response_200_local_var) {
        return NULL;
    }
	inline_response_200_local_var->count = count;

	return inline_response_200_local_var;
}


void inline_response_200_free(inline_response_200_t *inline_response_200) {
    listEntry_t *listEntry;
	free(inline_response_200);
}

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200->count
    if(inline_response_200->count) { 
    if(cJSON_AddNumberToObject(item, "count", inline_response_200->count) == NULL) {
    goto fail; //Numeric
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

    // inline_response_200->count
    cJSON *count = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "count");
    if (count) { 
    if(!cJSON_IsNumber(count))
    {
    goto end; //Numeric
    }
    }


    inline_response_200_local_var = inline_response_200_create (
        count ? count->valuedouble : 0
        );

    return inline_response_200_local_var;
end:
    return NULL;

}
