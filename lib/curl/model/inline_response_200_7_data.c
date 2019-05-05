#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_7_data.h"



inline_response_200_7_data_t *inline_response_200_7_data_create(
    long version
    ) {
	inline_response_200_7_data_t *inline_response_200_7_data_local_var = malloc(sizeof(inline_response_200_7_data_t));
    if (!inline_response_200_7_data_local_var) {
        return NULL;
    }
	inline_response_200_7_data_local_var->version = version;

	return inline_response_200_7_data_local_var;
}


void inline_response_200_7_data_free(inline_response_200_7_data_t *inline_response_200_7_data) {
    listEntry_t *listEntry;
	free(inline_response_200_7_data);
}

cJSON *inline_response_200_7_data_convertToJSON(inline_response_200_7_data_t *inline_response_200_7_data) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_7_data->version
    if(inline_response_200_7_data->version) { 
    if(cJSON_AddNumberToObject(item, "version", inline_response_200_7_data->version) == NULL) {
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

inline_response_200_7_data_t *inline_response_200_7_data_parseFromJSON(cJSON *inline_response_200_7_dataJSON){

    inline_response_200_7_data_t *inline_response_200_7_data_local_var = NULL;

    // inline_response_200_7_data->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_7_dataJSON, "version");
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }


    inline_response_200_7_data_local_var = inline_response_200_7_data_create (
        version ? version->valuedouble : 0
        );

    return inline_response_200_7_data_local_var;
end:
    return NULL;

}
