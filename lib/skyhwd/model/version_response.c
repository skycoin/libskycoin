#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "version_response.h"



version_response_t *version_response_create(
    version_response_data_t *data
    ) {
	version_response_t *version_response_local_var = malloc(sizeof(version_response_t));
    if (!version_response_local_var) {
        return NULL;
    }
	version_response_local_var->data = data;

	return version_response_local_var;
}


void version_response_free(version_response_t *version_response) {
    listEntry_t *listEntry;
    version_response_data_free(version_response->data);
	free(version_response);
}

cJSON *version_response_convertToJSON(version_response_t *version_response) {
	cJSON *item = cJSON_CreateObject();

	// version_response->data
    if(version_response->data) { 
    cJSON *data_local_JSON = version_response_data_convertToJSON(version_response->data);
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

version_response_t *version_response_parseFromJSON(cJSON *version_responseJSON){

    version_response_t *version_response_local_var = NULL;

    // version_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(version_responseJSON, "data");
    version_response_data_t *data_local_nonprim = NULL;
    if (data) { 
    data_local_nonprim = version_response_data_parseFromJSON(data); //nonprimitive
    }


    version_response_local_var = version_response_create (
        data ? data_local_nonprim : NULL
        );

    return version_response_local_var;
end:
    return NULL;

}
