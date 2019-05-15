#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "http_success_response.h"



http_success_response_t *http_success_response_create(
    char *data
    ) {
	http_success_response_t *http_success_response_local_var = malloc(sizeof(http_success_response_t));
    if (!http_success_response_local_var) {
        return NULL;
    }
	http_success_response_local_var->data = data;

	return http_success_response_local_var;
}


void http_success_response_free(http_success_response_t *http_success_response) {
    listEntry_t *listEntry;
    free(http_success_response->data);
	free(http_success_response);
}

cJSON *http_success_response_convertToJSON(http_success_response_t *http_success_response) {
	cJSON *item = cJSON_CreateObject();

	// http_success_response->data
    if(http_success_response->data) { 
    if(cJSON_AddStringToObject(item, "data", http_success_response->data) == NULL) {
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

http_success_response_t *http_success_response_parseFromJSON(cJSON *http_success_responseJSON){

    http_success_response_t *http_success_response_local_var = NULL;

    // http_success_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(http_success_responseJSON, "data");
    if (data) { 
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }
    }


    http_success_response_local_var = http_success_response_create (
        data ? strdup(data->valuestring) : NULL
        );

    return http_success_response_local_var;
end:
    return NULL;

}
