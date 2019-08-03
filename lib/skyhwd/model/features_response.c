#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "features_response.h"



features_response_t *features_response_create(
    features_response_data_t *data
    ) {
	features_response_t *features_response_local_var = malloc(sizeof(features_response_t));
    if (!features_response_local_var) {
        return NULL;
    }
	features_response_local_var->data = data;

	return features_response_local_var;
}


void features_response_free(features_response_t *features_response) {
    listEntry_t *listEntry;
    features_response_data_free(features_response->data);
	free(features_response);
}

cJSON *features_response_convertToJSON(features_response_t *features_response) {
	cJSON *item = cJSON_CreateObject();

	// features_response->data
    if(features_response->data) { 
    cJSON *data_local_JSON = features_response_data_convertToJSON(features_response->data);
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

features_response_t *features_response_parseFromJSON(cJSON *features_responseJSON){

    features_response_t *features_response_local_var = NULL;

    // features_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(features_responseJSON, "data");
    features_response_data_t *data_local_nonprim = NULL;
    if (data) { 
    data_local_nonprim = features_response_data_parseFromJSON(data); //nonprimitive
    }


    features_response_local_var = features_response_create (
        data ? data_local_nonprim : NULL
        );

    return features_response_local_var;
end:
    return NULL;

}
