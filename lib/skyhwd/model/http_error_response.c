#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "http_error_response.h"



http_error_response_t *http_error_response_create(
    http_error_response_error_t *error
    ) {
	http_error_response_t *http_error_response_local_var = malloc(sizeof(http_error_response_t));
    if (!http_error_response_local_var) {
        return NULL;
    }
	http_error_response_local_var->error = error;

	return http_error_response_local_var;
}


void http_error_response_free(http_error_response_t *http_error_response) {
    listEntry_t *listEntry;
    http_error_response_error_free(http_error_response->error);
	free(http_error_response);
}

cJSON *http_error_response_convertToJSON(http_error_response_t *http_error_response) {
	cJSON *item = cJSON_CreateObject();

	// http_error_response->error
    if(http_error_response->error) { 
    cJSON *error_local_JSON = http_error_response_error_convertToJSON(http_error_response->error);
    if(error_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "error", error_local_JSON);
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

http_error_response_t *http_error_response_parseFromJSON(cJSON *http_error_responseJSON){

    http_error_response_t *http_error_response_local_var = NULL;

    // http_error_response->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(http_error_responseJSON, "error");
    http_error_response_error_t *error_local_nonprim = NULL;
    if (error) { 
    error_local_nonprim = http_error_response_error_parseFromJSON(error); //nonprimitive
    }


    http_error_response_local_var = http_error_response_create (
        error ? error_local_nonprim : NULL
        );

    return http_error_response_local_var;
end:
    return NULL;

}
